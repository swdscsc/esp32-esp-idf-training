#include <stdio.h>
#include "freertos/FreeRTOS.h"            //系统
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "led.h"
#include "key.h"
#include "lcd.h"

void app_main(void)
{
    uint16_t cont = 0;
    uint8_t buff[50] = {0};
    led_init();
    key_init();
    bsp_lvgl_start();                                              //lcd+lvgl配置  

    //标签
    lv_obj_t *xyd = lv_label_create(lv_scr_act());                 //创建标签
    lv_label_set_text(xyd,"hello xyd!");                           //设置显示内容
    lv_obj_set_pos(xyd,100,50);                                    //设置标签在屏幕上面显示位置
    lv_obj_set_style_text_color(xyd,lv_color_hex(0xff0000),0);     //设置显示文本的字体颜色
    lv_obj_set_style_text_font(xyd,&lv_font_montserrat_24,0);

    //进度条
    lv_obj_t *bar = lv_bar_create(lv_scr_act());                   //创建进度条
    lv_obj_set_size(bar,260,30);                                   //设置进度条大小  长度200  宽度30
    lv_obj_center(bar);                                            //进行居中
    lv_bar_set_range(bar,0,260);                                   //设置进度条范围  0~260
    lv_bar_set_value(bar,0,LV_ANIM_ON);                            //设置初始值0并且把平滑动画打开
    lv_obj_set_style_bg_color(bar,lv_color_hex(0x444444),0);       //设置进度条背景颜色
    lv_obj_set_style_bg_color(bar,lv_color_hex(0x23d5ff),LV_PART_INDICATOR);    //设置进度条颜色   
    lv_obj_set_style_radius(bar,15,0);                             //设置背景圆弧
    lv_obj_set_style_radius(bar,15,LV_PART_INDICATOR);             //设置进度条圆弧

    
    lv_obj_t *a = lv_label_create(lv_scr_act());                 //创建标签
    lv_label_set_text(a,"0");                                    //设置显示内容
    lv_obj_set_pos(a,140,150);                                    //设置标签在屏幕上面显示位置
    lv_obj_set_style_text_color(a,lv_color_hex(0xff0000),0);     //设置显示文本的字体颜色
    lv_obj_set_style_text_font(a,&lv_font_montserrat_24,0);

    while (1)    
    { 
        if(key_scan() == 1)
        {
            cont += 20;
        }
        sprintf((char *)buff,"%d",cont);
        lv_label_set_text(a,(char *)buff);
        lv_bar_set_value(bar,cont,LV_ANIM_ON);
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

