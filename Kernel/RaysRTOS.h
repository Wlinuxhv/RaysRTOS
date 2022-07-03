/*****************************************************************************************  
 *  RaysRTOS ����ͷ�ļ�
 * 
 *  Copyright (C) 2010  Է��â 
 * 
 *  2010-07-09  RaysRTOS 
 *****************************************************************************************/

#include "CPU_CFG.h"

			
/*--------------------------------------------------------------------------------------+
|ϵͳ��������																			|
+---------------------------------------------------------------------------------------*/
void RAYS_TaskCreate(void (*Task)(void),STACK_TypeDef *Stack,PRIO_TypeDef Prio);//��������
void RAYS_Start(void);					//ϵͳ��������

#if(TASK_SUSPEND_EN==1)
void RAYS_TaskResume(PRIO_TypeDef Prio);	 	//����ָ�����
void RAYS_TaskSuspend(PRIO_TypeDef Prio);		//���������
#endif

void OSSched(void);						//�����Ⱥ���
void RAYS_TimeDelay(TICKS_TypeDef ticks); 		//������ʱ����
void Idle_Task(void);
void RAYS_Init(void);					//ϵͳ��ʼ��
void TickIntHook(void); 				//ϵͳ���Ĺ��Ӻ���




