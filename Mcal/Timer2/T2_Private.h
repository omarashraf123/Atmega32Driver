/*
 * T0_Private.h
 *
 *  Created on: Oct 7, 2026
 *      Author: oa000
 */

#ifndef MCAL_TIMER2_T2_PRIVATE_H_
#define MCAL_TIMER2_T2_PRIVATE_H_
#include "../../Common/Config.h"
#if Timer2_Driver
typedef enum
{
	/*TCCR2*/
	CS20  ,
	CS21  ,
	CS22  ,
	WGM21 ,
	COM20 ,
	COM21 ,
	WGM20 ,
	FOC2  ,
	/*TIMSK*/
	TOIE2=6,
	OCIE2 ,
	/*TIFR*/
	TOV2=6,
	OCF2 ,
}T2_BitName_t;
/*
 * 7 6 5 4 3 2 1 0
 * 0 0 0 0 0 0 0 0
 * 0 0 0 1 0 0 0 0
 * 0 0 1 0 0 0 0 0
 * 0 0 1 1 0 0 0 0
 * */
typedef enum
{	/*Non-PWM*/
	OC2_Disconnect= 0x00,
	OC2_Toggle= 0x10,
	OC2_Clear= 0x20,
	OC2_Set= 0x30,
	/*PWM Actions*/
	OC2_NonInverting = 0x20,
	OC2_Inverting = 0x30,
}T2_OutputCompare_t;


typedef enum
{
	T2_Disable 			,
	T2_NoPrescaller   ,
	T2_Prescaller_8    ,
	T2_Prescaller_32      ,
	T2_Prescaller_64     ,
	T2_Prescaller_128       ,
	T2_Prescaller_256    ,
	T2_Prescaller_1024  ,
}T2_ClockSelect_t;
/*
 * 7 6 5 4 3 2 1 0
 * 0 0 0 0 0 0 0 0
 * 0 1 0 0 0 0 0 0
 * 0 0 0 0 1 0 0 0
 * 0 1 0 0 1 0 0 0
 * */

typedef enum
{
	T2_NormalMode = 0x00,
	T2_PWMPhase = 0x40,
	T2_CTCMode= 0x08,
	T2_PWMFast = 0x48,
}T2_TimerMode_t;


typedef enum
{
	T2_TOVInterrptDisable = 0x00,
	T2_TOVInterrptEnable = 0x40,
	T2_OCMInterrptDisable = 0x00,
	T2_OCMInterrptEnable= 0x80,
}T2_InterrptState_t;

#endif



#endif /* MCAL_TIMER0_T0_PRIVATE_H_ */
