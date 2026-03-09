#include "stm32f10x.h"                  // Device header
#include "Encoder.h"

static volatile int64_t encoder_l1 = 0;   //左一电机
static volatile int64_t encoder_l2 = 0;	  //左二电机
static volatile int64_t encoder_r1 = 0;   //右一电机
static volatile int64_t encoder_r2 = 0;   //右二电机

static void Encoder_l1_Init(void);
static void Encoder_l2_Init(void);
static void Encoder_r1_Init(void);
static void Encoder_r2_Init(void);


void Encoder_Init()
{
	Encoder_l1_Init();
	Encoder_l2_Init();
	Encoder_r1_Init();
	Encoder_r2_Init();
}


/*
	@简介：读取左一编码器的当前位置
*/
int64_t Encoder_GetPos_l1(void)
{
	return encoder_l1;
}
/*
	@简介：读取左二编码器的当前位置
*/
int64_t Encoder_GetPos_l2(void)
{
	return encoder_l2;
}
/*
	@简介：读取右一编码器的当前位置
*/
int64_t Encoder_GetPos_r1(void)
{
	return encoder_r1;
}
/*
	@简介：读取右二编码器的当前位置
*/
int64_t Encoder_GetPos_r2(void)
{
	return encoder_r2;
}



/*
	@简介：左一编码器初始化
*/
static void Encoder_l1_Init()
{
	//初始化IO引脚
	//PD2  PD3  - IPU
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
	
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	//EXTI初始化
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource3);
	
	//EXTI参数配置
	EXTI_InitTypeDef EXTI_InitStructure = {0};
	EXTI_InitStructure.EXTI_Line = EXTI_Line3;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
	
	EXTI_Init(&EXTI_InitStructure);
	
	//开启EXTI中断
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel = EXTI3_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;   //较为重要，分配为首要优先级
	
	NVIC_Init(&NVIC_InitStruct);
}
/*
	@简介：左二编码器初始化
*/
static void Encoder_l2_Init()
{
	//初始化IO引脚
	//PE3  PE4  - IPU
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4;
	
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	//EXTI初始化
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE,GPIO_PinSource4);
	
	//EXTI参数配置
	EXTI_InitTypeDef EXTI_InitStructure = {0};
	EXTI_InitStructure.EXTI_Line = EXTI_Line4;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
	
	EXTI_Init(&EXTI_InitStructure);
	
	//开启EXTI中断
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel = EXTI4_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;   //较为重要，分配为首要优先级
	
	NVIC_Init(&NVIC_InitStruct);
}
/*
	@简介：右一编码器初始化
*/
static void Encoder_r1_Init()
{
	//初始化IO引脚
	//PG0  PG1  - IPU
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	
	GPIO_Init(GPIOG, &GPIO_InitStructure);
	
	//EXTI初始化
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOG,GPIO_PinSource0);
	
	//EXTI参数配置
	EXTI_InitTypeDef EXTI_InitStructure = {0};
	EXTI_InitStructure.EXTI_Line = EXTI_Line0;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
	
	EXTI_Init(&EXTI_InitStructure);
	
	//开启EXTI中断
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;   //较为重要，分配为首要优先级
	
	NVIC_Init(&NVIC_InitStruct);
}
/*
	@简介：右二编码器初始化
*/
static void Encoder_r2_Init()
{
	//初始化IO引脚
	//PC2  PC3  - IPU
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
	
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	//EXTI初始化
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource2);
	
	//EXTI参数配置
	EXTI_InitTypeDef EXTI_InitStructure = {0};
	EXTI_InitStructure.EXTI_Line = EXTI_Line2;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
	
	EXTI_Init(&EXTI_InitStructure);
	
	//开启EXTI中断
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel = EXTI2_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;   //较为重要，分配为首要优先级
	
	NVIC_Init(&NVIC_InitStruct);
}

/*
	@简介：EXTI_Line3的中断响应函数   左一编码器A相
*/
void EXTI3_IRQHandler(void)
{
	EXTI_ClearFlag(EXTI_Line3);//中断标志位清零
	
	uint8_t a = GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_3);  //A相
	uint8_t b = GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_2);  //B相
	
	if (a == Bit_SET)  //上升沿
	{
		if (b == Bit_RESET)
		{
			encoder_l1++;
		}
		else
		{
			encoder_l1--;
		}
	}
	else               //下降沿
	{
		if (b == Bit_RESET)
		{
			encoder_l1--;
		}
		else
		{
			encoder_l1++;
		}	
	}
}
/*
	@简介：EXTI_Line4的中断响应函数   左二编码器A相
*/
void EXTI4_IRQHandler(void)
{
	EXTI_ClearFlag(EXTI_Line4);//中断标志位清零
	
	uint8_t a = GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4);  //A相
	uint8_t b = GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3);  //B相
	
	if (a == Bit_SET)  //上升沿
	{
		if (b == Bit_RESET)
		{
			encoder_l2++;
		}
		else
		{
			encoder_l2--;
		}
	}
	else               //下降沿
	{
		if (b == Bit_RESET)
		{
			encoder_l2--;
		}
		else
		{
			encoder_l2++;
		}	
	}
}
/*
	@简介：EXTI_Line0的中断响应函数   右一编码器A相
*/
void EXTI0_IRQHandler(void)
{
	EXTI_ClearFlag(EXTI_Line0);//中断标志位清零
	
	uint8_t a = GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_0);  //A相
	uint8_t b = GPIO_ReadInputDataBit(GPIOG,GPIO_Pin_1);  //B相
	
	if (a == Bit_SET)  //上升沿
	{
		if (b == Bit_RESET)
		{
			encoder_r1++;
		}
		else
		{
			encoder_r1--;
		}
	}
	else               //下降沿
	{
		if (b == Bit_RESET)
		{
			encoder_r1--;
		}
		else
		{
			encoder_r1++;
		}	
	}
}
/*
	@简介：EXTI_Line2的中断响应函数   右二编码器A相
*/
void EXTI2_IRQHandler(void)
{
	EXTI_ClearFlag(EXTI_Line2);//中断标志位清零
	
	uint8_t a = GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_2);  //A相
	uint8_t b = GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_3);  //B相
	
	if (a == Bit_SET)  //上升沿
	{
		if (b == Bit_RESET)
		{
			encoder_r2++;
		}
		else
		{
			encoder_r2--;
		}
	}
	else               //下降沿
	{
		if (b == Bit_RESET)
		{
			encoder_r2--;
		}
		else
		{
			encoder_r2++;
		}	
	}
}
