/*
 * Led_Interface.h
 *
 *  Created on: Sep 3, 2026
 *      Author: oa000
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

#include "../../Mcal/DIO/DIO_Interface.h"

#include "Led_Private.h"
#include "Led_Config.h"


void Led_Init(uint8_t LedGroup , uint8_t LedPin );


void Led_On(uint8_t LedGroup , uint8_t LedPin, uint8_t ConnectionType );


void Led_Off(uint8_t LedGroup , uint8_t LedPin, uint8_t ConnectionType );


void Led_Toggle(uint8_t LedGroup , uint8_t LedPin);



#endif /* HAL_LED_LED_INTERFACE_H_ */
