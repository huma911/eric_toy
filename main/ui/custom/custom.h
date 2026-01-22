/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef __CUSTOM_H_
#define __CUSTOM_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "gui_guider.h"

#include "my_sensor.h"

typedef enum {
    AQI_ROTATION_UNKNOWN   = -750,
    AQI_ROTATION_EXCELLENT = 750,
    AQI_ROTATION_GOOD      = 450,
    AQI_ROTATION_MODERATE  = 150,
    AQI_ROTATION_POOR      = -150,
    AQI_ROTATION_UNHEALTHY = -450,
} AQI_Rotation_Type;

typedef struct {
    ENS160_AQI_INDEX_t  index;
    AQI_Rotation_Type   rotation;
    uint32_t            color;
    const char          *text;
}AQI_Entry;

typedef enum {
    AM = 0,
    PM,
} AM_PM_t;
typedef struct {
    uint8_t         hour;
    AM_PM_t         value;
} Time_format_t;
typedef struct {
    uint16_t year;
    uint8_t month;
    uint8_t day;

    uint8_t hour;
    uint8_t minute;
    uint8_t second;

    uint8_t week;
} time_value_t;

typedef enum {
    WEEK_SUNDAY = 0,
    WEEK_MONDAY,
    WEEK_TUESDAY,
    WEEK_WEDNESDAY,
    WEEK_THURSDAY,
    WEEK_FRIDAY,
    WEEK_SATURDAY,
    WEEK_DAY_NUM,
} Week_Type;

typedef struct {
    Week_Type       week;
    const char      *value;
} Week_Entry;

void custom_init(lv_ui *ui);

void set_welcome(bool have_saved_netinfo);
void set_welcome_progress_bar(uint8_t percent);
void set_date(lv_ui* ui, time_value_t* date_value);
void set_temperature_humidity(float temperature, float humidity);
void set_air_quality_tvoc_co2(ENS160_AQI_INDEX_t aqi, uint16_t tvoc, uint16_t co2);

extern lv_timer_t* digital_clock_timer;

#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
