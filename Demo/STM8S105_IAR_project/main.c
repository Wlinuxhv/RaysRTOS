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



/******************定义任务的堆栈***************/
INT8U Task0Stack[50];
INT8U Task1Stack[50];
INT8U Task2Stack[50];

/******************任务Task0定义***************/
void Task0(void)
{
 while(1)
 {
   RAYS_TimeDelay(3);
 }
}

/******************任务Task1定义***************/
void Task1(void)
{
 while(1)
 {
  PD_ODR_bit.ODR6=0;
   RAYS_TimeDelay(3); 
  PD_ODR_bit.ODR6=1;
   RAYS_TimeDelay(3);   
 }
}

/******************任务Task2定义***************/
void Task2(void)
{
 while(1)
 {
   RAYS_TimeDelay(40);
 }

}

/******************系统节拍初始化***************/
void TimerInit(void)
{
  TIM3_PSCR =0x08;    //256分频
  TIM3_ARRH =0x02;    //625分频_16M分频得到100Hz
  TIM3_ARRL =0x70;
  TIM3_CR1  =0x84;
  TIM3_IER  =0x01;     //开启中断  
  CLK_CKDIVR=0x00;   //时钟无分频
  CLK_PCKENR1 |= 0X40;//开启时钟
}

/****************主函数***************/
int main(void)
{
         RAYS_Init();
	 RAYS_TaskCreate(Task0,&Task0Stack[49],0);
	 RAYS_TaskCreate(Task1,&Task1Stack[49],1);
	 RAYS_TaskCreate(Task2,&Task2Stack[49],2);
	 TimerInit();
         PD_ODR_bit.ODR0=1;
         PD_DDR_bit.DDR6=1;
	 RAYS_Start();	              //此函数执行完系统即发生调度
	 while(1);
}
