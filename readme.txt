RaySRTOS0.4版本 支持三种平台：51  AVR  STM8
较以前版本将RaySRTOS主文件和不同CPU平台文件分开，形成了以下目录：

RaySRTOS（总体文件夹）
                     |Kernel（文件夹）|RaySRTOS.c 系统平台无关主文件
                     |                |RaySRTOS.h 系统平台无关头文件
                     |
                     |CPU（文件夹）   |8051_KEIL(文件夹)|CPU.c           特定平台CPU相关c文件
                     |                |                 |CPU_ASM.asm     特定平台调度代码
                     |                |                 |CPU_CFG.h       特定平台数据定义以及系统配置
                     |                |
                     |                |AVR_GCC(文件夹)  |......
                     |
                     |
                     |
                     |DEMO(文件夹)    |各种平台演示代码工程



该实时操作系统具备以下几个优点：


	1：全抢占式优先级调度
	2：小型化，适用于单片机等

