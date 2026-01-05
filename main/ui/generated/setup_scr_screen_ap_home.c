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



void setup_scr_screen_ap_home(lv_ui *ui)
{
    //Write codes screen_ap_home
    ui->screen_ap_home = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_ap_home, 160, 128);
    lv_obj_set_scrollbar_mode(ui->screen_ap_home, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_ap_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_ap_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_ap_home, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_ap_home, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_ap_home_cont_ap_home
    ui->screen_ap_home_cont_ap_home = lv_obj_create(ui->screen_ap_home);
    lv_obj_set_pos(ui->screen_ap_home_cont_ap_home, 2, 0);
    lv_obj_set_size(ui->screen_ap_home_cont_ap_home, 160, 128);
    lv_obj_set_scrollbar_mode(ui->screen_ap_home_cont_ap_home, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_ap_home_cont_ap_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_ap_home_cont_ap_home, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_ap_home_cont_ap_home, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_ap_home_cont_ap_home, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_ap_home_cont_ap_home, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_ap_home_cont_ap_home, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_ap_home_cont_ap_home, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_ap_home_cont_ap_home, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_ap_home_cont_ap_home, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_ap_home_cont_ap_home, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_ap_home_cont_ap_home, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_ap_home_cont_ap_home, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_ap_home_label_step_one
    ui->screen_ap_home_label_step_one = lv_label_create(ui->screen_ap_home_cont_ap_home);
    lv_obj_set_pos(ui->screen_ap_home_label_step_one, 5, 15);
    lv_obj_set_size(ui->screen_ap_home_label_step_one, 150, 25);
    lv_label_set_text(ui->screen_ap_home_label_step_one, "Step One");
    lv_label_set_long_mode(ui->screen_ap_home_label_step_one, LV_LABEL_LONG_WRAP);

    //Write style for screen_ap_home_label_step_one, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_ap_home_label_step_one, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_ap_home_label_step_one, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_ap_home_label_step_one, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_ap_home_label_step_one, &lv_font_llpixelfun_regular_22, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_ap_home_label_step_one, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_ap_home_label_step_one, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_ap_home_label_step_one, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_ap_home_label_step_one, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_ap_home_label_step_one, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_ap_home_label_step_one, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_ap_home_label_step_one, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_ap_home_label_step_one, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_ap_home_label_step_one, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_ap_home_label_step_one, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_ap_home_label_text
    ui->screen_ap_home_label_text = lv_label_create(ui->screen_ap_home_cont_ap_home);
    lv_obj_set_pos(ui->screen_ap_home_label_text, 5, 80);
    lv_obj_set_size(ui->screen_ap_home_label_text, 150, 30);
    lv_label_set_text(ui->screen_ap_home_label_text, "press and hold the button for 3 seconds.");
    lv_label_set_long_mode(ui->screen_ap_home_label_text, LV_LABEL_LONG_WRAP);

    //Write style for screen_ap_home_label_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_ap_home_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_ap_home_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_ap_home_label_text, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_ap_home_label_text, &lv_font_llpixelfun_regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_ap_home_label_text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_ap_home_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_ap_home_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_ap_home_label_text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_ap_home_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_ap_home_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_ap_home_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_ap_home_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_ap_home_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_ap_home_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_ap_home_img_button
    ui->screen_ap_home_img_button = lv_image_create(ui->screen_ap_home_cont_ap_home);
    lv_obj_set_pos(ui->screen_ap_home_img_button, 64, 45);
    lv_obj_set_size(ui->screen_ap_home_img_button, 32, 32);
    lv_obj_add_flag(ui->screen_ap_home_img_button, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_ap_home_img_button, &_button_RGB565A8_32x32);
    lv_image_set_pivot(ui->screen_ap_home_img_button, 50,50);
    lv_image_set_rotation(ui->screen_ap_home_img_button, 0);

    //Write style for screen_ap_home_img_button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_ap_home_img_button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_ap_home_img_button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_ap_home.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_ap_home);

}
