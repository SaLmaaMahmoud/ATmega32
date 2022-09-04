/*
 * LCD.c
 *
 * Created: 1/21/2021 7:08:51 PM
 *  Author: Salma
 *
 *	LCD PINS >> POTR_C
 *	RS >> PORT_B , PIN5
 *	RW >> PORT_B , PIN6
 *	E  >> PORT_B , PIN7
 */ 

#define F_CPU 8000000

#include "util/delay.h"

#include "BITMATH.h"
#include "STD_TYPES.h"

#include "GPIO.h"
#include "LCD.h"


static void send( u8 Byte )
{
	GPIO_voidSetPortPinValue(PORT_B , PIN1 , 0) ;   //// RW LOW == Selects write
	GPIO_voidSetPortValue(PORT_A , Byte) ;
	GPIO_voidSetPortPinValue(PORT_B , PIN3 , 1) ;   //// E HIGH == Reset
	_delay_ms( 1 ) ;
	GPIO_voidSetPortPinValue(PORT_B , PIN3 , 0) ;   //// E LOW == Making falling edge
}

void LCD_init( void )
{
	_delay_ms( 35 ) ;						// Wait more than 30 ms for power
	
	LCD_writeCMD( 0b00111000 ) ;			// 0b00111000 == 0x38		8 bit/ 2-line interface/ 5x8 dots
	_delay_ms( 1 ) ;						// Wait more than 37 us for Command to finish
	
	LCD_writeCMD( 0b00001100 ) ;			// 0b00001100 == 0x0C		Display on/ cursor off/ blinking off
	_delay_ms( 1 ) ;						// Wait more than 37 us for Command to finish
	
	LCD_writeCMD( 0b00000001 ) ;			// 0b00000001 == 0x01		Display Clear
	_delay_ms( 2 ) ;						// Wait more than 1.52 ms for Command to finish
	
	LCD_writeCMD( 0b00001100 ) ;			// 0b00000110 == 0x06		AC increment/ shift of entire display disabled
	_delay_ms( 1 ) ;						// Wait more than 37 us for Command to finish
}

void LCD_writeCMD ( u8 CMD )
{
	GPIO_voidSetPortPinValue(PORT_B , PIN0 , 0) ;   //// RS LOW == Selects IR
	send( CMD ) ;
	
}

void LCD_writeChar ( u8 Char )
{		
	GPIO_voidSetPortPinValue(PORT_B , PIN0 , 1) ;   //// RS HIGH == Selects DR
	send( Char ) ;
}

void LCD_writeCharPosition( u8 row , u8 col , u8 Char )
{
	/*
		row 0:		0x00 - 0x0F	
		row 1:		0x40 - 0x4F
		
		start			shift
		(0x40*row)		col
		
		address = (0x40*row)<<col
	*/
	
	u8 location = (0x80 | ((0x40*row)+col)) ;
	LCD_writeCMD(location) ;
	
	LCD_writeChar(Char) ;
}

void LCD_writeString( u8 row , u8 col , const u8* str )
{
	/*
		row 0:		0x00 - 0x0F	
		row 1:		0x40 - 0x4F
		
		start			shift
		(0x40*row)		col
		
		address = (0x40*row)<<col
	*/
	
	u8 location = (0x80 | ((0x40*row)+col)) ;
	LCD_writeCMD(location) ;
	
	u8 i = 0 ;
	
	while(str[i] != '\0'){
		if((((0x40*row)+col) + i) == 0x10)
			LCD_writeCMD(0b11000000);
		LCD_writeChar(str[i]) ;
		i++ ;
	}
}
