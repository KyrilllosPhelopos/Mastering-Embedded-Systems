/*
 * alarm_monitor.h
 *
 *  Created on: Aug 21, 2022
 *      Author: phelp
 */

#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_

#include"state.h"
#include"driver.h"


enum Alarm_Monitor_State
{
	Monitor_waiting,
	Monitor_alarm_on ,
	Monitor_alarm_off
};

// declaration state functions
STATE_define(Monitor_waiting);
STATE_define(Monitor_alarm_on);
STATE_define(Monitor_alarm_off);

// state pointer
extern void (*alarm_monitor_State)();

#endif /* ALARM_MONITOR_H_ */
