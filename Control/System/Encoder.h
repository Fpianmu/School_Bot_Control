#ifndef __Encoder_H
#define __Encoder_H

#include "stm32f10x.h"                  // Device header

int64_t Encoder_GetPos_l1(void);
int64_t Encoder_GetPos_l2(void);
int64_t Encoder_GetPos_r1(void);
int64_t Encoder_GetPos_r2(void);
void Encoder_Init(void);

#endif
