/*
 * LCD_Program.c

 *
 *  Created on: Sep 3, 2026
 *      Author: oa000
 */

#include <util/delay.h>
#include "LCD_Interface.h"


void LCD_Init()
{
#if LCD_Mode== Lcd_8BitMode

	DIO_DirectionSelectForPin(RSGroup,RSPin,DIO_Output);
	DIO_DirectionSelectForPin(RWGroup,RWPin,DIO_Output);
	DIO_DirectionSelectForPin(EGroup,EPin,DIO_Output);

	DIO_DirectionSelectForGroup(DataGroup,DIO_AllHigh);
	/*Init*/
	// 1- wait for 30 msec
	_delay_ms(35);
	// 2- sent the function set
	LCD_SendCommand(Lcd_FunctionSet);
	// 3- wait for 1msec
	_delay_ms(1);
	// 4- Sent the Display on Off
	LCD_SendCommand(Lcd_DisplayOnOff);
	// 5- wait for 1msec
	_delay_ms(1);
	// 6- Sent Clear
	LCD_SendCommand(Lcd_ClearScreen);
	// 7- wait for 2msec
	_delay_ms(2);
	// 8- Entry Mode sent
	LCD_SendCommand(Lcd_EntryMode);
#elif LCD_Mode == Lcd_4BitMode

	DIO_DirectionSelectForPin(RSGroup,RSPin,DIO_Output);
	DIO_DirectionSelectForPin(RWGroup,RWPin,DIO_Output);
	DIO_DirectionSelectForPin(EGroup,EPin,DIO_Output);

	DIO_DirectionSelectForPin(D4Group,D4Pin0,DIO_Output);
	DIO_DirectionSelectForPin(D5Group,D5Pin1,DIO_Output);
	DIO_DirectionSelectForPin(D6Group,D6Pin2,DIO_Output);
	DIO_DirectionSelectForPin(D7Group,D7Pin3,DIO_Output);

	//Init
	//1- Wait For 30 msec
	_delay_ms(35);
	//2- Sent Function Set
	LCD_SendCommand(Lcd_FunctionSet);
	//3- wait for 1msec
	_delay_ms(1);
	//4- Display On Off
	LCD_SendCommand(Lcd_DisplayOnOff);
	//5- wait for 1msec
	_delay_ms(1);
	//6- Display Clear
	LCD_SendCommand(Lcd_ClearScreen);
	//7-  wait for 2msec
	_delay_ms(2);
	//8-Enery Mode Set
	LCD_SendCommand(Lcd_EntryMode);
#endif
}
void LCD_SendCommand(uint8_t Command)
{
#if  LCD_Mode == Lcd_8BitMode
	//RS -> 0
	DIO_WriteForPin(RSGroup,RSPin,DIO_Low);
	//RW -> 0
	DIO_WriteForPin(RWGroup,RWPin,DIO_Low);
	//Data =  Command
	DIO_WriteForGroup(DataGroup,Command);
	//E-> 1
	DIO_WriteForPin(EGroup,EPin,DIO_High);
	// Wait 1msec
	_delay_ms(1);
	// E-> 0
	DIO_WriteForPin(EGroup,EPin,DIO_Low);
#elif LCD_Mode == Lcd_4BitMode
	DIO_WriteForPin(RSGroup,RSPin,DIO_Low);
	//RW->0
	DIO_WriteForPin(RWGroup,RWPin,DIO_Low);
	//Data = Command
	DIO_WriteForPin(D4Group,D4Pin0,Command);
	DIO_WriteForPin(D5Group,D5Pin1,Command);
	DIO_WriteForPin(D6Group,D6Pin2,Command);
	DIO_WriteForPin(D7Group,D7Pin3,Command);
	//E-> 1
	DIO_WriteForPin(EGroup,EPin,DIO_High);
	//Wait 1ms
	_delay_ms(1);
	//E ->  0
	DIO_WriteForPin(EGroup,EPin,DIO_Low);
#else #error "Invalid LCD Mode"
#endif
}

