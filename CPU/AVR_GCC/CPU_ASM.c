/***************************************************************************************** 
 *  RaysRTOS/RaysRTOS_ASM.c 
 * 
 *  RaysRTOS核心文件 
 * 
 *  Copyright (C) 2010  苑臣芒 
 * 
 *  2010-07-09  RaysRTOS1.0-Mega8 版本
 *  
 *	全抢占式调度 提供系统延时 挂起 恢复等功能 最大任务量8个  					   
 *****************************************************************************************/
#include "RaysRTOS.h"

/******************全局变量定义***************/
 extern struct TaskCtrBlock  TCB[OS_TASKS + 1];		// 定义任务控制块				
 extern INT8U   OSPrioCur;		            		// 正在运行的任务				
 extern INT8U   OSPrioHighRdy;           		// 更高优先级的任务				
 extern INT16U  *TEMP_SP;
/*
+---------------------------------------------------------------------------------------+
|函数名称：	OSSched																		|
|---------------------------------------------------------------------------------------|
|函数原型：	void OSSched(prio)															|
|																						|
|函数功能：	任务级切换函数 														   		|																						|
+---------------------------------------------------------------------------------------+
*/
void OSSched(void)
{
	OS_ENTER_CRITICAL();                	//关中断
				
	if(OSPrioHighRdy != OSPrioCur)			// 如果不是当前运行的任务，进行任务调度 */
	{
 	//push all
  __asm__ __volatile__("PUSH __zero_reg__          \n\t");  //R1 
  __asm__ __volatile__("PUSH __tmp_reg__           \n\t");  //R0  
  __asm__ __volatile__("IN   __tmp_reg__,__SREG__  \n\t");  //保存状态寄存器SREG 
  __asm__ __volatile__("PUSH __tmp_reg__           \n\t"); 
  __asm__ __volatile__("CLR  __zero_reg__          \n\t");  //R1重新清零    
  __asm__ __volatile__("PUSH R18                   \n\t"); 
  __asm__ __volatile__("PUSH R19                   \n\t"); 
  __asm__ __volatile__("PUSH R20                   \n\t"); 
  __asm__ __volatile__("PUSH R21                   \n\t"); 
  __asm__ __volatile__("PUSH R22                   \n\t"); 
  __asm__ __volatile__("PUSH R23                   \n\t"); 
  __asm__ __volatile__("PUSH R24                   \n\t"); 
  __asm__ __volatile__("PUSH R25                   \n\t"); 
  __asm__ __volatile__("PUSH R26                   \n\t"); 
  __asm__ __volatile__("PUSH R27                   \n\t"); 
  __asm__ __volatile__("PUSH R30                   \n\t");     
  __asm__ __volatile__("PUSH R31                   \n\t");
  __asm__ __volatile__("PUSH R2                    \n\t");   
  __asm__ __volatile__("PUSH R3                    \n\t");   
  __asm__ __volatile__("PUSH R4                    \n\t");   
  __asm__ __volatile__("PUSH R5                    \n\t"); 
  __asm__ __volatile__("PUSH R6                    \n\t"); 
  __asm__ __volatile__("PUSH R7                    \n\t");  
  __asm__ __volatile__("PUSH R8                    \n\t");  
  __asm__ __volatile__("PUSH R9                    \n\t");   
  __asm__ __volatile__("PUSH R10                   \n\t"); 
  __asm__ __volatile__("PUSH R11                   \n\t"); 
  __asm__ __volatile__("PUSH R12                   \n\t"); 
  __asm__ __volatile__("PUSH R13                   \n\t"); 
  __asm__ __volatile__("PUSH R14                   \n\t"); 
  __asm__ __volatile__("PUSH R15                   \n\t");   
  __asm__ __volatile__("PUSH R16                   \n\t");  
  __asm__ __volatile__("PUSH R17                   \n\t");  
  __asm__ __volatile__("PUSH R28                   \n\t");  //R28与R29用于建立在堆栈上的指针 
  __asm__ __volatile__("PUSH R29                   \n\t");  //入栈完成 
	SPPoint();   
	*TEMP_SP=SP;						//保存当前堆栈指针
	OSPrioCur = OSPrioHighRdy;			// 更新OSPrioCur
	SPPoint();
	SP=*TEMP_SP;            			//任务堆栈指针切换
 	//pop all
  __asm__ __volatile__("POP  R29                   \n\t");     
  __asm__ __volatile__("POP  R28                   \n\t"); 
  __asm__ __volatile__("POP  R17                   \n\t"); 
  __asm__ __volatile__("POP  R16                   \n\t"); 
  __asm__ __volatile__("POP  R15                   \n\t");     
  __asm__ __volatile__("POP  R14                   \n\t");     
  __asm__ __volatile__("POP  R13                   \n\t");     
  __asm__ __volatile__("POP  R12                   \n\t");     
  __asm__ __volatile__("POP  R11                   \n\t");     
  __asm__ __volatile__("POP  R10                   \n\t"); 
  __asm__ __volatile__("POP  R9                    \n\t"); 
  __asm__ __volatile__("POP  R8                    \n\t"); 
  __asm__ __volatile__("POP  R7                    \n\t");   
  __asm__ __volatile__("POP  R6                    \n\t"); 
  __asm__ __volatile__("POP  R5                    \n\t"); 
  __asm__ __volatile__("POP  R4                    \n\t");  
  __asm__ __volatile__("POP  R3                    \n\t"); 
  __asm__ __volatile__("POP  R2                    \n\t");        
  __asm__ __volatile__("POP  R31                   \n\t");     
  __asm__ __volatile__("POP  R30                   \n\t");     
  __asm__ __volatile__("POP  R27                   \n\t");     
  __asm__ __volatile__("POP  R26                   \n\t");     
  __asm__ __volatile__("POP  R25                   \n\t");     
  __asm__ __volatile__("POP  R24                   \n\t");     
  __asm__ __volatile__("POP  R23                   \n\t");     
  __asm__ __volatile__("POP  R22                   \n\t");     
  __asm__ __volatile__("POP  R21                   \n\t");     
  __asm__ __volatile__("POP  R20                   \n\t");     
  __asm__ __volatile__("POP  R19                   \n\t"); 
  __asm__ __volatile__("POP  R18                   \n\t");   
  __asm__ __volatile__("POP  __tmp_reg__           \n\t");      //SERG 出栈并恢复 
  __asm__ __volatile__("OUT  __SREG__,__tmp_reg__  \n\t");     
  __asm__ __volatile__("POP  __tmp_reg__           \n\t");      //R0 出栈 
  __asm__ __volatile__("POP  __zero_reg__          \n\t");      //R1 出栈 
	}
	OS_EXIT_CRITICAL();     //开中断
}

