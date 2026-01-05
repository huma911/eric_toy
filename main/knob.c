#include "knob.h"

#include "esp_log.h"
#include "driver/gpio.h"

#include "iot_knob.h"

#define TAG "main_knob"

//knob configuration
#define KNOB_GPIO_A                 (GPIO_NUM_10)

#define KNOB_GPIO_B                 (GPIO_NUM_20)
//knob configuration

static void knob_left_cb(void *arg, void *data)
{
    ESP_LOGI(TAG, "KNOB: KNOB_LEFT,count_value:%d", iot_knob_get_count_value((knob_handle_t)arg));
}

static void knob_right_cb(void *arg, void *data)
{
    ESP_LOGI(TAG, "KNOB: KNOB_RIGHT,count_value:%d", iot_knob_get_count_value((knob_handle_t)arg));
}


esp_err_t knob_init(void)
{
    // create knob
    knob_config_t cfg = {
        .default_direction = 0,
        .gpio_encoder_a = KNOB_GPIO_A,
        .gpio_encoder_b = KNOB_GPIO_B,
    };
    knob_handle_t s_knob = iot_knob_create(&cfg);
    if(s_knob == NULL) {
        ESP_LOGE(TAG, "knob create failed");
        return ESP_FAIL;
    } else {
        ESP_LOGI(TAG, "knob create success");
    }

    esp_err_t ret = ESP_FAIL;
    ret = iot_knob_register_cb(s_knob, KNOB_LEFT, knob_left_cb, NULL);
    if(ret != ESP_OK) {
        ESP_LOGE(TAG, "knob register left callback function failed");
        return ESP_FAIL;
    } else {
        ESP_LOGI(TAG, "knob register left callback function success");
    }
    ret = iot_knob_register_cb(s_knob, KNOB_RIGHT, knob_right_cb, NULL);
    if(ret != ESP_OK) {
        ESP_LOGE(TAG, "knob register right callback function failed");
        return ESP_FAIL;
    } else {
        ESP_LOGI(TAG, "knob register right callback function success");
    }

    return ESP_OK;
}