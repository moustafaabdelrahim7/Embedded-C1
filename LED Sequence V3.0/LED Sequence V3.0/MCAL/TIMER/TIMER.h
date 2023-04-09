

#ifndef TIMER_H_
#define TIMER_H_
#include "../MEMORYMAPIING.h"
#include "../../SERVICE/UTILES.h"
#include "../INTERRUPT/INTERRUPT.h"
typedef enum
{
	TIMER0_NORMAL_MODE=0,
	TIMER0_PHASE_CORRECT_MODE,
	TIMER0_CTC_MODE,
	TIMER0_FASTPWM_MODE
}Timer0Mode_type;

typedef enum
{
	TIMER0_STOP=0,
	TIMER0_SCALER_1,
	TIMER0_SCALER_8,
	TIMER0_SCALER_64,
	TIMER0_SCALER_256,
	TIMER0_SCALER_1024,
	TIMER0_EXTERNAL_FALLING,
	TIMER0_EXTERNAL_RISING
}Timer0SCALER_type;

typedef enum
{
	OC0_DISCONNECTED=0,
	OC0_TOGGLE,
	OC0_NON_INVERTING,
	OC0_INVERTING
}OC0Mode_type;

void Timer0_Init(Timer0Mode_type mode, Timer0SCALER_type scaler,OC0Mode_type oc_mode );
void timer0_SetCounter(uint8_t offset);
void Timer0_OVF_InterrupEnable(void);
void Timer0_OVF_InterrupDisable(void);
void Timer0_OVF_SetcallBack(void (*timer0_Fptr_ovf)(void));

void Timer0_SetCompare(uint8_t limit);
void Timer0_OC_InterruptEnable(void);
void Timer0_OC_InterruptDisable(void);
void Timer0_OC_SetCallBack(void (*pf_local) (void));



#endif /* TIMER_H_ */