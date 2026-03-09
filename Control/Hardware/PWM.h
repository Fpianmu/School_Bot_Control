#ifndef __PWM_H
#define __PWM_H

void PWM_Init(void);
void PWM_SetCompare1_Servo1(uint16_t Compare);
void PWM_SetCompare2_Servo2(uint16_t Compare);
void PWM_SetCompare1_T3(uint16_t Compare);
void PWM_SetCompare2_T3(uint16_t Compare);
void PWM_SetCompare3_T3(uint16_t Compare);
void PWM_SetCompare4_T3(uint16_t Compare);

#endif
