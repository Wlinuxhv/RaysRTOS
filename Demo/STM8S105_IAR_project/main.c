/*****************************************************************************************
 *  main.c
 *
 *  用户主文件
 *
 *  Copyright (C) 2010  苑臣芒
 *
 *  2010-07-09  RaysRTOS1.0-STM8 版本
 *****************************************************************************************/

/******************包含系统头文件***************/
#include "RaysRTOS.h"
#include "stm8s.h"
#include "USART.h"
#include "LED.h"

/******************定义任务的堆栈***************/
INT8U Task0Stack[50];
INT8U Task1Stack[50];
INT8U Task2Stack[50];
INT8U Task3Stack[50];

/******************任务Task0定义***************/
void Task0(void)
{
    while (1) {
        RAYS_TimeDelay(10);
        printstr("Task0\n");
    }
}

/******************任务Task1定义***************/
void Task1(void)
{
    while (1) {
        printstr("Task1\n");
        LED_ON();
        RAYS_TimeDelay(20);
        LED_OFF();
        RAYS_TimeDelay(20);
    }
}

/******************任务Task2定义***************/
void Task2(void)
{
    while (1) {
        RAYS_TimeDelay(30);
        printstr("Task2\n");
    }

}

/******************任务Task3定义***************/
void Task3(void)
{
    while (1) {
        RAYS_TimeDelay(40);
        printstr("Task3\n");
    }

}


/****************主函数***************/
int main(void)
{
    disableInterrupts();
    CLOCK_Config(SYS_CLOCK);//系统时钟初始化
    UART_Init(SYS_CLOCK, 115200);
    LED_Init();
    do {
        LED_ON();
        printstr("---------------Init OK------------\n");
        delay_ms(1000);
        LED_OFF();
        delay_ms(1000);
    } while (0);

    RAYS_Init();
    RAYS_TaskCreate(Task0, &Task0Stack[49], 0);
    RAYS_TaskCreate(Task1, &Task1Stack[49], 1);
    RAYS_TaskCreate(Task2, &Task2Stack[49], 2);
    RAYS_TaskCreate(Task3, &Task3Stack[49], 3);
    RAYS_Start();                //此函数执行完系统即发生调度
    while (1)
        asm("WFI");

}
