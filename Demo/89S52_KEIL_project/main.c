
#include "RaySRTOS.h"
#include "math.h"

/******************定义任务的堆栈***************/
INT8U Task0Stack[20];
INT8U Task1Stack[20];
INT8U Task2Stack[20];
/******************系统节拍初始化***************/
	 void TimerInit(void)
{
	TMOD=0x01;
    TH0=0xf9;
    TL0=0xfe;
    EA=1;
    ET0=1;
}
/******************任务Task0定义***************/
void Task0(void)
{
 INT8U asi=0;
 TimerInit();
 
 while(1)
 {
   P0++;
   RAYS_TimeDelay(3000);
 }
}
/******************任务Task1定义***************/
void Task1(void)
{

 while(1)
 {
   P1++;
   RAYS_TimeDelay(40);

 }
}

/******************任务Task2定义***************/
void Task2(void)
{

 while(1)
 {
   P2++;
   RAYS_TimeDelay(40);

 }
}

/****************主函数***************/
int main(void)
{
	 RAYS_Init();
	 RAYS_TaskCreate(Task0,Task0Stack,0);
	 RAYS_TaskCreate(Task1,Task1Stack,1);
	 RAYS_TaskCreate(Task2,Task2Stack,2);	 
	 RAYS_Start();	 //此函数执行完系统即发生调度
	 while(1);
}