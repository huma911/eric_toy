#ifndef _MY_SENSOR_H_
#define _MY_SENSOR_H_

#include "esp_err.h"

typedef void (*my_sensor_ens160_callback_t)(uint8_t aqi_index, uint16_t tvoc_value, uint16_t eco2_value);
typedef void (*my_sensor_aht21_callback_t)(float temperature_value, float humidity_value);

void my_sensor_init(my_sensor_ens160_callback_t sensor_ens160_cb, my_sensor_aht21_callback_t sensor_aht21_cb);

#endif