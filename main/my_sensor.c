#include "my_sensor.h"

#include "esp_log.h"
#include "driver/gpio.h"
#include "driver/i2c_master.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "ens160.h"
#include "ahtxx.h"

#define TAG "main_sensor"

#define ENS160_SAMPLING_PERIOD      (10000)
#define AHT21_SAMPLING_PERIOD       (5000)
#define SECOND_TO_MILLISECOND       (1000)

static i2c_master_bus_handle_t i2c_master_bus_handle = NULL;

static my_sensor_ens160_callback_t my_sensor_ens160_callback = NULL;
static my_sensor_aht21_callback_t my_sensor_aht21_callback   = NULL;

static void my_ens160_task(void *pvParameters)
{
    // initialize the xLastWakeTime variable with the current time.
    // TickType_t          last_wake_time   = xTaskGetTickCount ();
    //
    // initialize i2c device configuration
    ens160_config_t dev_cfg          = I2C_ENS160_CONFIG_DEFAULT;
    ens160_handle_t dev_hdl;
    //
    // init device
    ens160_init(i2c_master_bus_handle, &dev_cfg, &dev_hdl);
    if (dev_hdl == NULL) {
        ESP_LOGE(TAG, "ens160 handle init failed");
        assert(dev_hdl);
    }
    //
    uint16_t startup_time = 0; // seconds
    //
    // task loop entry point
    for ( ;; ) {
        ESP_LOGI(TAG, "######################## ENS160 - START #########################");
        //
        // handle sensor
        ens160_validity_flags_t dev_flag;
        if(ens160_get_validity_status(dev_hdl, &dev_flag) == ESP_OK) {
            // validate device status
            if(dev_flag == ENS160_VALFLAG_NORMAL) {
                ens160_air_quality_data_t aq_data;
                esp_err_t result = ens160_get_measurement(dev_hdl, &aq_data);
                if(result != ESP_OK) {
                    ESP_LOGE(TAG, "ens160 device read failed (%s)", esp_err_to_name(result));
                } else {
                    ens160_aqi_uba_row_t uba_aqi = ens160_aqi_index_to_definition(aq_data.uba_aqi);

                    ESP_LOGW(TAG, "index    %1x (%s)", aq_data.uba_aqi, uba_aqi.rating);
                    ESP_LOGW(TAG, "tvco     %d (0x%04x)", aq_data.tvoc, aq_data.tvoc);
                    ESP_LOGW(TAG, "etoh     %d (0x%04x)", aq_data.etoh, aq_data.etoh);
                    ESP_LOGW(TAG, "eco2     %d (0x%04x)", aq_data.eco2, aq_data.eco2);

                    if(my_sensor_ens160_callback != NULL) {
                        my_sensor_ens160_callback(aq_data.uba_aqi, aq_data.tvoc, aq_data.eco2);
                    }
                }
                //
                ens160_air_quality_raw_data_t aq_raw_data;
                result = ens160_get_raw_measurement(dev_hdl, &aq_raw_data);
                if(result != ESP_OK) {
                    ESP_LOGE(TAG, "ens160 device read failed (%s)", esp_err_to_name(result));
                } else {
                    ESP_LOGW(TAG, "ri-res 0 %lu", aq_raw_data.hp0_ri);
                    ESP_LOGW(TAG, "ri-res 1 %lu", aq_raw_data.hp1_ri);
                    ESP_LOGW(TAG, "ri-res 2 %lu", aq_raw_data.hp2_ri);
                    ESP_LOGW(TAG, "ri-res 3 %lu", aq_raw_data.hp3_ri);

                    ESP_LOGW(TAG, "bl-res 0 %lu", aq_raw_data.hp0_bl);
                    ESP_LOGW(TAG, "bl-res 1 %lu", aq_raw_data.hp1_bl);
                    ESP_LOGW(TAG, "bl-res 2 %lu", aq_raw_data.hp2_bl);
                    ESP_LOGW(TAG, "bl-res 3 %lu", aq_raw_data.hp3_bl);
                }
            } else if(dev_flag == ENS160_VALFLAG_WARMUP) {
                ESP_LOGW(TAG, "ens160 device is warming up (180-sec wait [%u-sec])", startup_time);
                startup_time = startup_time + ENS160_SAMPLING_PERIOD / SECOND_TO_MILLISECOND;
            } else if(dev_flag == ENS160_VALFLAG_INITIAL_STARTUP) {
                ESP_LOGW(TAG, "ens160 device is undrgoing initial starting up (3600-sec wait [%u-sec])", startup_time);
                startup_time = startup_time + ENS160_SAMPLING_PERIOD / SECOND_TO_MILLISECOND;
            } else if(dev_flag == ENS160_VALFLAG_INVALID_OUTPUT) {
                ESP_LOGW(TAG, "ens160 device signals are giving unexpected values");
            }
        }
        //
        ESP_LOGI(TAG, "######################## ENS160 - END ###########################");
        //
        //
        // pause the task per defined wait period
        // vTaskDelaySecUntil(&last_wake_time, ENS160_SAMPLING_PERIOD);
        vTaskDelay(pdMS_TO_TICKS(ENS160_SAMPLING_PERIOD));
    }
    //
    // free resources
    ens160_delete( dev_hdl );
    vTaskDelete( NULL );
}

