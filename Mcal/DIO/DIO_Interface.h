/*
 * DIO_Interface.h
 *
 *  Created on: Aug 20, 2026
 *      Author: oa000
 */


#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

#include <stdint.h>
#include "../../Common/Bitmath.h"
#include "../../Common/Defintion.h"
#include "../Atemga32Reg.h"

#include "DIO_Private.h"
#include "DIO_Config.h"

	// Dirction

void DIO_DirectionSelectForPin(uint8_t GroupName , uint8_t PinNo,uint8_t DirectionState);

void DIO_DirectionSelectForGroup(uint8_t GroupName , uint8_t DirectionState);
 // Output Value
void DIO_WriteForPin(uint8_t GroupName , uint8_t PinNo , uint8_t OutputValue );
void DIO_WriteForGroup(uint8_t GroupName,uint8_t OutputValue );

// Input Value

void DIO_ReadInputForPin(uint8_t GroupName ,uint8_t PinNo ,uint8_t *Inputstate  );
void DIO_ReadInputForGroup(uint8_t GroupName ,uint8_t *InputState  );

//  Toggle

void DIO_ToggleForPin(uint8_t GroupName,uint8_t PinNo);
void DIO_ToggleForGroup(uint8_t GroupName);

//Internal Pull UP

void DIO_InternalPullUpControl(uint8_t GroupName , uint8_t PinNo , uint8_t PullUpState);
#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
