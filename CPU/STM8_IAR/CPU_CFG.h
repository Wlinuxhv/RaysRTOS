/***************************************************************************************** 
 *  RaysRTOS/RaysRTOS.h 
 *  Copyright (C) 2010  Է��â  
 *  2010-07-09  RaysRTOS1.0-STM8 �汾
 *****************************************************************************************/

/*--------------------------------------------------------------------------------------+
|ƽ̨�޹ض���																				|
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
|ϵͳ����										|
+---------------------------------------------------------------------------------------*/
#define StackSizeIdle     50	      // �����������ջ��С                 
#define OS_TICKS_PER_SEC  100         // ����һ���ڵ�ʱ�ӽ�����             
#define OS_TASKS	  4	      // �趨�������������,��������������  
#define  TASK_SUSPEND_EN 1
/*--------------------------------------------------------------------------------------+
|ƽ̨����										|
+---------------------------------------------------------------------------------------*/
#include "stm8s.h"
#include "stm8s_tim1.h"
#include "stm8s_tim2.h"
#include <inttypes.h>
#include <stdio.h>

/*--------------------------------------------------------------------------------------+
|ϵͳ�ṹ��TCB										|
+---------------------------------------------------------------------------------------*/
struct TaskCtrBlock            	        // ������ƿ����ݽṹ
{
	INT16U	OSTCBStkPtr;		// ��������Ķ�ջ��  
	INT16U	OSTCBDly;		// ������ʱʱ��
};

/*--------------------------------------------------------------------------------------+
|ϵͳ�꺯��										|
+---------------------------------------------------------------------------------------*/
#define  OS_ENTER_CRITICAL()  asm("sim") /* �����ж� */
#define  OS_EXIT_CRITICAL()   asm("rim") /* �ָ�ԭ���ж�״̬ */


/******************ȫ�ֱ�������***************/
extern  INT8U   StackIdle[StackSizeIdle]; 				// ������������ջ
extern  INT8U   OSRdyTbl;     							// ���������б�
extern  INT8U   OSPrioCur;		            			// ��ǰ��������ȼ�
extern  INT8U   OSPrioHighRdy;           		    	// ����Ҫ������������ȼ�	
extern  INT8U   IdleCount;						// ���������Լ���
extern  struct  TaskCtrBlock TCB[OS_TASKS + 1];			// ����������ƿ�TCB����
extern  INT16U *TEMP_SP; 
/*--------------------------------------------------------------------------------------+
|ϵͳ��������										|
+---------------------------------------------------------------------------------------*/
void CPU_TaskCreate(void (*p_Task)(void),STACK_TypeDef *p_Stack,PRIO_TypeDef Prio);
void CPU_OSStart(void);
void SPPoint(void);
//����CPU�ڲ�ʱ��
#define  SYS_CLOCK    16
void CLOCK_Config(u8 q);
void delay_ms(unsigned int time);
void delay_us(void);