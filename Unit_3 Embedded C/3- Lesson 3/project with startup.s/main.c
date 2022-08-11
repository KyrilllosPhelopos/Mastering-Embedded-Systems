#include <stdio.h>
#include <stdbool.h>

#include "Platform_Types.h"

#define RCC_BASE 	0x40021000
#define PORTA_BASE 	0x40010800

#define RCC_APB2ENR 	*(volatile uint32_t*)(RCC_BASE + 0x18)
#define GPIOA_CRH		*(volatile uint32_t*)(PORTA_BASE + 0x04)
#define GPIOA_ODR		*((volatile uint32_t*)(PORTA_BASE + 0x0c)


typedef union {
	vuint32_t  all_fieled;
	struct {
		vuint32_t  reserved:13;
		vuint32_t  P_13:1;
	}pin;
}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(PORTA_BASE + 0x0c);

int main(void) {

	int i;
	RCC_APB2ENR |= (1<<2);
	GPIOA_CRH   &= 0xFF0FFFFF;
	GPIOA_CRH   |= 0x00200000;

	while(1){
		R_ODR->pin.P_13=1;
		for ( i =0 ;i < 5000 ; i++);
		R_ODR->pin.P_13=0;
		for (i =0 ;i < 5000 ; i++);
	}
	return 0;
}



