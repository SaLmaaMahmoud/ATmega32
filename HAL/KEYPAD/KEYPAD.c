/*
 * KEYPAD.c
 *
 * Created: 1/20/2021 12:16:41 AM
 *  Author: Salma
 */ 

#define F_CPU 8000000

#include "util/delay.h"

#include "BITMATH.h"
#include "STD_TYPES.h"

#include "GPIO.h"
#include "KEYPAD.h"

int Key_padRow[] = {R0, R1, R2, R3};	//rows
int Key_padCol[] = {C0, C1, C2, C3};	//column 
	
void  Keypad_init()
{
	keypadDDR &= ~ (1<<R0)|(1<<R1)|(1<<R2)|(1<<R3);			//A0>>A3 : OUTPUTS
	
	keypadDDR |= ((1<<C0)|(1<<C1)|(1<<C2)|(1<<C3));			//A4>>A7 : INPUTS
	
	keypadPORT = 0xFF ;
}


u8 Keypad_getkey()
{
	int i, j;
	for(i = 0; i < 4; i++)
	{
		keypadPORT |= ((1<<Key_padCol[0] ) | (1<<Key_padCol[1] ) | (1<<Key_padCol[2] ) | (1<<Key_padCol[3] ));

		keypadPORT &= ~ (1 << Key_padCol[i]);	//send a low to a particular row of the keypad

		for(j = 0; j < 4; j++)
		{
			if(!(keypadPIN & (1<<Key_padRow[j])))	//check if key is pressed
			{
				while(!(keypadPIN & (1<<Key_padRow[j])));  //wait for key to be released  (Single press)
				switch(i)
				{
					//ROW 0
					case(0):
					{
						if		(j == 0) return '7';
						else if (j == 1) return '8';
						else if (j == 2) return '9';
						else if (j == 3) return '/';
						break;
					}
					//ROW 1
					case(1):
					{
						if		(j == 0) return '4';
						else if (j == 1) return '5';
						else if (j == 2) return '6';
						else if (j == 3) return '*';
						break;
					}
					//ROW 2
					case(2):
					{
						if		(j == 0) return '1';
						else if (j == 1) return '2';
						else if (j == 2) return '3';
						else if (j == 3) return '-';
						break;
					}
					//ROW 3
					case(3):
					{
						if		(j == 0) return 'O';
						else if (j == 1) return '0';
						else if (j == 2) return '=';
						else if (j == 3) return '+';
						break;
					}
				} //End Switch
			} //End if Condition
		} //End first for loop
	} //End second for loop
	
	return 0;
}