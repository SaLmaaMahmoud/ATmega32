/*
 * UART.c
 *
 * Created: 14/04/2021 01:04:57 AM
 *  Author: Salma
 */ 

#include "STD_TYPES.h"
#include "BITMATH.h"

#include "UART.h"

void UART_Init( void )
{
	//Set Baud Rate --> 9600/16MHz
	UBRRL = 102 ;
	CLEAR_REG( UBRRH ) ;
	
	//Set Frame Format --> 8-bits data , 1 Stop , No Parity
	UCSRC = 0X86 ;
	
	//Enable Rx and Tx
	SET_BIT(UCSRB , RXEN) ;
	SET_BIT(UCSRB , TXEN) ;
}

void UART_SendChar(u8 data)
{
	//Wait for empty transmit buffer
	while ( (UCSRA&0x20) == 0x00 ){} ;
	
	//Send the data
	UDR = data ;
}

u8 UART_GetChar(void)
{
	u8 data ;
	
	//Wait for empty transmit buffer
	while ( (UCSRA&0x80) == 0x00 ){} ;
		
	/* Clear Flag */
	SET_BIT(UCSRA , RXC) ;
	
	data = UDR ;
	//Return received data
	return data ;
}

void UART_SendString(u8 *data)
{
	while ( *data != '\0')
	{
		UART_SendChar( *data ) ;
		data++ ;
	}
}

void UART_GetString(u8 *data)
{
	while ( *data != '\0')
	{
		*data = UART_GetChar( ) ;
		data++ ;
	}
}

