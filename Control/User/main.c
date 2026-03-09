#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "ps2.h"
#include "Servo.h"
#include "Motor.h"
#include "Encoder.h"

unsigned char Key_Pressed = 0;   //手柄按键是否按下的判断
unsigned char mode = PSB_LOSE;  //手柄模式
unsigned char lx,ly,rx,ry;  //两个摇杆的x,y方向数值记录

void System_Init()
{
	//取消抢占优先级  分为16级子优先级
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
	//手柄初始化
	PS2_Init();   
	
	//电机，舵机初始化
	Engine_Init(); 
	
	//OLED屏幕初始化
	OLED_Init();
	OLED_Clear();
	
	//编码器初始化
	Encoder_Init();
}
int main(void)
{
	System_Init();
	while(1)
	{
		
	}
	
}





// TIM2中断服务函数
void TIM2_IRQHandler(void)
{
    // 检查是否为更新中断
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
    {
        // 清除中断标志位
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
        // 增加计数
        //time_count++;
    }
}
