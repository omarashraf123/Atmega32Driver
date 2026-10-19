/*
 * Buzzer_Program.c
 *
 *  Created on: Sep 3, 2026
 *      Author: oa000
 */


#include "Buzzer_Interface.h"



void Buzzer_init(uint8_t BuzzerGroup,uint8_t BuzzerPin)
{
	DIO_DirectionSelectForPin(BuzzerGroup,BuzzerPin,DIO_Output);
}

void Buzzer_on(uint8_t BuzzerGroup,uint8_t BuzzerPin)
{
	DIO_WriteForPin(BuzzerGroup,BuzzerPin,DIO_High);
}

void Buzzer_off(uint8_t BuzzerGroup,uint8_t BuzzerPin)
{
	DIO_WriteForPin(BuzzerGroup,BuzzerPin,DIO_Low);
}

void Buzzer_Tone(uint8_t BuzzerGroup,uint8_t BuzzerPin)
{
	DIO_ToggleForPin(BuzzerGroup,BuzzerPin);
}
