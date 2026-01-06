/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#include "esp_log.h"
#include "lvgl.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "custom.h"

#include "esp_lvgl_port.h"
/*********************
 *      DEFINES
 *********************/

  #define TAG "lvgl_custom"

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**
 * Create a demo application
 */

lv_ui*        custom_ui           = NULL;


const Week_Entry week_entries[] = {
	{WEEK_SUNDAY,        "Sunday"		},
	{WEEK_MONDAY,        "Monday"		},
	{WEEK_TUESDAY,       "Tuesday"		},
	{WEEK_WEDNESDAY,     "Wednesday"	},
	{WEEK_THURSDAY,      "Thursday"		},
	{WEEK_FRIDAY,        "Friday"		},
	{WEEK_SATURDAY,      "Saturday"		},
};

static void date_config(lv_ui* ui)
{
    time_t current_time = time(NULL);

    struct tm t;

    //1.convert the local time
    localtime_r(&current_time, &t);

    //2.set date
    char date_text[64];
    snprintf(date_text, sizeof(date_text), "%d/%d/%d", t.tm_mday, t.tm_mon + 1, t.tm_year + 1900);

    //3.set week
    char week_text[64];
    memset(week_text, 0, sizeof(week_text));
    snprintf(week_text, sizeof(week_text), "%s", week_entries[t.tm_wday].value);

    //4.set tomorrow and after tomorrow week
    char week_tomorrow_text[64];
    memset(week_tomorrow_text, 0, sizeof(week_tomorrow_text));
    snprintf(week_tomorrow_text, sizeof(week_tomorrow_text), "%s", week_entries[(t.tm_wday + 1) % WEEK_DAY_NUM].value);

    char week_after_text[64];
    memset(week_after_text, 0, sizeof(week_after_text));
    snprintf(week_after_text, sizeof(week_after_text), "%s", week_entries[(t.tm_wday + 2) % WEEK_DAY_NUM].value);

    //5.set lvgl label
    lvgl_port_lock(0);
    // lv_label_set_text(ui->screen_main_label_date, date_text);
    // lv_label_set_text(ui->screen_main_label_week, week_text);
    // lv_label_set_text(ui->screen_main_label_tomorrow, week_tomorrow_text);
    // lv_label_set_text(ui->screen_main_label_after_tomorrow, week_after_text);
    lvgl_port_unlock();
}

void set_home_time(lv_ui* ui, time_value_t* date_value)
{
    //1.set clock
    // screen_clock_home_digital_clock_main_hour_value = (int)(date_value->hour);
    // screen_clock_home_digital_clock_main_min_value  = (int)(date_value->minute);
    // screen_clock_home_digital_clock_main_sec_value  = (int)(date_value->second);

    //2.set date
    // char date_text[64];
    // memset(date_text, 0, sizeof(date_text));
    // snprintf(date_text, sizeof(date_text), "%d/%d/%d", date_value->day, date_value->month, date_value->year);

    //3.set week
    // char week_text[64];
    // memset(week_text, 0, sizeof(week_text));
    // snprintf(week_text, sizeof(week_text), "%s", week_entries[date_value->week].value);

    //4.set tomorrow and after tomorrow week
    // char week_tomorrow_text[64];
    // memset(week_tomorrow_text, 0, sizeof(week_tomorrow_text));
    // snprintf(week_tomorrow_text, sizeof(week_tomorrow_text), "%s", week_entries[(date_value->week + 1) % WEEK_DAY_NUM].value);

    // char week_after_text[64];
    // memset(week_after_text, 0, sizeof(week_after_text));
    // snprintf(week_after_text, sizeof(week_after_text), "%s", week_entries[(date_value->week + 2) % WEEK_DAY_NUM].value);

    //5.set lvgl label
    // lvgl_port_lock(0);
    // lv_label_set_text(ui->screen_main_label_date, date_text);
    // lv_label_set_text(ui->screen_main_label_week, week_text);
    // lv_label_set_text(ui->screen_main_label_tomorrow, week_tomorrow_text);
    // lv_label_set_text(ui->screen_main_label_after_tomorrow, week_after_text);

    // lv_label_set_text(ui->screen_aclock_label_date, date_text);
    // lv_label_set_text(ui->screen_aclock_label_week, week_text);
    // lvgl_port_unlock();
}

static void time_format_convert(int hour, Time_format_t *convert_time)  // 24 to 12
{
    if(hour == 0) {
        convert_time->hour = 12;
        convert_time->value = AM;
    } else if(hour < 12){
        convert_time->hour = hour;
        convert_time->value = AM;
    } else if(hour == 12) {
        convert_time->hour = 12;
        convert_time->value = PM;
    } else {
        convert_time->hour = hour - 12;
        convert_time->value = PM;
    }
}

static void time_stamp_sync_task(void* param)
{
    struct tm t;

    while(1) {
        // 1. get the time stamp
        time_t current_time = time(NULL);

        // 2. convert to the local time
        localtime_r(&current_time, &t);

        // 3. set lvgl
        if (lv_obj_is_valid(guider_ui.screen_clock_home))
        {
            Time_format_t convert_time;
            time_format_convert(t.tm_hour, &convert_time);
            lvgl_port_lock(0);
            lv_label_set_text_fmt(guider_ui.screen_clock_home_label_digital_clock, "%d:%02d:%02d %s", convert_time.hour, t.tm_min, t.tm_sec, convert_time.value? "PM" : "AM");
            lvgl_port_unlock();
        }

        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

void custom_init(lv_ui *ui)
{
    /* Add your codes here */

    custom_ui = ui;

    if(pdFAIL == xTaskCreatePinnedToCore(time_stamp_sync_task, "time_sync", 4096, NULL, 5, NULL, 0)) {
            ESP_LOGE(TAG, "creat time stamp sync task failed!");;
        }

    lvgl_port_lock(0);
    //todo
    lvgl_port_unlock();
}

