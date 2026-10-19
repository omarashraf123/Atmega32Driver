/*
 * T0_Program.c
 *
 *  Created on: Oct 7, 2026
 *      Author: oa000
 */

#include "../../Common/Config.h"
#if Timer0_Driver

#include "T0_Interface.h"


#if T0_Normal
static  void (*NormalPF)(void) = NULL;
static T0_PreloadValue = T0_InitPreloadValue;
void T0_NormalInit()
{
	/*
	 * TCCR0
	 *! 1. Wave Generation Mode as Normal Mode
	 *! 2.Select Output Compare Match Disconnect
	 *! 3.Clock Select -> Prescaller
	 * */

	TCCR0_Reg = T0_NormalMode|OC0_Disconnect|T0_ClockSelect ;
	 // TCNT -> InialValue Preload
	    TCNT0_Reg = T0_InitPreloadValue;
	    // TIMSK -> Enable for OVF Interrupt
	    SetBit(TIMSK_Reg,TOIE0);
	}
	void T0_SetPreLoad(uint8_t PreloadValue)
	{
	     TCNT0_Reg = PreloadValue;
	     T0_PreloadValue = PreloadValue;
	}
	void T0_NormalCallBack(void(*PF)(void))
	{
	    if(PF!=NULL)
	    {
	        NormalPF=PF;
	    }
	}
	void __vector_11(void) __attribute__((signal));
	void __vector_11(void)
	{
	    static uint32_t count =  0 ;
	    count++;
	    if(count==T0_NoOfOVFCount)
	    {
	        // Action
	        if(NormalPF!=NULL)
	        {
	            NormalPF();
	        }
	        // Clear Count
	        count = 0 ;
	        // Update Preload
	        TCNT0_Reg = T0_PreloadValue;
	    }
	}
#endif

#if T0_CTC
static void(*CTCPF)(void)= Null;
static T0_CompareValue = T0_InitComapareValue;
void T0_CTCInit()
{

	// OCR0 -> Inial Compare Value
	OCR0_Reg = T0_InitComapareValue;
	// Enable Interrpt for CTC
	SetBit(TIMSK_Reg,OCIE0);
	/*
	* TCCR0
	*! 1. Wave Generation Mode as CTC MOde
	*! 2.Select Output Compare Match Action
	*! 3.Clock Select -> Prescaller
	* */
	TCCR0_Reg = T0_CTCMode|T0_CTCAction|T0_ClockSelect;

}
void T0_SetCompareValue(uint8_t CompareValue)
{
	OCR0_Reg=CompareValue;
	T0_CompareValue =CompareValue;
}
void T0_CTCCallBack(void (*PF)(void))
{
	if(PF!=Null)
	{
		CTCPF=PF;
	}
}
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	static uint32_t Count =0;
	Count++;
	if(Count==T0_NoOfCTCCount)
	{
		//Action
		if(CTCPF!=NULL)
		{
			CTCPF();
		}
		//Clear Count
		Count=0;
		//Update Compare Value
		OCR0_Reg= T0_InitComapareValue;
	}
}
#endif

#if T0_PWM
void T0_PWMInit()
{
	/*
	 * //! 1. Select PWM Mode
	 * //! 2. Select Acton (Inverting / Non-Inverting)
	 * //! 3. Clock Select
	 * */
	TCCR0_Reg = T0_PWMMode|T0_PWMAction|T0_ClockSelect;
}
void T0_SetDutyCycle(uint8_t DutycyclePre)
{
	if(DutycyclePre<=100)
	{
		if(T0_PWMAction==OC0_NonInverting)
		{
		//Compare Value = OVF*DutyCycle/100 -> Inverting
		OCR0_Reg = (255*(uint16_t)DutycyclePre)/100;
		}
		else if(T0_PWMAction==OC0_Inverting)
		{
			//Compare Value = (OVFValue - OVFValue*(DutyCycle/100);-> NonInverting
			OCR0_Reg= (255 - (255*(uint16_t)DutycyclePre)/100);
		}
	}
}
#endif

#endif
