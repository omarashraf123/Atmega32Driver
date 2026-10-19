/*
 * LCD_Config.h
 *
 *  Created on: Sep 3, 2026
 *      Author: oa000
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_

#include "../../Mcal/DIO/DIO_Interface.h"

/*
 * Lcd_8BitMode
 * Lcd_4BitMode
 * */

#define LCD_Mode  Lcd_8BitMode

#define RSPin     DIO_Pin0
#define RSGroup   DIO_GroupC

#define RWPin     DIO_Pin1
#define RWGroup   DIO_GroupC

#define EPin     DIO_Pin2
#define EGroup   DIO_GroupC

#if LCD_Mode==Lcd_8BitMode
    #define DataGroup DIO_GroupD
#elif LCD_Mode==Lcd_4BitMode
    #define D4Pin0       DIO_Pin4
    #define D4Group      DIO_GroupD

    #define D5Pin1       DIO_Pin5
    #define D5Group      DIO_GroupD

	#define D6Pin2       DIO_Pin6
    #define D6Group      DIO_GroupD

	#define D7Pin3       DIO_Pin7
    #define D7Group      DIO_GroupD

#else
    #error "Invaild Lcd Mode"
#endif

/**
 * Lcd_4Bit2Line5x8F
 * Lcd_4Bit2Line5x11F
 * Lcd_4Bit1Line5x8F
 * Lcd_4Bit1Line5x11F
 * Lcd_8Bit2Line5x8F
 * Lcd_8Bit2Line5x11F
 * Lcd_8Bit1Line5x8F
 * Lcd_8Bit1Line5x11F
 */
#define Lcd_FunctionSet  Lcd_8Bit2Line5x8F

/**
 * Lcd_DisplayOff
 * Lcd_DisplayOnCursorOff
 * Lcd_DisplayOnCursorOnBlinkOff
 * Lcd_DisplayOnCursorOnBlinkOn
 */
#define Lcd_DisplayOnOff   Lcd_DisplayOnCursorOnBlinkOn
/**
 * Lcd_EntryMode_DecNoShift
 * Lcd_EntryMode_DecShift
 * Lcd_EntryMode_IncNoShift
 * Lcd_EntryMode_IncShift
 */
#define Lcd_EntryMode  Lcd_EntryMode_IncNoShift

#endif /* HAL_LCD_LCD_CONFIG_H_ */















