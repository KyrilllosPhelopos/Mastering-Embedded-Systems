/*
 * GccApplication1.c
 *
 * Created: 9/2/2022 11:24:16 PM
 * Author : Kyrillos Sawiris 
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>



int main(void)
{
	/*==============================================
		setting PORTD pins 4,5,6,7 as OUTPUT pins
	=============================================*/
	 
		DDRD |=(1<<4);//Buzzer
		DDRD |=(1<<5);//led 1
		DDRD |=(1<<6);//led 2
		DDRD |=(1<<7);//led 3 
	
    
    while (1) 
    {
		PORTD |=(1<<5);
		_delay_ms(1000);
		PORTD &=~(1<<5);
		
		PORTD |=(1<<6);
		_delay_ms(1000);
		PORTD &=~(1<<6);
		
		PORTD |=(1<<7);
		_delay_ms(1000);
		PORTD &=~(1<<7);
		
		PORTD |=(1<<4);
		_delay_ms(1000);
		PORTD &=~(1<<4);
    }
}

