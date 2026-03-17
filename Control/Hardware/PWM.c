#include "stm32f10x.h"                  // Device header

void PWM_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3 | RCC_APB1Periph_TIM4, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB 
						| RCC_APB2Periph_TIM8 | RCC_APB2Periph_GPIOC, ENABLE);
	
	
	//GPIO初始化
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
//	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	
	//定时器初始化
	
	/*
		@简介：定时器TIM4初始化
	*/
	
	TIM_InternalClockConfig(TIM4);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 20000 - 1;		//ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler = 72 - 1;		//PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseInitStructure);
	
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;		//CCR
	TIM_OC1Init(TIM4, &TIM_OCInitStructure);
	TIM_OC2Init(TIM4, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM4,TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM4,TIM_OCPreload_Enable);
	TIM_Cmd(TIM4, ENABLE);
	
	/*
		@简介：定时器TIM3初始化
	*/
	
	
	TIM_InternalClockConfig(TIM3);
	
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 100 - 1;		//ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler = 72 - 1;		//PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);
	
	//TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;		//CCR
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM3,TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable);
	TIM_OC3PreloadConfig(TIM3,TIM_OCPreload_Enable);
	TIM_OC4PreloadConfig(TIM3,TIM_OCPreload_Enable);
	TIM_Cmd(TIM3, ENABLE);
	
	
	/*
		@简介：定时器TIM8初始化
		暂无用途，停用
	*/
	
//	TIM_InternalClockConfig(TIM8);
//    TIM_TimeBaseInitStructure.TIM_Period = 100 - 1;        // ARR
//    TIM_TimeBaseInitStructure.TIM_Prescaler = 72 - 1;      // PSC
//	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
//    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
//    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
//    TIM_TimeBaseInit(TIM8, &TIM_TimeBaseInitStructure);
//	
//    TIM_OCStructInit(&TIM_OCInitStructure);
//    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
//    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
//    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;   //设置空闲状态
//    TIM_OCInitStructure.TIM_Pulse = 0;
//	
//    TIM_OC3Init(TIM8, &TIM_OCInitStructure);  // PC8 IN1
//	TIM_OC3PreloadConfig(TIM8,TIM_OCPreload_Enable);
//    TIM_OC4Init(TIM8, &TIM_OCInitStructure);  // PC9 IN2
//	TIM_OC4PreloadConfig(TIM8,TIM_OCPreload_Enable);
//    
//	TIM_BDTRInitTypeDef TIM_BDTRInitStructure;
//	TIM_BDTRInitStructure.TIM_OSSRState = TIM_OSSRState_Enable;          // 运行模式输出使能
//	TIM_BDTRInitStructure.TIM_OSSIState = TIM_OSSIState_Enable;          // 空闲模式输出使能  
//	TIM_BDTRInitStructure.TIM_LOCKLevel = TIM_LOCKLevel_OFF;             // 无锁定
//	TIM_BDTRInitStructure.TIM_DeadTime = 0;                              // 无死区时间（单路输出不需要）
//	TIM_BDTRInitStructure.TIM_Break = TIM_Break_Disable;                 // 禁用刹车功能
//	TIM_BDTRInitStructure.TIM_BreakPolarity = TIM_BreakPolarity_Low;     // 刹车极性（随意设置，因为已禁用）
//	TIM_BDTRInitStructure.TIM_AutomaticOutput = TIM_AutomaticOutput_Enable;  // 自动输出使能

//	TIM_BDTRConfig(TIM8, &TIM_BDTRInitStructure);
//    
//	TIM_ARRPreloadConfig(TIM8,ENABLE);  //预装载寄存器
//	TIM_CtrlPWMOutputs(TIM8, ENABLE);    //高级定时器必须使能主输出   先
//	TIM_Cmd(TIM8, ENABLE);     //后   注意先后顺序
	
	
	/*
		@简介：定时器TIM2初始化  定时器中断
		暂无用途，停用
	*/
	
//	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
//    NVIC_InitTypeDef NVIC_InitStructure;

//    // 使能TIM2时钟
//    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

//    // 配置定时器基本参数
//    TIM_TimeBaseStructure.TIM_Period = 1000; // 自动重装载值
//    TIM_TimeBaseStructure.TIM_Prescaler = 7200 - 1; // 预分频系数
//    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
//    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
//    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

//    // 使能TIM2更新中断
//    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);

//    // 配置NVIC
//    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//    NVIC_Init(&NVIC_InitStructure);

//    // 启动定时器
//    TIM_Cmd(TIM2, ENABLE);
}

void PWM_SetCompare1_Servo1(uint16_t Compare)
{
	TIM_SetCompare1(TIM4, Compare);
}
void PWM_SetCompare2_Servo2(uint16_t Compare)
{
	TIM_SetCompare2(TIM4, Compare);
}
void PWM_SetCompare1_T3(uint16_t Compare)
{
	TIM_SetCompare1(TIM3, Compare);
}
void PWM_SetCompare2_T3(uint16_t Compare)
{
	TIM_SetCompare2(TIM3, Compare);
}
void PWM_SetCompare3_T3(uint16_t Compare)
{
	TIM_SetCompare3(TIM3, Compare);
}
void PWM_SetCompare4_T3(uint16_t Compare)
{
	TIM_SetCompare4(TIM3, Compare);
}

