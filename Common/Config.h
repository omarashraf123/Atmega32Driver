/*
 * Config.h
 *
 *  Created on: Oct 9, 2026
 *      Author: oa000
 */

#ifndef COMMON_CONFIG_H_
#define COMMON_CONFIG_H_

#include "Defintion.h"

#ifndef F_CPU
#define F_CPU 8000000UL
#endif// _COMMON_CONFIG_H
/*MCAL*/
/* Driver Switches Used By The Current Project. */
#define ADC_Driver             Enable
#define DIO_Driver             Enable
#define EXTI_Driver            Enable
#define GIE_Driver             Enable
#define InternalEEPROM         Enable
#define SPI_Driver             Enable
#define Timer0_Driver          Enable
#define Timer1_Driver          Enable
#define Timer2_Driver          Enable
#define TWI_Driver             Enable
#define Usart_Driver           Enable

/*Hal*/
#define Button_Driver    	 Enable
#define Buzzer_Driver    	 Enable
#define DcMotor_Driver    	 Enable
#define Kpd_Driver        	 Enable
#define Lcd_Driver        	 Enable
#define Led_Driver        	 Enable
#define SevSeg_Driver  		 Enable
#define Servo_Driver	  	 Enable

#if Timer0_Driver
#define T0_Normal   Disable
#define T0_CTC      Disable
#define T0_PWM		Enable
#endif

#if Timer1_Driver

#define T1_Normal 	                  Disable
#define T1_PWMPhaseCorrect_8Bit       Disable
#define T1_PWMPhaseCorrect_9Bit       Disable
#define T1_PWMPhaseCorrect_10Bit      Disable
#define T1_CTC_OCR1A                  Disable  // The Top -> OCR1A
#define T1_FastPWM_8Bit               Disable
#define T1_FastPWM_9Bit               Disable
#define T1_FastPWM_10Bit              Disable
#define T1_PWMFreqCorrect_ICR1        Disable  // The Top -> Input Capture Reg
#define T1_PWMFreqCorrect_OCR1A       Disable  // The Top -> OCR1A
#define T1_PWMPhaseCorrect_ICR1       Disable  // The Top -> Input Capture Reg
#define T1_PWMPhaseCorrect_OCR1A      Disable  // The Top -> OCR1A
#define T1_CTC_ICR1		              Disable  // The Top -> Input Capture Reg
#define T1_FastPWM_ICR1               Enable  // The Top -> Input Capture Reg
#define T1_FastPWM_OCR1A	          Disable  // The Top -> OCR1A

#endif



#if Timer2_Driver
#define T2_Normal   Enable
#define T2_CTC      Enable
#define T2_PWM		Enable
#endif



#endif /* COMMON_CONFIG_H_ */
