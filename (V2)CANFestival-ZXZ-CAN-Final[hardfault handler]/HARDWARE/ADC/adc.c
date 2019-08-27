 #include "adc.h"
 #include "delay.h"
 
	   
														   
void  Adc_Init(void)
{ 	
	ADC_InitTypeDef ADC_InitStructure; 
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA |RCC_APB2Periph_ADC1	, ENABLE );	 
 

	RCC_ADCCLKConfig(RCC_PCLK2_Div6);  

	//PA1                       
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;		
	GPIO_Init(GPIOA, &GPIO_InitStructure);	

	ADC_DeInit(ADC1); 

	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;	
	ADC_InitStructure.ADC_ScanConvMode = ENABLE;	
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;	
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;	
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;	
	ADC_InitStructure.ADC_NbrOfChannel = 2;	
	ADC_Init(ADC1, &ADC_InitStructure);	  

  
	ADC_Cmd(ADC1, ENABLE);	
	
	ADC_ResetCalibration(ADC1);	 
	 
	while(ADC_GetResetCalibrationStatus(ADC1));	
	
	ADC_StartCalibration(ADC1);	
 
	while(ADC_GetCalibrationStatus(ADC1));	
	ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_239Cycles5 );
	ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 2, ADC_SampleTime_239Cycles5 );		  			    
				    

 
//	ADC_SoftwareStartConvCmd(ADC1, ENABLE);		

}				  

void Get_Adc( u16 * pdata)   
{
  	
	//ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_239Cycles5 );	//ADC1,ADC通道,采样时间为239.5周期	  			    
  
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);		
	 
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC ));
	pdata[0] = ADC_GetConversionValue(ADC1);
	//设置指定ADC的规则组通道，一个序列，采样时间
	//ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_239Cycles5 );	//ADC1,ADC通道,采样时间为239.5周期	  			    
  
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);		
	 
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC ));
	pdata[1] = ADC_GetConversionValue(ADC1);
	
	return ;	
}

void Get_Adc_Average(u16* pdata, u8 times)
{

	u32 temp_val_0=0;
	u32 temp_val_1 = 0;
	u8 t;
	if(pdata == 0)
		return;

	for(t=0;t<times;t++)
	{
		Get_Adc(pdata);
		temp_val_0+=(pdata[0]>>2)<<2;
		temp_val_1 += (pdata[1]>>2)<<2;
		delay_ms(1);
	}
	pdata[0] = temp_val_0/times;
	pdata[1] = temp_val_1/times;
} 	 



























