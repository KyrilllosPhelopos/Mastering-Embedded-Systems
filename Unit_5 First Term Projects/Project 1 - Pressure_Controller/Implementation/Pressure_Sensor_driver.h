/*
 * Pressure_Sensor_driver.h
 *
 *  Created on: Aug 21, 2022
 *      Author: phelp
 */

#ifndef PRESSURE_SENSOR_DRIVER_H_
#define PRESSURE_SENSOR_DRIVER_H_

#include"state.h"
#include"driver.h"


enum ps_state
{
	ps_init,
	ps_reading,
	ps_waiting
};

// declaration state functions
STATE_define(ps_init);
STATE_define(ps_reading);
STATE_define(ps_waiting);

// state pointer
extern void (*pressure_Stata)();


#endif /* PRESSURE_SENSOR_DRIVER_H_ */
