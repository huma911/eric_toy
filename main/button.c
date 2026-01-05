#include "button.h"

#include "esp_log.h"
#include "driver/gpio.h"

#include "button_types.h"
#include "button_gpio.h"
#include "iot_button.h"

#define TAG "main_button"

//button configuration
#define BUTTON_GPIO_K0                  (GPIO_NUM_0)

#define BUTTON_GPIO_KNOB                (GPIO_NUM_21)
//button configuration

static void button_k0_single_click_cb(void *arg,void *usr_data)
{
    ESP_LOGI(TAG, "BUTTON_K0_SINGLE_CLICK");
}

static void button_knob_single_click_cb(void *arg,void *usr_data)
{
    ESP_LOGI(TAG, "BUTTON_KNOB_SINGLE_CLICK");
}

esp_err_t button_init(void)
{
    //k0
    {
        // create gpio button: k0
        const button_config_t btn_k0_cfg = {0};
        const button_gpio_config_t btn_k0_gpio_cfg = {
            .gpio_num = BUTTON_GPIO_K0,
            .active_level = 0,
        };
        button_handle_t gpio_k0_btn     = NULL;
        esp_err_t ret = iot_button_new_gpio_device(&btn_k0_cfg, &btn_k0_gpio_cfg, &gpio_k0_btn);
        if(gpio_k0_btn == NULL || ret == ESP_FAIL) {
            ESP_LOGE(TAG, "Button k0 create failed");
            return ESP_FAIL;
        } else {
            ESP_LOGI(TAG, "Button k0 create success");
        }

        // register the button callback
        ret = iot_button_register_cb(gpio_k0_btn, BUTTON_SINGLE_CLICK, NULL, button_k0_single_click_cb, NULL);
        if(ret == ESP_FAIL) {
            ESP_LOGE(TAG, "Button k0 register callback failed");
            return ESP_FAIL;
        } else {
            ESP_LOGI(TAG, "Button k0 register callback success");
        }
    }

    //knob button
    {
        // create gpio button: knob button
        const button_config_t btn_knob_cfg = {0};
        const button_gpio_config_t btn_knob_gpio_cfg = {
            .gpio_num = BUTTON_GPIO_KNOB,
            .active_level = 0,
        };
        button_handle_t gpio_knob_btn = NULL;
        esp_err_t ret = iot_button_new_gpio_device(&btn_knob_cfg, &btn_knob_gpio_cfg, &gpio_knob_btn);
        if(gpio_knob_btn == NULL || ret == ESP_FAIL) {
            ESP_LOGE(TAG, "Button knob create failed");
            return ESP_FAIL;
        } else {
            ESP_LOGI(TAG, "Button knob create success");
        }

        // register the button callback
        ret = iot_button_register_cb(gpio_knob_btn, BUTTON_SINGLE_CLICK, NULL, button_knob_single_click_cb, NULL);
        if(ret == ESP_FAIL) {
            ESP_LOGE(TAG, "Button knob register callback failed");
            return ESP_FAIL;
        } else {
            ESP_LOGI(TAG, "Button knob register callback success");
        }
    }

    return ESP_OK;
}