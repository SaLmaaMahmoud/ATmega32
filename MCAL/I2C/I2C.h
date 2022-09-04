/*
 * I2C.h
 *
 *  Created on: ???/???/????
 *      Author: m2381
 */

#ifndef I2C_H_
#define I2C_H_

#include "STD_TYPES.h"

#define TW_MT_ARB_LOST			0x38
#define TW_MR_ARB_LOST			0x38
#define TW_START				0x08
#define TW_REP_START			0x10
#define TW_MT_SLA_ACK			0x18
#define TW_MT_DATA_ACK			0x28
#define TW_MR_DATA_NOT_ACK		0x58
#define TW_MR_SLA_NOT_ACK		0x48
#define TW_MT_SLA_NOT_ACK		0x20
#define TW_MT_DATA_NOT_ACK		0x30
#define TW_MR_DATA_ACK			0x50
#define TW_MR_SLA_ACK			0x40


void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Write(u8 data);
u8 I2C_ReadACK(void);
u8 I2C_ReadNACK(void);
u8 I2C_GetStatus(void);



#endif /* I2C_H_ */
