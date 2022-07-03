/**
  ******************************************************************************
  * @file    stm8s_it.c
  * @author  MCD Application Team
  * @version V2.2.0
  * @date    30-September-2014
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all peripherals interrupt service 
  *          routine.
   ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "stm8s_it.h"

/** @addtogroup Template_Project
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* Public functions ----------------------------------------------------------*/

#ifdef _COSMIC_
/**
  * @brief Dummy Interrupt routine
  * @par Parameters:
  * None
  * @retval
  * None
*/
INTERRUPT_HANDLER(NonHandledInterrupt, 25)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}
#endif /*_COSMIC_*/

/**
  * @brief TRAP Interrupt routine
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER_TRAP(TRAP_IRQHandler)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief Top Level Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(TLI_IRQHandler, 0)

{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief Auto Wake Up Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(AWU_IRQHandler, 1)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief Clock Controller Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(CLK_IRQHandler, 2)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief External Interrupt PORTA Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EXTI_PORTA_IRQHandler, 3)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
  //Ir_Receive_Handler(); 
}

/**
  * @brief External Interrupt PORTB Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EXTI_PORTB_IRQHandler, 4)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief External Interrupt PORTC Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EXTI_PORTC_IRQHandler, 5)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
  //IR_rx();
  //disableInterrupts();
  //Ir_Receive_Handle(); 
  //enableInterrupts();

  //g_debug = (g_debug + 1)%255;
}

/**
  * @brief External Interrupt PORTD Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EXTI_PORTD_IRQHandler, 6)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief External Interrupt PORTE Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EXTI_PORTE_IRQHandler, 7)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

#if defined (STM8S903) || defined (STM8AF622x) 
/**
  * @brief External Interrupt PORTF Interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(EXTI_PORTF_IRQHandler, 8)
 {
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
 }
#endif /* (STM8S903) || (STM8AF622x) */

#if defined (STM8S208) || defined (STM8AF52Ax)
/**
  * @brief CAN RX Interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(CAN_RX_IRQHandler, 8)
 {
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
 }

/**
  * @brief CAN TX Interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(CAN_TX_IRQHandler, 9)
 {
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
 }
#endif /* (STM8S208) || (STM8AF52Ax) */

/**
  * @brief SPI Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(SPI_IRQHandler, 10)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @brief Timer1 Update/Overflow/Trigger/Break Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(TIM1_UPD_OVF_TRG_BRK_IRQHandler, 11)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
    if(TIM1_GetITStatus(TIM1_IT_UPDATE)!=RESET)
    {
        TIM1_ClearITPendingBit(TIM1_IT_UPDATE);
        //IR_Time++;
        //TIM1_SetCounter(0);

    }
}

/**
  * @brief Timer1 Capture/Compare Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(TIM1_CAP_COM_IRQHandler, 12)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

#if defined (STM8S903) || defined (STM8AF622x)
/**
  * @brief Timer5 Update/Overflow/Break/Trigger Interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(TIM5_UPD_OVF_BRK_TRG_IRQHandler, 13)
 {
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
 }
 
/**
  * @brief Timer5 Capture/Compare Interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(TIM5_CAP_COM_IRQHandler, 14)
 {
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
 }

#else /* (STM8S208) || (STM8S207) || (STM8S105) || (STM8S103) || (STM8AF62Ax) || (STM8AF52Ax) || (STM8AF626x) */
/**
  * @brief Timer2 Update/Overflow/Break Interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(TIM2_UPD_OVF_BRK_IRQHandler, 13)
 {
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
    if(TIM2_GetITStatus(TIM2_IT_UPDATE)!=RESET)
    {
        TIM2_ClearITPendingBit(TIM2_IT_UPDATE);
		//_interrupt_13();
    }
 }

/**
  * @brief Timer2 Capture/Compare Interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(TIM2_CAP_COM_IRQHandler, 14)
 {
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
 }
#endif /* (STM8S903) || (STM8AF622x) */

#if defined (STM8S208) || defined(STM8S207) || defined(STM8S007) || defined(STM8S105) || \
    defined(STM8S005) ||  defined (STM8AF62Ax) || defined (STM8AF52Ax) || defined (STM8AF626x)
/**
  * @brief Timer3 Update/Overflow/Break Interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(TIM3_UPD_OVF_BRK_IRQHandler, 15)
 {
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
 }

/**
  * @brief Timer3 Capture/Compare Interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(TIM3_CAP_COM_IRQHandler, 16)
 {
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
 }
#endif /* (STM8S208) || (STM8S207) || (STM8S105) || (STM8AF62Ax) || (STM8AF52Ax) || (STM8AF626x) */

#if defined (STM8S208) || defined(STM8S207) || defined(STM8S007) || defined(STM8S103) || \
    defined(STM8S003) ||  defined (STM8AF62Ax) || defined (STM8AF52Ax) || defined (STM8S903)
