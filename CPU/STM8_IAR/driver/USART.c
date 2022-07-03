#include "USART.h"
#include <stdio.h>
#include "va_list.h"

#ifdef ITN9
u8 usart_rx_buf[UART_BUF_REG_NUM][UART_BUF_REG_LEN];    //接收缓冲,最大40个字节
u8 usart_rx_temporary[40]; //数据保存暂存器,最多能够缓存40个字节
u8 usartrxbuf_pagebuf = 0;   //最上面接受缓存的页码（5）缓存
u8 usart_rd_len = 0;       //有用信息的数据长度
u8 usart_rd_lentemp = 0;   //用来记录已读取的数据长度
u8 usart_rx_enableflag = 0; //接收状态标记
u8 usart_rx_lenrightflag = 0; //数据长度校验位正确标志
u8 usart_rx_successflag = 0; //成功接收到数据信息
#endif /* ITN9 */

/**************************
函数功能：初始化UART
输入参数：SYS_Clk:系统时钟（2,4,8,16）
         baud：   波特率
输出参数：无
返 回 值：无
备    注：无
***************************/
void UART_Init(u8 SYS_Clk, u32 baud)
#if 0
{
    UART1_DeInit();
    UART1_Init((u32)9600, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO, UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TXRX_ENABLE);

    UART1_ITConfig(UART1_IT_RXNE, DISABLE);

    UART1_Cmd(ENABLE);
    //enableInterrupts();
}
#else
{
    u16 UART_Temp;
    UART_IOConfig();//UART IO引脚初始化
    UART1->CR2 = 0;// 禁止UART发送和接收
    UART1->CR1 = 0;// b5 = 0,允许UART  b2 = 0,禁止校验
    UART1->CR3 = 0;// b5,b4 = 00,1个停止位

    /**************************************************
        设置波特率，必须注意以下几点：
        (1) 必须先写BRR2
        (2) BRR1存放的是分频系数的第11位到第4位，
        (3) BRR2存放的是分频系数的第15位到第12位，和第3位到第0位
        例如对于波特率位9600时，分频系数=2000000/9600=208
        对应的十六进制数为00D0，BBR1=0D,BBR2=00
    *************************************************/
    UART_Temp = SYS_Clk * 1000000 / baud;
    UART1->BRR2 = (u8)((UART_Temp & 0x000F) | ((UART_Temp & 0xF000) >> 8));
    UART1->BRR1 = (u8)((UART_Temp & 0x0FF0) >> 4);

#if 0
    UART1->CR2 = 0x2C; // b3 = 1,允许发送
    // b2 = 1,允许接收
    // b5 = 1,允许产生接收中断

#else
    UART1->CR2 = 0x08; // b3 = 1,允许发送
    // b2 = 0,不允许接收
    // b5 = 0,不允许产生接收中断

#endif
    //enableInterrupts();

}
#endif

/**************************************
函数功能：从UART3发送一个字符
输入参数：ch -- 要发送的字符
输出参数：无
返 回 值：无
备    注：无
***************************************/
void UART_SendChar(unsigned char ch)
{
    while ((UART1->SR & 0x80) == 0x00); // 若发送寄存器不空，则等待
    UART1->DR = ch;                     // 将要发送的字符送到数据寄存器
}

/***********************************
函数功能：UART IO口初始化
输入参数：无
输出参数：无
备   注：ＩＯ在输出模式下，可通过ＣＲ２寄存器
         控制输出速率
***********************************/
void UART_IOConfig(void)
{
    TXPort->DDR |= TXPin;//输出模式
    TXPort->CR1 |= TXPin;//推挽输出

    RXPort->DDR &= ~RXPin; //输入模式
    RXPort->CR1 &= ~RXPin; //浮空输入
}

#if 1
/***********************************************
函数功能: 重定义fputc函数
备   注：使用printf需重定义fputc函数，并且
        修改在General Options 中的Library Configuration
        和Library Options
***********************************************/
//int fputc(int ch, FILE *f)
//{
//    while((UART1->SR&0X40)==0);
//
//    UART1->DR = (u8) ch;
//
//    return ch;
//}


int Strlen(unsigned char *pstr)
{
    int cnt = -1;
    while (*pstr != '\0') {
        pstr++;
        cnt++;
    }
    return cnt;
}

void Uart1_Sendstr(unsigned char *pstr, ...)
{
    int strlen = Strlen(pstr);
    while (strlen-- >= 0) {
        UART_SendChar(*pstr);
        pstr++;
    }
}

#define printch(ch)    UART_SendChar(ch)

/*
0~32767
*/
void    printdec(int dec)
{
    if (dec == 0) {
        printch('0');
        return;
    }
    printdec(dec / 10);
    printch((char)(dec % 10 + '0'));
}

#ifdef FLOAT_SUPPORT
/*
    x.xxx
    0~32767.998
*/
void printflt(double flt)
{
    //int icnt = 0;
    int tmpint = 0;

    tmpint = (int)flt;
    printdec(tmpint);
    printch('.');
    flt = flt - tmpint;
    tmpint = (int)(flt * 1000);
    printdec(tmpint);
}
#endif

void printstr(char *str)
{
    while (*str) {
        printch(*str++);
    }
}

void printbin(int bin)
{
    if (bin == 0) {
        printstr("0b");
        return;
    }
    printbin(bin / 2);
    printch((char)(bin % 2 + '0'));
}

void printhex(int hex)
{
    if (hex == 0) {
        printstr("0x");
        return;
    }
    printhex(hex / 16);
    if (hex < 10) {
        printch((char)(hex % 16 + '0'));
    } else {
        printch((char)(hex % 16 - 10 + 'A'));
    }
}


void print(char *fmt, ...)
{
#ifdef FLOAT_SUPPORT

    double vargflt = 0;
#endif
    int  vargint = 0;
    char *vargpch = NULL;
    char vargch = 0;
    char *pfmt = NULL;
    va_list vp;

    va_start(vp, fmt);
    pfmt = fmt;

    while (*pfmt) {
        if (*pfmt == '%') {
            switch (*(++pfmt)) {

                case 'c':
                    vargch = va_arg(vp, int);
                    /*    va_arg(ap, type), if type is narrow type (char, short, float) an error is given in strict ANSI
                        mode, or a warning otherwise.In non-strict ANSI mode, 'type' is allowed to be any expression. */
                    printch(vargch);
                    break;
                case 'd':
                case 'i':
                    vargint = va_arg(vp, int);
                    printdec(vargint);
                    break;
#ifdef FLOAT_SUPPORT
                case 'f':
                    vargflt = va_arg(vp, double);
                    /*    va_arg(ap, type), if type is narrow type (char, short, float) an error is given in strict ANSI
                        mode, or a warning otherwise.In non-strict ANSI mode, 'type' is allowed to be any expression. */
                    printflt(vargflt);
                    break;
#endif
                case 's':
                    vargpch = va_arg(vp, char *);
                    printstr(vargpch);
                    break;
                case 'b':
                case 'B':
                    vargint = va_arg(vp, int);
                    printbin(vargint);
                    break;
                case 'x':
                case 'X':
                    vargint = va_arg(vp, int);
                    printhex(vargint);
                    break;
                case '%':
                    printch('%');
                    break;
                default:
                    break;
            }
            pfmt++;
        } else {
            printch(*pfmt++);
        }
    }
    va_end(vp);
}
#endif
