/*
 * main.c
 *
 * Description: 3x3 Keypad controlling 8 LEDs with different animations
 */

#include <util/delay.h>
#include "Mcal/DIO/DIO_Interface.h"
#include "Hal/DCMotor/DCMotor_Interface.h"
#include "Hal/LCD/LCD_Interface.h"
#include "Hal/LED/Led_Interface.h"
#include "Hal/KPD/KPD_Interface.h"
#include "Hal/Buzzer/Buzzer_Interface.h"
#include "Hal/SevSeg/SevSeg_Interface.h"
#include "Mcal/EXTI/EXTI_Interface.h"
#include "Mcal/GIE/GIE_Interface.h"
#include "Mcal/Timer0/T0_Interface.h"
#include "Mcal/Timer1/T1_Interface.h"
#include "Mcal/Timer2/T2_Interface.h"
void main()
{
//	Led_Init(DIO_GroupB,DIO_Pin3);
//	T0_PWMInit();
	LCD_Init();
	//uint8_t LightIntensity = 0;
	LCD_WriteString("Hello World");
	while (1);
//	{

//		for(LightIntensity=0;LightIntensity<=100;LightIntensity++)
//		{
//			T0_SetDutyCycle(LightIntensity);
//			_delay_ms(50);
//		}
//		for(LightIntensity=100;LightIntensity>0;LightIntensity--)
//		{
//			T0_SetDutyCycle(LightIntensity);
//			_delay_ms(50);
//		}
//	}
//	}
}











