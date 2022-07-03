#ifndef  _LED_H
#define  _LED_H
#include "stm8s_gpio.h"

//#define  LEDPort  GPIOA
//#define  LEDPin   (1 << 3) 


#define  LEDPort  GPIOB
#define  LEDPin   (1 << 5) 

void LED_Init(void);
void LED_ON(void);
void LED_OFF(void);


#endif
