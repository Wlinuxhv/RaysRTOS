#ifndef  _USART_H
#define  _USART_H
#include "stm8s_uart1.h"
//#include "ALL_Includes.h"
//#include "va_list.h"
//定义UART的TX、RX引脚
#define  TXPort  GPIOD
#define  TXPin   (1 << 5)
#define  RXPort  GPIOD
#define  RXPin   (1 << 6)


#if 0 //ITN9
#define UART_BUF_REG_LEN (40)
#define UART_BUF_REG_NUM (5)
extern u8 usart_rx_buf[UART_BUF_REG_NUM][UART_BUF_REG_LEN];    //接收缓冲,最大40个字节
extern u8 usart_rx_temporary[UART_BUF_REG_LEN]; //数据保存暂存器,最多能够缓存40个字节
extern u8 usartrxbuf_pagebuf;    //最上面接受缓存的页码（5）缓存
extern u8 usart_rd_len;         //有用信息的数据长度
extern u8 usart_rd_lentemp;    //用来记录已读取的数据长度
extern u8 usart_rx_enableflag;  //接收状态标记
extern u8 usart_rx_lenrightflag;//数据长度校验位正确标志
extern u8 usart_rx_successflag; //成功接收到数据信息
ITStatus UART1_GetITStatus(UART1_IT_TypeDef UART1_IT);
void UART1_ClearITPendingBit(UART1_IT_TypeDef UART1_IT);
uint8_t UART1_ReceiveData8(void);
uint16_t UART1_ReceiveData9(void);
//typedef enum { UART1_IT_TXE        = (uint16_t)0x0277, /*!< Transmit interrupt */
//               UART1_IT_TC         = (uint16_t)0x0266, /*!< Transmission Complete interrupt */
//               UART1_IT_RXNE       = (uint16_t)0x0255, /*!< Receive interrupt */
//               UART1_IT_IDLE       = (uint16_t)0x0244, /*!< IDLE line interrupt */
//               UART1_IT_OR         = (uint16_t)0x0235, /*!< Overrun Error interrupt */
//               UART1_IT_PE         = (uint16_t)0x0100, /*!< Parity Error interrupt */
//               UART1_IT_LBDF       = (uint16_t)0x0346, /**< LIN break detection interrupt */
//               UART1_IT_RXNE_OR    = (uint16_t)0x0205  /*!< Receive/Overrun interrupt */
//             } UART1_IT_TypeDef;
#endif


void UART_Init(u8 SYS_Clk, u32 baud);
void UART_SendChar(unsigned char ch);
void UART_IOConfig(void);
int Strlen(unsigned char *pstr);
void Uart1_Sendstr(unsigned char *pstr, ...);


void printdec(int dec)  ;
#ifdef FLOAT_SUPPORT
void printflt(double flt)  ;
#endif
void printstr(char *str);
void printbin(int bin);
void printhex(int hex) ;
void print(char *fmt, ...);

#endif
