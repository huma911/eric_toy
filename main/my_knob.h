#ifndef _MY_KNOB_H_
#define _MY_KNOB_H_

#include "esp_err.h"

#include "iot_knob.h"

//knob handle
extern knob_handle_t knob_encoder;

esp_err_t my_knob_init(void);

#endif