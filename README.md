# ESP32 (esp-idf) 实训进阶工程集

岭南师范学院 计算机科学与技术 2027 届 · 嵌入式实训作品。
从零开始的 ESP32 学习曲线，每一步都可独立编译运行，体现「感知—处理—显示—联网」的能力递进。

## 工程列表（由浅入深）
| 目录 | 内容 | 关键知识点 |
| --- | --- | --- |
| `01-helloworld` | 第一个 esp-idf 程序 | 工程结构、编译下载、日志输出 |
| `02-led` | LED _gpio 控制 + 自定义 LED 组件 | 组件化（components/）、GPIO 输出 |
| `03-key` | 按键输入 + LED 联动 | GPIO 输入、消抖、组件复用 |
| `04-freertos` | 多任务 + 按键/LED 任务 | FreeRTOS 任务创建、队列/事件组 |
| `05-lvgl` | LVGL 图形界面 + LCD 显示 | SPI 屏驱动、LVGL 移植、UI 刷新 |
| `06-qmi` | QMI8658 六轴姿态 + 显示 | I2C 传感器驱动、姿态解算、LVGL 展示 |
| `07-wifi` | WiFi STA/AP + 综合联动 | esp-netif、事件组、WiFi 配网、与 LED/KEY/LCD/QMI 集成 |
| `08-qmi-read` | QMI8658 三轴角度读取 | I2C 持续采样、姿态角计算与串口输出 |

## 环境
- 工具链：Espressif esp-idf v5.1.x
- 硬件：ESP32-S3 开发板、QMI8658 六轴 IMU、SPI LCD
- 编译：`idf.py build && idf.py flash monitor`

> 说明：仓库仅包含源码与工程配置，不含 `build/` 编译产物与 `managed_components/` 依赖（由 esp-idf 自动拉取）。
