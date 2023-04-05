/*
 * MemoryMaping.h
 *
 * Created: 03/04/2023 12:53:10 م
 *  Author: Moustafa Abdelrahim
 */ 


#ifndef MEMORYMAPING_H_
#define MEMORYMAPING_H_
#include "../../SERVICE/Std_Types.h"

/********************************************DIO MAPING************************	********/
#define DDRA (*(volatile uint8_t*)0x3A)
#define DDRB (*(volatile  uint8_t*)0x37)
#define DDRC (*(volatile uint8_t*)0x34)
#define DDRD (*(volatile uint8_t*)0x31)


#define PINA (*(volatile uint8_t*)0x39)
#define PINB (*(volatile uint8_t*)0x36)
#define PINC (*(volatile uint8_t*)0x33)
#define PIND (*(volatile uint8_t*)0x30)


#define PORTA (*(volatile uint8_t*)0x3B)
#define PORTB (*(volatile uint8_t*)0x38)
#define PORTC (*(volatile uint8_t*)0x35)
#define PORTD (*(volatile uint8_t*)0x32)

/******************************EXT INTERRUPT MAPPING**************************************/

#define MCUCSR  (*(volatile uint8_t*)0X54)
#define MCUCR  (*(volatile uint8_t*)0X55)
#define GIFR  (*(volatile uint8_t*)0X5A)
#define GICR  (*(volatile uint8_t*)0X5B)
/*************interrupt registers pin macro*/
#define ISC10 2
#define ISC11 3
#define ISC01 1
#define ISC00 0
#define ISC2  6
#define INT2 5
#define INT0 6
#define INT1 7
/****data sheet attributes to enable context switching and to enable global interrupt*/
#define INT0_VECTOR    __vector_1
#define ISR(vector)    void vector(void)__attribute__((signal));  \
                         void vector(void)                        //context switching
						 
						 
#define sei()      __asm__ __volatile__ ("sei" ::)  //interrupt enabling


#endif /* MEMORYMAPING_H_ */