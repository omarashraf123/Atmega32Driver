/*
 * T1_Interface.h
 *
 *  Created on: Oct 9, 2026
 *      Author: oa000
 */

#ifndef MCAL_TIMER1_T1_INTERFACE_H_
#define MCAL_TIMER1_T1_INTERFACE_H_

#include "../../Common/Bitmath.h"
#include "../../Common/Defintion.h"
#include "../../Common/Config.h"
#include "../Atemga32Reg.h"

#include "T1_Private.h"
#include "T1_Config.h"

#if Timer1_Driver
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

void T1_PWMInit();
void T1_SetFreq(uint32_t Freq_Hz);

void T1_SetTopVAlue();


#endif //T1_FastPWM_ICR1

#if T1_FastPWM_OCR1A

#endif // T1_FastPWM_OCR1A



#endif



#endif /* MCAL_TIMER1_T1_INTERFACE_H_ */
