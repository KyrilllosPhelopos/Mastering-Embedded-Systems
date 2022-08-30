/*
 * atmega32Interrupt.c
 *
 * Created: 8/31/2022 12:13:46 AM
 * Author : Kyrillos Sawiris 
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


int main(void)
{
    //Any logical change on INT0 generates an interrupt request. 01
	MCUCR |=(1<<ISC00);
	MCUCR &=~(1<<ISC01);
	
	//1 1 The rising edge of INT1 generates an interrupt request.
	MCUCR |=(1<<ISC10);
	MCUCR |=(1<<ISC10);
	
	/*If ISC2 is written to zero, a falling edge on
	INT2 activates the interrupt. If ISC2 is written to one, a rising edge on INT2 activates*/
	MCUSR|= (1<<ISC2);
	
	
	//enable interrupts 0,1,2 from GIFR 
	
	//Enable INT1
	GIFR |=(1<<INTF1);
	//Enable INT0
	GIFR |=(1<<INTF0);
	//Enable INT2
	GIFR |=(1<<INTF2);
	
	//set dirrection of leds to be out
	DDRD |=(1<<5);
	DDRD |=(1<<6);
	DDRD |=(1<<7);
	//enable global interrupt
	sei();
    while (1) 
    {
		//turn off all leds 
		PORTD &=~(1<<5);
		PORTD &=~(1<<6);
		PORTD &=~(1<<7);
		
    }
}

//Action on INT0
ISR(INT0_vect)
{
	//turn on led on PORTD pin 5
	PORTD |=(1<<5);
	_delay_ms(500);
}

//Action on INT1
ISR(INT1_vect)
{
	//turn on led on PORTD pin 6
	PORTD |=(1<<6);
	_delay_ms(500);
}

//Action on INT2
ISR(INT2_vect)
{
	//turn on led on PORTD pin 7
	PORTD |=(1<<7);
	_delay_ms(500);
}