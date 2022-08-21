/*
 * alarm_monitor.c
 *
 *  Created on: Aug 21, 2022
 *      Author: phelp
 */

#include"alarm_monitor.h"

void (*alarm_monitor_State)();

void high_pressure(void)
{
	alarm_monitor_State=STATE(Monitor_alarm_on);
}

STATE_define(Monitor_alarm_off)
{
    stop_alarm();
}


STATE_define(Monitor_alarm_on)
{
    start_alarm();
    alarm_monitor_State=STATE(Monitor_waiting);
}

STATE_define(Monitor_waiting)
{
    Delay(500000);
    alarm_monitor_State=STATE(Monitor_alarm_off);
}
