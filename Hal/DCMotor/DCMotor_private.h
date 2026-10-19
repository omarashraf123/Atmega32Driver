/*
 * DCMotor_private.h
 *
 *  Created on: Sep 5, 2026
 *      Author: oa000
 */

#ifndef HAL_DCMOTOR_DCMOTOR_PRIVATE_H_
#define HAL_DCMOTOR_DCMOTOR_PRIVATE_H_


#include <stdint.h>

typedef enum
{
	Dc_WithoutHBridge,
	Dc_WithHBridge,
}Dc_ConnectionType_t;



typedef struct
{
	uint8_t ConnectionType;

	uint8_t Dc_M1Group;
	uint8_t Dc_M1Pin;

	uint8_t Dc_M2Group;
	uint8_t Dc_M2Pin;
}Dc_Config_t;

#endif /* HAL_DCMOTOR_DCMOTOR_PRIVATE_H_ */