static void my_aht21_task(void *pvParameters)
{
    // initialize the xLastWakeTime variable with the current time.
    // TickType_t         last_wake_time   = xTaskGetTickCount ();
    //
    // initialize i2c device configuration
    ahtxx_config_t dev_cfg          = I2C_AHT20_CONFIG_DEFAULT;
    ahtxx_handle_t dev_hdl;
    //
    // init device
    ahtxx_init(i2c_master_bus_handle, &dev_cfg, &dev_hdl);
    if (dev_hdl == NULL) {
        ESP_LOGE(TAG, "ahtxx handle init failed");
        assert(dev_hdl);
    }
    //
    // task loop entry point
    for ( ;; ) {
        ESP_LOGI(TAG, "######################## AHTXX - START #########################");
        //
        // handle sensor
        float temperature, humidity;
        esp_err_t result = ahtxx_get_measurement(dev_hdl, &temperature, &humidity);
        if(result != ESP_OK) {
            ESP_LOGE(TAG, "ahtxx device read failed (%s)", esp_err_to_name(result));
        } else {
            ESP_LOGI(TAG, "air temperature:     %.2f °C", temperature);
            ESP_LOGI(TAG, "relative humidity:   %.2f %%", humidity);

            if(my_sensor_aht21_callback != NULL) {
                my_sensor_aht21_callback(temperature, humidity);
            }
        }
        //
        ESP_LOGI(TAG, "######################## AHTXX - END ###########################");
        //
        //
        // pause the task per defined wait period
        // vTaskDelaySecUntil(&last_wake_time, I2C0_TASK_SAMPLING_RATE);
        vTaskDelay(pdMS_TO_TICKS(AHT21_SAMPLING_PERIOD));
    }
    //
    // free resources
    ahtxx_delete( dev_hdl );
    vTaskDelete( NULL );
}

void my_sensor_init(my_sensor_ens160_callback_t sensor_ens160_cb, my_sensor_aht21_callback_t sensor_aht21_cb)
{
    ESP_LOGI(TAG, "Initialize I2C master bus");
    i2c_master_bus_config_t buscfg = {
        .i2c_port = 0,
        .sda_io_num = GPIO_NUM_1,
        .scl_io_num = GPIO_NUM_2,
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .glitch_ignore_cnt = 7,
        .flags = {
            .enable_internal_pullup = true,
        }
    };
    ESP_ERROR_CHECK(i2c_new_master_bus(&buscfg, &i2c_master_bus_handle));

    if(sensor_ens160_cb != NULL) {
        my_sensor_ens160_callback = (my_sensor_ens160_callback_t)sensor_ens160_cb;
    }
    if(sensor_aht21_cb != NULL) {
        my_sensor_aht21_callback = (my_sensor_aht21_callback_t)sensor_aht21_cb;
    }

    xTaskCreatePinnedToCore(my_ens160_task, "ens160_task", 4096, NULL, 5, NULL, 0);
    xTaskCreatePinnedToCore(my_aht21_task, "ens160_task", 4096, NULL, 5, NULL, 0);
}