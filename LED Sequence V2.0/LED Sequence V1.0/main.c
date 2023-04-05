
#include "MCAL/DIO/DIO-Interface.h"
#include "HAL/button/button.h"
#include "HAL/LED/LED-Interface.h"
#include "util/delay.h"
#include "MCAL/interrupt/EXT_Interrupt.h"
#define   F_CPU 8000000UL            //FOR DELAY LIB
uint8_t FLAG=0;                      //SHARED RESOURCE FOR INTERRUPR
int main(void)
{
	/**********intializing LED*************/
	LED_INIT(pina0);
	LED_INIT(pina1);
	LED_INIT(pina2);
	LED_INIT(pina3);
	/*****************INTIALIZING INTERRUPT***********/
	sei();
	Button_INIT(pind2);
	EXI_TriggerEdge(EX_INT0,LOW_LEVEL);
	EXI_Enable(EX_INT0);
	
	while(1)
	{
	}
}
	
	
ISR(INT0_VECTOR)
{

			if(FLAG==0)
			{
				LED_ON(pina0);
				FLAG++;
				_delay_ms(300);
			}
			else if(FLAG==1)
			{
				LED_ON(pina1);
				_delay_ms(300);
				FLAG++;
			}
			else if(FLAG==2)
			{
				LED_ON(pina2);
				_delay_ms(300);
				FLAG++;
			}
			else if(FLAG==3)
			{
				LED_ON(pina3);
				_delay_ms(300);
				FLAG++;
			}
			else if(FLAG==4)
			{
				LED_OFF(pina0);
				_delay_ms(300);
				FLAG++;
			}
			else if(FLAG==5)
			{
				LED_OFF(pina1);
				_delay_ms(300);
				FLAG++;
			}
			else if(FLAG==6)
			{
				LED_OFF(pina2);
				_delay_ms(300);
				FLAG++;
			}
			else if(FLAG==7)
			{
				LED_OFF(pina3);
				_delay_ms(300);
				FLAG=0;
			}
			
		
}