/**
  * @brief UART1 TX Interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(UART1_TX_IRQHandler, 17)
 {
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
 }

/**
  * @brief UART1 RX Interrupt routine.
  * @param  None
  * @retval None
  */
#include "USART.h"

 INTERRUPT_HANDLER(UART1_RX_IRQHandler, 18)
{
    if(UART1_GetITStatus(UART1_IT_RXNE) != RESET) //接收中断，每接收一个字节（8位二进制数据），中断一次,每次中断（即每接收一个数据）都执行一次下列程序
    {
        UART1_ClearITPendingBit(UART1_IT_RXNE);
    }
}
#ifdef WL_UART
{
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
    u8 i,res,check_temp;
    if(UART1_GetITStatus(UART1_IT_RXNE) != RESET) //接收中断，每接收一个字节（8位二进制数据），中断一次,每次中断（即每接收一个数据）都执行一次下列程序
    {
        UART1_ClearITPendingBit(UART1_IT_RXNE);
        res= UART1_ReceiveData8();                   //读取接收到的数据
        //printstr("[DEBUG] raw :");
        //printhex(res);
        //printstr("\n----------------------------------\n");

        if((res==0xee)&&(usart_rx_enableflag==0))         //当接受到包头(0xee)数据并且还没有成功接收完数据信息
        {/*head*/
            usart_rx_enableflag=1;                        //说明这是包头，启动接收数据标志，进入数据接收阶段
            //printstr("[DEBUG] head :");
            //printhex(res);
            usart_rx_lenrightflag=0;               //数据长度校验清零
            usart_rx_successflag=0;                //数据接收成功标志清零
            usart_rd_len=0;                         //数据长度清零
            usart_rd_lentemp=0;
            //printstr("\n----------------------------------\n");
        }
        else if(usart_rx_enableflag==1)                        //到接受数据标志置位时，接受数据
        {/*a frame*/            
            //printstr("[DEBUG] usart_rd_lentemp :");
            //printhex(usart_rd_lentemp);
            //printstr("\n----------------------------------\n");

            if(usart_rd_lentemp==0)                       //包头后第一个数据为需要传输的数据的长度
            {/*paylen*/
                usart_rd_len=res;                         //读取数据的长度 
                //printstr("[DEBUG] usart_rd_len :");
                //printdec(usart_rd_len);
                
                if(usart_rd_len >= UART_BUF_REG_LEN)
                {
                    usart_rx_lenrightflag=0;    //数据长度校验清零
                    usart_rx_successflag=0;     //数据接收成功标志清零
                    Uart1_Sendstr("[ERROR]Paylen too long receive failed\n");
                    usart_rx_enableflag=0;      //数据接收完成，数据接收启动标志清零
                    usart_rd_len=0;             //数据长度清零
                    usart_rd_lentemp=0;         //数据长度暂存器清零                                                                                
                }
                //printstr("\n----------------------------------\n");
            }
            else if(usart_rd_lentemp==usart_rd_len+1)     //当读取到第usart_rd_lentemp+1个数据时，校验是否是长度信息的反码
            {/*校验数据长度的取反*/
                check_temp=~usart_rd_len;                 //取数据长度校验位的反码
                printstr("[DEBUGc] check_temp :");
                printdec(check_temp);
                printstr("\n");
                printstr("[DEBUGc] res :");
                printdec(res);
                
                if(res==check_temp)                       //当数据长度校验正确时
                {
                    usart_rx_lenrightflag=1;              //数据长度校验标志置一
                }
                else                                                                                     
                {                                          //当数据长度校验错误时
                    usart_rx_lenrightflag=0;               //数据长度校验清零
                    usart_rx_successflag=0;                //数据接收成功标志清零
                    usart_rx_enableflag=0;                  //当数据长度校验错误时，数据接收启动标志清零
                    usart_rd_len=0;                         //数据长度清零
                    usart_rd_lentemp=0;                     //数据长度暂存器清零
                    Uart1_Sendstr("[ERROR]Checksum failed receive failed\n");
                }
                //printstr("\n----------------------------------\n");
            }
            else if(usart_rd_lentemp == usart_rd_len+2)       //当读取到第usart_rd_lentemp+2个数据时，校验包尾是否正确
            {/*tail*/
                //printstr("the tail");
                if((res==0xef)&&(usart_rx_lenrightflag==1)) //如果包尾数据与长度校验都正确
                {
                    usart_rx_lenrightflag=0;                //数据长度校验清零
                    usart_rx_successflag=1;                 //数据接收成功标志置一
                    usart_rx_enableflag=0;                  //数据接收完成，数据接收启动标志清零
                    usart_rd_len=0;                         //数据长度清零
                    usart_rd_lentemp=0;                     //数据长度暂存器清零                                        
                    Uart1_Sendstr("[NOTICE]receive sucess\n");
                    //printstr("\n----------------------------------\n");
                }
                else 
                {                                          //当包尾数据校验错误时
                    usart_rx_lenrightflag=0;                //数据长度校验清零
                    usart_rx_successflag=0;                //数据接收成功标志清零

                    usart_rx_enableflag=0;                 //数据接收完成，数据接收启动标志清零
                    usart_rd_len=0;                        //数据长度清零
                    usart_rd_lentemp=0;                    //数据长度暂存器清零                                        
                    Uart1_Sendstr("[ERROR]receive failed\n");

                }
                //printstr("\n----------------------------------\n");
            }
            else
            {
                //printstr("the storing");
                //printstr("\n----------------------------------\n");
                usart_rx_temporary[usart_rd_lentemp-1] = res;    //当usart_rd_lentemp为数据段时，将数据存到串口数据接收寄存器中    
            }

            usart_rd_lentemp++; //每次记录数据，数据长度暂存器自加    

            if(usart_rx_successflag==1)                    //如果成功接收到信息数据，将缓存usart_rx_temporary[]内的数据传递给usart_rx_buf[][]
            {
                for(i=0;i<usart_rd_len;i++)
                    usart_rx_buf[usartrxbuf_pagebuf][i]=usart_rx_temporary[i];
                usartrxbuf_pagebuf++;                              //接受缓存的页码缓存自加
                if(usartrxbuf_pagebuf==UART_BUF_REG_NUM) 
                {
                    usartrxbuf_pagebuf=0;    //接受缓存的页码缓存最大为5
                }
                usartrxbuf_pagebuf++;
                usart_rd_lentemp = 0;
                usart_rx_successflag = 0;
            }            
        }
    }
}
#endif /* WL_UART */

