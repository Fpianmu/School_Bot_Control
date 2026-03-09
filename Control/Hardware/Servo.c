#include "stm32f10x.h"                  // Device header
#include "PWM.h"

void Servo_SetAngle_S1(float Angle)
{
	PWM_SetCompare1_Servo1(Angle * 2000 / 180+ 500);
}
void Servo_SetAngle_S2(float Angle)
{
	PWM_SetCompare2_Servo2(Angle * 2000 / 180+ 500);
}
