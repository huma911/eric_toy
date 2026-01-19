#include "my_button.h"

#include "esp_log.h"
#include "driver/gpio.h"

#include "ap_wifi.h"
#include "gui_guider.h"
#include "custom.h"

#define TAG "main_button"

//button configuration
#define BUTTON_GPIO_K0                  (GPIO_NUM_21)

#define BUTTON_GPIO_KNOB                (GPIO_NUM_20)
//button configuration

//button handle
button_handle_t button_k0_enter      = NULL;
button_handle_t button_encoder_enter = NULL;

static void button_k0_enter_single_click_cb(void *arg,void *usr_data)
{
    ESP_LOGI(TAG, "BUTTON_K0_ENTER_SINGLE_CLICK");

    if(lv_obj_is_valid(guider_ui.screen_welcome_home)) {
        extern lv_ui guider_ui;
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_ap_home, guider_ui.screen_ap_home_del, &guider_ui.screen_welcome_home_del, setup_scr_screen_ap_home, LV_SCR_LOAD_ANIM_FADE_IN, 1000, 0, true, true);
    } else if(lv_obj_is_valid(guider_ui.screen_ap_ap)) {
        extern lv_ui guider_ui;
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_ap_html, guider_ui.screen_ap_html_del, &guider_ui.screen_ap_ap_del, setup_scr_screen_ap_html, LV_SCR_LOAD_ANIM_FADE_IN, 1000, 0, true, true);
    } else if(lv_obj_is_valid(guider_ui.screen_ap_html)) {
        extern lv_ui guider_ui;
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_ap_finish, guider_ui.screen_ap_finish_del, &guider_ui.screen_ap_html_del, setup_scr_screen_ap_finish, LV_SCR_LOAD_ANIM_FADE_IN, 1000, 0, true, true);
    } else {
        ;
    }
}

static void button_knob_single_click_cb(void *arg,void *usr_data)
{
    ESP_LOGI(TAG, "BUTTON_KNOB_SINGLE_CLICK");
}

static void button_k0_enter_long_press_start_cb(void *arg,void *usr_data)
{
    ESP_LOGI(TAG, "BUTTON_K0_ENTER_LONG_PRESS_START");

    if(lv_obj_is_valid(guider_ui.screen_ap_home)) {
        extern lv_ui guider_ui;
        ui_load_scr_animation(&guider_ui, &guider_ui.screen_ap_ap, guider_ui.screen_ap_ap_del, &guider_ui.screen_ap_home_del, setup_scr_screen_ap_ap, LV_SCR_LOAD_ANIM_FADE_IN, 1000, 0, true, true);
        ap_wifi_apcfg(true);    //enter AP configuration
    }
}

static void button_knob_long_press_start_cb(void *arg,void *usr_data)
{
    ESP_LOGI(TAG, "BUTTON_KNOB_LONG_PRESS_START");
}

esp_err_t my_button_init(void)
{
    //k0
    {
        // create gpio button: k0
        const button_config_t btn_k0_cfg = {0};
        const button_gpio_config_t btn_k0_gpio_cfg = {
            .gpio_num = BUTTON_GPIO_K0,
            .active_level = 0,
        };
        
        esp_err_t ret = iot_button_new_gpio_device(&btn_k0_cfg, &btn_k0_gpio_cfg, &button_k0_enter);
        if(button_k0_enter == NULL || ret == ESP_FAIL) {
            ESP_LOGE(TAG, "Button k0 create failed");
            return ESP_FAIL;
        } else {
            ESP_LOGI(TAG, "Button k0 create success");
        }

        // register the button callback
        // single click
        ret = iot_button_register_cb(button_k0_enter, BUTTON_SINGLE_CLICK, NULL, button_k0_enter_single_click_cb, NULL);
        if(ret == ESP_FAIL) {
            ESP_LOGE(TAG, "Button k0 register single click callback failed");
            return ESP_FAIL;
        } else {
            ESP_LOGI(TAG, "Button k0 register single click callback success");
        }

        // long press start
        button_event_args_t args = {
            .long_press.press_time = 2000,
        };
        ret = iot_button_register_cb(button_k0_enter, BUTTON_LONG_PRESS_START, &args, button_k0_enter_long_press_start_cb, NULL);
        if(ret == ESP_FAIL) {
            ESP_LOGE(TAG, "Button k0 register long press start callback failed");
            return ESP_FAIL;
        } else {
            ESP_LOGI(TAG, "Button k0 register long press start callback success");
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
        
        esp_err_t ret = iot_button_new_gpio_device(&btn_knob_cfg, &btn_knob_gpio_cfg, &button_encoder_enter);
        if(button_encoder_enter == NULL || ret == ESP_FAIL) {
            ESP_LOGE(TAG, "Button knob create failed");
            return ESP_FAIL;
        } else {
            ESP_LOGI(TAG, "Button knob create success");
        }

        // register the button callback
        // single click
        // ret = iot_button_register_cb(button_encoder_enter, BUTTON_SINGLE_CLICK, NULL, button_knob_single_click_cb, NULL);
        // if(ret == ESP_FAIL) {
        //     ESP_LOGE(TAG, "Button knob register single click callback failed");
        //     return ESP_FAIL;
        // } else {
        //     ESP_LOGI(TAG, "Button knob register single click callback success");
        // }

        // long press start
        // button_event_args_t args = {
        //     .long_press.press_time = 2000,
        // };
        // ret = iot_button_register_cb(button_encoder_enter, BUTTON_LONG_PRESS_START, &args, button_knob_long_press_start_cb, NULL);
        // if(ret == ESP_FAIL) {
        //     ESP_LOGE(TAG, "Button knob register long press start callback failed");
        //     return ESP_FAIL;
        // } else {
        //     ESP_LOGI(TAG, "Button knob register long press start callback success");
        // }
    }

    return ESP_OK;
}