/*****************************************************************************************
 *  RaysRTOS/RaysRTOS_ASM.s
 *
 *  RaysRTOS核心文件
 *
 *  Copyright (C) 2010  苑臣芒
 *
 *  2010-07-09  RaysRTOS1.0-STM8 版本
 *
 *  全抢占式调度 提供系统延时 挂起 恢复等功能 最大任务量8个
 *****************************************************************************************/

NAME RaysRTOS_ASM

EXTERN OSPrioCur
EXTERN OSPrioHighRdy
EXTERN SPPoint
EXTERN TickIntHook

PUBLIC OSSched
PUBLIC TEMP_SP

EXTERN ? b0
EXTERN ? b1
EXTERN ? b2
EXTERN ? b3
EXTERN ? b4
EXTERN ? b5
EXTERN ? b6
EXTERN ? b7
EXTERN ? b8
EXTERN ? b9
EXTERN ? b10
EXTERN ? b11
EXTERN ? b12
EXTERN ? b13
EXTERN ? b14
EXTERN ? b15

SECTION `.far.bss` : DATA : NOROOT(0)
TEMP_SP :
DS8 2
/*
+---------------------------------------------------------------------------------------+
|函数名称： OSSched                                 |
|---------------------------------------------------------------------------------------|
|函数原型： void OSSched(prio)                              |
|                                           |
|函数功能： 任务级切换函数                              |                                                                                       |
+---------------------------------------------------------------------------------------+
*/
SECTION `.far_func.text` : CODE : ROOT(0)
OSSched :
sim
push #0
LD        A, L : OSPrioCur
CP        A, L : OSPrioHighRdy
JRNE      ?? lb_0
JP        L : ?? OSSched_0

?? lb_0 :
pushw y
pushw x
push  a
push  cc
push ? b0
push ? b1
push ? b2
push ? b3
push ? b4
push ? b5
push ? b6
push ? b7
push ? b8
push ? b9
push ? b10
push ? b11
push ? b12
push ? b13
push ? b14
push ? b15

CALL      L : SPPoint
LDW    y, L : TEMP_SP
LDW    x, SP
LDW(y), x
LD        A, L : OSPrioHighRdy
LD        L : OSPrioCur, A
CALL       L : SPPoint
LDW    Y, L : TEMP_SP
LDW    Y, (Y)
LDW SP, Y

pop ? b15
pop ? b14
pop ? b13
pop ? b12
pop ? b11
pop ? b10
pop ? b9
pop ? b8
pop ? b7
pop ? b6
pop ? b5
pop ? b4
pop ? b3
pop ? b2
pop ? b1
pop ? b0
pop  cc
pop  a
popw x
popw y
?? OSSched_0 :
rim
RETF

/*
+---------------------------------------------------------------------------------------+
|函数名称： interrupt                               |
|---------------------------------------------------------------------------------------|
|函数原型：  interrupt_13                               |
|                                           |
|函数功能： 中断级切换函数                              |                                                                                       |
+---------------------------------------------------------------------------------------+
*/
PUBLIC __interrupt_13
SECTION `.far_func.text` : CODE : ROOT(0)
__interrupt_13 :
sim
CLR       A
;
LD        L: 0x5322, A
;
这里是指的TIM3的某个寄存器，就是清除TIM3->SR0, SR1
;
TIM2 的久应该改成 0x5304
;
#define TIM2_BaseAddress        0x5300
LD     L: 0x5304, A
;
typedef struct TIM2_struct
    ;
{
    ;
    __IO uint8_t CR1;   /*!< control register 1 */
    ;
#if defined(STM8S103) || defined(STM8S003)
    ;
    uint8_t RESERVED1; /*!< Reserved register */
    ;
    uint8_t RESERVED2; /*!< Reserved register */
    ;
#endif
    ;
    __IO uint8_t IER;   /*!< interrupt enable register */
    ;
    __IO uint8_t SR1;   /*!< status register 1 */
    ;
    __IO uint8_t SR2;   /*!< status register 2 */
    ;
    ...
    ;
}

;
#define TIM3_BaseAddress        0x5320
;
typedef struct TIM3_struct
    ;
{
    ;
    __IO uint8_t CR1;   /*!< control register 1 */
    ;
    __IO uint8_t IER;   /*!< interrupt enable register */
    ;
    __IO uint8_t SR1;   /*!< status register 1 */
    ;
    __IO uint8_t SR2;   /*!< status register 2 */
    ;
    ...
    ;
}

push ? b0
push ? b1
push ? b2
push ? b3
push ? b4
push ? b5
push ? b6
push ? b7
push ? b8
push ? b9
push ? b10
push ? b11
push ? b12
push ? b13
push ? b14
push ? b15
CALL      L : TickIntHook
CALL      L : SPPoint
LDW    y, L : TEMP_SP
LDW    x, SP
LDW(y), x
LD        A, L : OSPrioHighRdy
LD        L : OSPrioCur, A
CALL       L : SPPoint
LDW    Y, L : TEMP_SP
LDW    Y, (Y)
LDW SP, Y

pop ? b15
pop ? b14
pop ? b13
pop ? b12
pop ? b11
pop ? b10
pop ? b9
pop ? b8
pop ? b7
pop ? b6
pop ? b5
pop ? b4
pop ? b3
pop ? b2
pop ? b1
pop ? b0
rim
IRET


END
