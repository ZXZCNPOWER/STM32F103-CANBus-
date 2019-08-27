#include "can_hw.h"
#include "led.h"
#include "delay.h"
#include "usart.h"
#include "TestMaster.h"

 

u8 CAN_Mode_Init(u8 tsjw,u8 tbs2,u8 tbs1,u16 brp,u8 mode)
{ 
	GPIO_InitTypeDef 		GPIO_InitStructure; 
	CAN_InitTypeDef        	CAN_InitStructure;
	CAN_FilterInitTypeDef  	CAN_FilterInitStructure;
#if CAN_RX0_INT_ENABLE 
	NVIC_InitTypeDef  		NVIC_InitStructure;
#endif

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	                   											 

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);			

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	
	GPIO_Init(GPIOA, &GPIO_InitStructure);			


	CAN_InitStructure.CAN_TTCM=DISABLE;			 
	CAN_InitStructure.CAN_ABOM=DISABLE;			 
	CAN_InitStructure.CAN_AWUM=DISABLE;			
	CAN_InitStructure.CAN_NART=ENABLE;			 
	CAN_InitStructure.CAN_RFLM=DISABLE;		 	 
	CAN_InitStructure.CAN_TXFP=DISABLE;			
	CAN_InitStructure.CAN_Mode= mode;	        

	CAN_InitStructure.CAN_SJW=tsjw;				
	CAN_InitStructure.CAN_BS1=tbs1; 			
	CAN_InitStructure.CAN_BS2=tbs2;				
	CAN_InitStructure.CAN_Prescaler=brp;        
	CAN_Init(CAN1, &CAN_InitStructure);         

	CAN_FilterInitStructure.CAN_FilterNumber=0;	
	CAN_FilterInitStructure.CAN_FilterMode=CAN_FilterMode_IdMask; 	
	CAN_FilterInitStructure.CAN_FilterScale=CAN_FilterScale_32bit; 	 
	CAN_FilterInitStructure.CAN_FilterIdHigh=0x0000;	
	CAN_FilterInitStructure.CAN_FilterIdLow=0x0000;
	CAN_FilterInitStructure.CAN_FilterMaskIdHigh=0x0000;
	CAN_FilterInitStructure.CAN_FilterMaskIdLow=0x0000;
	CAN_FilterInitStructure.CAN_FilterFIFOAssignment=CAN_Filter_FIFO0;
	CAN_FilterInitStructure.CAN_FilterActivation=ENABLE;

	CAN_FilterInit(&CAN_FilterInitStructure);			
	
#if CAN_RX0_INT_ENABLE 
	CAN_ITConfig(CAN1,CAN_IT_FMP0,ENABLE);						    

	NVIC_InitStructure.NVIC_IRQChannel = USB_LP_CAN1_RX0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;     
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;           
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
#endif
	return 0;
}   
 
#if CAN_RX0_INT_ENABLE	//ʹ��RX0�ж�
	    
void USB_LP_CAN1_RX0_IRQHandler(void)
{
  	u32 i;
	Message m;
	CanRxMsg RxMessage;
    CAN_Receive(CAN1, CAN_FIFO0, &RxMessage);
	m.cob_id = RxMessage.StdId;
	if(RxMessage.RTR == CAN_RTR_REMOTE)
	{
		m.rtr = 1;
	}
	else if(RxMessage.RTR == CAN_RTR_DATA)
	{
		m.rtr = 0;
	}
	m.len = RxMessage.DLC;
	for(i = 0; i < RxMessage.DLC; i++){
		m.data[i] = RxMessage.Data[i];
	}
	canDispatch(&TestMaster_Data, &m);
	/*
	for(i=0;i<8;i++)
	printf("rxbuf[%d]:%d\r\n",i,RxMessage.Data[i]);
	*/
}
#endif

//can����һ������(�̶���ʽ:IDΪ0X12,��׼֡,����֡)	
//len:���ݳ���(���Ϊ8)				     
//msg:����ָ��,���Ϊ8���ֽ�.
//����ֵ:0,�ɹ�;
//		 ����,ʧ��;
#if 0
u8 Can_Send_Msg(u8* msg,u8 len)
{	
	u8 mbox;
	u16 i=0;
	CanTxMsg TxMessage;
	TxMessage.StdId=0x12;			// ��׼��ʶ�� 
	TxMessage.ExtId=0x12;			// ������չ��ʾ�� 
	TxMessage.IDE=CAN_Id_Standard; 	// ��׼֡
	TxMessage.RTR=CAN_RTR_Data;		// ����֡
	TxMessage.DLC=len;				// Ҫ���͵����ݳ���
	for(i=0;i<len;i++)
	TxMessage.Data[i]=msg[i];			          
	mbox= CAN_Transmit(CAN1, &TxMessage);   
	i=0; 
	while((CAN_TransmitStatus(CAN1, mbox)==CAN_TxStatus_Failed)&&(i<0XFFF))i++;	//�ȴ����ͽ���
	if(i>=0XFFF)return 1;
	return 0;	 
}
#endif
unsigned char canSend(CAN_PORT notused, Message *m)
{
	uint32_t  i;
	CanTxMsg  TxMessage;
	CanTxMsg *ptx_msg=&TxMessage;
	ptx_msg->StdId = m->cob_id;

	if(m->rtr)
		ptx_msg->RTR = CAN_RTR_REMOTE;
	else
		ptx_msg->RTR = CAN_RTR_DATA;

	ptx_msg->IDE = CAN_ID_STD;
	ptx_msg->DLC = m->len;
	for(i = 0; i < m->len; i++)
		ptx_msg->Data[i] = m->data[i];
	if( CAN_Transmit( CAN1, ptx_msg )==CAN_NO_MB)
	{
		return 0xff;
	}
	else
	{
		return 0x00;
	}

}
//can�ڽ������ݲ�ѯ
//buf:���ݻ�����;	 
//����ֵ:0,�����ݱ��յ�;
//		 ����,���յ����ݳ���;
#if 0
u8 Can_Receive_Msg(u8 *buf)
{		   		   
 	u32 i;
	CanRxMsg RxMessage;
    if( CAN_MessagePending(CAN1,CAN_FIFO0)==0)return 0;		//û�н��յ�����,ֱ���˳� 
    CAN_Receive(CAN1, CAN_FIFO0, &RxMessage);//��ȡ����	
    for(i=0;i<8;i++)
    buf[i]=RxMessage.Data[i];  
	return RxMessage.DLC;	
}

#endif












