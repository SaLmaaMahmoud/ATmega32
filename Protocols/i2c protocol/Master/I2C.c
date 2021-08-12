/*
 * I2C.c
 *
 * Created: 12/04/2021 04:24:20 PM
 *  Author: Salma
 */ 

#include "I2C.h"
#include "BITMATH.h"

/* Initialize I2C */
void i2c_voidInit(I2C_PRESCALER pre)
{
	//Enable I2C
	SET_BIT(TWCR , TWEN) ;			
	
	//Bit Rate
	TWBR = 0X48 ;		
				
	CLEAR_REG(TWSR) ;	
	
	switch ( pre )
	{
		case I2C_Prescaler_1 :
			break;
		case I2C_Prescaler_4 :
			SET_BIT(TWSR , TWPS0) ;
			break;
		case I2C_Prescaler_16 :
			SET_BIT(TWSR , TWPS1) ;
			break;
		case I2C_Prescaler_64 :
			SET_BIT(TWSR , TWPS0) ;
			SET_BIT(TWSR , TWPS1) ;
			break;
		default:
			break;
	}
	
	//Enable Ack
	SET_BIT(TWCR , TWEA) ;
	
}

/* Send Start condition */
void i2c_voidStart(void)
{
	SET_BIT(TWCR , TWINT) ;			//Clear flag
	SET_BIT(TWCR , TWSTA) ;			//Send start
	SET_BIT(TWCR , TWEN)  ;			//Enable I2C
	
	while( !(TWCR & (1<<TWINT) ) ){};				//Wait for TWINT Flag set
}

/* Send Stop condition */
void i2c_voidStop(void)
{
	SET_BIT(TWCR , TWINT) ;			//Clear flag
	SET_BIT(TWCR , TWSTO) ;			//Send stop
	SET_BIT(TWCR , TWEN)  ;			//Enable I2C
	
	while( !(TWCR & (1<<TWINT) ) ){};				//Wait for TWINT Flag set
}

/* Send data */
void i2c_voidSend_Data(u8 data)
{
	TWDR = data ;
	
	SET_BIT(TWCR , TWINT) ;			//Clear flag
	SET_BIT(TWCR , TWEN)  ;			//Enable I2C
		
	while( !(TWCR & (1<<TWINT) ) ){};				//Wait for TWINT Flag set
}

/* Check Acknowledge Bit */
u8 i2c_u8Read_Ack(void)
{
	SET_BIT(TWCR , TWINT) ;			//Clear flag
	SET_BIT(TWCR , TWEN)  ;			//Enable I2C
	SET_BIT(TWCR , TWEA)  ;			//Enable Ack
		
	while( !(TWCR & (1<<TWINT) ) ){};				//Wait for TWINT Flag set
		
	return TWDR ;
}

u8 i2c_u8Read_NACK(void)
{
	SET_BIT(TWCR , TWINT) ;			//Clear flag
	SET_BIT(TWCR , TWEN)  ;			//Enable I2C
	
	while( !(TWCR & (1<<TWINT) ) ){};				//Wait for TWINT Flag set
	
	return TWDR ;
}

u8 i2c_u8get_Status(void)
{
	u8 status;
	status = TWSR & 0xF8;
	return status;
}
