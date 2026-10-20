/*
 * T1_Program.c
 *
 *  Created on: Oct 9, 2026
 *      Author: oa000
 */
#include "T1_Interface.h"
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

	#if T1_ICU_EdgeSelect==T1_ICU_Trigger_Falling
		SetBit(TCCR1B_Reg,ICNC1);
		ClearBit(TCCR1B_Reg,ICES1);
	#endif

	#if T1_ICU_EdgeSelect==T1_ICU_Trigger_Rising
	SetBit(TCCR1B_Reg,ICES1);
	SetBit(TCCR1B_Reg,ICNC1);
	#endif

void T1_PWMInit()
{
	// !!!  Pesodo code
	//! 1. Set Mode 14
	//! 2. Action (Inverting || Non-Inverting)
	//! 3. Channel
	//! 4. TopValue
	//! 5. Clock Select
	TCCR1A_Reg= (TCCR1A_Reg&~T1_OCR1AModeMask)|(T1_FastPWMMode_ICR1&T1_OCR1BModeMask);
	TCCR1B_Reg = (TCCR1B_Reg&~T1_OCR1BModeMask)|(T1_FastPWMMode_ICR1&(T1_OCR1AModeMask<<1));
	TCCR1B_Reg = (TCCR1B_Reg&~T1_PrescallerMask)|(T1_ClockSelect);
#if  ChannelSelect == T1_CompareOutput_A

	// Set Action
	TCCR1A_Reg = (TCCR1A_Reg&~T1_ActionMask)|(T1_PWMAction&T1_OCR1B_ActionMask);
	//TCCR1B_Reg = (TCCR1B_Reg&~)
	//Set top Value
	T1_SetTopVAlue();
#endif // ChannelSelect == T1_CompareOutput_A
#if  ChannelSelect == T1_CompareOutput_B
	TCCR1A_Reg = (TCCR1A_Reg&~T1_ActionMask)|(T1_PWMAction&T1_OCR1A_ActionMask);
#endif //ChannelSelect == T1_CompareOutput_B
#if  ChannelSelect == T1_TwoCompareOutput
	TCCR1A_Reg = (TCCR1A_Reg&~T1_ActionMask)|(T1_PWMAction);
#endif //ChannelSelect == T1_TwoCompareOutput

}
	uint32_t TopValue   = NULL;
	uint32_t Freq_Value = NULL;
void T1_SetFreq(uint32_t Freq_Hz)
{
	Freq_Value = Freq_Hz;
}
void T1_SetTopVAlue()
{
	TopValue = (CPU_Freq/(T1_ClockSelect*Freq_Value))-1;
}
void T1_InterruptEnable()
{
#if ChannelSelect == T1_CompareOutput_A
	SetBit(TIMSK_Reg,OCIE1A);
#endif

#if ChannelSelect == T1_CompareOutput_B
	SetBit(TIMSK_Reg,OCIE1B);
#endif

#if ChannelSelect == T1_TwoCompareOutput
	SetBit(TIMSK_Reg,OCIE1A);
	SetBit(TIMSK_Reg,OCIE1B);
#endif
}
void T1_InterruptDisable()
{
#if ChannelSelect == T1_CompareOutput_A
	ClearBit(TIMSK_Reg,OCIE1A);
#endif

#if ChannelSelect == T1_CompareOutput_B
	ClearBit(TIMSK_Reg,OCIE1B);
#endif

#if ChannelSelect == T1_TwoCompareOutput
	ClearBit(TIMSK_Reg,OCIE1B);
#endif
}

void __vector_6(void) //   ICU (ISR)
{
	uint8_t Count =0 ;
	Count++;
	if(Count== 1)
	{
		TCNT1L_Reg = 0;
	}
	if(Count ==2)
	{
		TCNT1L_Reg = ICR1L_Reg;
	}
	if(Count==3)
	{
		TCNT1L_Reg = ICR1L_Reg;
		TCNT1L_Reg = 0;
		Count=0;
	}

}
void __vector_7(void)//   COMPA
{

}
void __vector_8(void)//	 COMPB
{

}
void __vector_9(void)//	 OVF
{

}

#endif //T1_FastPWM_ICR1

#if T1_FastPWM_OCR1A

#endif // T1_FastPWM_OCR1A


#endif

