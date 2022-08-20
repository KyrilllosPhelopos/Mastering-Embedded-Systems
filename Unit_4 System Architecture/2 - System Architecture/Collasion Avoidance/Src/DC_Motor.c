/*
 * Collasion_Avoidance.c
 *
 *  Created on: Aug 17, 2022
 *      Author: phelp
 */


#include"DC_Motor.h"

 void (* DC_state)();

 static unsigned int speed;
 enum DC_status DC_state_id;


void DC_init()
{
	printf("DC_init");
}

void DC_Motor(int s)
{
speed = s;
DC_state = STATE(DC_busy);

printf("CA -> -> -> DC   DC_Motor() \n");
}
STATE_define(DC_idle)
{
	 //state action
	 DC_state_id = DC_idle;
	 DC_state = STATE(DC_idle);

	 printf("DC_idle STATE: speed = %d \n",speed);
}


STATE_define(DC_busy)
{
	 //state action
	 DC_state_id = DC_busy;
	 DC_state = STATE(DC_idle);

	 printf("DC_busy STATE: speed = %d \n",speed);
}
