/*
 * T0_Program.c
 *
 *  Created on: Oct 7, 2026
 *      Author: oa000
 */

#include "../../Common/Config.h"
#if Timer2_Driver

#include "T2_Interface.h"


#if T2_Normal
static  void (*NormalPF)(void) = NULL;
static T2_PreloadValue = T2_InitPreloadValue;
void T2_NormalInit()
{
	/*
	 * TCCR2
	 *! 1. Wave Generation Mode as Normal Mode
	 *! 2.Select Output Compare Match Disconnect
	 *! 3.Clock Select -> Prescaller
	 * */

	TCCR2_Reg = T2_NormalMode|OC2_Disconnect|T2_ClockSelect ;
	 // TCNT -> InialValue Preload
	    TCNT2_Reg = T2_InitPreloadValue;
	    // TIMSK -> Enable for OVF Interrupt
	    SetBit(TIMSK_Reg,TOIE2);
	}
	void T2_SetPreLoad(uint8_t PreloadValue)
	{
	     TCNT2_Reg = PreloadValue;
	     T2_PreloadValue = PreloadValue;
	}
	void T2_NormalCallBack(void(*PF)(void))
	{
	    if(PF!=NULL)
	    {
	        NormalPF=PF;
	    }
	}
	void __vector_5(void) __attribute__((signal));
	void __vector_5(void)
	{
	    static uint32_t count =  0 ;
	    count++;
	    if(count==T2_NoOfOVFCount)
	    {
	        // Action
	        if(NormalPF!=NULL)
	        {
	            NormalPF();
	        }
	        // Clear Count
	        count = 0 ;
	        // Update Preload
	        TCNT2_Reg = T2_PreloadValue;
	    }
	}
#endif

#if T2_CTC
static void(*CTCPF)(void)= Null;
static T2_CompareValue = T2_InitComapareValue;
void T2_CTCInit()
{
	/*
	* TCCR0
	*! 1. Wave Generation Mode as CTC MOde
	*! 2.Select Output Compare Match Action
	*! 3.Clock Select -> Prescaller
	* */
	TCCR2_Reg = T2_CTCMode|T2_CTCAction|T2_ClockSelect;
	// OCR0 -> Inial Compare Value
	OCR2_Reg = T2_InitComapareValue;
	// Enable Interrpt for CTC
	SetBit(TIMSK_Reg,OCIE2);
}
void T2_SetCompareValue(uint8_t CompareValue)
{
	OCR2_Reg=CompareValue;
	T2_CompareValue =CompareValue;
}
void T2_CTCCallBack(void (*PF)(void))
{
	if(PF!=Null)
	{
		CTCPF=PF;
	}
}
void __vector_4(void) __attribute__((signal));
void __vector_4(void)
{
	static uint32_t Count =0;
	Count++;
	//Action
	if(CTCPF!=NULL)
	{
		CTCPF();
	}
	//Clear Count
	Count=0;
	//Update Compare Value
	OCR2_Reg= T2_InitComapareValue;
}
#endif

#if T2_PWM
void T2_PwmInit()
{
	/*
	 * ! 1. Select PWM Mode
	 * ! 2. Select Acton (Inverting / Non-Inverting)
	 * ! 3. Clock Select
	 * */
	TCCR2_Reg= T2_PWMMode|T2_PWMAction|T2_ClockSelect;
}
void T2_SetDutyCycle(uint8_t DutycyclePre)
{
	if(T2_PWMAction==OC2_NonInverting)
	{
		OCR2_Reg = (256*(uint16_t)DutycyclePre)/100;
	}
	else if(T2_PWMAction==OC2_Inverting)
	{
		//Compare (OCR0) = OVFValue*(1-(DutyCycle/100))
		//Compare (OCR0) = OVFValue - OVFValue*(DutyCycle/100)
		OCR2_Reg= 256 - (256*(uint16_t)DutycyclePre)/100;
	}
}
#endif


#endif
