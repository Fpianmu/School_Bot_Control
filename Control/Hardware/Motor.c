#include "stm32f10x.h"                  // Device header
#include "PWM.h"

void Motor_Init()
{
	
	/*
		@简介:TB6612方向引脚定义
	*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOF , ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14;
	GPIO_Init(GPIOF, &GPIO_InitStructure);
	
	GPIO_ResetBits(GPIOD,GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11);
	GPIO_ResetBits(GPIOF,GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14);
	
}
void Move_L1(int16_t speed)
{
	//范围限制判断
	if (speed > 100 )
	{
		speed = 100;
	}
	if (speed < -100 )
	{
		speed = -100;
	}
	
	//PWM输出
	if (speed > 0)  //前进
	{
		GPIO_SetBits(GPIOD,GPIO_Pin_8);
		GPIO_ResetBits(GPIOD,GPIO_Pin_9);
		PWM_SetCompare1_T3(speed);
	}
	else if (speed < 0)  //后退
	{
		GPIO_SetBits(GPIOD,GPIO_Pin_9);
		GPIO_ResetBits(GPIOD,GPIO_Pin_8);
		PWM_SetCompare1_T3(0);
	}
	else   //停车
	{
		GPIO_ResetBits(GPIOD,GPIO_Pin_8);
		GPIO_ResetBits(GPIOD,GPIO_Pin_9);
		PWM_SetCompare1_T3(0);
	}
}
void Move_L2(int16_t speed)
{
	//范围限制判断
	if (speed > 100 )
	{
		speed = 100;
	}
	if (speed < -100 )
	{
		speed = -100;
	}
	
	//PWM输出
	if (speed > 0)  //前进
	{
		GPIO_SetBits(GPIOD,GPIO_Pin_10);
		GPIO_ResetBits(GPIOD,GPIO_Pin_11);
		PWM_SetCompare2_T3(0);
	}
	else if (speed < 0)  //后退
	{
		GPIO_SetBits(GPIOD,GPIO_Pin_11);
		GPIO_ResetBits(GPIOD,GPIO_Pin_10);
		PWM_SetCompare2_T3(-speed);
	}
	else   //停车
	{
		GPIO_ResetBits(GPIOD,GPIO_Pin_10);
		GPIO_ResetBits(GPIOD,GPIO_Pin_11);
		PWM_SetCompare2_T3(0);
	}
}
void Move_R1(int16_t speed)
{
	//范围限制判断
	if (speed > 100 )
	{
		speed = 100;
	}
	if (speed < -100 )
	{
		speed = -100;
	}
	
	//PWM输出
	if (speed > 0)  //前进
	{
		GPIO_SetBits(GPIOF,GPIO_Pin_11);
		GPIO_ResetBits(GPIOF,GPIO_Pin_12);
		PWM_SetCompare3_T3(speed);
	}
	else if (speed < 0)  //后退
	{
		GPIO_SetBits(GPIOF,GPIO_Pin_12);
		GPIO_ResetBits(GPIOF,GPIO_Pin_11);
		PWM_SetCompare3_T3(-speed);
	}
	else   //停车
	{
		GPIO_ResetBits(GPIOF,GPIO_Pin_11);
		GPIO_ResetBits(GPIOF,GPIO_Pin_12);
		PWM_SetCompare3_T3(0);
	}
}
void Move_R2(int16_t speed)
{
	//范围限制判断
	if (speed > 100 )
	{
		speed = 100;
	}
	if (speed < -100 )
	{
		speed = -100;
	}
	
	//PWM输出
	if (speed > 0)  //前进
	{
		GPIO_SetBits(GPIOF,GPIO_Pin_13);
		GPIO_ResetBits(GPIOF,GPIO_Pin_14);
		PWM_SetCompare4_T3(speed);
	}
	else if (speed < 0)  //后退
	{
		GPIO_SetBits(GPIOF,GPIO_Pin_14);
		GPIO_ResetBits(GPIOF,GPIO_Pin_13);
		PWM_SetCompare4_T3(-speed);
	}
	else   //停车
	{
		GPIO_ResetBits(GPIOF,GPIO_Pin_13);
		GPIO_ResetBits(GPIOF,GPIO_Pin_14);
		PWM_SetCompare4_T3(0);
	}
}
void Engine_Init()
{
	//所有电机、舵机的初始化集合
	PWM_Init();
	Motor_Init();
}

