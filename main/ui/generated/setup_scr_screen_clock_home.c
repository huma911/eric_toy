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



int screen_clock_home_digital_clock_main_min_value = 25;
int screen_clock_home_digital_clock_main_hour_value = 11;
int screen_clock_home_digital_clock_main_sec_value = 50;
char screen_clock_home_digital_clock_main_meridiem[] = "AM";
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

    //Write codes screen_clock_home_digital_clock_main
    static bool screen_clock_home_digital_clock_main_timer_enabled = false;
    ui->screen_clock_home_digital_clock_main = lv_label_create(ui->screen_clock_home);
    lv_obj_set_pos(ui->screen_clock_home_digital_clock_main, 15, 10);
    lv_obj_set_size(ui->screen_clock_home_digital_clock_main, 130, 30);
    lv_label_set_text(ui->screen_clock_home_digital_clock_main, "11:25:50 AM");
    if (!screen_clock_home_digital_clock_main_timer_enabled) {
        lv_timer_create(screen_clock_home_digital_clock_main_timer, 1000, NULL);
        screen_clock_home_digital_clock_main_timer_enabled = true;
    }

    //Write style for screen_clock_home_digital_clock_main, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_clock_home_digital_clock_main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_clock_home_digital_clock_main, lv_color_hex(0x00fff5), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_clock_home_digital_clock_main, &lv_font_llpixelfun_regular_22, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_clock_home_digital_clock_main, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_clock_home_digital_clock_main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_clock_home_digital_clock_main, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_clock_home_digital_clock_main, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_clock_home_digital_clock_main, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_clock_home_digital_clock_main, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_clock_home_digital_clock_main, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_clock_home_digital_clock_main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_clock_home_digital_clock_main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_clock_home_digital_clock_main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_clock_home_digital_clock_main, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_clock_home_cont_air_quality
    ui->screen_clock_home_cont_air_quality = lv_obj_create(ui->screen_clock_home);
    lv_obj_set_pos(ui->screen_clock_home_cont_air_quality, 0, 45);
    lv_obj_set_size(ui->screen_clock_home_cont_air_quality, 160, 83);
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

    //Write codes screen_clock_home_label_air
    ui->screen_clock_home_label_air = lv_label_create(ui->screen_clock_home_cont_air_quality);
    lv_obj_set_pos(ui->screen_clock_home_label_air, 15, 10);
    lv_obj_set_size(ui->screen_clock_home_label_air, 70, 12);
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
    lv_obj_set_style_text_align(ui->screen_clock_home_label_air, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
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
    lv_obj_set_pos(ui->screen_clock_home_img_quality, 105, 0);
    lv_obj_set_size(ui->screen_clock_home_img_quality, 24, 24);
    lv_obj_add_flag(ui->screen_clock_home_img_quality, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_clock_home_img_quality, &_air_RGB565A8_24x24);
    lv_image_set_pivot(ui->screen_clock_home_img_quality, 50,50);
    lv_image_set_rotation(ui->screen_clock_home_img_quality, 0);

    //Write style for screen_clock_home_img_quality, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_clock_home_img_quality, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_clock_home_img_quality, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_clock_home_label_humidity
    ui->screen_clock_home_label_humidity = lv_label_create(ui->screen_clock_home_cont_air_quality);
    lv_obj_set_pos(ui->screen_clock_home_label_humidity, 5, 25);
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
    lv_obj_set_pos(ui->screen_clock_home_label_temperature, 80, 25);
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
    lv_obj_set_pos(ui->screen_clock_home_label_humidity_value, 5, 35);
    lv_obj_set_size(ui->screen_clock_home_label_humidity_value, 70, 10);
    lv_label_set_text(ui->screen_clock_home_label_humidity_value, "100%");
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
    lv_obj_set_pos(ui->screen_clock_home_label_temp_value, 80, 35);
    lv_obj_set_size(ui->screen_clock_home_label_temp_value, 75, 10);
    lv_label_set_text(ui->screen_clock_home_label_temp_value, "40.2C");
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
    lv_obj_set_pos(ui->screen_clock_home_label_tvoc, 5, 50);
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
    lv_obj_set_pos(ui->screen_clock_home_label_co2, 80, 50);
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
    lv_obj_set_pos(ui->screen_clock_home_label_tvoc_value, 5, 62);
    lv_obj_set_size(ui->screen_clock_home_label_tvoc_value, 70, 10);
    lv_label_set_text(ui->screen_clock_home_label_tvoc_value, "0.055mg/m3");
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
    lv_obj_set_pos(ui->screen_clock_home_label_co2_value, 80, 60);
    lv_obj_set_size(ui->screen_clock_home_label_co2_value, 75, 10);
    lv_label_set_text(ui->screen_clock_home_label_co2_value, "466ppm");
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
