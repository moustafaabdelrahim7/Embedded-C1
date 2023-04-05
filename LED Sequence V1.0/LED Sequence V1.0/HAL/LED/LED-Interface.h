﻿

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_
#include "../../MCAL/DIO/DIO-Interface.h"

typedef enum {
	VALID_LED,
	INVALID_LED_PORT,
	INVLAID_LED_PIN_NUMBER
}LED_ERROR_TYPE;
 LED_ERROR_TYPE LED_INIT(DIO_PIN_TYPE PIN);
 LED_ERROR_TYPE LED_ON(DIO_PIN_TYPE PIN);
 LED_ERROR_TYPE LED_OFF(DIO_PIN_TYPE PIN);





#endif /* LED-INTERFACE_H_ */