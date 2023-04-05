

#ifndef EXT_INTERRUPT_H_
#define EXT_INTERRUPT_H_
#include "../DIO/MemoryMaping.h"
#include "../../SERVICE/Std_Types.h"
#include "../../SERVICE/Utiles.h"

#define  NULL ((void*)0)         //to define null



typedef enum{
	EX_INT0=0,
	EX_INT1,
	EX_INT2
	}EXInterruptSource_type;

typedef enum{
	LOW_LEVEL=0,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE
	}TriggerEdge_type;
	
typedef enum{
	VALID_INTERRUPT=0,
	INVALID_INTERRUPT,
	INVALID_TRIGGER_STATE
}INTERRUPT_ERROR_TYPE;


INTERRUPT_ERROR_TYPE EXI_Enable(EXInterruptSource_type interrupt);
INTERRUPT_ERROR_TYPE EXI_Disable (EXInterruptSource_type interrupt);
INTERRUPT_ERROR_TYPE EXI_TriggerEdge (EXInterruptSource_type interrupt, TriggerEdge_type edge );
INTERRUPT_ERROR_TYPE EXI_SetCallBack(EXInterruptSource_type interrupt, void (*pf_local)(void));



#endif /* EXT_INTERRUPT_H_ */