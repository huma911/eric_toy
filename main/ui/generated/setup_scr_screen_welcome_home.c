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



void setup_scr_screen_welcome_home(lv_ui *ui)
{
    //Write codes screen_welcome_home
    ui->screen_welcome_home = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_welcome_home, 160, 128);
    lv_obj_set_scrollbar_mode(ui->screen_welcome_home, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_welcome_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_welcome_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_welcome_home, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_welcome_home, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_welcome_home_cont_welcome
    ui->screen_welcome_home_cont_welcome = lv_obj_create(ui->screen_welcome_home);
    lv_obj_set_pos(ui->screen_welcome_home_cont_welcome, 0, 0);
    lv_obj_set_size(ui->screen_welcome_home_cont_welcome, 160, 128);
    lv_obj_set_scrollbar_mode(ui->screen_welcome_home_cont_welcome, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_welcome_home_cont_welcome, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_welcome_home_cont_welcome, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_welcome_home_cont_welcome, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_welcome_home_cont_welcome, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_welcome_home_cont_welcome, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_welcome_home_cont_welcome, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_welcome_home_cont_welcome, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_welcome_home_cont_welcome, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_welcome_home_cont_welcome, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_welcome_home_cont_welcome, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_welcome_home_cont_welcome, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_welcome_home_cont_welcome, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_welcome_home_bar_progress
    ui->screen_welcome_home_bar_progress = lv_bar_create(ui->screen_welcome_home_cont_welcome);
    lv_obj_set_pos(ui->screen_welcome_home_bar_progress, 20, 100);
    lv_obj_set_size(ui->screen_welcome_home_bar_progress, 120, 10);
    lv_obj_set_style_anim_duration(ui->screen_welcome_home_bar_progress, 500, 0);
    lv_bar_set_mode(ui->screen_welcome_home_bar_progress, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->screen_welcome_home_bar_progress, 0, 100);
    lv_bar_set_value(ui->screen_welcome_home_bar_progress, 0, LV_ANIM_ON);

    //Write style for screen_welcome_home_bar_progress, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_welcome_home_bar_progress, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_welcome_home_bar_progress, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_welcome_home_bar_progress, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_welcome_home_bar_progress, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_welcome_home_bar_progress, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_welcome_home_bar_progress, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_welcome_home_bar_progress, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_welcome_home_bar_progress, lv_color_hex(0xe6b219), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_welcome_home_bar_progress, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_welcome_home_bar_progress, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_welcome_home_label_text
    ui->screen_welcome_home_label_text = lv_label_create(ui->screen_welcome_home_cont_welcome);
    lv_obj_set_pos(ui->screen_welcome_home_label_text, 20, 60);
    lv_obj_set_size(ui->screen_welcome_home_label_text, 120, 30);
    lv_label_set_text(ui->screen_welcome_home_label_text, "Please waiting for the clock initial");
    lv_label_set_long_mode(ui->screen_welcome_home_label_text, LV_LABEL_LONG_WRAP);

    //Write style for screen_welcome_home_label_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_welcome_home_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_welcome_home_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_welcome_home_label_text, lv_color_hex(0x24d32e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_welcome_home_label_text, &lv_font_llpixelfun_regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_welcome_home_label_text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_welcome_home_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_welcome_home_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_welcome_home_label_text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_welcome_home_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_welcome_home_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_welcome_home_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_welcome_home_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_welcome_home_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_welcome_home_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_welcome_home_label_welcome
    ui->screen_welcome_home_label_welcome = lv_label_create(ui->screen_welcome_home_cont_welcome);
    lv_obj_set_pos(ui->screen_welcome_home_label_welcome, 10, 20);
    lv_obj_set_size(ui->screen_welcome_home_label_welcome, 140, 25);
    lv_label_set_text(ui->screen_welcome_home_label_welcome, "Welcome");
    lv_label_set_long_mode(ui->screen_welcome_home_label_welcome, LV_LABEL_LONG_WRAP);

    //Write style for screen_welcome_home_label_welcome, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_welcome_home_label_welcome, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_welcome_home_label_welcome, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_welcome_home_label_welcome, lv_color_hex(0xe619a7), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_welcome_home_label_welcome, &lv_font_llpixelfun_regular_22, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_welcome_home_label_welcome, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_welcome_home_label_welcome, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_welcome_home_label_welcome, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_welcome_home_label_welcome, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_welcome_home_label_welcome, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_welcome_home_label_welcome, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_welcome_home_label_welcome, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_welcome_home_label_welcome, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_welcome_home_label_welcome, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_welcome_home_label_welcome, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_welcome_home.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_welcome_home);

}
