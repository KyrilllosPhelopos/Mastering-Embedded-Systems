/*
 * Alarm_Actuator_Driver.h
 *
 *  Created on: Aug 21, 2022
 *      Author: phelp
 */

#ifndef ALARM_ACTUATOR_DRIVER_H_
#define ALARM_ACTUATOR_DRIVER_H_

#include"state.h"
#include"driver.h"

enum alarm_state
{
	init,
	waiting,
	Alarm_on ,
	Alarm_off
};


//state pointer to function
extern void (*alarm_State)();

// declaration state functions
STATE_define(Alarm_off);
STATE_define(Alarm_on);
STATE_define(waiting);

#endif /* ALARM_ACTUATOR_DRIVER_H_ */
