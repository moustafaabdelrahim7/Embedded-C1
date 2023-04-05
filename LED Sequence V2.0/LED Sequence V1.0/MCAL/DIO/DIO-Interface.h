﻿/*
 * IncFile1.h
 *
 * Created: 03/04/2023 12:09:22 م
 *  Author: Genius
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_
#include "../../SERVICE/Utiles.h"
#include "MemoryMaping.h"

typedef enum{
	pina0=0,
	pina1=1,
	pina2,
	pina3,
	pina4,
	pina5,
	pina6,
	pina7,
	pinb0,
	pinb1,
	pinb2,
	pinb3,
	pinb4,
	pinb5,
	pinb6,
	pinb7,
	pinc0,
	pinc1,
	pinc2,
	pinc3,
	pinc4,
	pinc5,
	pinc6,
	pinc7,
	pind0,
	pind1,
	pind2,
	pind3,
	pind4,
	pind5,
	pind6,
	pind7,
TOTAL_PINS=32} DIO_PIN_TYPE;

typedef enum{
	LOW=0,
HIGH} DIO_VOLTAGE_TYPE;

typedef enum{
	OUTPUT,
	INFREE,
	INPLUP
} DIO_PINSTATUS_TYPE;

typedef enum{
	PA,
	PB,
	PC,
PD} DIO_PORT_TYPE;

typedef enum {
	VALID_DIO,
	INVALID_PIN_NUMBER,
	INVALID_PORT,
	INVALID_VOLTAGE,
	INVALID_DIRECTION
}DIO_ERROR_TYPE;

DIO_ERROR_TYPE DIO_INITPIN(DIO_PIN_TYPE PIN,DIO_PINSTATUS_TYPE STATUS);
DIO_ERROR_TYPE DIO_WRITEPIN(DIO_PIN_TYPE PIN,DIO_VOLTAGE_TYPE VOLTAGE);
DIO_ERROR_TYPE DIO_READPIN(DIO_PIN_TYPE PIN,DIO_VOLTAGE_TYPE* VOLT);






#endif /* INCFILE1_H_ */