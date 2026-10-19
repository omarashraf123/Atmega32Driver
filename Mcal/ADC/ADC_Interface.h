/*
 * ADC_Interface.h
 *
 *  Created on: Sep 25, 2026
 *      Author: oa000
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

#include "../../Common/Bitmath.h"
#include "../../Common/Defintion.h"
#include "../../Common/Config.h"
#include "../Atemga32Reg.h"

#include "ADC_Private.h"
#include "ADC_Config.h"

#if ADC_Driver

/*Initialization*/
void ADC_Init();
void ADC_DeInit();
/*Control*/
void ADC_Enable();
void ADC_Disable();
void ADC_EnableInterrupt();
void ADC_DisableInterrupt();
/*Polling*/
uint8_t ADC_Read(uint8_t Channel,uint16_t *DigitalValue,uint32_t MaxTimeOut);
/*Interrupt*/

uint8_t ADC_StartConversion(uint8_t Channel);
uint8_t ADC_SetCallBack(void(*ADC_PF)(uint16_t Result));

static void ADC_SelectChannel(uint8_t Channel);
uint8_t ADC_GetStatus();


#endif
#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
