/*
 * EXTI_Interface.h
 *
 *  Created on: Sep 19, 2026
 *      Author: oa000
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_


#include "../Atemga32Reg.h"
#include "../../Common/Bitmath.h"
#include "../../Common/Defintion.h"
#include "../../Common/Config.h"

#include "EXTI_Private.h"
#include "EXTI_Config.h"
#if EXTI_Driver
void EXTI_Init(uint8_t InterruptNumber , uint8_t SensControl);

void EXTI_Enable(uint8_t InterruptNumber);

void EXTI_Disable(uint8_t InterruptNumber);

/*CallBacks*/

void EXTI_CallBackFunction(uint8_t InterruptNumber , void (*PF)(void));


#endif
#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
