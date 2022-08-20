

#ifndef US_Sensor_H_
#define US_Sensor_H_

#include"state.h"

enum US_status{
	US_busy
};

//prototype
void US_init();
STATE_define(US_busy);
//global pointer to function
extern void (* US_state)();



#endif