void LCD_WriteCharacter(uint8_t Character)
{
#if  LCD_Mode == Lcd_8BitMode

	//RS -> 1
	DIO_WriteForPin(RSGroup,RSPin,DIO_High);
	//RW -> 0
	DIO_WriteForPin(RWGroup,RWPin,DIO_Low);
	//Data =  Character
	DIO_WriteForGroup(DataGroup,Character);
	//E-> 1
	DIO_WriteForPin(EGroup,EPin,DIO_High);
	// Wait 1msec
	_delay_ms(1);
	// E-> 0
	DIO_WriteForPin(EGroup,EPin,DIO_Low);

#elif LCD_Mode == Lcd_4BitMode
	//RS -> 1
	DIO_WriteForPin(RSGroup,RSPin,DIO_High);
	//RW->0
	DIO_WriteForPin(RWGroup,RWPin,DIO_Low);
	//Data = Character
	DIO_WriteForPin(D4Group,D4Pin0,Character);
	DIO_WriteForPin(D5Group,D5Pin1,Character);
	DIO_WriteForPin(D6Group,D6Pin2,Character);
	DIO_WriteForPin(D7Group,D7Pin3,Character);
	//E-> 1
	DIO_WriteForPin(EGroup,EPin,DIO_High);
	//Wait 1ms
	_delay_ms(1);
	//E ->  0
	DIO_WriteForPin(EGroup,EPin,DIO_Low);

#endif
}


void LCD_WriteString(uint8_t *String)
{
	if(String!=NULL)
	{
		uint8_t Index = 0 ;
		while(String[Index]!=NullChar)
		{
			LCD_WriteCharacter(String[Index]);
			Index++;
		}
	}

}

void LCD_WriteNumber(int32_t Number)
{
	uint8_t NumberDigits[10] = {0};
	uint8_t Index = 0 ;
	int8_t Counter = 0;

	if(Number==0)
	{
		LCD_WriteCharacter('0');
		return;
	}
	if(Number<0)
	{
		LCD_WriteCharacter('-');
		Number = Number*-1;
	}
	while(Number!=0)
	{
		NumberDigits[Index] = (Number %10)+'0';
		Number = Number/10;
		Index++;
	}
	for(Counter=Index-1;Counter>=0;Counter--)
	{
		LCD_WriteCharacter(NumberDigits[Counter]);
	}
}

void LCD_MoveTo(uint8_t Line, uint8_t Digit)
{
	 uint8_t DDRAM_Address = 0 ;
	    switch(Line)
	    {
	        case Lcd_Line1: DDRAM_Address = Lcd_Line1Address+Digit;break;
	        case Lcd_Line2: DDRAM_Address = Lcd_Line2Address+Digit;break;
	        default:break;
	    }
	    LCD_SendCommand(Lcd_SetDDRAMCommand|DDRAM_Address);
}

void LCD_StoreSpecialCharacter(uint8_t *SpecialCharacter ,uint8_t Location )
{
#if LCD_Mode == Lcd_8BitMode
	if(SpecialCharacter !=Null ){
		uint8_t LocationAddress = Location*Lcd_CGRAMMaxSizeOfLocation;
		LCD_SendCommand(Lcd_SetCGRAMCommand|LocationAddress);
		uint8_t Counter =0;
		for(Counter=0;Counter<8;Counter++)
		{
			LCD_WriteCharacter(SpecialCharacter[Counter]);
		}
		LCD_MoveTo(Lcd_Line1,0);
	}
#elif LCD_Mode == Lcd_4BitMode
	if(SpecialCharacter !=Null )
	{
		uint8_t LocationAddress = Location*Lcd_CGRAMMaxSizeOfLocation;
		LCD_SendCommand(Lcd_SetCGRAMCommand|LocationAddress);
		uint8_t Counter =0;
		for(Counter=0;Counter<4;Counter++)
		{
			LCD_WriteCharacter(SpecialCharacter[Counter]);
		}
		LCD_MoveTo(Lcd_Line1,0);
	}
#endif
}






