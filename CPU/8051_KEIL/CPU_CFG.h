/*****************************************************************************************  
 *  8051 CPU相关H文件
 * 
 *  Copyright (C) 2010  苑臣芒 
 * 
 *  2010-07-09  RaysRTOS 
 *****************************************************************************************/
/*--------------------------------------------------------------------------------------+
|特定硬件平台                                                                           |
+---------------------------------------------------------------------------------------*/
#include<REG52.h>

typedef unsigned char  BOOLEAN;
typedef unsigned char  INT8U;                                             
typedef signed   char  INT8S;                                            
typedef unsigned int   INT16U;                                            
typedef signed   int   INT16S;                                            
typedef unsigned long  INT32U;                                        
typedef signed   long  INT32S; 

/*--------------------------------------------------------------------------------------+
|系统配置																				|
+---------------------------------------------------------------------------------------*/
#define StackSizeIdle     20		 // 定义空闲任务栈大小                 
#define OS_TICKS_PER_SEC  100        // 设置一秒内的时钟节拍数             
#define OS_TASKS		  3			 // 设定运行任务的数量,不包含空闲任务 
#define TASK_SUSPEND_EN   0          //任务是否可以挂起和恢复 1：可以 0：不可以


typedef unsigned char  STACK_TypeDef;
typedef unsigned char  PRIO_TypeDef;
typedef unsigned int   TICKS_TypeDef;

/*--------------------------------------------------------------------------------------+
|任务结构体TCB                                                                          |
+---------------------------------------------------------------------------------------*/
  struct TaskCtrBlock            	 // 任务控制块数据结构
{
	INT8U	OSTCBStkPtr;			 // 保存任务的堆栈顶  
	INT16U	OSTCBDly;				 // 任务延时时钟
};

/*--------------------------------------------------------------------------------------+
|系统宏函数																				|
+---------------------------------------------------------------------------------------*/
#define  OS_ENTER_CRITICAL()  (EA=0) // 进入临界段

#define  OS_EXIT_CRITICAL()   (EA=1) // 退出临界段


/******************全局变量声明***************/
extern  INT8U   StackIdle[StackSizeIdle]; 				// 建立空闲任务栈
extern  INT8U   OSRdyTbl;     							// 就绪任务列表
extern  INT8U   OSPrioCur;		            			// 当前任务的优先级
extern  INT8U   OSPrioHighRdy;           		    	// 即将要运行任务的优先级	
extern  INT8U  IdleCount;								// 空闲任务自加数
extern  struct  TaskCtrBlock TCB[OS_TASKS + 1];			// 定义任务控制块TCB数组

void CPU_TaskCreate(void (*p_Task)(void),STACK_TypeDef *p_Stack,PRIO_TypeDef t_Prio);
void CPU_OSStart(void);


