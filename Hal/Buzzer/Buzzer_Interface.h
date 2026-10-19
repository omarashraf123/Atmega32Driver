/*
 * Buzzer_Interface.h
 *
 *  Created on: Sep 3, 2026
 *      Author: oa000
 */

#ifndef HAL_BUZZER_BUZZER_INTERFACE_H_
#define HAL_BUZZER_BUZZER_INTERFACE_H_

#include "../../Mcal/DIO/DIO_Interface.h"

#include "Buzzer_private.h"
#include "Buzzer_Config.h"


void Buzzer_init(uint8_t BuzzerGroup,uint8_t BuzzerPin);

void Buzzer_on(uint8_t BuzzerGroup,uint8_t BuzzerPin);

void Buzzer_off(uint8_t BuzzerGroup,uint8_t BuzzerPin);

void Buzzer_Tone(uint8_t BuzzerGroup,uint8_t BuzzerPin);

#endif /* HAL_BUZZER_BUZZER_INTERFACE_H_ */
