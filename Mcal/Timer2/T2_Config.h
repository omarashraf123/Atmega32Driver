/*
 * T0_Config.h
 *
 *  Created on: Oct 7, 2026
 *      Author: oa000
 */

#ifndef MCAL_TIMER2_T2_CONFIG_H_
#define MCAL_TIMER2_T2_CONFIG_H_
#include "../../Common/Config.h"
#include "T2_Private.h"
#if Timer2_Driver
/*
	T2_Disable
	T2_NoPrescaller
	T2_Prescaller_8
	T2_Prescaller_32
	T2_Prescaller_64
	T2_Prescaller_128
	T2_Prescaller_256
	T2_Prescaller_1024
 * */
#define T2_ClockSelect      T2_Prescaller_64

#if T2_Normal
	#define T2_InitPreloadValue   44
	#define T2_NoOfOVFCount		  49
#endif
#if T2_CTC
	#define T2_InitComapareValue  150
//	1-OC2_Disconnect
//	2-OC2_Toggle
//	3-OC2_Clear
//	4-OC2_Set
	#define T2_CTCAction     OC2_Set
	#define T2_NoOfCTCCount   50
#endif
#if T2_PWM
	/*
	 *! 1- T2_PWMFast
	 *! 1- T2_PWMPhase
	 * */
	#define T2_PWMMode  T2_PWMFast
     /*
     //! 1- OC2_NonInverting
     //! 2- OC2_Inverting
     */
    #define T2_PWMAction    OC2_NonInverting

#endif
#endif
#endif /* MCAL_TIMER0_T0_CONFIG_H_ */
