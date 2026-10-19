/*
 * GIE_Program.c

 *
 *  Created on: Sep 18, 2026
 *      Author: oa000
 */
#include "../../Common/Bitmath.h"
#include "../../Common/Defintion.h"
#include "../Atemga32Reg.h"
#include "GIE_Interface.h"

void GIE_Enable()
{
	SetBit(SREG_Reg,7);
}

void GIE_Disable()
{
	ClearBit(SREG_Reg,7);
}







