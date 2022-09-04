/*
 * Timer.c
 *
 * Created: 1/31/2021 1:30:08 AM
 *  Author: Salma
 */ 

#include <avr/io.h>

#include "BITMATH.h"
#include "STD_TYPES.h"

#include "GPIO.h"
#include "Timer.h"

void TIMER0( prescallar pres )
{
	SET_BIT(TIMSK_ , TIMSK_TOIE0) ;			//Enable Timer interrupt
	TCCR_0 = 0x00 ;							//Reset
	
	switch ( pres ){
		case prescallar_1 :
			SET_BIT(TCCR_0 , CS00) ;
			break;
		
		case prescallar_8 :
			SET_BIT(TCCR_0 , CS01) ;
			break;
		
		case prescallar_64 :
			SET_BIT(TCCR_0 , CS00) ;
			SET_BIT(TCCR_0 , CS01) ;
			break;
		
		case prescallar_256 :
			SET_BIT(TCCR_0 , CS02) ;
			break;
			
		case prescallar_1024 :
			SET_BIT(TCCR_0 , CS00) ;
			SET_BIT(TCCR_0 , CS02) ;
			break;
		
		case prescallar_FallinEdge :
			SET_BIT(TCCR_0 , CS01) ;
			SET_BIT(TCCR_0 , CS02) ;
			break;
			
		case prescallar_RisinEdge :
			SET_BIT(TCCR_0 , CS00) ;
			SET_BIT(TCCR_0 , CS01) ;
			SET_BIT(TCCR_0 , CS02) ;
			break;
			
		default:
			break;
	}
}


void TIMER1( prescallar pres )
{
	SET_BIT(TIMSK_ , TIMSK_TOIE1) ;		//Enable Timer interrupt
	
	//Reset
	TCCR1A = 0x00 ;
	TCCR1B = 0x08 ;		//CTC Mode						
	
	TCNT_1 = 64560 ;
	
	switch ( pres ){
		case prescallar_1 :
			SET_BIT(TCCR_1B , CS10) ;
			break;
			
		case prescallar_8 :
			SET_BIT(TCCR_1B , CS11) ;
			break;
			
		case prescallar_64 :
			SET_BIT(TCCR_1B , CS10) ;
			SET_BIT(TCCR_1B , CS11) ;
			break;
			
		case prescallar_256 :
			SET_BIT(TCCR_1B , CS12) ;
			break;
			
		case prescallar_1024 :
			SET_BIT(TCCR_1B , CS10) ;
			SET_BIT(TCCR_1B , CS12) ;
			break;
			
		case prescallar_FallinEdge :
			SET_BIT(TCCR_1B , CS11) ;
			SET_BIT(TCCR_1B , CS12) ;
			break;
			
		case prescallar_RisinEdge :
			SET_BIT(TCCR_1B , CS10) ;
			SET_BIT(TCCR_1B , CS11) ;
			SET_BIT(TCCR_1B , CS12) ;
			break;
			
		default:
			break;
	}
}