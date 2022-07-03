/*****************************************************************************************  
 *  RaysRTOS 总体头文件
 * 
 *  Copyright (C) 2010  苑臣芒 
 * 
 *  2010-07-09  RaysRTOS 
 *****************************************************************************************/

#include "CPU_CFG.h"

			
/*--------------------------------------------------------------------------------------+
|系统函数声明																			|
+---------------------------------------------------------------------------------------*/
void RAYS_TaskCreate(void (*Task)(void),STACK_TypeDef *Stack,PRIO_TypeDef Prio);//创建任务
void RAYS_Start(void);					//系统启动函数

#if(TASK_SUSPEND_EN==1)
void RAYS_TaskResume(PRIO_TypeDef Prio);	 	//任务恢复函数
void RAYS_TaskSuspend(PRIO_TypeDef Prio);		//任务挂起函数
#endif

void OSSched(void);						//汇编调度函数
void RAYS_TimeDelay(TICKS_TypeDef ticks); 		//任务延时函数
void Idle_Task(void);
void RAYS_Init(void);					//系统初始化
void TickIntHook(void); 				//系统节拍钩子函数




