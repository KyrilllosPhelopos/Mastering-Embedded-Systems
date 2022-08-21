/*
 * Pressure_Sensor_driver.c
 *
 *  Created on: Aug 21, 2022
 *      Author: phelp
 */

#include"Pressure_Sensor_driver.h"

static int Pval =0;

void (*pressure_Stata)();

STATE_define(ps_init)
{
	// go to ready state
	pressure_Stata=STATE(ps_reading);
}

STATE_define(ps_reading)
{
	/*
	 *1- read Pval
	 *2- send Pval
	 *3- go to wait state
	 */
    Pval=getPressureVal();
    set_pressure_value( Pval);
    pressure_Stata=STATE(ps_waiting);

}

STATE_define(ps_waiting)
{
	/*
	 * wait for a whole and then goto ready state
	 * */
    Delay(60000);
    pressure_Stata=STATE(ps_reading);
    pressure_Stata();
}
