/*
 * EEPROM.c
 *
 *  Created on: ???/???/????
 *      Author: m2381
 */


#include "EEPROM.h"

void EEPROM_Init(void)
{
	I2C_Init();
}

void EEPROM_Write (u8 data, u8 address)
{
	I2C_Start( ) ;

	I2C_Write( 0xA0 ) ;				//Write Mode
	I2C_Write( address ) ;
	I2C_Write( data ) ;

	I2C_Stop( ) ;
}


u8 EEPROM_Read (u8 address)
{
	u8 res = 0 ;

	I2C_Start( ) ;

	I2C_Write( 0xA0 ) ;				//Write Mode
	I2C_Write( address ) ;

	I2C_Start( ) ;

	I2C_Write( 0xA1 ) ;				//Read Mode

	res = I2C_ReadNACK() ;

	I2C_Stop( ) ;

	return res ;
}
