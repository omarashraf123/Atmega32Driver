/*
 * T0_Interface.h
 *
 *  Created on: Oct 7, 2026
 *      Author: oa000
 */

#ifndef MCAL_TIMER0_T0_INTERFACE_H_
#define MCAL_TIMER0_T0_INTERFACE_H_

#include "../../Common/Bitmath.h"
#include "../../Common/Defintion.h"
#include "../../Common/Config.h"

#include "../Atemga32Reg.h"

#include "T0_Private.h"
#include "T0_Config.h"
#if Timer0_Driver

#if T0_Normal
void T0_NormalInit();
void T0_SetPreLoad(uint8_t PreloadValue);
void NormalCallBack(void(*PF)(void));
#endif

#if T0_CTC
void T0_CTCInit();
void T0_SetCompareValue(uint8_t CompareValue);
void T0_CTCCallBack(void (*PF)(void));
#endif

#if T0_PWM
void T0_PWMInit();
void T0_SetDutyCycle(uint8_t DutycyclePre);
#endif

#endif

#endif /* MCAL_TIMER0_T0_INTERFACE_H_ */
