/*
 * state.h
 *
 *  Created on: Aug 21, 2022
 *      Author: Kyrillos Sawiris
 */

#ifndef STATE_H_
#define STATE_H_

#define STATE_define(_stateFunc_) void ST_##_stateFunc_()
#define STATE(_stateFunc_) ST_##_stateFunc_



//state connections

void high_pressure(void);
void stop_alarm(void);
void start_alarm(void);
void set_pressure_value(int pressure_value);


#endif /* STATE_H_ */
