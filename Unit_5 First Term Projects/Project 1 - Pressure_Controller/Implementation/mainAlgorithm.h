/*
 * mainAlgorithm.h
 *
 *  Created on: Aug 21, 2022
 *      Author: phelp
 */

#ifndef MAINALGORITHM_H_
#define MAINALGORITHM_H_

#include"state.h"
#include"driver.h"
#include"Pressure_Sensor_driver.h"

enum MainAlg_state
{
	HighPressureDetection
};

STATE_define(HighPressureDetection);

extern void (* mainAlgState)();

#endif /* MAINALGORITHM_H_ */
