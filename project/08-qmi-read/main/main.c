#include <stdio.h>
#include "freertos/FreeRTOS.h"            //系统
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "led.h"
#include "key.h"
#include "lcd.h"
#include "qmi.h"

#define TAG "MAIN"

void app_main(void)
{
   t_sQMI8658 sensor_data;

    /****函数初始化调用，只执行一次*****/
    led_init();      //led初始化
    key_init();      //key初始化
    IIC_Init();
    Qmi8658_Init();



    while (1)
    {
        
        qmi8658_fetch_angleFromAcc(&sensor_data);
        printf("角度-> X:%.1f, Y: %.1f, Z: %.1f\r\n", sensor_data.AngleX,sensor_data.AngleY,sensor_data.AngleZ);
        vTaskDelay(1000 / portTICK_PERIOD_MS);

    }
}


