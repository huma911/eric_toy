#ifndef _MY_BUTTON_H_
#define _MY_BUTTON_H_

#include "esp_err.h"

#include "button_types.h"
#include "button_gpio.h"
#include "iot_button.h"

//button handle
extern button_handle_t button_k0_enter;
extern button_handle_t button_encoder_enter;

esp_err_t my_button_init(void);

#endif