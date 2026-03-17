#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "ps2.h"
#include "Servo.h"
#include "Motor.h"
#include "Encoder.h"


const float cosa = 0.707;
const float cosb = 0.707;
const float l = 0.2;
unsigned char Key_Pressed = 0;   //手柄按键是否按下的判断
unsigned char mode = PSB_LOSE;  //手柄模式
unsigned char lx,ly,rx,ry;  //两个摇杆的x,y方向数值记录
int vx,vy,w;
int va,vb,vc,vd;

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
	
	Servo_SetAngle_S1(105);
	Servo_SetAngle_S2(40);
	while(1)
	{
		PS2_ReadData();  //读取摇杆
		mode = ps2_mode_get();  //读取模式
		ps2_key_serch();   //读取按键
		/*
			进入运动模式
		*/
		if (mode == PSB_REDLIGHT_MODE)
		{
			
			lx = ps2_get_anolog_data(PSS_LX);
			ly = ps2_get_anolog_data(PSS_LY);
			rx = ps2_get_anolog_data(PSS_RX);
			ry = ps2_get_anolog_data(PSS_RY);
			
			vy = ( -(lx - 128) *100)/ 128;
			vx = ( (ly - 128) *100)/ 128;
			w =  ( (rx - 128) *100)/ 128;
			
			va = + vx * cosb + vy * cosa + w*l ;
			vb = + vx * cosb - vy * cosa + w*l ;
			vc = - vx * cosb + vy * cosa + w*l ;
			vd = - vx * cosb - vy * cosa + w*l ;
			
			OLED_ShowSignedNum(10,5,va,5);
			OLED_ShowSignedNum(11,5,vb,5);
			OLED_ShowSignedNum(12,5,vc,5);
			OLED_ShowSignedNum(13,5,vd,5);
			
			Move_L1(va);
			Move_L2(vb);
			Move_R1(vc);
			Move_R2(vd);
			
			if (ps2_get_key_state(PSB_L1))
			{
				Servo_SetAngle_S1(130);
				Servo_SetAngle_S2(0);
			}
			if (ps2_get_key_state(PSB_L2))
			{
				Servo_SetAngle_S1(105);
				Servo_SetAngle_S2(140);
			}
		}
//		Move_L1(40);
//		Move_L2(40);
//		Move_R1(40);
//		Move_R2(40);
		Delay_ms(20);
	}
	
}





//// TIM2中断服务函数
//void TIM2_IRQHandler(void)
//{
//    // 检查是否为更新中断
//    if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET)
//    {
//        // 清除中断标志位
//        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
//        // 增加计数
//        //time_count++;
//    }
//}
