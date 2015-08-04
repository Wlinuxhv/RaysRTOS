
#include "RaysRTOS.h"


/******************全局变量定义***************/
    INT8U   StackIdle[StackSizeIdle]; 				// 建立空闲任务栈
    INT8U   OSRdyTbl;     					// 就绪任务列表
    INT8U   OSPrioCur;		            			// 当前任务的优先级
    INT8U   OSPrioHighRdy;               		    	// 即将要运行任务的优先级	
    INT8U   IdleCount;						// 空闲任务自加数
    struct  TaskCtrBlock TCB[OS_TASKS + 1];			// 定义任务控制块TCB数组
    
    
    
/*
+---------------------------------------------------------------------------------------+
|函数名称：	SPPoint									|
|---------------------------------------------------------------------------------------|
|函数原型：	void SPPoint(prio)							|
|											|
|函数功能：	处理C与汇编中SP指向问题 						|
+---------------------------------------------------------------------------------------+
*/	
void SPPoint(void)
{
  TEMP_SP=&(TCB[OSPrioCur].OSTCBStkPtr);	
}

void CPU_TaskCreate(void (*p_Task)(void),STACK_TypeDef *p_Stack,PRIO_TypeDef Prio)
{
		*(p_Stack--) =  (unsigned char)((unsigned int)p_Task&0x00ff);;	  //函数入口	pcl
		*(p_Stack--) =  (unsigned char)(((unsigned int)p_Task&0xff00)>>8);  //函数入口    pch
                *(p_Stack--) =  (unsigned char)(((unsigned int)p_Task&0xff0000)>>16);  //函数入口    pce      
					
   		*(p_Stack--)=0;                           //YL 
                *(p_Stack--)=0;                    	  //YH 
                *(p_Stack--)=0;                    	  //XL  
                *(p_Stack--)=0;                    	  //XH  
                *(p_Stack--)=0;                    	  //A  
                *(p_Stack--)=0X20;                    	  //CC 
                *p_Stack--  = (INT8U)0x00;                //?B0
                *p_Stack--  = (INT8U)0x01;                //?B1
                *p_Stack--  = (INT8U)0x02;                //?B2
                *p_Stack--  = (INT8U)0x03;                //?B3
                *p_Stack--  = (INT8U)0x04;                //?B4
                *p_Stack--  = (INT8U)0x05;                //?B5
                *p_Stack--  = (INT8U)0x06;                //?B6
                *p_Stack--  = (INT8U)0x07;                //?B7
                *p_Stack--  = (INT8U)0x08;                //?B8
                *p_Stack--  = (INT8U)0x09;                //?B9
                *p_Stack--  = (INT8U)0x10;                //?B10
                *p_Stack--  = (INT8U)0x11;                //?B11
                *p_Stack--  = (INT8U)0x12;                //?B12
                *p_Stack--  = (INT8U)0x13;                //?B13
                *p_Stack--  = (INT8U)0x14;                //?B14
                *p_Stack--  = (INT8U)0x15;                //?B15         
		TCB[Prio].OSTCBStkPtr = (INT32U)p_Stack;  /* 将人工堆栈的栈顶，保存到堆栈的数组中*/
		TCB[Prio].OSTCBDly = 0;			/* 初始化任务延时    	*/
}


INT16U temp_Ptr;
void CPU_OSStart(void)
{
  CPU_TaskCreate(Idle_Task,&StackIdle[StackSizeIdle-1],OS_TASKS);
	temp_Ptr=TCB[OSPrioCur].OSTCBStkPtr+16+6; 
        TIM3_CR1 |=0x01;// 启动计时器
        asm("LDW     Y,   L:temp_Ptr");                      
        asm("LDW     SP, Y");
        asm("rim");
        asm("RETF");
}