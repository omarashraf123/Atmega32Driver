/*
 * DIO_Private.h
 *
 *  Created on: Aug 20, 2026
 *      Author: oa000
 */

#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_


typedef enum{
	DIO_Input = 0,
	DIO_Output = 1,
	DIO_AllOutput = 0xFF,
}DIO_Direction_t;

typedef enum{
	DIO_Low,
	DIO_High,
	DIO_AllHigh,
}DIO_OutputValue_t;

typedef enum{
	DIO_GroupA = 1,
	DIO_GroupB ,
	DIO_GroupC ,
	DIO_GroupD ,
}DIO_GroupName_t;

typedef enum{
	DIO_Pin0,
	DIO_Pin1,
	DIO_Pin2,
	DIO_Pin3,
	DIO_Pin4,
	DIO_Pin5,
	DIO_Pin6,
	DIO_Pin7,
	DIo_AllPins = 0xFF,
}DIO_PinNo_t;




#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
