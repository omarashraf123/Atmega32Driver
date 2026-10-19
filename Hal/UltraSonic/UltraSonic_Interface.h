/*
 * UltraSonic_Interface.h
 *
 *  Created on: Oct 12, 2026
 *      Author: oa000
 */

#ifndef HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_
#define HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_

#include <stdint.h>
#include "../../Mcal/DIO/DIO_Interface.h"
#include "../../Mcal/Timer1/T1_Interface.h"

#include "UltraSonic_Private.h"
#include "UltraSonic_Config.h"

void UltraSonic_Init();

void UltraSonic_Trigger();

uint8_t UltraSonic_GetDistance(uint8_t *DistanceValue);

#endif /* HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_ */
