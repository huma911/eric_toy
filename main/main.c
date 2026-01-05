#include <stdio.h>

#include "nvs_flash.h"
#include "esp_log.h"

#include "esp_lvgl_port.h"

#include "ap_wifi.h"

#include "button.h"
#include "knob.h"
#include "display.h"

#include "gui_guider.h"
#include "custom.h"

#define TAG "main_app"

lv_ui guider_ui;

static void wifi_state_callback(WIFI_STATE state)
{
    if(state == WIFI_STATE_CONNECTED) {
        ESP_LOGI(TAG, "wifi connected!");
        // if(lv_obj_has_flag(guider_ui.screen_main_img_wifi, LV_OBJ_FLAG_HIDDEN)) {
        //     lv_obj_clear_flag(guider_ui.screen_main_img_wifi, LV_OBJ_FLAG_HIDDEN);  //show the wifi state image
        // }
        // my_sntp_init();
    } else if(state == WIFI_STATE_DISCONNECTED) {
        ESP_LOGI(TAG, "wifi disconnected!");
    } else {
        ;
    }
}

static void wifi_no_info_callback(void *arg)
{
    ESP_LOGI(TAG, "wifi no info callback");
}

void app_main(void)
{
    ESP_ERROR_CHECK(nvs_flash_init());
    
    ESP_LOGI(TAG, "Hello world!");

    button_init();
    knob_init();

    display_init();

    lvgl_port_lock(0);
    setup_ui(&guider_ui);
    custom_init(&guider_ui);
    lvgl_port_unlock();

    ap_wifi_init(wifi_state_callback, wifi_no_info_callback);
}
