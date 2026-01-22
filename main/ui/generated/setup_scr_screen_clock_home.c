/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_screen_clock_home(lv_ui *ui)
{
    //Write codes screen_clock_home
    ui->screen_clock_home = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_clock_home, 160, 128);
    lv_obj_set_scrollbar_mode(ui->screen_clock_home, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_clock_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_clock_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_clock_home, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_clock_home, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_clock_home_label_digital_clock
    ui->screen_clock_home_label_digital_clock = lv_label_create(ui->screen_clock_home);
    lv_obj_set_pos(ui->screen_clock_home_label_digital_clock, 10, 10);
    lv_obj_set_size(ui->screen_clock_home_label_digital_clock, 140, 30);
    lv_label_set_text(ui->screen_clock_home_label_digital_clock, "8:08:08 AM");
    lv_label_set_long_mode(ui->screen_clock_home_label_digital_clock, LV_LABEL_LONG_WRAP);

    //Write style for screen_clock_home_label_digital_clock, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_clock_home_label_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_clock_home_label_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_clock_home_label_digital_clock, lv_color_hex(0x00fff5), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_clock_home_label_digital_clock, &lv_font_llpixelfun_regular_22, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_clock_home_label_digital_clock, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_clock_home_label_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_clock_home_label_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_clock_home_label_digital_clock, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_clock_home_label_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_clock_home_label_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_clock_home_label_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_clock_home_label_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_clock_home_label_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_clock_home_label_digital_clock, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_clock_home_cont_air_quality
    ui->screen_clock_home_cont_air_quality = lv_obj_create(ui->screen_clock_home);
    lv_obj_set_pos(ui->screen_clock_home_cont_air_quality, 0, 35);
    lv_obj_set_size(ui->screen_clock_home_cont_air_quality, 160, 93);
    lv_obj_set_scrollbar_mode(ui->screen_clock_home_cont_air_quality, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_clock_home_cont_air_quality, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_clock_home_cont_air_quality, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_clock_home_cont_air_quality, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_clock_home_cont_air_quality, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_clock_home_cont_air_quality, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_clock_home_cont_air_quality, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_clock_home_cont_air_quality, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_clock_home_cont_air_quality, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_clock_home_cont_air_quality, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_clock_home_cont_air_quality, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_clock_home_cont_air_quality, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_clock_home_cont_air_quality, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_clock_home_label_air_value
    ui->screen_clock_home_label_air_value = lv_label_create(ui->screen_clock_home_cont_air_quality);
    lv_obj_set_pos(ui->screen_clock_home_label_air_value, 10, 15);
    lv_obj_set_size(ui->screen_clock_home_label_air_value, 65, 12);
    lv_label_set_text(ui->screen_clock_home_label_air_value, "Unknown");
    lv_label_set_long_mode(ui->screen_clock_home_label_air_value, LV_LABEL_LONG_WRAP);

    //Write style for screen_clock_home_label_air_value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_clock_home_label_air_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_clock_home_label_air_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_clock_home_label_air_value, lv_color_hex(0xbab9ba), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_clock_home_label_air_value, &lv_font_llpixelfun_regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_clock_home_label_air_value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_clock_home_label_air_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_clock_home_label_air_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_clock_home_label_air_value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_clock_home_label_air_value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_clock_home_label_air_value, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_clock_home_label_air_value, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_clock_home_label_air_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_clock_home_label_air_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_clock_home_label_air_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_clock_home_label_air_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_clock_home_label_air_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_clock_home_label_air
    ui->screen_clock_home_label_air = lv_label_create(ui->screen_clock_home_cont_air_quality);
    lv_obj_set_pos(ui->screen_clock_home_label_air, 10, 5);
    lv_obj_set_size(ui->screen_clock_home_label_air, 65, 12);
    lv_label_set_text(ui->screen_clock_home_label_air, "Air Quality");
    lv_label_set_long_mode(ui->screen_clock_home_label_air, LV_LABEL_LONG_WRAP);

    //Write style for screen_clock_home_label_air, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_clock_home_label_air, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_clock_home_label_air, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_clock_home_label_air, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_clock_home_label_air, &lv_font_llpixelfun_regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_clock_home_label_air, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_clock_home_label_air, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_clock_home_label_air, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_clock_home_label_air, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_clock_home_label_air, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_clock_home_label_air, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_clock_home_label_air, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_clock_home_label_air, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_clock_home_label_air, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_clock_home_label_air, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_clock_home_label_air, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_clock_home_label_air, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_clock_home_img_quality
    ui->screen_clock_home_img_quality = lv_image_create(ui->screen_clock_home_cont_air_quality);
    lv_obj_set_pos(ui->screen_clock_home_img_quality, 85, 0);
    lv_obj_set_size(ui->screen_clock_home_img_quality, 64, 32);
    lv_obj_add_flag(ui->screen_clock_home_img_quality, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_clock_home_img_quality, &_airquality_RGB565A8_64x32);
    lv_image_set_pivot(ui->screen_clock_home_img_quality, 50,50);
    lv_image_set_rotation(ui->screen_clock_home_img_quality, 0);

    //Write style for screen_clock_home_img_quality, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_clock_home_img_quality, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_clock_home_img_quality, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_clock_home_img_indicator
    ui->screen_clock_home_img_indicator = lv_image_create(ui->screen_clock_home_cont_air_quality);
    lv_obj_set_pos(ui->screen_clock_home_img_indicator, 109, 0);
    lv_obj_set_size(ui->screen_clock_home_img_indicator, 16, 32);
    lv_obj_add_flag(ui->screen_clock_home_img_indicator, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_clock_home_img_indicator, &_pointer_RGB565A8_16x32);
    lv_image_set_pivot(ui->screen_clock_home_img_indicator, 9,30);
    lv_image_set_rotation(ui->screen_clock_home_img_indicator, -750);

    //Write style for screen_clock_home_img_indicator, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_clock_home_img_indicator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_clock_home_img_indicator, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_clock_home_label_humidity
    ui->screen_clock_home_label_humidity = lv_label_create(ui->screen_clock_home_cont_air_quality);
    lv_obj_set_pos(ui->screen_clock_home_label_humidity, 5, 35);
    lv_obj_set_size(ui->screen_clock_home_label_humidity, 70, 12);
    lv_label_set_text(ui->screen_clock_home_label_humidity, "humidity");
    lv_label_set_long_mode(ui->screen_clock_home_label_humidity, LV_LABEL_LONG_WRAP);

    //Write style for screen_clock_home_label_humidity, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_clock_home_label_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_clock_home_label_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_clock_home_label_humidity, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_clock_home_label_humidity, &lv_font_llpixelfun_regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_clock_home_label_humidity, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_clock_home_label_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_clock_home_label_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_clock_home_label_humidity, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_clock_home_label_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_clock_home_label_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_clock_home_label_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_clock_home_label_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_clock_home_label_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_clock_home_label_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_clock_home_label_temperature
    ui->screen_clock_home_label_temperature = lv_label_create(ui->screen_clock_home_cont_air_quality);
    lv_obj_set_pos(ui->screen_clock_home_label_temperature, 80, 35);
    lv_obj_set_size(ui->screen_clock_home_label_temperature, 75, 12);
    lv_label_set_text(ui->screen_clock_home_label_temperature, "temperature");
    lv_label_set_long_mode(ui->screen_clock_home_label_temperature, LV_LABEL_LONG_WRAP);

    //Write style for screen_clock_home_label_temperature, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_clock_home_label_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_clock_home_label_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_clock_home_label_temperature, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_clock_home_label_temperature, &lv_font_llpixelfun_regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_clock_home_label_temperature, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_clock_home_label_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_clock_home_label_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_clock_home_label_temperature, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_clock_home_label_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_clock_home_label_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_clock_home_label_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_clock_home_label_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_clock_home_label_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_clock_home_label_temperature, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_clock_home_label_humidity_value
    ui->screen_clock_home_label_humidity_value = lv_label_create(ui->screen_clock_home_cont_air_quality);
    lv_obj_set_pos(ui->screen_clock_home_label_humidity_value, 5, 45);
    lv_obj_set_size(ui->screen_clock_home_label_humidity_value, 70, 10);
    lv_label_set_text(ui->screen_clock_home_label_humidity_value, "warm-up");
    lv_label_set_long_mode(ui->screen_clock_home_label_humidity_value, LV_LABEL_LONG_WRAP);

    //Write style for screen_clock_home_label_humidity_value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_clock_home_label_humidity_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_clock_home_label_humidity_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_clock_home_label_humidity_value, lv_color_hex(0x00a1ff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_clock_home_label_humidity_value, &lv_font_llpixelfun_regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_clock_home_label_humidity_value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_clock_home_label_humidity_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_clock_home_label_humidity_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_clock_home_label_humidity_value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_clock_home_label_humidity_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_clock_home_label_humidity_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_clock_home_label_humidity_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_clock_home_label_humidity_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_clock_home_label_humidity_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_clock_home_label_humidity_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_clock_home_label_temp_value
    ui->screen_clock_home_label_temp_value = lv_label_create(ui->screen_clock_home_cont_air_quality);
    lv_obj_set_pos(ui->screen_clock_home_label_temp_value, 80, 45);
    lv_obj_set_size(ui->screen_clock_home_label_temp_value, 75, 10);
    lv_label_set_text(ui->screen_clock_home_label_temp_value, "warm-up");
    lv_label_set_long_mode(ui->screen_clock_home_label_temp_value, LV_LABEL_LONG_WRAP);

    //Write style for screen_clock_home_label_temp_value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_clock_home_label_temp_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_clock_home_label_temp_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_clock_home_label_temp_value, lv_color_hex(0xff6500), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_clock_home_label_temp_value, &lv_font_llpixelfun_regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_clock_home_label_temp_value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_clock_home_label_temp_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_clock_home_label_temp_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_clock_home_label_temp_value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_clock_home_label_temp_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_clock_home_label_temp_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_clock_home_label_temp_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_clock_home_label_temp_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_clock_home_label_temp_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_clock_home_label_temp_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_clock_home_label_tvoc
    ui->screen_clock_home_label_tvoc = lv_label_create(ui->screen_clock_home_cont_air_quality);
    lv_obj_set_pos(ui->screen_clock_home_label_tvoc, 5, 60);
    lv_obj_set_size(ui->screen_clock_home_label_tvoc, 70, 12);
    lv_label_set_text(ui->screen_clock_home_label_tvoc, "TVOC");
    lv_label_set_long_mode(ui->screen_clock_home_label_tvoc, LV_LABEL_LONG_WRAP);

    //Write style for screen_clock_home_label_tvoc, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_clock_home_label_tvoc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_clock_home_label_tvoc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_clock_home_label_tvoc, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_clock_home_label_tvoc, &lv_font_llpixelfun_regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_clock_home_label_tvoc, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_clock_home_label_tvoc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_clock_home_label_tvoc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_clock_home_label_tvoc, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_clock_home_label_tvoc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_clock_home_label_tvoc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_clock_home_label_tvoc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_clock_home_label_tvoc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_clock_home_label_tvoc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_clock_home_label_tvoc, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_clock_home_label_co2
    ui->screen_clock_home_label_co2 = lv_label_create(ui->screen_clock_home_cont_air_quality);
    lv_obj_set_pos(ui->screen_clock_home_label_co2, 80, 60);
    lv_obj_set_size(ui->screen_clock_home_label_co2, 75, 12);
    lv_label_set_text(ui->screen_clock_home_label_co2, "CO2");
    lv_label_set_long_mode(ui->screen_clock_home_label_co2, LV_LABEL_LONG_WRAP);

    //Write style for screen_clock_home_label_co2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_clock_home_label_co2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_clock_home_label_co2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_clock_home_label_co2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_clock_home_label_co2, &lv_font_llpixelfun_regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_clock_home_label_co2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_clock_home_label_co2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_clock_home_label_co2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_clock_home_label_co2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_clock_home_label_co2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_clock_home_label_co2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_clock_home_label_co2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_clock_home_label_co2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_clock_home_label_co2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_clock_home_label_co2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_clock_home_label_tvoc_value
    ui->screen_clock_home_label_tvoc_value = lv_label_create(ui->screen_clock_home_cont_air_quality);
    lv_obj_set_pos(ui->screen_clock_home_label_tvoc_value, 5, 70);
    lv_obj_set_size(ui->screen_clock_home_label_tvoc_value, 70, 10);
    lv_label_set_text(ui->screen_clock_home_label_tvoc_value, "warm-up");
    lv_label_set_long_mode(ui->screen_clock_home_label_tvoc_value, LV_LABEL_LONG_WRAP);

    //Write style for screen_clock_home_label_tvoc_value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_clock_home_label_tvoc_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_clock_home_label_tvoc_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_clock_home_label_tvoc_value, lv_color_hex(0x5aff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_clock_home_label_tvoc_value, &lv_font_llpixelfun_regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_clock_home_label_tvoc_value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_clock_home_label_tvoc_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_clock_home_label_tvoc_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_clock_home_label_tvoc_value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_clock_home_label_tvoc_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_clock_home_label_tvoc_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_clock_home_label_tvoc_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_clock_home_label_tvoc_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_clock_home_label_tvoc_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_clock_home_label_tvoc_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_clock_home_label_co2_value
    ui->screen_clock_home_label_co2_value = lv_label_create(ui->screen_clock_home_cont_air_quality);
    lv_obj_set_pos(ui->screen_clock_home_label_co2_value, 80, 70);
    lv_obj_set_size(ui->screen_clock_home_label_co2_value, 75, 10);
    lv_label_set_text(ui->screen_clock_home_label_co2_value, "warm-up");
    lv_label_set_long_mode(ui->screen_clock_home_label_co2_value, LV_LABEL_LONG_WRAP);

    //Write style for screen_clock_home_label_co2_value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_clock_home_label_co2_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_clock_home_label_co2_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_clock_home_label_co2_value, lv_color_hex(0xffbf00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_clock_home_label_co2_value, &lv_font_llpixelfun_regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_clock_home_label_co2_value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_clock_home_label_co2_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_clock_home_label_co2_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_clock_home_label_co2_value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_clock_home_label_co2_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_clock_home_label_co2_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_clock_home_label_co2_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_clock_home_label_co2_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_clock_home_label_co2_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_clock_home_label_co2_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_clock_home.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_clock_home);

}
