/***************************************************************************************** 
 *  RaysRTOS/RaysRTOS_ASM.s 
 * 
 *  RaysRTOS�����ļ� 
 * 
 *  Copyright (C) 2010  Է��â 
 * 
 *  2010-07-09  RaysRTOS1.0-STM8 �汾
 *  
 *	ȫ��ռʽ���� �ṩϵͳ��ʱ ���� �ָ��ȹ��� ���������8��  					   
 *****************************************************************************************/      
        NAME RaysRTOS_ASM

        EXTERN OSPrioCur
        EXTERN OSPrioHighRdy
        EXTERN SPPoint
        EXTERN TickIntHook

        PUBLIC OSSched
        PUBLIC TEMP_SP

        EXTERN ?b0
        EXTERN ?b1  
        EXTERN ?b2        
        EXTERN ?b3
        EXTERN ?b4
        EXTERN ?b5
        EXTERN ?b6
        EXTERN ?b7
        EXTERN ?b8
        EXTERN ?b9
        EXTERN ?b10
        EXTERN ?b11
        EXTERN ?b12
        EXTERN ?b13
        EXTERN ?b14       
        EXTERN ?b15           

        SECTION `.far.bss`:DATA:NOROOT(0)
TEMP_SP:
        DS8 2
/*
+---------------------------------------------------------------------------------------+
|�������ƣ�	OSSched									|
|---------------------------------------------------------------------------------------|
|����ԭ�ͣ�	void OSSched(prio)						        |
|											|
|�������ܣ�	�����л����� 								|																						|
+---------------------------------------------------------------------------------------+
*/
        SECTION `.far_func.text`:CODE:ROOT(0)
OSSched:
        sim
        push #0
        LD        A, L:OSPrioCur
        CP        A, L:OSPrioHighRdy
        JRNE      ??lb_0
        JP        L:??OSSched_0

??lb_0:
        pushw y     
        pushw x
        push  a
        push  cc
        push ?b0
        push ?b1
        push ?b2
        push ?b3
        push ?b4
        push ?b5        
        push ?b6
        push ?b7               
        push ?b8
        push ?b9
        push ?b10
        push ?b11       
        push ?b12
        push ?b13
        push ?b14
        push ?b15 
            
        CALL      L:SPPoint
        LDW    y,L:TEMP_SP
        LDW    x,SP
        LDW   (y),x 
        LD        A, L:OSPrioHighRdy
        LD        L:OSPrioCur, A        
        CALL       L:SPPoint
        LDW    Y,L:TEMP_SP
        LDW    Y,(Y)
        LDW SP,Y

        pop ?b15
        pop ?b14
        pop ?b13
        pop ?b12
        pop ?b11
        pop ?b10        
        pop ?b9
        pop ?b8            
        pop ?b7
        pop ?b6
        pop ?b5
        pop ?b4        
        pop ?b3
        pop ?b2
        pop ?b1
        pop ?b0      
        pop  cc
        pop  a
        popw x
        popw y
??OSSched_0:
        rim
        RETF

/*
+---------------------------------------------------------------------------------------+
|�������ƣ�	interrupt								|
|---------------------------------------------------------------------------------------|
|����ԭ�ͣ�	 interrupt_13+2     							|
|											|
|�������ܣ�	�жϼ��л����� 								|																						|
+---------------------------------------------------------------------------------------+
*/
TIM2SR1 EQU   0x5304

      PUBLIC _interrupt_15
      SECTION `.far_func.text`:CODE:NOROOT(0)
_interrupt_15:
        sim
        CLR       A
        LD        L:TIM2SR1, A
        push ?b0
        push ?b1
        push ?b2
        push ?b3
        push ?b4
        push ?b5       
        push ?b6
        push ?b7               
        push ?b8
        push ?b9
        push ?b10
        push ?b11        
        push ?b12
        push ?b13
        push ?b14
        push ?b15         
        CALL      L:TickIntHook       
        CALL      L:SPPoint
        LDW    y,L:TEMP_SP
        LDW    x,SP
        LDW   (y),x 
        LD        A, L:OSPrioHighRdy
        LD        L:OSPrioCur, A        
        CALL       L:SPPoint
        LDW    Y,L:TEMP_SP
        LDW    Y,(Y)
        LDW SP,Y
        
        pop ?b15
        pop ?b14
        pop ?b13
        pop ?b12
        pop ?b11
        pop ?b10       
        pop ?b9
        pop ?b8       
        pop ?b7
        pop ?b6
        pop ?b5
        pop ?b4        
        pop ?b3
        pop ?b2
        pop ?b1
        pop ?b0    
        rim
        IRET

        END

