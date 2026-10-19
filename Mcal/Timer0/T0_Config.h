/*
 * T0_Config.h
 *
 *  Created on: Oct 7, 2026
 *      Author: oa000
 */

#ifndef MCAL_TIMER0_T0_CONFIG_H_
#define MCAL_TIMER0_T0_CONFIG_H_
#include "../../Common/Config.h"
#include "T0_Private.h"
#if Timer0_Driver
/*
 *  T0_Disable
	T0_NoPrescaller
	T0_Prescaller_8
	T0_Prescaller_64
	T0_Prescaller_256
	T0_Prescaller_1024
	T0_ExternalFalling
	T0_ExternalRising
 * */
#define T0_ClockSelect      T0_Prescaller_64

#if T0_Normal
	#define T0_InitPreloadValue   44
	#define T0_NoOfOVFCount		  49
#endif
#if T0_CTC
	#define T0_InitComapareValue  150
//	1-OC0_Disconnect
//	2-OC0_Toggle
//	3-OC0_Clear
//	4-OC0_Set
	#define T0_CTCAction     OC0_Set
	#define T0_NoOfCTCCount   50
#endif
#if T0_PWM
	/*
	 *! 1- T0_PWMFast
	 *! 2- T0_PWMPhase
	 * */
	#define T0_PWMMode  T0_PWMFast
     /*
     //! 1- OC0_NonInverting
     //! 2- OC0_Inverting
     */
    #define T0_PWMAction    OC0_NonInverting

#endif
#endif
#endif /* MCAL_TIMER0_T0_CONFIG_H_ */
