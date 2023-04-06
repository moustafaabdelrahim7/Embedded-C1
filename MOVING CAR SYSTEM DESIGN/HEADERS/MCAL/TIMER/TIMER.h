

#ifndef TIMERS_H_
#define TIMERS_H_


/**************************************************************************/
/* Timer0 */
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
void timer0_SetCounter(u8 offset);
void Timer0_OVF_InterrupEnable(void);
void Timer0_OVF_InterrupDisable(void);
void Timer0_OVF_SetcallBack(void (*timer0_Fptr_ovf)(void));

void Timer0_SetCompare(u8 limit);
void Timer0_OC_InterruptEnable(void);
void Timer0_OC_InterruptDisable(void);
void Timer0_OC_SetCallBack(void (*pf_local) (void));

/************************************************************************************************************/
/* Timer1 */

typedef enum
{
	TIMER1_STOP=0,
	TIMER1_SCALER_1,
	TIMER1_SCALER_8,
	TIMER1_SCALER_64,
	TIMER1_SCALER_256,
	TIMER1_SCALER_1024,
	TIMER1_EXTERNAL_FALLING,
	TIMER1_EXTERNAL_RISING
}Timer1Scaler_type;

typedef enum
{
	TIMER1_NORMAL_MODE,
	TIMER1_CTC_ICR_TOP_MODE,
	TIMER1_CTC_OCRA_TOP_MODE,
	TIMER1_FASTPWM_ICR_TOP_MODE,
	TIMER1_FASTPWM_OCRA_TOP_MODE,
	TIMER1_PHASECORRECT_ICR_TOP_MODE,
	TIMER1_PHASECORRECT_OCRA_TOP_MODE,
	TIMER1_PHASE_AND_FREQUENCY_CORRECT_ICR_TOP_MODE,
	TIMER1_PHASE_AND_FREQUENCY_CORRECT_OCRA_TOP_MODE
}Timer1Mode_type;

typedef enum
{
	RISING=0,
	FALLING
}ICU_Edge_type;



typedef enum
{
	OCRA_DISCONNECTED=0,
	OCRA_TOGGLE,
	OCRA_NON_INVERTING,
	OCRA_INVERTING
}OC1A_Mode_type;

typedef enum
{
	OCRB_DISCONNECTED=0,
	OCRB_TOGGLE,
	OCRB_NON_INVERTING,
	OCRB_INVERTING
}OC1B_Mode_type;

void Timer1_InputCaptureEdge(ICU_Edge_type edge);
void Timer1_Init(Timer1Mode_type mode, Timer1Scaler_type scaler, OC1A_Mode_type oc1a_mdoe,OC1B_Mode_type oc1b_mdoe );

void Timer1_ICU_InterruptEnable(void);
void Timer1_ICU_InterruptDisable(void);
void Timer1_OVF_InterruptEnable(void);
void Timer1_OVF_InterruptDisable(void);
void Timer1_OCA_InterruptEnable(void);
void Timer1_OCA_InterruptDisable(void);
void Timer1_OCB_InterruptEnable(void);
void Timer1_OCB_InterruptDisable(void);
void Timer1_OVF_SetCallBack(void (* local_Ptr) (void));
void Timer1_OCA_SetCallBack(void (* local_Ptr) (void));
void Timer1_OCB_SetCallBack(void (* local_Ptr) (void));
void Timer1_ICU_SetCallBack(void (* local_Ptr) (void));




#endif /* TIMERS_H_ */
