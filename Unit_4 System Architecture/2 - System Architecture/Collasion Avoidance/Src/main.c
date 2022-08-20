/*
 * main.c
 *
 *  Created on: Aug 17, 2022
 *      Author: phelp
 */


#include "Collasion_Avoidance.h"
#include "DC_Motor.h"
#include"US_Sensor.h"



void setup(void)
{
	// init all the drivers
	US_init();
	DC_init();

	// init IRQ ....
	// init HAL US_Driver DC_Driver
	// init BLOCK
	// Set States pointers for each block
	CA_state = STATE(CA_waiting);

     US_state= ST_US_busy;
     DC_state = STATE(DC_idle);
}

int main(void)
{
	volatile int i;
	setup();

	while(1)
	{
		// Call state for each block
		US_state();
		CA_state();
		DC_state();

		// Delay
		for(i = 0 ; i <= 50000 ; i++);
	}
	return 0;
}
