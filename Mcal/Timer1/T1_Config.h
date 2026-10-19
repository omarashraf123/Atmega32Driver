/*
 * T1_Config.h
 *
 *  Created on: Oct 9, 2026
 *      Author: oa000
 */

#ifndef MCAL_TIMER1_T1_CONFIG_H_
#define MCAL_TIMER1_T1_CONFIG_H_
#include "../../Common/Config.h"
#include "T1_Private.h"

#if Timer1_Driver
/*
 * T1_Disable
 * T1_NoPrescaller
 * T1_Prescaller_8
 * T1_Prescaller_64
 * T1_Prescaller_256
 * T1_Prescaller_1024
 * T1_ExternalFalling
 * T1_ExternalRising
 * */
#define T1_ClockSelect  T1_Prescaller_64

#define CPU_Freq    8000000UL

#if T1_NormalMode

#endif // T1_NormalMode

#if T1_PWMPhaseCorrectMode_8Bit

#endif //T1_PWMPhaseCorrectMode_8Bit

#if T1_PWMPhaseCorrectMode_9Bit

#endif //T1_PWMPhaseCorrectMode_9Bit

#if T1_PWMPhaseCorrectMode_10Bit

#endif //T1_PWMPhaseCorrectMode_10Bit

#if T1_CTCMode_OCR1A

#endif //T1_CTCMode_OCR1A

#if T1_FastPWM_8Bit

#endif // T1_FastPWM_8Bit

#if T1_FastPWM_9Bit

#endif //T1_FastPWM_9Bit

#if T1_FastPWM_10Bit

#endif //T1_FastPWM_10Bit

#if T1_PWMFreqCorrect_ICR1

#endif //T1_PWMFreqCorrect_ICR1

#if T1_PWMFreqCorrect_OCR1A

#endif //T1_PWMFreqCorrect_OCR1A

#if T1_PWMPhaseCorrect_ICR1

#endif

#if T1_PWMPhaseCorrect_OCR1A

#endif //T1_PWMPhaseCorrect_OCR1A

#if T1_CTCMode_ICR1

#endif //T1_CTCMode_ICR1

#if T1_FastPWM_ICR1
/*
 * T1_ICU_Trigger_Falling
 * T1_ICU_Trigger_Rising
 * */
#define ICU_EdgeSelect


/*
 * T1_CompareOutput_A
 * T1_CompareOutput_B
 * T1_TwoCompareOutput
 * */
#define ChannelSelect  T1_CompareOutput_A

#if ChannelSelect == T1_CompareOutput_A
/*
 *  *  ! 1.Fast PWM Actions OC1A
 *  * OC1A_Disable
 *  * OC1A_NonInvetrting    // 1. Clear -> 2. Set
 *  * OC1A_Invetrting       // 1. Set -> 2. Clear
 * */
	#define T1_ModeMask  T1_OCR1AModeMask
	#define T1_ActionMask T1_OCR1A_ActionMask
	#define T1_PWMAction   OC1A_NonInvetrting
#endif // T1_CompareOutput_A

#if ChannelSelect == T1_CompareOutput_B
/*
 *  *  ! 1.Fast PWM Actions OC1B
 *  * OC1B_Disable
 *  * OC1B_NonInvetrting    // 1. Clear -> 2. Set
 *  * OC1B_Invetrting       // 1. Set -> 2. Clear
 * */
	#define T1_ModeMask  T1_OCR1BModeMask
	#define T1_ActionMask T1_OCR1B_ActionMask
	#define T1_PWMAction   OC1B_NonInvetrting
#endif // T1_CompareOutput_B

#if ChannelSelect == T1_TwoCompareOutput

/*
 *  *  *  ! 1.Fast PWM Actions ->T1_TwoCompareOutput
 *  * T1_CompareOutput_Inverting
 *  * T1_CompareOutput_NonInverting
 *  * T1_OC1AInverting_OC1BNonInverting
 *  * T1_OC1ANonInverting_OC1BInverting
 * */
	#define T1_ActionMask T1_TwoOCR_ActionMask
	#define T1_PWMAction   T1_CompareOutput_Inverting


#endif // T1_TwoCompareOutput

#endif //T1_FastPWM_ICR1

#if T1_FastPWM_OCR1A

#endif // T1_FastPWM_OCR1A

#endif // Timer1_Driver


#endif /* MCAL_TIMER1_T1_CONFIG_H_ */
