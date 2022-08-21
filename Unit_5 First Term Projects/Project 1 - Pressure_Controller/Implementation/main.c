#include "Pressure_Sensor_driver.h"
#include "mainAlgorithm.h"
#include "alarm_monitor.h"
#include "Alarm_Actuator_Driver.h"

	void setup()
	{
		GPIO_INITIALIZATION();
		pressure_Stata=STATE(ps_init);
		mainAlgState=STATE(HighPressureDetection);
		alarm_monitor_State=STATE(Monitor_alarm_off);
		alarm_State=STATE(Alarm_off);
	}

int main ()
{
	setup();
	while (1)
	{
		pressure_Stata();
		mainAlgState();
		alarm_monitor_State();
		alarm_State();
	}

}
