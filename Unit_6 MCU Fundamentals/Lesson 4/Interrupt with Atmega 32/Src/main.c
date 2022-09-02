/*
 * atmega32Interrupt.c
 *
 * Created: 8/31/2022 12:13:46 AM
 * Author : Kyrillos Sawiris 
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <avr/interrupt.h>
#include <util/delay.h>


int main(void)
{
	
	/*===============================================================
						configuration of INT0
	===================================================================*/
	
	/*
		Bit 1, 0 – ISC01, ISC00: Interrupt Sense Control 0 Bit 1 and Bit 0
	*/
    //0 1 Any logical change on INT0 generates an interrupt request.
	MCUCR |=(1<<ISC00);
	MCUCR &=~(1<<ISC01);
	
	
	/*===============================================================
						configuration of INT1
	===================================================================*/
	
	
	/*
		Bit 3, 2 – ISC11, ISC10: Interrupt Sense Control 1 Bit 1 and Bit 0
	*/
	//1 1 The rising edge of INT1 generates an interrupt request.
	
	MCUCR |=(1<<ISC10);
	MCUCR |=(1<<ISC11);
	

/*===============================================================
						configuration of INT2
===================================================================*/

	/*If ISC2 is written to zero, a falling edge on
	INT2 activates the interrupt. If ISC2 is written to one, a rising edge on INT2 activates*/
	MCUCSR&=~(1<<ISC2);
	
	
	/*===============================================================================
						enable interrupts 0,1,2 from GIFR 
	==================================================================================*/
	
	//Enable INT1
	GICR |=(1<<INTF1);
	//Enable INT0
	GICR |=(1<<INTF0);
	//Enable INT2
	GICR |=(1<<INTF2);
	
	
	
	
	/*=====================================================================
					SETTING THE DIRECTION THE LEDS to be OUTPUT
	===============================================================*/
	DDRD |=(1<<5);
	DDRD |=(1<<6);
	DDRD |=(1<<7);
	
	
	/*=====================================================
					enable global interrupt
	======================================================*/
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
	_delay_ms(1000);
}

//Action on INT1
ISR(INT1_vect)
{
	//turn on led on PORTD pin 6
	PORTD |=(1<<6);
	_delay_ms(1000);
}

//Action on INT2
ISR(INT2_vect)
{
	//turn on led on PORTD pin 7
	PORTD |=(1<<7);
	_delay_ms(1000);
}