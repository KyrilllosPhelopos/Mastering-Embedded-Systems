/*
 * Keypad.h
 *
 * Created: 9/4/2022 11:10:09 PM
 *  Author: Kyrillos Sawiris
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_


#include "stm32f103c6.h"
#include "GPIO.h"


//keypad connection port
#define KEYPAD_PORT GPIOB


#define R0 GPIO_PIN_0
#define R1 GPIO_PIN_1
#define R2 GPIO_PIN_3
#define R3 GPIO_PIN_4
#define C0 GPIO_PIN_5
#define C1 GPIO_PIN_6
#define C2 GPIO_PIN_7
#define C3 GPIO_PIN_8


void Keypad_init();
char Keypad_getkey();


#endif /* KEYPAD_H_ */
