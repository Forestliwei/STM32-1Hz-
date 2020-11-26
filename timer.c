#include "timer.h"

 void Tim4_Init(u16 arr,u16 psc)
 {
	 TIM_TimeBaseInitTypeDef TIM_TimeBaseInitstructure;
	 
	 /*************************定时器时钟源使能*********************************/
	 RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	 
	 /*************************定时器基本配置*********************************/
	 TIM_TimeBaseInitstructure.TIM_Prescaler = psc;//预分频系数
	 TIM_TimeBaseInitstructure.TIM_Period = arr;//自动装在值
	 TIM_TimeBaseInitstructure.TIM_CounterMode = TIM_CounterMode_Up;//向上计数
	 TIM_TimeBaseInitstructure.TIM_ClockDivision = TIM_CKD_DIV1;    
	 TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitstructure);
	 
	 /*************************设置TIM4更新事件作为外部触发源*********************************/
	 TIM_SelectOutputTrigger(TIM4,TIM_TRGOSource_Update);//更新作为触发源
	 /*************************使能TIM4计数器*********************************/
	 TIM_Cmd(TIM4,ENABLE);
 }

