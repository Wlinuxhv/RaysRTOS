/*****************************************************************************************  
 *  AVR CPU相关C文件
 * 
 *  Copyright (C) 2010  苑臣芒 
 * 
 *  2010-07-09  RaysRTOS 
 *****************************************************************************************/

#include "RaySRTOS.h"


/******************全局变量定义***************/
  INT8U   StackIdle[StackSizeIdle]; 				// 建立空闲任务栈
  INT8U   OSRdyTbl;     							// 就绪任务列表
  INT8U   OSPrioCur;		            			// 当前任务的优先级
  INT8U   OSPrioHighRdy	;           		    	// 即将要运行任务的优先级	
  INT8U  IdleCount;								// 空闲任务自加数
  struct  TaskCtrBlock TCB[OS_TASKS + 1];			// 定义任务控制块TCB数组
  INT16U  *TEMP_SP;

/*
+---------------------------------------------------------------------------------------+
|函数名称：	SPPoint																		|
|---------------------------------------------------------------------------------------|
|函数原型：	void SPPoint(prio)															|
|																						|
|函数功能：	处理C与汇编中SP指向问题 														|
+---------------------------------------------------------------------------------------+
*/	
 	void SPPoint(void)
	{
	  TEMP_SP=&(TCB[OSPrioCur].OSTCBStkPtr);	
	}

void  CPU_TaskCreate(void (*p_Task)(void),INT8U *p_Stack,INT8U t_Prio)
	{
	unsigned char i=0;
		*(p_Stack--) = 	(unsigned char)((unsigned int)p_Task&0x00ff);;	  		//函数入口	
		*(p_Stack--) =  (unsigned char)(((unsigned int)p_Task&0xff00)>>8);      	//函数入口
		*(p_Stack--) =0x00;                    	  //R1 __zero_reg__             
  		*(p_Stack--) =0x00;                    	  //R0 __tmp_reg__ 
  		*(p_Stack--) =0x80;                    	  //SREG 在任务中，开启全局中断         
 	 for(i=0;i<30;i++)  						
   		*(p_Stack--)=i;                    		   						
		TCB[t_Prio].OSTCBStkPtr = (INT16U)p_Stack;// 将人工堆栈的栈顶，保存到堆栈的数组中
		TCB[t_Prio].OSTCBDly = 0;	
	}

void CPU_OSStart(void)
   {
    CPU_TaskCreate(Idle_Task,&StackIdle[StackSizeIdle-1],OS_TASKS);
	OSPrioCur = OSPrioHighRdy=0;			// 在就绪表中查找最高级的就绪任务 
	SP=TCB[OSPrioCur].OSTCBStkPtr+33; 		//将栈顶移到pc位置,准备弹出
	TIMSK|=_BV(TOIE0);
	sei();	
   }

