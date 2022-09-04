/*
 * Keypad.h
 *
 * Created: 9/4/2022 11:10:09 PM
 *  Author: Kyrillos Sawiris
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_


#define F_CPU 8000000UL

#include<avr/io.h>
#include<util/delay.h>

//keypad connection port
#define KEYPAD_PORT             PORTD
#define DataDir_KEYPAD_PORT     DDRD
#define keypadPIN               PIND

#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7



void Keypad_init();
char Keypad_getkey();


#endif /* KEYPAD_H_ */