#include "BITMATH.h"
#include "STD_TYPES.h"
#include "SPI.h"
#include <avr/io.h>

void spi_init_master()
{
	//LSB
	SET_BIT(SPCR , DDRD) ;
	
	//MASTER select
	SET_BIT(SPCR , MSTR) ;
	
	//Clock polarity leading -> falling edge
	SET_BIT(SPCR , CPOL) ;
	
	//Setup -> leading edge
	SET_BIT(SPCR , CPHA) ;
	
	//Clock prescaler -> 64
	CLEAR_BIT(SPSR , SPI2X) ;
	SET_BIT(SPCR , SPR1) ;
	CLEAR_BIT(SPCR , SPR0) ;
	
	//Enable spi
	SET_BIT(SPCR , SPE) ;
	
	//Disable interrupt
	CLEAR_BIT(SPCR , SPIE) ;
}


void spi_init_slave()
{
	//LSB
	SET_BIT(SPCR , DDRD) ;
	
	//SLAVE select
	CLEAR_BIT(SPCR , MSTR) ;
	
	//Clock polarity leading -> falling edge
	SET_BIT(SPCR , CPOL) ;
	
	//Setup -> leading edge
	SET_BIT(SPCR , CPHA) ;
	
	//Enable spi
	SET_BIT(SPCR , SPE) ;
	
	//Disable interrupt
	CLEAR_BIT(SPCR , SPIE) ;
}


//transmit & recieve in the same function
u8 spi_transfer_data(u8 data)
{
	SPDR = data ;
	
	//Waiting (busy wait) for transfer to end
	while(GIT_BIT(SPSR , SPIF) == 0)
	{
		
	}
	
	return SPDR ;
}
