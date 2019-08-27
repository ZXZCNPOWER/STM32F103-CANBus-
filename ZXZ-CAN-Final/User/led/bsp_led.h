#ifndef __LED_H
#define	__LED_H


#include "stm32f10x.h"



#define LED1_GPIO_PORT    	GPIOB			             
#define LED1_GPIO_CLK 	    RCC_APB2Periph_GPIOB	
#define LED1_GPIO_PIN		GPIO_Pin_5			       


#define LED2_GPIO_PORT    	GPIOB
#define LED2_GPIO_CLK 	    RCC_APB2Periph_GPIOB		
#define LED2_GPIO_PIN		GPIO_Pin_0			     

#define LED3_GPIO_PORT    	GPIOB			              
#define LED3_GPIO_CLK 	    RCC_APB2Periph_GPIOB		
#define LED3_GPIO_PIN		GPIO_Pin_1			        


/** the macro definition to trigger the led on or off 
  * 1 - off
  *0 - on
  */
#define ON  0
#define OFF 1


#define LED1(a)	if (a)	\
					GPIO_SetBits(LED1_GPIO_PORT,LED1_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED1_GPIO_PORT,LED1_GPIO_PIN)

#define LED2(a)	if (a)	\
					GPIO_SetBits(LED2_GPIO_PORT,LED2_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED2_GPIO_PORT,LED2_GPIO_PIN)

#define LED3(a)	if (a)	\
					GPIO_SetBits(LED3_GPIO_PORT,LED3_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED3_GPIO_PORT,LED3_GPIO_PIN)



#define	digitalHi(p,i)		 {p->BSRR=i;}	 
#define digitalLo(p,i)		 {p->BRR=i;}	 
#define digitalToggle(p,i) {p->ODR ^=i;} 



#define LED1_TOGGLE		 digitalToggle(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1_OFF		   digitalHi(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1_ON			   digitalLo(LED1_GPIO_PORT,LED1_GPIO_PIN)

#define LED2_TOGGLE		 digitalToggle(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define LED2_OFF		   digitalHi(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define LED2_ON			   digitalLo(LED2_GPIO_PORT,LED2_GPIO_PIN)

#define LED3_TOGGLE		 digitalToggle(LED3_GPIO_PORT,LED3_GPIO_PIN)
#define LED3_OFF		   digitalHi(LED3_GPIO_PORT,LED3_GPIO_PIN)
#define LED3_ON			   digitalLo(LED3_GPIO_PORT,LED3_GPIO_PIN)



void LED_GPIO_Config(void);

#endif /* __LED_H */
