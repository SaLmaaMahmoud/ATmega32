/*
 * LED.h
 *
 * Created: 13/08/2021 03:47:31 AM
 *  Author: Salma
 */ 


#ifndef LED_H_
#define LED_H_

#include "STD_TYPES.h"
#include "GPIO.h"

/* LED CONFIGURATION */
#define LED_DIRECTION		OUTPUT
#define LED_PORT			PORT_C
#define LED_PIN				PIN5
/***********************/

/******************** PUBPLIC FUNCTIONS ********************/

/*Description : Initialize the Heating element LED
  Parameters  : void
  Return      : None */
void LED_Init(void) ;

/*Description : Turn ON the Heating element LED
  Parameters  : void
  Return      : None */
void LED_ON(void) ;

/*Description : Turn OFF the Heating element LED
  Parameters  : void
  Return      : None */
void LED_OFF(void) ;

/*Description : Toggle the Heating element LED
  Parameters  : void
  Return      : None */
void LED_Blink(void) ;


#endif /* LED_H_ */