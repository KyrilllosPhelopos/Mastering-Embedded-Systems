/*
 * GccApplication1.c
 *
 * Created: 9/3/2022 3:40:54 PM
 * Author : Kyrillos Sawiris
 */ 

#define F_CPU 8000000UL
#include "MemMap.h"
//#include <avr/io.h>
#include "CommonMacros.h"
#include <util/delay.h>


int main(void)
{
   // using portc pin 4,5,6,7 for 7Seg_DECO
   //and portc pin 2,3 for transistor used in multiplexing 
   
   DDRC |=0xfc;
    while (1) 
    {
		for(int i =0 ;i<9;i++)
		{
			//reset 7_Seg
			RESET_BIT(PORTC,0b1111,4);
			//set the value of i to the 7Seg
			SET_BIT(PORTC,i,4);
			//open transistor 1 for 200msec
			SET_BIT(PORTC,1,3);
			_delay_ms(200);
			//open transistor 1 for 200msec
			SET_BIT(PORTC,1,2);
			_delay_ms(200); 
		}
    }
}

