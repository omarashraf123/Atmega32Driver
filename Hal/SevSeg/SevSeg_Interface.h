/*
 * SeVSeg_Interface.h
 *
 *  Created on: Sep 3, 2026
 *      Author: oa000
 */

#ifndef HAL_SEVSEG_SEVSEG_INTERFACE_H_
#define HAL_SEVSEG_SEVSEG_INTERFACE_H_

#include "../../Mcal/DIO/DIO_Interface.h"

#include "SevSeg_Private.h"
#include "SevSeg_Config.h"

void SSD_Init();

void SSD_DisplayNo(uint8_t Number);

void SSD_CountNo(void);



#endif /* HAL_SEVSEG_SEVSEG_INTERFACE_H_ */
