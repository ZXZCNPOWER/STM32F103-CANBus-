/*
CAN BUS - GPIO EXPANDER
"code tested with STM32F103RB"

1.same code for "sender" and "receiver"
2.press the blue button on STM32, give a command 1-7 through serial monitor software, CAN Message will be sent
3.LED2 on Receiver board will be on if receive the message '1'
4.There need to be at least 2 nodes on CAN BUS Line(H&L) 
"I use a usb-CAN analyser¡°

CAN Transceiver can be SN65HVD234 OR TJA1050(5V VCC)



*/
#include "stm32f10x.h"
#include "./usart/bsp_debug_usart.h"
#include "./led/bsp_led.h"   
#include "./key/bsp_key.h"  
#include "./can/bsp_can.h"

//typedef unsigned char uint8_t;
//typedef unsigned short int uint16_t;
//typedef unsigned int uint32_t;
__IO uint8_t state = 0;
__IO uint32_t flag = 0;		 //label if receive message , f10x_it.c,CAN_RX_IRQHandler()
CanTxMsg TxMessage;			     //send message
CanRxMsg RxMessage;				 //receive message
#define LED_ON GPIO_SetBits(GPIOA, GPIO_Pin_5)        
#define LED_OFF GPIO_ResetBits(GPIOA, GPIO_Pin_5)     

/// simple delay function

void delay(u32 t)            
{
    u16 i;
    while(t--)
        for(i=0;i<1000;i++);
}


static void can_delay(__IO u32 nCount)
{
	for(; nCount != 0; nCount--);
} 


int main(void)
{	

  /*Init USART1*/
  Debug_USART_Config();
	LED_GPIO_Config();
	/*Init key*/
	Key_GPIO_Config();
 
	
	CAN_Config();
	

	printf("\r\n press button, print ID & message sent \r\n");


  while(1)
	{
//		printf("\r\n ready to press button \r\n");

//		if(	Key_Scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN) == KEY_OFF)
		if(GPIO_ReadInputDataBit(KEY1_GPIO_PORT,KEY1_GPIO_PIN) == KEY_OFF)
		{

			
			/*set TxMessage*/
			CAN_SetMsg(&TxMessage);
			/*save message into mailbox sent */
			CAN_Transmit(CANx, &TxMessage);
			
			can_delay(10000);//wait to check CAN_TransmitStatus
			
			printf("\r\n TxStatus Check \r\n");
			state = CAN_TransmitStatus(CANx, (uint8_t)0x00);
			printf("%u" , state);
			state = CAN_TransmitStatus(CANx, (uint8_t)0x01);
			printf("%u" , state);
			state = CAN_TransmitStatus(CANx, (uint8_t)0x02);
			printf("%u" , state);
			

			printf("\r\n sent ExtId£º0x%x \r\n",TxMessage.ExtId);
			
			CAN_DEBUG_ARRAY(TxMessage.Data,8); 
			CAN_CancelTransmit(CANx, (uint8_t)0x00);
			
		}else{
			
			delay(200);
		}
	
//		printf("\r\n ready to check flag \r\n");
//		
		if(flag==1)
		{		
			printf("\r\nCAN received£º\r\n");	

			CAN_DEBUG_ARRAY(RxMessage.Data,8);
			
			if(RxMessage.Data[0] == 01){
				
				printf("checked");
				LED_ON;                    //LED ONBOARD ON
        delay(5000);
        LED_OFF;                //OFF
        delay(1000);

				printf("led finished");
				
			}else{
				      delay(50);

			}
			
			
			flag=0;
			
			can_delay(1000000);
		}else{
		
		delay(5000);
//		printf("\r\n nothing received \r\n");
		}


}

}

