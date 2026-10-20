/*
 * T1_Private.h
 *
 *  Created on: Oct 9, 2026
 *      Author: oa000
 */

#ifndef MCAL_TIMER1_T1_PRIVATE_H_
#define MCAL_TIMER1_T1_PRIVATE_H_
#include "../../Common/Config.h"
#include "../Atemga32Reg.h"

#if Timer1_Driver

typedef enum
{
	/*TCCR1A*/
	WGM10,
	WGM11 ,
	FOC1B ,
	FOC1A ,
	COM1B0 ,
	COM1B1 ,
	COM1A0 ,
	COM1A1 ,
	/*TCCR1B*/
	CS10=0,
	CS11 ,
	CS12 ,
	WGM12 ,
	WGM13 ,
	ICES1=6 ,
	ICNC1 ,
	/*TIMSK*/
	TOIE1 =2 ,
	OCIE1B ,
	OCIE1A ,
	TICIE1 ,
	/*TIFR*/
	TOV1 =2,
	OCF1B ,
	OCF1A ,
	ICF1 ,
}T1_BitName_t;
// 7 6 5 4 3 2 1 0
// 0 0 0 0 0 0 0 0
typedef enum
{
	T1_Disable,
	T1_NoPrescaller,
	T1_Prescaller_8,
	T1_Prescaller_64,
	T1_Prescaller_256,
	T1_Prescaller_1024,
	T1_ExternalFalling,
	T1_ExternalRising,
}T1_Clockslect_t;
// 7 6 5 4 3 2 1 0
// 1 0 1 0 0 0 0 0
typedef enum
{
	/*CTC OC1A*/
	OC1A_Disconnected =0x00,
	OC1A_Toggle= 0x40,
	OC1A_Clear= 0x80,
	OC1A_Set = 0xC0,
	/*CTC OC1B*/
	OC1B_Disconnected =0x00,
	OC1B_Toggle= 0x10,
	OC1B_Clear= 0x20,
	OC1B_Set = 0x30,
	/*Fast PWM Actions OC1A*/
	OC1A_Disable = 0x00,
	OC1A_NonInvetrting = 0x80,
	OC1A_Invetrting = 0xC0,
	/*Fast PWM Actions OC1B*/
	OC1B_Disable = 0x00,
	OC1B_NonInvetrting = 0x20,
	OC1B_Invetrting    = 0x30,
	/*Fast PWM Actions -> Two COmpare Output*/
	T1_CompareOutput_Inverting        = 0xF0,
	T1_CompareOutput_NonInverting     = 0xA0,
	T1_OC1AInverting_OC1BNonInverting =0xE0,
	T1_OC1ANonInverting_OC1BInverting =0xB0,
}T1_OutputAction_t;

typedef enum
{
	T1_NormalMode =0x00,
	T1_PWMPhaseCorrectMode_8Bit  =0x01,
	T1_PWMPhaseCorrectMode_9Bit   =0x02,
	T1_PWMPhaseCorrectMode_10Bit  =0x03,
	T1_CTCMode_OCR1A  =0x08,              // The Top -> OCR1A
	T1_FastPWMMode_8Bit =0x09,
	T1_FastPWMMode_9Bit =0x0A,
	T1_FastPWMMode_10Bit =0x0B,
	T1_PWMFreqCorrectMode_ICR1 =0x10,        // The Top -> Input Capture Reg
	T1_PWMFreqCorrectMode_OCR1A =0x11,       // The Top -> OCR1A
	T1_PWMPhaseCorrectMode_ICR1 =0x12,       // The Top -> Input Capture Reg
	T1_PWMPhaseCorrectMode_OCR1A =0x13,      // The Top -> OCR1A
	T1_CTCMode_ICR1 =0x18,		       // The Top -> Input Capture Reg
	T1_FastPWMMode_ICR1  = 0x1A,	       // The Top -> Input Capture Reg
	T1_FastPWMMode_OCR1A =0x1B,		       // The Top -> OCR1A
}T1_TimerMode_t;

typedef enum
{
	T1_ICU_Trigger_Falling,
	T1_ICU_Trigger_Rising ,
}T1_ICU_Edge_t;


typedef enum
{
	T1_CompareOutput_A ,
	T1_CompareOutput_B ,
	T1_TwoCompareOutput,
}T1_ComapreOutput_t;

typedef enum
{
	T1_OCR1AModeMask     =0x03,
	T1_OCR1BModeMask     =0x18,
	T1_OCR1A_ActionMask  = 0xC0,
	T1_OCR1B_ActionMask  = 0x30,
	T1_TwoOCR_ActionMask = 0xF0,
	T1_PrescallerMask    = 0x07,
}T1_MaskValue_t;


void __vector_6(void) __attribute__ ((signal)); //   ICU (ISR)
void __vector_7(void) __attribute__ ((signal)); //   COMPA
void __vector_8(void) __attribute__ ((signal)); //	 COMPB
void __vector_9(void) __attribute__ ((signal)); //	 OVF


#endif /*Timer1_Driver*/



#endif /* MCAL_TIMER1_T1_PRIVATE_H_ */
