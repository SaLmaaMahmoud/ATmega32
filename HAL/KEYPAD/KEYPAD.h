/*
 * KEYPAD.h
 *
 * Created: 1/20/2021 12:16:57 AM
 *  Author: Salma
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

//Keypad Information
#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

#define keypadPORT PORTA_R
#define keypadPIN PINA_R
#define keypadDDR DDRA_R

void  Keypad_init();
u8    Keypad_getkey();

#endif /* KEYPAD_H_ */