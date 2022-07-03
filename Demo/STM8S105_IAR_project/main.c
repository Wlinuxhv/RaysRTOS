/*****************************************************************************************
 *  main.c
 *
 *  �û����ļ�
 *
 *  Copyright (C) 2010  Է��â
 *
 *  2010-07-09  RaysRTOS1.0-STM8 �汾
 *****************************************************************************************/

/******************����ϵͳͷ�ļ�***************/
#include "RaysRTOS.h"
#include "stm8s.h"
#include "USART.h"
#include "LED.h"

/******************��������Ķ�ջ***************/
INT8U Task0Stack[50];
INT8U Task1Stack[50];
INT8U Task2Stack[50];
INT8U Task3Stack[50];

/******************����Task0����***************/
void Task0(void)
{
    while (1) {
        RAYS_TimeDelay(10);
        printstr("Task0\n");
    }
}

/******************����Task1����***************/
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

/******************����Task2����***************/
void Task2(void)
{
    while (1) {
        RAYS_TimeDelay(30);
        printstr("Task2\n");
    }

}

/******************����Task3����***************/
void Task3(void)
{
    while (1) {
        RAYS_TimeDelay(40);
        printstr("Task3\n");
    }

}


/****************������***************/
int main(void)
{
    disableInterrupts();
    CLOCK_Config(SYS_CLOCK);//ϵͳʱ�ӳ�ʼ��
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
    RAYS_Start();                //�˺���ִ����ϵͳ����������
    while (1)
        asm("WFI");

}
