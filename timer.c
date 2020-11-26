#include "timer.h"

 void Tim4_Init(u16 arr,u16 psc)
 {
	 TIM_TimeBaseInitTypeDef TIM_TimeBaseInitstructure;
	 
	 /*************************��ʱ��ʱ��Դʹ��*********************************/
	 RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	 
	 /*************************��ʱ����������*********************************/
	 TIM_TimeBaseInitstructure.TIM_Prescaler = psc;//Ԥ��Ƶϵ��
	 TIM_TimeBaseInitstructure.TIM_Period = arr;//�Զ�װ��ֵ
	 TIM_TimeBaseInitstructure.TIM_CounterMode = TIM_CounterMode_Up;//���ϼ���
	 TIM_TimeBaseInitstructure.TIM_ClockDivision = TIM_CKD_DIV1;    
	 TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitstructure);
	 
	 /*************************����TIM4�����¼���Ϊ�ⲿ����Դ*********************************/
	 TIM_SelectOutputTrigger(TIM4,TIM_TRGOSource_Update);//������Ϊ����Դ
	 /*************************ʹ��TIM4������*********************************/
	 TIM_Cmd(TIM4,ENABLE);
 }

