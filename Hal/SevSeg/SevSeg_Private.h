/*
 * SeVSeg_Private.h
 *
 *  Created on: Sep 3, 2026
 *      Author: oa000
 */

#ifndef HAL_SEVSEG_SEVSEG_PRIVATE_H_
#define HAL_SEVSEG_SEVSEG_PRIVATE_H_




#define SSD1     1
#define SSD2     2
#define MultiSSD 3

#define SSD_AnodeConnection    1
#define SSD_CathodeConnection  2


#define SDDMaxNumber 10


// Anode  LedOn -> 0 LedOff -> 1
// h g f e d c b a
// 7 6 5 4 3 2 1 0 ->
// 1 1 0 0 0 0 0 0 -> 0
// 1 1 1 1 1 0 0 1 -> 1
// 1 0 1 0 0 1 0 0 -> 2
// 1 0 1 1 0 0 0 0 -> 3
// 1 0 0 1 1 0 0 1 -> 4
// 1 0 0 1 0 0 1 0 -> 5
// 1 0 0 0 0 0 1 0 -> 6
// 1 1 1 1 1 0 0 0 -> 7
// 1 0 0 0 0 0 0 0 -> 8
// 1 0 0 1 0 0 0 0 -> 9


typedef enum
{
	Anode_Zero   = 0xC0  ,
	Anode_One    = 0xF9  ,
	Anode_Two    = 0xA4  ,
	Anode_Three  = 0xB0  ,
	Anode_Four   = 0x99  ,
	Anode_Five   = 0x92  ,
	Anode_Six    = 0x82  ,
	Anode_Seven  = 0xF8  ,
	Anode_Eight  = 0x80  ,
	Anode_Nine   = 0x90  ,
}SSD_AnodeNo_t;




// Cathode  LedOn -> 1 LedOff -> 0
// h g f e d c b a
// 7 6 5 4 3 2 1 0 ->
// 0 0 1 1  1 1 1 1 -> 0
// 		0x3F
// 0 0 0 0  0 1 1 0 -> 1
//		0x06
// 0 1 0 1  1 0 1 1 -> 2
//		0x5B
// 0 1 0 0  1 1 1 1 -> 3
//		0x4F
// 0 1 1 0  0 1 1 0 -> 4
//		0x66
// 0 1 1 0  1 1 0 1 -> 5
//		0x6D
// 0 1 1 1  1 1 0 1 -> 6
//		0x7D
// 0 0 0 0 0 1 1 1 -> 7
//		0x07
// 0 1 1 1  1 1 1 1 -> 8
//		0x7F
// 0 1 1 0  1 1 1 1 -> 9
//		0x6F
typedef enum
{
	Cathode_Zero  =0x3F,
    Cathode_One   =0x06,
    Cathode_Two   =0x5B,
    Cathode_Three =0x4F,
    Cathode_Four  =0x66,
    Cathode_Five  =0x6D,
    Cathode_Six   =0x7D,
    Cathode_Seven =0x07,
    Cathode_Eight =0x07,
    Cathode_Nine  =0x6F,
}SSD_CathodeNo_t;



#endif /* HAL_SEVSEG_SEVSEG_PRIVATE_H_ */
