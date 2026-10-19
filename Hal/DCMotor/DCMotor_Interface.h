/*
 * DCMotor_Interface.h
 *
 *  Created on: Sep 5, 2026
 *      Author: oa000
 */

#ifndef HAL_DCMOTOR_DCMOTOR_INTERFACE_H_
#define HAL_DCMOTOR_DCMOTOR_INTERFACE_H_

#include "../../Mcal/DIO/DIO_Interface.h"


#include "DCMotor_private.h"
#include "DCMotor_Config.h"

void DC_Init(Dc_Config_t *Config);

/*API for on off control Only*/

void DC_On(Dc_Config_t *Config);

void DC_Off(Dc_Config_t *Config);

/*API For On Off & Direction Control*/

void DC_OnCW(Dc_Config_t *Config);

void DC_OnCCW(Dc_Config_t *Config);


#endif /* HAL_DCMOTOR_DCMOTOR_INTERFACE_H_ */









