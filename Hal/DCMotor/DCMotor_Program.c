/*
 * DCMotor_Program.c
 *
 *  Created on: Sep 5, 2026
 *      Author: oa000
 */

#include "DCMotor_Interface.h"

void DC_Init(Dc_Config_t *Config)
{
	if(Config!=Null)
	{
		if(Config->ConnectionType==Dc_WithoutHBridge)
		{
			DIO_DirectionSelectForPin(Config->Dc_M1Group,Config->Dc_M1Pin,DIO_Output );
		}
		else if(Config->ConnectionType==Dc_WithHBridge)
		{
			DIO_DirectionSelectForPin(Config->Dc_M1Group,Config->Dc_M1Pin,DIO_Output );
			DIO_DirectionSelectForPin(Config->Dc_M2Group,Config->Dc_M2Pin,DIO_Output );
		}else
		{

		}
	}
}


// DC_Motor On Off Only

void DC_On(Dc_Config_t *Config)
{
	if(Config!=Null)
	{
		if(Config->ConnectionType ==Dc_WithoutHBridge )
		{
			DIO_WriteForPin(Config->Dc_M1Group,Config->Dc_M1Pin,DIO_High);
		}
	}
}
void DC_Off(Dc_Config_t *Config)
{
	if(Config!=Null)
	{
		if(Config->ConnectionType==Dc_WithoutHBridge)
		{
			DIO_WriteForPin(Config->Dc_M1Group,Config->Dc_M1Pin,DIO_Low);
		}
		if(Config->ConnectionType==Dc_WithHBridge)
		{
			DIO_WriteForPin(Config->Dc_M1Group,Config->Dc_M1Pin,DIO_Low);
			DIO_WriteForPin(Config->Dc_M2Group,Config->Dc_M2Pin,DIO_Low);
		}else
		{

		}
	}
	else
	{

	}
}

void DC_OnCW(Dc_Config_t *Config)
{
	if(Config!=Null)
	{
		if(Config->ConnectionType==Dc_WithHBridge)
		{
			DIO_WriteForPin(Config->Dc_M1Group,Config->Dc_M1Pin,DIO_High);
			DIO_WriteForPin(Config->Dc_M2Group,Config->Dc_M2Pin,DIO_Low);
		}else
		{}
	}
}

void DC_OnCCW(Dc_Config_t *Config)
{
	if(Config!=Null)
	{
		if(Config->ConnectionType==Dc_WithHBridge)
		{
			DIO_WriteForPin(Config->Dc_M1Group,Config->Dc_M1Pin,DIO_Low);
			DIO_WriteForPin(Config->Dc_M2Group,Config->Dc_M2Pin,DIO_High);
		}else

		{

		}
	}

}













