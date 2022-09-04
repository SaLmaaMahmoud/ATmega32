/*
 * I2C.c
 *
 *  Created on: ???/???/????
 *      Author: m2381
 */


#include <avr/io.h>

#include "I2C.h"

void I2C_Init(void)
{
  // TWI initialization
  // Bit Rate: 400.000 kHz
  TWBR = 72;
  // Generate Acknowledge Pulse: On
  // TWI Interrupt: Off
  TWCR = 0x44;
  TWSR = 0x00;
  TWSR &= (~((1 << TWPS1) | (1 << TWPS0)));
}

void I2C_Start(void)
{

  // Send Start Condition
  TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

  // Wait for TWINT flag set in TWCR Register
  while (!(TWCR & (1 << TWINT)))
    ;
}

void I2C_Stop(void)
{
  // Send Stop Condition
  TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}

void I2C_Write(u8 data)
{
  // Put data On TWI Register
  TWDR = data;
  // Send Data
  TWCR = (1 << TWINT) | (1 << TWEN);
  // Wait for TWINT flag set in TWCR Register
  while (!(TWCR & (1 << TWINT)))
    ;
}

u8 I2C_ReadACK(void)
{
  TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);    //enable Ack
  // Wait for TWINT flag set in TWCR Register
  while (!(TWCR & (1 << TWINT)))
    ;
  // Read Data
  return TWDR;
}

u8 I2C_ReadNACK(void)
{
  TWCR = (1 << TWINT) | (1 << TWEN);
  // Wait for TWINT flag set in TWCR Register
  while (!(TWCR & (1 << TWINT)))
    ;
  // Read Data
  return TWDR;
}

u8 I2C_GetStatus(void)
{
  unsigned char status;
  status = TWSR & 0xF8;
  return status;
}
