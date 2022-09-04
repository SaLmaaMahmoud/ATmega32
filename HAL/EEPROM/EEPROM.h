/*
 * EEPROM.h
 *
 *  Created on: ???/???/????
 *      Author: m2381
 */

#ifndef EEPROM_H_
#define EEPROM_H_


#include "I2C.h"
#include "BITMATH.h"

	#define ADDRESS		0x00

	/******************** PUBPLIC FUNCTIONS ********************/
	/*Description : Initialize EEPROM
		  Parameters  : void
		  return type : None*/
	void EEPROM_Init(void) ;

	/*Description : Write EEPROM
	  Parameters  : 8-bits data, 8-bits address
	  return type : None*/
	void EEPROM_Write (u8 data, u8 address) ;

	/*Description : Read EEPROM
	  Parameters  : 8-bits address
	  return type : None*/
	u8 EEPROM_Read (u8 address) ;



#endif /* EEPROM_H_ */
