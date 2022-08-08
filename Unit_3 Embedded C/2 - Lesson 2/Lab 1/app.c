#include "uart.h"

unsigned char string_buff [100] = "learn-in-depth:kyrillos";

void main(void)
{
	
	UART0_Send_String(string_buff);
}