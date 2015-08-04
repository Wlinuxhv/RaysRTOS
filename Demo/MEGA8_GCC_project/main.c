/***************************************************************************************** 
 *  main.c 
 * 
 *  Copyright (C) 2010  苑臣芒 
 * 
 *  2010-07-09  RaysRTOS1.0-Mega8 版本
 *****************************************************************************************/

/******************包含系统头文件***************/
#include "RaysRTOS.h"

/******************定义任务的堆栈***************/
INT8U Task0Stack[50];
INT8U Task1Stack[50];
INT8U Task2Stack[50];

//用户函数定义
void delays(unsigned char xx)
{
 while(xx--);

}
void delaysss(void)
{
 unsigned char i=0;
 i=10;
   delays(i);

}
/******************任务Task0定义***************/
void Task0(void)
{
	 unsigned char i=0;
 while(1)
 {
   PORTD=i++;
   RAYS_TimeDelay(3);
 }
}
/******************任务Task1定义***************/
void Task1(void)
{
 while(1)
 {
   PORTB^=0x01;
   RAYS_TimeDelay(4);

 }
}
/******************任务Task2定义***************/
void Task2(void)
{
INT8U ss=0;
 while(1)
 {
	 PORTC^=0x01;
	 for(ss=0;ss<10;ss++)
		 RAYS_TimeDelay(4);
	 delaysss();
 }

}

/******************系统节拍初始化***************/
	 void TimerInit(void)
{
	TCNT0=0;
	TCCR0=_BV(CS02)|_BV(CS00);
}

/****************主函数***************/
int main(void)
{
	 RAYS_Init();
	 cli();
	 DDRB=0X01;
	 DDRD=0xff;
	 DDRC=0X01;
	 RAYS_TaskCreate(Task0,&Task0Stack[49],0);
	 RAYS_TaskCreate(Task1,&Task1Stack[49],1);
	 RAYS_TaskCreate(Task2,&Task2Stack[49],2);
	 TimerInit();
	 RAYS_Start();	 //此函数执行完系统即发生调度
	 while(1);
}
