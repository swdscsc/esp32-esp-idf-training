#ifndef __WIFI_AP_H
#define __WIFI_AP_H

//AP配置参数
#define  ESP_WIFI_SSID   "ESP32_1"           //WIFI名字
#define  ESP_WIFI_PASS   "12345678"          //WIFI密码
#define  ESP_WIFI_CHANNEL  1                 //WIFI通道
#define  MAX_STA_CONN      4                 //连接个数

//函数声明
void wifi_init_softap(void);

#endif


