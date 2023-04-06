#include "MCAL/DIO/DIO.h"
#include "HAL/BUTTON/BUTTON.h"
#include "HAL/LED/LED.h"
#include "util/delay.h"
#include "MCAL/INTERRUPT/INTERRUPT.h"
#define   F_CPU 8000000UL            //FOR DELAY LIB

int main(void)
{
	/**********intializing LED& DIO*************/
	LED_INIT(pina0);
	LED_INIT(pina1);
	LED_INIT(pina2);
	LED_INIT(pina3);
	DIO_INITPIN(pind2,INPLUP);
	/*****************INTIALIZING INTERRUPT***********/
	sei();
	EXI_TriggerEdge(EX_INT0,LOW_LEVEL);
	EXI_Enable(EX_INT0);
	
	while(1)
	{
	}
}

