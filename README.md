# TI MSPM0G3507 TestBase

基于 **TI MSPM0G3507 LaunchPad**、Code Composer Studio 与 MSPM0 SDK 的运动控制测试工程。本项目将双直流电机、编码器、巡线传感器、蓝牙遥控、步进电机和串口总线舵机等模块整合到同一套控制框架中，用于小车底盘、机械臂/云台和闭环控制方案的联调与验证。

> 当前版本为 `2026-11-22` 的代码归档。

> 立创开源广场项目页：[TI-M0G3507-TestBase](https://oshwhub.com/qwqemm/project_iroydjzk)

## 主要功能

- 双直流电机 PWM 驱动与正反转控制
- 双编码器测速、方向识别和增量式 PID 速度闭环
- 7 路巡线传感器采样与位置偏差计算
- 按键切换工作模式，OLED 显示模式、速度和状态
- 蓝牙串口 DMA 接收与遥控指令解析
- 总线舵机位置、速度、高度控制
- 步进电机 PWM 驱动、方向控制和角度计算
- 电池电压、板载温度及备用电源电压 ADC 采样

## 工作模式

| 模式 | 名称 | 功能 |
| --- | --- | --- |
| 0 | `order` | 显示电机转向和编码器速度；进入 ON 状态后执行巡线及舵机动作序列 |
| 1 | `BT` | 接收蓝牙遥控数据，控制双电机、升降机构和云台 |
| 2 | `speed` | 编码器计数与速度 PID 闭环测试 |
| 3 | 步进电机启动 | 以固定速度启动步进电机 |
| 4 | 步进电机停止 | 停止步进电机 |

- `KEY_1`：切换工作模式。
- `KEY_2`：在模式 0～2 中切换 `OFF/ON` 子状态。

## 外设与引脚

| 模块 | 引脚/资源 | 说明 |
| --- | --- | --- |
| OLED | PA31、PA28 | 软件 I2C：SCL、SDA |
| 按键 | PB4、PB5 | `KEY_1`、`KEY_2` |
| 蜂鸣器 | PB10 | 按键操作提示 |
| 编码器 1 | PA12、PB6、PB8 | 定时器计数与 A/B 相方向识别 |
| 编码器 2 | PB26、PB7、PB9 | 定时器计数与 A/B 相方向识别 |
| 直流电机 | PA0、PA1、PB12、PB13 | TIMA0 四路 PWM 输出 |
| 步进电机 | PB0、PA30 | TIMA1 脉冲输出、方向控制 |
| 巡线传感器 | PA27、PA26、PA25、PA24、PB25、PB24、PB20 | 7 路数字输入 |
| 蓝牙串口 | PB2、PB3 | UART3，115200 baud，DMA 接收 |
| 舵机/云台串口 | PA8、PA9 | UART1，115200 baud |
| 调试接口 | PA20、PA19 | SWCLK、SWDIO |

完整引脚复用与中断配置以 [`main.syscfg`](main.syscfg) 为准。

## 目录结构

```text
.
├── main.c                  # 系统初始化和主循环
├── main.syscfg             # SysConfig 外设与引脚配置
├── hardware/               # OLED、电机、编码器、PID、ADC、蓝牙等驱动
├── User/                   # 五种用户工作模式
├── targetConfigs/          # CCS 调试目标配置
├── .ccsproject             # CCS 工程元数据
├── .cproject               # CCS 构建配置
└── .project                # Eclipse/CCS 项目描述
```

## 开发环境

- Code Composer Studio（Theia 版本）
- MSPM0 SDK `2.10.00.04`
- TI Arm Clang 编译器
- LP-MSPM0G3507 LaunchPad
- SEGGER J-Link（当前 `targetConfigs/MSPM0G3507.ccxml` 使用）

## 构建与运行

1. 安装 Code Composer Studio、MSPM0 SDK 和 TI Arm Clang。
2. 在 CCS 中通过 **Import Project** 导入本目录。
3. 打开 `main.syscfg`，确认器件、引脚和串口配置与目标板一致。
4. 编译工程并确认 SysConfig 成功生成 `ti_msp_dl_config.c/.h`。
5. 连接调试器，选择 `targetConfigs/MSPM0G3507.ccxml` 后下载运行。

## 蓝牙数据说明

蓝牙接收使用 36 字节 DMA 缓冲区，程序在数据中查找 `0xFF` 包头并提取 12 字节控制帧。当前字段用于左右电机速度、升降高度和云台角度/速度。实际协议需与发送端保持一致。

## 归档说明

- `Debug/`、日志、编译中间文件、IDE 本地配置和自动生成的 `README.html` 已通过 `.gitignore` 排除。
- 电机方向、编码器方向、PID 参数及机械机构比例需要在目标硬件上重新校准。
- 本工程用于测试与联调，不包含生产级故障保护或安全认证。
