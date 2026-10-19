/*
 * LCD_Private.h
 *
 *  Created on: Sep 3, 2026
 *      Author: oa000
 */

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_

#include "../../Mcal/DIO/DIO_Interface.h"


#define Lcd_8BitMode 1
#define Lcd_4BitMode 2


#define Lcd_ClearScreen 0x01

/*
DisplayOnOff
D=1 ,display on ; D=0 display off
C=1 Cursor on ; C=0 Cursor off
B=1 Cursor Blinking on ;B=0 Cursor Blinking Off
0 0 0 0 1 D C B
0 0 0 0 1 0 0 0 -> D=0 , C=0 ,B=0
0 0 0 0 1 1 0 0 -> D=1 , C=0 ,B=0
0 0 0 0 1 1 1 0 -> D=0 , C=0 ,B=0
0 0 0 0 1 1 1 1 -> D=1 , C=1 ,B=1
*/
#define Lcd_DisplayOff                0x08
#define Lcd_DisplayOnCursorOff        0x0C
#define Lcd_DisplayOnCursorOnBlinkOff 0x0E
#define Lcd_DisplayOnCursorOnBlinkOn  0x0F

/*	Function Set
 * DL = 1, 8Bit Interface ; DL=0,Bit Interface
 * N = 1, 2-Line display; N = 0, 1-Line display;
 * F = 1, 5�11 dots font; F = 0, 5�8 dots font;
 *  0 0 1 DL N F x x
 *  0 0 1  0 0 1 0 0
 * 								0 0 1 DL N F x x
 * */
#define Lcd_4Bit2Line5x8F  0x28//0 0 1 0 1 0 0 0
#define Lcd_4Bit2Line5x11F 0x2C//0 0 1 0 1 1 0 0
#define Lcd_4Bit1Line5x8F  0x20//0 0 1 0 0 0 0 0
#define Lcd_4Bit1Line5x11F 0x24//0 0 1 0 1 1 0 0
#define Lcd_8Bit2Line5x8F  0x38//0 0 1 1 1 0 0 0
#define Lcd_8Bit2Line5x11F 0x3C//0 0 1 1 1 1 0 0
#define Lcd_8Bit1Line5x8F  0x30//0 0 1 1 0 0 0 0
#define Lcd_8Bit1Line5x11F 0x34//0 0 1 1 0 1 0 0
/* Entry Mode options
 * I/D=1 , AC= AC+1 (Screen Shift Left);I/D=0 ,
 * AC= AC-1 (Screen Shift Right);
 * S =1, Screen Shifting On
 * S=0, Screen Shifting Off
 * 0 0 0 0 0 1 I/D S
 * 0 0 0 0 0 1  0  0 -> I/D=0 ,S=0
 * 0 0 0 0 0 1  1  0 -> I/D=1 ,S=0
 *										 0 0 0 0 0 1 I/D S
 * */
#define Lcd_EntryMode_DecNoShift 0x04 // 0 0 0 0 0 1  0  0
#define Lcd_EntryMode_DecShift   0x05 // 0 0 0 0 0 1  0  1
#define Lcd_EntryMode_IncNoShift 0x06 // 0 0 0 0 0 1  1  0
#define Lcd_EntryMode_IncShift   0x07 // 0 0 0 0 0 1  1  1

/*	Cursor Or Display Shift Options
 * S/C=1, Shift Screen,
 * S/C=0, Shift Cursor;
 * R/L=1 Shift To Right-Side,
 * R/L=0 Shift To Left-Side;
 * 0 0 0 1 S/C R/L x x
 * 								      0 0 0 1 S/C R/L x x
 * */
#define Lcd_ShiftCursorLeft  0x10    //0 0 0 1  0   0  0 0
#define Lcd_ShiftCursorRight 0x14    //0 0 0 1  0   1  0 0
#define Lcd_ShiftDisplayLeft 0x18    //0 0 0 1  1   0  0 0
#define Lcd_ShiftDisplayRight 0x1C   //0 0 0 1  1   1  0 0


#define Lcd_Line1  0
#define Lcd_Line2  1

#define Lcd_Line1Address 0x00
#define Lcd_Line2Address 0x40


#define Lcd_SetDDRAMCommand 0x80
#define Lcd_SetCGRAMCommand 0x40
#define Lcd_CGRAMMaxLocation 8
#define Lcd_CGRAMMaxSizeOfLocation 8

#endif /* HAL_LCD_LCD_PRIVATE_H_ */
