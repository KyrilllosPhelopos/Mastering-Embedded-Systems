/*
 * state.h
 *
 *  Created on: Aug 17, 2022
 *      Author: phelp
 */

#ifndef STATE_H_
#define STATE_H_

#include<stdio.h>
#include "stdlib.h"

#define STATE_define(_stateFunc_) void ST_##_stateFunc_()
#define STATE(_stateFunc_) ST_##_stateFunc_

#define Dprintf(...)	{fflush(stdout); fflush(stdin);\
						printf(__VA_ARGS__);\
						fflush(stdout); fflush(stdin);}

//state connections

void US_distance_set (int d);
void DC_Motor(int s);


#endif /* STATE_H_ */