/*
+---------------------------------------------------------------------------------------+
|函数名称：	SIGNAL																		|
|---------------------------------------------------------------------------------------|
|函数原型：	 SIGNAL(SIG_OVERFLOW0)														|
|																						|
|函数功能：	中断级切换函数 														   		|																						|
+---------------------------------------------------------------------------------------+
*/
SIGNAL(SIG_OVERFLOW0)
{
	OS_ENTER_CRITICAL();           //关中断
	TCNT0=TCNT0_INIT;
	//push all 除了中断自动保存的寄存器
  __asm__ __volatile__("PUSH R2                    \n\t");   
  __asm__ __volatile__("PUSH R3                    \n\t");   
  __asm__ __volatile__("PUSH R4                    \n\t");   
  __asm__ __volatile__("PUSH R5                    \n\t"); 
  __asm__ __volatile__("PUSH R6                    \n\t"); 
  __asm__ __volatile__("PUSH R7                    \n\t");  
  __asm__ __volatile__("PUSH R8                    \n\t");  
  __asm__ __volatile__("PUSH R9                    \n\t");   
  __asm__ __volatile__("PUSH R10                   \n\t"); 
  __asm__ __volatile__("PUSH R11                   \n\t"); 
  __asm__ __volatile__("PUSH R12                   \n\t"); 
  __asm__ __volatile__("PUSH R13                   \n\t"); 
  __asm__ __volatile__("PUSH R14                   \n\t"); 
  __asm__ __volatile__("PUSH R15                   \n\t");   
  __asm__ __volatile__("PUSH R16                   \n\t");  
  __asm__ __volatile__("PUSH R17                   \n\t");  
  __asm__ __volatile__("PUSH R28                   \n\t");  //R28与R29用于建立在堆栈上的指针 
  __asm__ __volatile__("PUSH R29                   \n\t");  //入栈完成 

  	TickIntHook();
	SPPoint();   
	*TEMP_SP=SP;						//保存当前堆栈指针
	OSPrioCur = OSPrioHighRdy;			// 更新OSPrioCur
	SPPoint();
	SP=*TEMP_SP;            			//任务堆栈指针切换
	//pop all 除了中断自动保存的寄存器
  __asm__ __volatile__("POP  R29                   \n\t");     
  __asm__ __volatile__("POP  R28                   \n\t"); 
  __asm__ __volatile__("POP  R17                   \n\t"); 
  __asm__ __volatile__("POP  R16                   \n\t"); 
  __asm__ __volatile__("POP  R15                   \n\t");     
  __asm__ __volatile__("POP  R14                   \n\t");     
  __asm__ __volatile__("POP  R13                   \n\t");     
  __asm__ __volatile__("POP  R12                   \n\t");     
  __asm__ __volatile__("POP  R11                   \n\t");     
  __asm__ __volatile__("POP  R10                   \n\t"); 
  __asm__ __volatile__("POP  R9                    \n\t"); 
  __asm__ __volatile__("POP  R8                    \n\t"); 
  __asm__ __volatile__("POP  R7                    \n\t");   
  __asm__ __volatile__("POP  R6                    \n\t"); 
  __asm__ __volatile__("POP  R5                    \n\t"); 
  __asm__ __volatile__("POP  R4                    \n\t");  
  __asm__ __volatile__("POP  R3                    \n\t"); 
  __asm__ __volatile__("POP  R2                    \n\t");   
  OS_EXIT_CRITICAL();              //开中断
} 
