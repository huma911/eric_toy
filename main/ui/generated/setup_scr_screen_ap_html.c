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



void setup_scr_screen_ap_html(lv_ui *ui)
{
    //Write codes screen_ap_html
    ui->screen_ap_html = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_ap_html, 160, 128);
    lv_obj_set_scrollbar_mode(ui->screen_ap_html, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_ap_html, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_ap_html, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_ap_html, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_ap_html, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_ap_html_cont_p_html
    ui->screen_ap_html_cont_p_html = lv_obj_create(ui->screen_ap_html);
    lv_obj_set_pos(ui->screen_ap_html_cont_p_html, 0, 0);
    lv_obj_set_size(ui->screen_ap_html_cont_p_html, 160, 128);
    lv_obj_set_scrollbar_mode(ui->screen_ap_html_cont_p_html, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_ap_html_cont_p_html, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_ap_html_cont_p_html, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_ap_html_cont_p_html, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_ap_html_cont_p_html, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_ap_html_cont_p_html, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_ap_html_cont_p_html, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_ap_html_cont_p_html, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_ap_html_cont_p_html, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_ap_html_cont_p_html, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_ap_html_cont_p_html, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_ap_html_cont_p_html, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_ap_html_cont_p_html, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_ap_html_label_step_three
    ui->screen_ap_html_label_step_three = lv_label_create(ui->screen_ap_html_cont_p_html);
    lv_obj_set_pos(ui->screen_ap_html_label_step_three, 5, 15);
    lv_obj_set_size(ui->screen_ap_html_label_step_three, 150, 25);
    lv_label_set_text(ui->screen_ap_html_label_step_three, "Step Three");
    lv_label_set_long_mode(ui->screen_ap_html_label_step_three, LV_LABEL_LONG_WRAP);

    //Write style for screen_ap_html_label_step_three, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_ap_html_label_step_three, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_ap_html_label_step_three, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_ap_html_label_step_three, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_ap_html_label_step_three, &lv_font_llpixelfun_regular_22, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_ap_html_label_step_three, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_ap_html_label_step_three, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_ap_html_label_step_three, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_ap_html_label_step_three, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_ap_html_label_step_three, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_ap_html_label_step_three, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_ap_html_label_step_three, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_ap_html_label_step_three, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_ap_html_label_step_three, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_ap_html_label_step_three, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_ap_html_label_text
    ui->screen_ap_html_label_text = lv_label_create(ui->screen_ap_html_cont_p_html);
    lv_obj_set_pos(ui->screen_ap_html_label_text, 5, 80);
    lv_obj_set_size(ui->screen_ap_html_label_text, 150, 40);
    lv_label_set_text(ui->screen_ap_html_label_text, "Open 192.168.100.1 by a browser, scan and establish a connection.");
    lv_label_set_long_mode(ui->screen_ap_html_label_text, LV_LABEL_LONG_WRAP);

    //Write style for screen_ap_html_label_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_ap_html_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_ap_html_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_ap_html_label_text, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_ap_html_label_text, &lv_font_llpixelfun_regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_ap_html_label_text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_ap_html_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_ap_html_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_ap_html_label_text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_ap_html_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_ap_html_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_ap_html_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_ap_html_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_ap_html_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_ap_html_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_ap_html_img_html_1
    ui->screen_ap_html_img_html_1 = lv_image_create(ui->screen_ap_html_cont_p_html);
    lv_obj_set_pos(ui->screen_ap_html_img_html_1, 45, 45);
    lv_obj_set_size(ui->screen_ap_html_img_html_1, 32, 32);
    lv_obj_add_flag(ui->screen_ap_html_img_html_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_ap_html_img_html_1, &_html_1_RGB565A8_32x32);
    lv_image_set_pivot(ui->screen_ap_html_img_html_1, 50,50);
    lv_image_set_rotation(ui->screen_ap_html_img_html_1, 0);

    //Write style for screen_ap_html_img_html_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_ap_html_img_html_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_ap_html_img_html_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_ap_html_img_html_2
    ui->screen_ap_html_img_html_2 = lv_image_create(ui->screen_ap_html_cont_p_html);
    lv_obj_set_pos(ui->screen_ap_html_img_html_2, 83, 45);
    lv_obj_set_size(ui->screen_ap_html_img_html_2, 32, 32);
    lv_obj_add_flag(ui->screen_ap_html_img_html_2, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->screen_ap_html_img_html_2, &_html_2_RGB565A8_32x32);
    lv_image_set_pivot(ui->screen_ap_html_img_html_2, 50,50);
    lv_image_set_rotation(ui->screen_ap_html_img_html_2, 0);

    //Write style for screen_ap_html_img_html_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->screen_ap_html_img_html_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->screen_ap_html_img_html_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_ap_html.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_ap_html);

}
