/*
 * Timer.h
 *
 * Created: 1/31/2021 1:30:37 AM
 *  Author: Salma
 */ 


#ifndef TIMER_H_
#define TIMER_H_

/********************** Registers Definition **********************/
#define TCCR_0		TCCR0
#define TCNT_0		TCNT0
#define OCR_0 		OCR0
#define TIMSK_		TIMSK
#define TIFR_		TIFR

#define TCCR_1A		TCCR1A
#define TCCR_1B		TCCR1B
#define TCNT_1		TCNT1

/******************************************************************/

/************************ Registers PINS *************************/
#define TIMSK_TOIE0		0
#define TIMSK_OCIE0		1
#define TIMSK_TOIE1		2
#define TIMSK_OCIE1B	3
#define TIMSK_OCIE1A	4

#define TIFR_TOV0		0
#define TIFR_OCF0		1
#define TIFR_TOV1		2
#define TIFR_OCF1B		3
#define TIFR_OCF1A		4

#define CS00			0
#define CS01			1
#define CS02			2

#define CS10			0
#define CS11			1
#define CS12			2
/****************************************************************/

/********************** Prescaller Modes ***********************/
typedef enum {
	prescallar_1	,
	prescallar_8	,
	prescallar_64	, 
	prescallar_256	,
	prescallar_1024	,
	prescallar_FallinEdge ,
	prescallar_RisinEdge ,
} prescallar ;
/****************************************************************/

//Initiate TIMER0
void TIMER0( prescallar pres ) ;

//Initiate TIMER1
void TIMER1( prescallar pres ) ;

#endif /* TIMER_H_ */