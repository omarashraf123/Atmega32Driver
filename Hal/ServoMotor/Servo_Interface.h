/*
 * Servo_Interface.h
 *
 *  Created on: Oct 18, 2026
 *      Author: oa000
 */

#ifndef HAL_SERVOMOTOR_SERVO_INTERFACE_H_
#define HAL_SERVOMOTOR_SERVO_INTERFACE_H_

#include "../../Mcal/DIO/DIO_Interface.h"
#include "../../Mcal/Timer1/T1_Interface.h"

#include "Servo_Private.h"
#include "Servo_Config.h"

#if Servo_Driver

void Servo_Init();

void Servo_SetAngle();

#endif
#endif /* HAL_SERVOMOTOR_SERVO_INTERFACE_H_ */
