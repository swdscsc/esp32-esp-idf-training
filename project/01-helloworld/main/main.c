#include <stdio.h>
#include "freertos/FreeRTOS.h"            //系统
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/gpio.h"

void led_init(void)
{
    //配置IO1引脚
    gpio_config_t gpioconfig = {
        .intr_type = 0,                       //中断开关 --- 关闭中断
        .mode = GPIO_MODE_OUTPUT,             //模式配置 --- 输出模式
        .pin_bit_mask = 1ULL << GPIO_NUM_1,   //引脚选择 --- IO1引脚
        .pull_down_en = 0,                    //下拉电阻 --- 关闭下拉电阻 --- 初始电平为低电平
        .pull_up_en = 0,                      //上拉电阻 --- 关闭上拉电阻 --- 初始电平为高电平
    };
    gpio_config(&gpioconfig);
}


void app_main(void)
{
    char a = 10;
    led_init();

    //开灯
    gpio_set_level(GPIO_NUM_1,0);           //控制IO1引脚输出低电平


    while (1)                 
    {
        a++;
        printf("a:%d\n",a);                      //灰色
        ESP_LOGI("main","hello xyd");            //绿色
        ESP_LOGE("main","你好");                 //红色
        //延时500ms
        vTaskDelay(pdMS_TO_TICKS(500));   
    }
}


