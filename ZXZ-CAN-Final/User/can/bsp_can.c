
#include "./can/bsp_can.h"


static void CAN_GPIO_Config(void)
{
 	GPIO_InitTypeDef GPIO_InitStructure;   	

  /* Enable GPIO clock */
  RCC_APB2PeriphClockCmd(CAN_TX_GPIO_CLK|CAN_RX_GPIO_CLK, ENABLE);

	GPIO_PinRemapConfig(GPIO_Remap1_CAN1, DISABLE);

	 /* Configure CAN TX pins */
  GPIO_InitStructure.GPIO_Pin = CAN_TX_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;		         
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

  GPIO_Init(CAN_TX_GPIO_PORT, &GPIO_InitStructure);
	
	/* Configure CAN RX  pins */
  GPIO_InitStructure.GPIO_Pin = CAN_RX_PIN ;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	             
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

  GPIO_Init(CAN_RX_GPIO_PORT, &GPIO_InitStructure);
}


static void CAN_NVIC_Config(void)
{
   	NVIC_InitTypeDef NVIC_InitStructure;
		/* Configure one bit for preemption priority */
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

		NVIC_InitStructure.NVIC_IRQChannel = CAN_RX_IRQ;	   
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;		   
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;			   
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}


static void CAN_Mode_Config(void)
{
	CAN_InitTypeDef        CAN_InitStructure;

	/* Enable CAN clock */
  RCC_APB1PeriphClockCmd(CAN_CLK, ENABLE);


	CAN_DeInit(CANx);
	CAN_StructInit(&CAN_InitStructure);


	CAN_InitStructure.CAN_TTCM=DISABLE;			   
	CAN_InitStructure.CAN_ABOM=DISABLE;			    
	CAN_InitStructure.CAN_AWUM=DISABLE;			   
	CAN_InitStructure.CAN_NART=ENABLE;			  
	CAN_InitStructure.CAN_RFLM=DISABLE;			   
	CAN_InitStructure.CAN_TXFP=ENABLE;			   
	CAN_InitStructure.CAN_Mode = CAN_Mode_Normal;  
	CAN_InitStructure.CAN_SJW=CAN_SJW_1tq;		  
	 
	/* ss=1 bs1=5 bs2=3 位时间宽度为(1+5+3) 波特率即为时钟周期tq*(1+3+5)  */
	CAN_InitStructure.CAN_BS1=CAN_BS1_4tq;		   
	CAN_InitStructure.CAN_BS2=CAN_BS2_3tq;		 
	
	
	CAN_InitStructure.CAN_Prescaler =9*4;		  
	CAN_Init(CANx, &CAN_InitStructure);
}


static void CAN_Filter_Config(void)
{
	CAN_FilterInitTypeDef  CAN_FilterInitStructure;


	CAN_FilterInitStructure.CAN_FilterNumber=1;					
	CAN_FilterInitStructure.CAN_FilterMode=CAN_FilterMode_IdMask;	
	CAN_FilterInitStructure.CAN_FilterScale=CAN_FilterScale_32bit;	


	CAN_FilterInitStructure.CAN_FilterIdHigh          =  0x0000;
	CAN_FilterInitStructure.CAN_FilterIdLow           =  0x0000;
	CAN_FilterInitStructure.CAN_FilterMaskIdHigh      =  0x0000;
	CAN_FilterInitStructure.CAN_FilterMaskIdLow       =  0x0000;
	CAN_FilterInitStructure.CAN_FilterFIFOAssignment=CAN_Filter_FIFO0 ;				
	CAN_FilterInitStructure.CAN_FilterActivation=ENABLE;		
	CAN_FilterInit(&CAN_FilterInitStructure);
	
	CAN_ITConfig(CANx, CAN_IT_FMP0, ENABLE);
}



void CAN_Config(void)
{
  CAN_GPIO_Config();
  CAN_NVIC_Config();
  CAN_Mode_Config();
  CAN_Filter_Config();   
}



void Init_RxMes(CanRxMsg *RxMessage)
{
  uint8_t ubCounter = 0;


  RxMessage->StdId = 0x00;
  RxMessage->ExtId = 0x00;
  RxMessage->IDE = CAN_ID_STD;
  RxMessage->DLC = 0;
  RxMessage->FMI = 0;
  for (ubCounter = 0; ubCounter < 8; ubCounter++)
  {
    RxMessage->Data[ubCounter] = 0x00;
  }
}


void CAN_SetMsg(CanTxMsg *TxMessage)
{	  
	char ch;
	
	printf("pls key in a value 1-7 as a command\n");
	ch=getchar();
	int x = ch - '0';
  printf("usart received：%c\n",ch);
	
	uint8_t ubCounter = 0;

  TxMessage->StdId=0x01;						 
  TxMessage->ExtId=0x1314;					 
  TxMessage->IDE=CAN_ID_EXT;					 
  TxMessage->RTR=CAN_RTR_DATA;				
  TxMessage->DLC=8;
	TxMessage->Data[0] = x;
  	
	
	
	for (ubCounter = 1; ubCounter < 8; ubCounter++)
  {
    TxMessage->Data[ubCounter] = 0;
  }
}

void delay_ms(uint16_t ms)
{
 TIM6->PSC=35999;
 TIM6->ARR=ms*2;
 TIM6->CR1|=(1<<3);
 TIM6->CR1|=0x1;
 while((TIM6->SR&0X1)==0);
 TIM6->SR=0;
}

/**************************END OF FILE************************************/











