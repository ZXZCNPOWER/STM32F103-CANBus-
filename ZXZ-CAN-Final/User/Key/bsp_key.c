
#include "./key/bsp_key.h"  


void Key_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK|KEY2_GPIO_CLK,ENABLE);

	GPIO_InitStructure.GPIO_Pin = KEY1_GPIO_PIN; 

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 

	GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure);
	

	GPIO_InitStructure.GPIO_Pin = KEY2_GPIO_PIN; 

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 

	GPIO_Init(KEY2_GPIO_PORT, &GPIO_InitStructure);	
}



/*********************************************END OF FILE**********************/
