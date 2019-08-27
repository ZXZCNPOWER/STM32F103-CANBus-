#include "beep.h"
#include "stm32f10x.h"

void Beep_init()
{
	TIM1_PWM_Init(180-1, 100-1);
	TIM_SetCompare1(TIM1, 180/2);//ռ�ձ�50%
}

void Beep_CMD(FunctionalState state)
{
	  TIM_CtrlPWMOutputs(TIM1, state);	

}
