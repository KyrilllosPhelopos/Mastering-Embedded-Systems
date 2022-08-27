#include <stdio.h>
#include <stdbool.h>

#define RCC_BASE 	0x40021000
#define PORTA_BASE 	0x40010800

#define RCC_CFGR		*(volatile uint32_t*)((RCC_BASE + 0x4))
#define RCC_APB2ENR 	*(volatile uint32_t*)(RCC_BASE + 0x18)
#define GPIOA_CRH		*(volatile uint32_t*)(PORTA_BASE + 0x04)
#define GPIOA_ODR		*((volatile uint32_t*)(PORTA_BASE + 0x0c)


typedef union {
	volatile unsigned int    all_fieled;
	struct {
		volatile unsigned int  reserved:13;
		volatile unsigned int  P_13:1;
	}pin;
}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(PORTA_BASE + 0x0c);

int main(void) {

	/*
	 * 				APB2 Settings
	 *
		 PPRE2: APB high-speed prescaler (APB2)
		Set and cleared by software to control the division factor of the APB high-speed clock
		(PCLK2).
		0xx: HCLK not divided
		100: HCLK divided by 2
		101: HCLK divided by 4
		110: HCLK divided by 8
		111: HCLK divided by 16
	 * */
	RCC_CFGR |=(101<<11);

	/*
	 * 					APB1 Settings
	 *
	 * 	Bits 10:8 PPRE1: APB low-speed prescaler (APB1)
		Set and cleared by software to control the division factor of the APB low-speed clock
		(PCLK1).
		Warning: the software has to set correctly these bits to not exceed 36 MHz on this domain.
		0xx: HCLK not divided
		100: HCLK divided by 2
		101: HCLK divided by 4
		110: HCLK divided by 8
		111: HCLK divided by 16
	 * */
	RCC_CFGR |=(100<<8);




	GPIOA_CRH   &= 0xFF0FFFFF;
	GPIOA_CRH   |= 0x00200000;




	while(1){
		R_ODR->pin.P_13=1;
		for (int i =0 ;i < 5000 ; i++);
		R_ODR->pin.P_13=0;
		for (int i =0 ;i < 5000 ; i++);
	}
	return 0;
}



