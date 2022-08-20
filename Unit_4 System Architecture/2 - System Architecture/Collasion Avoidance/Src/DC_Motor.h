

#ifndef DC_Sensor_H
#define DC_Sensor_H

#include"state.h"

enum DC_status{
	DC_idle,
	DC_busy
};

//prototype
void DC_init();
STATE_define(DC_idle);
STATE_define(DC_busy);
//global pointer to function
extern void (* DC_state)();


#endif
