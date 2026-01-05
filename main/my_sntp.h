#ifndef _MY_SNTP_H_
#define _MY_SNTP_H_

#include <time.h>

#include "esp_err.h"
#include "esp_sntp.h"

esp_err_t my_sntp_init(sntp_sync_time_cb_t callback);

void my_time_zone_set(void);

#endif