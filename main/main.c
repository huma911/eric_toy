#include <stdio.h>

#include "nvs_flash.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_spiffs.h"

#include "esp_lvgl_port.h"

#include "ap_wifi.h"

#include "my_button.h"
#include "my_knob.h"
#include "my_display.h"
#include "my_sntp.h"

#include "gui_guider.h"
#include "custom.h"

#define TAG "main_app"

lv_ui guider_ui;


//html path in the spiffs
#define INDEX_HTML_PATH "/spiffs/html/apcfg.html"

static void spiffs_init(void)
{
    // 0. config spiffs
    esp_vfs_spiffs_conf_t conf = {
        .base_path = "/spiffs",
        .partition_label = "storage",
        .max_files = 5,
        .format_if_mount_failed = false
    };

    // 1. register spiffs
    ESP_ERROR_CHECK(esp_vfs_spiffs_register(&conf));
}

static void my_sntp_sync_time_cb(struct timeval *tv)
{
    struct tm t;
    time_value_t my_time_value;

    ESP_LOGI(TAG, "SNTP have got the timestamp!");
    
    localtime_r(&(tv->tv_sec), &t);

    my_time_value.year = t.tm_year + 1900;
    my_time_value.month = t.tm_mon + 1;
    my_time_value.day = t.tm_mday;
    my_time_value.week = t.tm_wday;
    my_time_value.hour = t.tm_hour;
    my_time_value.minute = t.tm_min;
    my_time_value.second = t.tm_sec;

    set_date(&guider_ui, &my_time_value);

    set_welcome_progress_bar(100);
}

static void wifi_state_callback(WIFI_STATE state)
{
    if(state == WIFI_STATE_CONNECTED) {
        ESP_LOGI(TAG, "wifi connected!");
        // if(lv_obj_has_flag(guider_ui.screen_main_img_wifi, LV_OBJ_FLAG_HIDDEN)) {
        //     lv_obj_clear_flag(guider_ui.screen_main_img_wifi, LV_OBJ_FLAG_HIDDEN);  //show the wifi state image
        // }
        my_sntp_init(my_sntp_sync_time_cb);
    } else if(state == WIFI_STATE_DISCONNECTED) {
        ESP_LOGI(TAG, "wifi disconnected!");
        set_welcome_progress_bar(50);
    } else {
        ;
    }
}

static void wifi_saved_info_callback(bool arg)
{
    ESP_LOGI(TAG, "wifi %s info callback", arg? "have" : "no");
    set_welcome(arg);
}

void app_main(void)
{
    ESP_ERROR_CHECK(nvs_flash_init());
    
    ESP_LOGI(TAG, "Hello world!");

    spiffs_init();

    my_button_init();
    // my_knob_init();

    my_display_init();

    my_time_zone_set();

    lvgl_port_lock(0);
    // setup_ui(&guider_ui);
    custom_init(&guider_ui);
    lvgl_port_unlock();

    ap_wifi_init(wifi_state_callback, wifi_saved_info_callback, INDEX_HTML_PATH);


    // vTaskDelay(pdMS_TO_TICKS(3000));
    // ap_wifi_apcfg(true);

    //test
    // while(1) {
    //     time_t now = time(NULL);
    //     ESP_LOGI(TAG, "current time stamp: %lld", now);
    //     vTaskDelay(pdMS_TO_TICKS(1000));
    // }
}
