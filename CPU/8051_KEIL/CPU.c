/*****************************************************************************************  
 *  8051 CPU相关C文件
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


void  CPU_TaskCreate(void (*p_Task)(void),INT8U *p_Stack,INT8U t_Prio)
	{
		*(  p_Stack) = (unsigned int)p_Task & 0xff;	// 函数入口
		*(++p_Stack) = (unsigned int)p_Task>>8;    	// 函数入口
		*(++p_Stack) = 0;//ACC    
		*(++p_Stack) = 0;//B   
		*(++p_Stack) = 0;//DPH   
		*(++p_Stack) = 0;//DPL   
		*(++p_Stack) = 0;//PSW    
		*(++p_Stack) = 0;//R0   		
		*(++p_Stack) = 1;//R1    
		*(++p_Stack) = 2;//R2   
		*(++p_Stack) = 3;//R3   
		*(++p_Stack) = 4;//R4   
		*(++p_Stack) = 5;//R5    
		*(++p_Stack) = 6;//R6 
		*(++p_Stack) = 7;//R7					  	// 除pc外保存13个寄存器		                      
		TCB[t_Prio].OSTCBStkPtr = (INT8U)p_Stack;	// 将人工堆栈的栈顶，保存到堆栈的数组中
		TCB[t_Prio].OSTCBDly = 0;				  	// 初始化任务延时
	}
void CPU_OSStart(void)
   {
   CPU_TaskCreate(Idle_Task,StackIdle,OS_TASKS);
   SP=TCB[OSPrioHighRdy].OSTCBStkPtr-13;			// 将栈顶移到pc位置,准备弹出
   TR0=1;
   }
   
	