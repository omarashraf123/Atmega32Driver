/*
 * SeVSeg_Config.h
 *
 *  Created on: Sep 3, 2026
 *      Author: oa000
 */

#ifndef HAL_SEVSEG_SEVSEG_CONFIG_H_
#define HAL_SEVSEG_SEVSEG_CONFIG_H_

#include "../../Mcal/DIO/DIO_Interface.h"
#include "SevSeg_Private.h"

/*
 * SSD1
 * SSD2
 * MultiSSD
 * */
#define SSD_Mode  MultiSSD
/*SSD_AnodeConnection
 *SSD_CathodeConnection
 * */
#define SSD_ConnectionMode   SSD_AnodeConnection

#if SSD_Mode == SSD1

	#define SSD1_Group	DIO_GroupA

	#elif SSD_Mode == SSD2

		#define SSD2_Group	DIO_GroupB

#elif SSD_Mode == MultiSSD

	#define SSD1_Group	DIO_GroupA
	#define SSD2_Group	DIO_GroupB

#endif


#endif /* HAL_SEVSEG_SEVSEG_CONFIG_H_ */
