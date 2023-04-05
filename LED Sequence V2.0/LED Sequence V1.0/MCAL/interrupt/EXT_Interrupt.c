#include "EXT_Interrupt.h"

 void  static (*Fptr_INT0) (void) = NULL;
 void  static (*Fptr_INT1) (void) = NULL;
 void  static (*Fptr_INT2) (void) = NULL;
 
 /*this function enables the interrupt pin*/
 
INTERRUPT_ERROR_TYPE EXI_Enable(EXInterruptSource_type interrupt)
{

		switch(interrupt)
	{
		case EX_INT0:
		set_bit(GICR,INT0); break;
		case EX_INT1:
		set_bit(GICR,INT1); break;
		case EX_INT2:
		set_bit(GICR,INT2); break;
		
	}
	
}

/*it disable interrupt pin*/

INTERRUPT_ERROR_TYPE EXI_Disable (EXInterruptSource_type interrupt)
{
	
	switch(interrupt)
	{
		case EX_INT0:
		clear_bit(GICR,INT0); break;
		case EX_INT1:
		clear_bit(GICR,INT1); break;
		case EX_INT2:
		clear_bit(GICR,INT2); break;
	}
	
}

/*it defines the trigger state of the interrupt*/
INTERRUPT_ERROR_TYPE EXI_TriggerEdge (EXInterruptSource_type interrupt, TriggerEdge_type edge )
{

	switch(interrupt)
	{
		case EX_INT0:
		switch(edge)
		{
			case LOW_LEVEL:
			clear_bit(MCUCR,ISC00);
			clear_bit(MCUCR,ISC01);
			break;
			case ANY_LOGIC_CHANGE:
			set_bit(MCUCR,ISC00);
			clear_bit(MCUCR,ISC01); 
			break;
			case FALLING_EDGE:
			clear_bit(MCUCR,ISC00);
			set_bit(MCUCR,ISC01);
			 break;
			case RISING_EDGE:
			set_bit(MCUCR,ISC00);
			set_bit(MCUCR,ISC01);
			 break;
		}
		break;
		case EX_INT1:
		switch(edge)
		{
			case LOW_LEVEL:
			clear_bit(MCUCR,ISC10);
			clear_bit(MCUCR,ISC11); break;
			case ANY_LOGIC_CHANGE:
			set_bit(MCUCR,ISC10);
			clear_bit(MCUCR,ISC11); break;
			case FALLING_EDGE:
			clear_bit(MCUCR,ISC10);
			set_bit(MCUCR,ISC11); break;
			case RISING_EDGE:
			set_bit(MCUCR,ISC10);
			set_bit(MCUCR,ISC11); break;
		}
		break;
		case EX_INT2:
		switch(edge)
		{
			case LOW_LEVEL:
			 /*DO nothing OR set default */
			break;
			case  ANY_LOGIC_CHANGE:
		 /*DO nothing OR set default */
			break;
			case FALLING_EDGE:
			clear_bit(MCUCSR,ISC2);
			 break;
			case RISING_EDGE:
			set_bit(MCUCSR,ISC2); 
			break;
		}
		break;
	}
	
}

/*
INTERRUPT_ERROR_TYPE EXI_SetCallBack(EXInterruptSource_type interrupt, void (*pf_local)(void))
{
	switch(interrupt)
	{
		case EX_INT0:
		Fptr_INT0=pf_local; 
		break;
		case EX_INT1:
		Fptr_INT1=pf_local; 
		break;
		case EX_INT2:
		Fptr_INT2=pf_local;
	    break;
	}
}
*/
/*ISR(INT0_vect)
{
	Fptr_INT0();
}
*/