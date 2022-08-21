/*
 * Alarm_Actuator_Driver.c
 *
 *  Created on: Aug 21, 2022
 *      Author: kyrillos
 */

#include"Alarm_Actuator_Driver.h"


void (*alarm_State)();


void stop_alarm(void)
{

	alarm_State=STATE(Alarm_off);
}

void start_alarm(void)
{

	alarm_State=STATE(Alarm_on);
}

STATE_define(init)
{
	alarm_State=STATE(Alarm_off);
}

STATE_define(waiting)
{
	alarm_State=STATE(Alarm_off);
}

STATE_define(Alarm_off)
{
	Set_Alarm_actuator(1);
	alarm_State=STATE(waiting);
}

STATE_define(Alarm_on)
{
	Set_Alarm_actuator(0);
	alarm_State=STATE(waiting);
}

