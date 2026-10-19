/*
 * Led_Program.c
 *
 *  Created on: Sep 3, 2026
 *      Author: oa000
 */
#include "Led_Interface.h"

void Led_Init(uint8_t LedGroup , uint8_t LedPin )
{
	DIO_DirectionSelectForPin(LedGroup,LedPin,DIO_Output);
}


void Led_On(uint8_t LedGroup , uint8_t LedPin, uint8_t ConnectionType )
{
	if(ConnectionType == Led_SourceConnection)
	{
		DIO_WriteForPin(LedGroup , LedPin , DIO_High);
	}
	else if(ConnectionType == Led_SinkConnection)
	{
		DIO_WriteForPin(LedGroup,LedPin,DIO_Low);

	}
}


void Led_Off(uint8_t LedGroup , uint8_t LedPin, uint8_t ConnectionType )
{
	{
		if(ConnectionType == Led_SourceConnection)
		{
			DIO_WriteForPin(LedGroup , LedPin , DIO_Low);
		}
		else if(ConnectionType == Led_SinkConnection)
		{
			DIO_WriteForPin(LedGroup,LedPin,DIO_High);

		}
	}
}


void Led_Toggle(uint8_t LedGroup , uint8_t LedPin)
{
	DIO_ToggleForPin(LedGroup,LedPin);
}





















