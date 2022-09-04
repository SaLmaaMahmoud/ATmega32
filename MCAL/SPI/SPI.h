#ifndef SPI_H_
#define SPI_H_

#include <stdint.h>

void spi_init_master() ;
void spi_init_slave() ;
u8 spi_transfer_data(u8 data) ; //transmit & recieve in the same function


#endif