#if 0
 {
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
    u8 i,res,check_temp;
    Uart1_Sendstr("[NOTICE]INTERRUPT_HANDLER in\n");
    if(UART1_GetITStatus(UART1_IT_RXNE) != RESET) //接收中断，每接收一个字节（8位二进制数据），中断一次,每次中断（即每接收一个数据）都执行一次下列程序
#if 1
    {
		res=UART1_ReceiveData8();                    //读取接收到的数据
		if((res==0xee)&&(usart_rx_enableflag==0))         //当接受到包头(0xee)数据并且还没有成功接收完数据信息
		{/*head*/
		    usart_rx_enableflag=1;                        //说明这是包头，启动接收数据标志，进入数据接收阶段
        }
        
		if(usart_rx_enableflag==1)                        //到接受数据标志置位时，接受数据
		{/*a frame*/            
			res=UART1_ReceiveData8();                //读取串口标志
			if(usart_rd_lentemp==0)                       //包头后第一个数据为需要传输的数据的长度
			{/*paylen*/
				usart_rd_len=res;                         //读取数据的长度 
				if(usart_rd_len>=UART_BUF_REG_LEN)
				{
					usart_rx_lenrightflag=0;    //数据长度校验清零
					usart_rx_successflag=0;     //数据接收成功标志清零
                    Uart1_Sendstr("[ERROR]receive failed\n");
					usart_rx_enableflag=0;      //数据接收完成，数据接收启动标志清零
					usart_rd_len=0;             //数据长度清零
					usart_rd_lentemp=0;         //数据长度暂存器清零                                                                                
				}
			}
			else if(usart_rd_lentemp==usart_rd_len+1)     //当读取到第usart_rd_lentemp+1个数据时，校验是否是长度信息的反码
			{/*校验数据长度的取反*/
				check_temp=~usart_rd_len;                 //取数据长度校验位的反码
				if(res==check_temp)                       //当数据长度校验正确时
				{
                    usart_rx_lenrightflag=1;              //数据长度校验标志置一
                }
				else                                                                                     
				{                                          //当数据长度校验错误时
					usart_rx_lenrightflag=0;               //数据长度校验清零
					usart_rx_successflag=0;                //数据接收成功标志清零
                    Uart1_Sendstr("[ERROR]receive failed\n");
                    usart_rx_enableflag=0;                  //当数据长度校验错误时，数据接收启动标志清零
					usart_rd_len=0;                         //数据长度清零
					usart_rd_lentemp=0;                     //数据长度暂存器清零
				}
			}
			else if(usart_rd_lentemp==usart_rd_len+2)       //当读取到第usart_rd_lentemp+2个数据时，校验包尾是否正确
			{/*tail*/
				if((res==0xef)&&(usart_rx_lenrightflag==1)) //如果包尾数据与长度校验都正确
				{
					usart_rx_lenrightflag=0;                //数据长度校验清零
					usart_rx_successflag=1;                 //数据接收成功标志置一
                    Uart1_Sendstr("[NOTICE]receive sucess\n");
					usart_rx_enableflag=0;                  //数据接收完成，数据接收启动标志清零
					usart_rd_len=0;                         //数据长度清零
					usart_rd_lentemp=0;                     //数据长度暂存器清零                                        
				}
				else 
				{                                          //当包尾数据校验错误时
					usart_rx_lenrightflag=0;                //数据长度校验清零
					usart_rx_successflag=0;                //数据接收成功标志清零
                    Uart1_Sendstr("[ERROR]receive failed\n");
                    usart_rx_enableflag=0;                 //数据接收完成，数据接收启动标志清零
					usart_rd_len=0;                        //数据长度清零
					usart_rd_lentemp=0;                    //数据长度暂存器清零                                        
				}
			}
			else usart_rx_temporary[usart_rd_lentemp-1]=res;    //当usart_rd_lentemp为数据段时，将数据存到串口数据接收寄存器中    
				
			usart_rd_lentemp++;                            //每次记录数据，数据长度暂存器自加    
			if(usart_rx_successflag==1)                    //如果成功接收到信息数据，将缓存usart_rx_temporary[]内的数据传递给usart_rx_buf[][]
			{
				for(i=0;i<usart_rd_len;i++)
					usart_rx_buf[usartrxbuf_pagebuf][i]=usart_rx_temporary[i];
				usartrxbuf_pagebuf++;                              //接受缓存的页码缓存自加
				if(usartrxbuf_pagebuf==UART_BUF_REG_NUM) 
                {
                    usartrxbuf_pagebuf=0;    //接受缓存的页码缓存最大为5
                }
				usartrxbuf_pagebuf++;
			}            
		}
	}
#endif

}
#endif

 



