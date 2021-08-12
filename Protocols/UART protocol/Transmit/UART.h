/*
 * UART.h
 *
 * Created: 14/04/2021 01:05:15 AM
 *  Author: Salma
 */ 


#ifndef UART_H_
#define UART_H_
	
	/* Registers Definition */
	/* UART Registers */
	#define		UDR			*( (volatile u8 *) (0x2C) )
	#define		UCSRA		*( (volatile u8 *) (0x2B) )
	#define		UCSRB		*( (volatile u8 *) (0x2A) )
	#define		UBRRL		*( (volatile u8 *) (0x29) )
	#define		UCSRC		*( (volatile u8 *) (0x40) )
	#define		UBRRH		*( (volatile u8 *) (0x40) )

	/* UCSRA Macros */
	#define		RXC		7
	#define		TXC		6
	#define		UDRE	5
	#define		FE		4
	#define		DOR		3
	#define		PE		2
	#define		U2X		1
	#define		MPCM	0
	
	/* UCSRB Macros */
	#define		RXCIE	7
	#define		TXCIE	6
	#define		UDRIE	5
	#define		RXEN	4
	#define		TXEN	3
	#define		UCSZ2	2
	#define		RXB8	1
	#define		TXB8	0

	/* UCSRC Macros */
	#define		URSEL	7
	#define		UMSEL	6
	#define		UPM1	5
	#define		UPM0	4
	#define		USBS	3
	#define		UCSZ1	2
	#define		UCSZ0	1
	#define		UCPOL	0
	
	/******************** PUBPLIC FUNCTIONS ********************/
	
	/*Description : Initialize UART Module
	  Parameters  : void
	  return type : void*/
	void UART_Init( void ) ;
	
	/*Description : Send Char
	  Parameters  : u8 data
	  return type : void*/
	void UART_SendChar(u8 data);

	/*Description : Get Char
	  Parameters  : void
	  return type : 8-bits*/
	u8 UART_GetChar(void);
	
	/*Description : Send String
	  Parameters  : u8 *data
	  return type : void*/
	void UART_SendString(u8 *data);

	/*Description : Get String
	  Parameters  : u8 *data
	  return type : void*/
	void UART_GetString(u8 *data);

	
#endif /* UART_H_ */