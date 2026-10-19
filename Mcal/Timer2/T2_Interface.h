/*
 * T0_Interface.h
 *
 *  Created on: Oct 7, 2026
 *      Author: oa000
 */

#ifndef MCAL_TIMER2_T2_INTERFACE_H_
#define MCAL_TIMER2_T2_INTERFACE_H_

#include "../../Common/Bitmath.h"
#include "../../Common/Defintion.h"
#include "../../Common/Config.h"

#include "../Atemga32Reg.h"

#include "T2_Config.h"
#include "T2_Private.h"
#if Timer2_Driver

#if T2_Normal
void T2_NormalInit();
void T2_SetPreLoad(uint8_t PreloadValue);
void NormalCallBack(void(*PF)(void));
#endif

#if T2_CTC
void T2_CTCInit();
void T2_SetCompareValue(uint8_t CompareValue);
void T2_CTCCallBack(void (*PF)(void));
#endif

#if T2_PWM
void T2_PwmInit();
void T2_SetDutyCycle(uint8_t DutycyclePre);
#endif

#endif

#endif /* MCAL_TIMER0_T0_INTERFACE_H_ */