#endif /* (STM8S208) || (STM8S207) || (STM8S103) || (STM8S903) || (STM8AF62Ax) || (STM8AF52Ax) */

#if defined(STM8AF622x)
/**
  * @brief UART4 TX Interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(UART4_TX_IRQHandler, 17)
 {
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
 }

/**
  * @brief UART4 RX Interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(UART4_RX_IRQHandler, 18)
 {
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
 }
#endif /* (STM8AF622x) */

/**
  * @brief I2C Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(I2C_IRQHandler, 19)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

#if defined(STM8S105) || defined(STM8S005) ||  defined (STM8AF626x)
/**
  * @brief UART2 TX interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(UART2_TX_IRQHandler, 20)
 {
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
 }

/**
  * @brief UART2 RX interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(UART2_RX_IRQHandler, 21)
 {
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
 }
#endif /* (STM8S105) || (STM8AF626x) */

#if defined(STM8S207) || defined(STM8S007) || defined(STM8S208) || defined (STM8AF52Ax) || defined (STM8AF62Ax)
/**
  * @brief UART3 TX interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(UART3_TX_IRQHandler, 20)
 {
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
 }

/**
  * @brief UART3 RX interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(UART3_RX_IRQHandler, 21)
 {
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
 }
#endif /* (STM8S208) || (STM8S207) || (STM8AF52Ax) || (STM8AF62Ax) */

#if defined(STM8S207) || defined(STM8S007) || defined(STM8S208) || defined (STM8AF52Ax) || defined (STM8AF62Ax)
/**
  * @brief ADC2 interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(ADC2_IRQHandler, 22)
 {
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
 }
#else /* STM8S105 or STM8S103 or STM8S903 or STM8AF626x or STM8AF622x */
/**
  * @brief ADC1 interrupt routine.
  * @par Parameters:
  * None
  * @retval 
  * None
  */
 INTERRUPT_HANDLER(ADC1_IRQHandler, 22)
 {
    /* In order to detect unexpected events during development,
       it is recommended to set a breakpoint on the following instruction.
    */
 }
#endif /* (STM8S208) || (STM8S207) || (STM8AF52Ax) || (STM8AF62Ax) */

#if defined (STM8S903) || defined (STM8AF622x)
/**
  * @brief Timer6 Update/Overflow/Trigger Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(TIM6_UPD_OVF_TRG_IRQHandler, 23)
 {
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
 }
#else /* STM8S208 or STM8S207 or STM8S105 or STM8S103 or STM8AF52Ax or STM8AF62Ax or STM8AF626x */
/**
  * @brief Timer4 Update/Overflow Interrupt routine.
  * @param  None
  * @retval None
  */
 INTERRUPT_HANDLER(TIM4_UPD_OVF_IRQHandler, 23)
 {
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
 }
#endif /* (STM8S903) || (STM8AF622x)*/

/**
  * @brief Eeprom EEC Interrupt routine.
  * @param  None
  * @retval None
  */
INTERRUPT_HANDLER(EEPROM_EEC_IRQHandler, 24)
{
  /* In order to detect unexpected events during development,
     it is recommended to set a breakpoint on the following instruction.
  */
}

/**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
