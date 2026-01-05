#include "my_sntp.h"

#include "esp_log.h"

#define TAG "main_knob"

esp_err_t my_sntp_init(sntp_sync_time_cb_t callback)
{
    //1. check if sntp have been started
    if(esp_sntp_enabled()) {
        ESP_LOGW(TAG, "SNTP have been started!");
        return ESP_FAIL;
    }
    ESP_LOGI(TAG, "SNTP start init!");

    //2. set sntp working mode: poll mode
    esp_sntp_setoperatingmode(ESP_SNTP_OPMODE_POLL);

    //3. set sntp server: 0-aliyun 1-apple 2-NTP
    esp_sntp_setservername(0, "ntp.aliyun.com");
    esp_sntp_setservername(1, "time.asia.apple.com");
    esp_sntp_setservername(2, "pool.ntp.org");

    //4. register callback
    esp_sntp_set_time_sync_notification_cb(callback);

    //5. start sntp
    esp_sntp_init();

    return ESP_OK;
}

void my_time_zone_set(void)
{
    //0. set the time zone
    setenv("TZ", "CST-8", 1);   //set timezone environment variable
    tzset();                    //enable timezone environment variable
}