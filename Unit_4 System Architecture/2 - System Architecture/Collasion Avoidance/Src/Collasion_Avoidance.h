/*
 * state.h
 *
 *  Created on: Aug 17, 2022
 *      Author: phelp
 */

#ifndef Collasion_Avoidance_
#define Collasion_Avoidance_



#include"state.h"

enum CA_status{
	CA_waiting,
	CA_driving
};

//prototype

STATE_define(CA_waiting);
STATE_define(CA_driving);
//global pointer to function
extern void (* CA_state)();


#endif /* Collasion_Avoidance_ */
