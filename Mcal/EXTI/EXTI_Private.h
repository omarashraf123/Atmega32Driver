/*
 * EXTI_Private.h
 *
 *  Created on: Sep 19, 2026
 *      Author: oa000
 */

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_
#include "../../Common/Config.h"
#if EXTI_Driver
typedef enum
{
    /*MCUCR*/
    ISC00,
    ISC01,
    ISC10,
    ISC11,
    /*MCUCSR*/
    ISC2=6,
    /*GICR */
    INT2 = 5,
    INT0,
    INT1,
    /*GIFR */
    INTF2 = 5,
    INTF0,
    INTF1

}Exti_BitName_t;
/*Options*/
typedef enum
{
    Exti_LowLevel,
    Exti_AnyLogic,
    Exti_Falling,
    Exti_Rising,

}Exti_SensControl_t;

typedef  enum
{
    Exti0,
    Exti1,
    Exti2,
}Exti_Numbers_t;

#endif

#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
