#include "knob.h"

#include "esp_log.h"
#include "driver/gpio.h"

#include "iot_knob.h"

#define TAG "main_knob"

esp_err_t knob_init(void)
{
    // create knob
    knob_config_t cfg = {
        .default_direction = 0,
        .gpio_encoder_a = GPIO_NUM_10,
        .gpio_encoder_b = GPIO_NUM_20,
    };
    knob_handle_t s_knob = iot_knob_create(&cfg);
    if(s_knob == NULL) {
        ESP_LOGE(TAG, "knob create failed");
        return ESP_FAIL;
    } else {
        ESP_LOGI(TAG, "knob create success");
    }

    return ESP_OK;
}