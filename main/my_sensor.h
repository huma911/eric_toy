#ifndef _MY_SENSOR_H_
#define _MY_SENSOR_H_

#include "esp_err.h"

#include "ens160.h"
#include "ahtxx.h"

typedef enum ENS160_AQI_INDEX {
    ENS160_AQI_UNKNOWN   = ENS160_AQI_UBA_INDEX_UNKNOWN,
    ENS160_AQI_EXCELLENT = ENS160_AQI_UBA_INDEX_1,
    ENS160_AQI_GOOD      = ENS160_AQI_UBA_INDEX_2,
    ENS160_AQI_MODERATE  = ENS160_AQI_UBA_INDEX_3,
    ENS160_AQI_POOR      = ENS160_AQI_UBA_INDEX_4,
    ENS160_AQI_UNHEALTHY = ENS160_AQI_UBA_INDEX_5,
} ENS160_AQI_INDEX_t;

typedef void (*my_sensor_ens160_callback_t)(uint8_t aqi_index, uint16_t tvoc_value, uint16_t eco2_value);
typedef void (*my_sensor_aht21_callback_t)(float temperature_value, float humidity_value);

void my_sensor_init(my_sensor_ens160_callback_t sensor_ens160_cb, my_sensor_aht21_callback_t sensor_aht21_cb);

#endif