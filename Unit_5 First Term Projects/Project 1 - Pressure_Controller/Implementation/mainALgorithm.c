/*
 * mainALgorithm.c
 *
 *  Created on: Aug 21, 2022
 *      Author: phelp
 */

#include"mainAlgorithm.h"

int Pval =0;
int threshold =20;

void (* mainAlgState)();

void set_pressure_value(int pressure_value)
{
	Pval=pressure_value;
	mainAlgState=STATE(HighPressureDetection);
}

STATE_define(HighPressureDetection)
{
	if(Pval>threshold)
		high_pressure();
	mainAlgState=STATE(HighPressureDetection);
}
