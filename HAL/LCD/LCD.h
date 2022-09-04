/*
 * LCD.h
 *
 * Created: 1/21/2021 7:09:05 PM
 *  Author: Salma
 */ 


#ifndef LCD_H_
#define LCD_H_

void LCD_init( void ) ;
void LCD_writeCMD ( u8 CMD ) ;
void LCD_writeChar ( u8 Char ) ;
void LCD_writeCharPosition( u8 row , u8 col , u8 Char ) ;
void LCD_writeString( u8 row , u8 col , const u8* str ) ;



#endif /* LCD_H_ */