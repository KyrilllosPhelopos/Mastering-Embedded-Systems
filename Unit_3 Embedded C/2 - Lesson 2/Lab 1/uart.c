#include "uart.h"

#define UART0DR *((volatile unsigned int *)((unsigned int *)0x101f1000))

void UART0_Send_String(unsigned char * P_TX_Str)
{
while (* P_TX_Str != '\0')
{
UART0DR =  (unsigned int) * P_TX_Str;
P_TX_Str++;
}
}