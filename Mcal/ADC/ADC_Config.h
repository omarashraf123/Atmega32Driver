/*
 * ADC_Config.h
 *
 *  Created on: Sep 25, 2026
 *      Author: oa000
 */

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_
#include "../../Common/Config.h"
#include "ADC_Private.h"
#if ADC_Driver
/*
 * Adc_Disable
 * Adc_Enable
*/
#define Adc_InitState   Adc_Enable
/*
 	* Adc_Aref
	*Adc_Avcc
	*Adc_Internal
 * */
#define Adc_VrefSelection Adc_Internal

/*
 * Adc_RightAdjust
 * Adc_LeftAdjust
 * */
#define Adc_AdjustSelection  Adc_LeftAdjust
/*
 *Adc_DivisionFactor2,
 *Adc_DivisionFactor2,
 *Adc_DivisionFactor4,
 *Adc_DivisionFactor8,
 *Adc_DivisionFactor16,
 *Adc_DivisionFactor32,
 *Adc_DivisionFactor64,
 *Adc_DivisionFactor128,
 * */
#define Adc_DivisionFactorSelection    Adc_DivisionFactor8
/*
 * Adc_SingleMode
 * Adc_AutoMode
 * */
#define Adc_ModeSelect   Adc_SingleMode

#if Adc_Mode == Adc_AutoMode
/*
 * 		Adc_FreeRunning
 * 		Adc_AnalogComparator
 * 		Adc_EXTI0
 * 		Adc_CTC0
 * 		Adc_OVF0
 * 		Adc_CTC1
 * 		Adc_OVF1
 * 		Adc_ICU1
 * 				*/
#define Adc_TriggerSource Adc_FreeRunning
#endif
/*
 * Adc_InterruptDisable
 * Adc_InterruptEnable
 * */
#define Adc_InterruptState  Adc_InterruptEnable
#endif
#endif /* MCAL_ADC_ADC_CONFIG_H_ */
