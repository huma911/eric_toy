#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdint.h>

typedef struct {
    union {
        struct __packed
        {
            union
            {
                struct __packed
                {
                    uint8_t have_wifi_saved_info   : 1;
                    uint8_t ens160_warm_up_finished: 1;
                    uint8_t bit2                   : 1;
                    uint8_t bit3                   : 1;
                    uint8_t bit4                   : 1;
                    uint8_t bit5                   : 1;
                    uint8_t bit6                   : 1;
                    uint8_t bit7                   : 1;
                };
                uint8_t system_flag_0_uint8;
            };
            union
            {
                struct __packed
                {
                    uint8_t bit8 : 1;
                    uint8_t bit9 : 1;
                    uint8_t bit10: 1;
                    uint8_t bit11: 1;
                    uint8_t bit12: 1;
                    uint8_t bit13: 1;
                    uint8_t bit14: 1;
                    uint8_t bit15: 1;
                };
                uint8_t system_flag_1_uint8;
            };
            union
            {
                struct __packed
                {
                    uint8_t bit16: 1;
                    uint8_t bit17: 1;
                    uint8_t bit18: 1;
                    uint8_t bit19: 1;
                    uint8_t bit20: 1;
                    uint8_t bit21: 1;
                    uint8_t bit22: 1;
                    uint8_t bit23: 1;
                };
                uint8_t system_flag_2_uint8;
            };
            union
            {
                struct __packed
                {
                    uint8_t bit24: 1;
                    uint8_t bit25: 1;
                    uint8_t bit26: 1;
                    uint8_t bit27: 1;
                    uint8_t bit28: 1;
                    uint8_t bit29: 1;
                    uint8_t bit30: 1;
                    uint8_t bit31: 1;
                };
                uint8_t system_flag_3_uint8;
            };
        };
        uint32_t system_flag_uint32;
    };
}system_flag_t;

typedef struct _ERIC_TOY_INST
{
    system_flag_t         system_flag;
}eric_toy_instance_t;

extern eric_toy_instance_t myself;

#endif