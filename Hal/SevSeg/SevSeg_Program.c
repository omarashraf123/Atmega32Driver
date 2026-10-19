/*
 * SevSeg_Program.c
 *
 *  Created on: Sep 3, 2026
 *      Author: oa000
 */


#include "SevSeg_Interface.h"

#if SSD_ConnectionMode == SSD_AnodeConnection

	static uint8_t SSD_Number[SDDMaxNumber] =
									{
					Anode_Zero   ,
					Anode_One    ,
					Anode_Two    ,
					Anode_Three  ,
					Anode_Four   ,
					Anode_Five   ,
					Anode_Six    ,
					Anode_Seven  ,
					Anode_Eight  ,
					Anode_Nine   ,
									};
#elif SSD_ConnectionMode == SSD_CathodeConnection
	static uint8_t SSD_Number[SDDMaxNumber] =
			{
			Cathode_Zero ,
			Cathode_One  ,
			Cathode_Two  ,
			Cathode_Three,
			Cathode_Four ,
			Cathode_Five ,
			Cathode_Six  ,
			Cathode_Seven,
			Cathode_Eight,
			Cathode_Nine ,
			};
#endif
void SSD_Init()
{
#if SSD_Mode == SSD1
		DIO_DirectionSelectForGroup(SSD1_Group,DIO_AllOutput);
#elif SSD_Mode == SSD2

		DIO_DirectionSelectForGroup(SSD2_Group,DIO_AllOutput);

#elif SSD_Mode == MultiSSD
		DIO_DirectionSelectForGroup(SSD1_Group,DIO_AllOutput);
		DIO_DirectionSelectForGroup(SSD2_Group,DIO_AllOutput);
#endif
}

void SSD_DisplayNo( uint8_t Number)
{
#if SSD_Mode == SSD1
		DIO_WriteForGroup(SSD1_Group,SSD_Number[Number]);
#elif SSD_Mode == SSD2

		DIO_WriteForGroup(SSD2_Group,SSD_Number[Number]);

#elif	SSD_Mode == MultiSSD
		DIO_WriteForGroup(SSD1_Group,SSD_Number[Number]);
		DIO_WriteForGroup(SSD2_Group,SSD_Number[Number]);
#endif
}
void SSD_CountNo(void)
{
#if SSD_Mode == SSD1
    static uint8_t Local_u8Counter1 = 0;


    DIO_WriteForGroup(SSD1_Group, SSD_Number[Local_u8Counter1]);


    Local_u8Counter1++;
    if(Local_u8Counter1 > 9)
    {
        Local_u8Counter1 = 0;
    }

#elif SSD_Mode == SSD2
    static uint8_t Local_u8Counter2 = 0;

    DIO_WriteForGroup(SSD2_Group, SSD_Number[Local_u8Counter2]);

    	Local_u8Counter2++;
    if(Local_u8Counter2 > 9)
    {
        Local_u8Counter2 = 0;
    }

#elif SSD_Mode == MultiSSD
    static uint8_t Local_u8MultiCounter = 0;
    uint8_t Local_u8Units = 0;
    uint8_t Local_u8Tens  = 0;

    Local_u8Units = Local_u8MultiCounter % 10;
    Local_u8Tens  = Local_u8MultiCounter / 10;

    DIO_WriteForGroup(SSD1_Group, SSD_Number[Local_u8Units]);
    DIO_WriteForGroup(SSD2_Group, SSD_Number[Local_u8Tens]);

    Local_u8MultiCounter++;
    if(Local_u8MultiCounter > 99)
    {
        Local_u8MultiCounter = 0;
    }
#endif
}




