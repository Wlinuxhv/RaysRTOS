/***************************************************************************************** 
 *  RaysRTOS/RaysRTOS.h 
 *  Copyright (C) 2010  苑臣芒  
 *  2010-07-09  RaysRTOS1.0-STM8 版本
 *****************************************************************************************/

/*--------------------------------------------------------------------------------------+
|平台无关定义																				|
+---------------------------------------------------------------------------------------*/
typedef unsigned char  BOOLEAN;
typedef unsigned char  INT8U;                                             
typedef signed   char  INT8S;                                            
typedef unsigned int   INT16U;                                            
typedef signed   int   INT16S;                                            
typedef unsigned long  INT32U;                                        
typedef signed   long  INT32S; 

typedef unsigned char  STACK_TypeDef;
typedef unsigned char  PRIO_TypeDef;
typedef unsigned int   TICKS_TypeDef;

/*--------------------------------------------------------------------------------------+
|系统配置										|
+---------------------------------------------------------------------------------------*/
#define StackSizeIdle     50	      // 定义空闲任务栈大小                 
#define OS_TICKS_PER_SEC  100         // 设置一秒内的时钟节拍数             
#define OS_TASKS	  4	      // 设定运行任务的数量,不包含空闲任务  
#define  TASK_SUSPEND_EN 1
/*--------------------------------------------------------------------------------------+
|平台代码										|
+---------------------------------------------------------------------------------------*/
#include "stm8s.h"
#include "stm8s_tim1.h"
#include "stm8s_tim2.h"
#include <inttypes.h>
#include <stdio.h>

/*--------------------------------------------------------------------------------------+
|系统结构体TCB										|
+---------------------------------------------------------------------------------------*/
struct TaskCtrBlock            	        // 任务控制块数据结构
{
	INT16U	OSTCBStkPtr;		// 保存任务的堆栈顶  
	INT16U	OSTCBDly;		// 任务延时时钟
};

/*--------------------------------------------------------------------------------------+
|系统宏函数										|
+---------------------------------------------------------------------------------------*/
#define  OS_ENTER_CRITICAL()  asm("sim") /* 关总中断 */
#define  OS_EXIT_CRITICAL()   asm("rim") /* 恢复原来中断状态 */


/******************全局变量声明***************/
extern  INT8U   StackIdle[StackSizeIdle]; 				// 建立空闲任务栈
extern  INT8U   OSRdyTbl;     							// 就绪任务列表
extern  INT8U   OSPrioCur;		            			// 当前任务的优先级
extern  INT8U   OSPrioHighRdy;           		    	// 即将要运行任务的优先级	
extern  INT8U   IdleCount;						// 空闲任务自加数
extern  struct  TaskCtrBlock TCB[OS_TASKS + 1];			// 定义任务控制块TCB数组
extern  INT16U *TEMP_SP; 
/*--------------------------------------------------------------------------------------+
|系统函数声明										|
+---------------------------------------------------------------------------------------*/
void CPU_TaskCreate(void (*p_Task)(void),STACK_TypeDef *p_Stack,PRIO_TypeDef Prio);
void CPU_OSStart(void);
void SPPoint(void);
//定义CPU内部时钟
#define  SYS_CLOCK    16
void CLOCK_Config(u8 q);
void delay_ms(unsigned int time);
void delay_us(void);