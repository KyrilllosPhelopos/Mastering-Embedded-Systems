#include <stdio.h>
#include <stdbool.h>

#define RCC_BASE 	0x40021000
#define PORTA_BASE 	0x40010800

#define RCC_CR			*(volatile uint32_t*)((RCC_BASE + 0x0))
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
	 * 		CLK SOURCE
	 *
	 * Bits 1:0 SW: System clock switch
				Set and cleared by software to select SYSCLK source.
				Set by hardware to force HSI selection when leaving Stop and Standby mode or in case of
				failure of the HSE oscillator used directly or indirectly as system clock (if the Clock Security
				System is enabled).
				00: HSI selected as system clock
				01: HSE selected as system clock
				10: PLL selected as system clock
				11: not allowed
	 * */
	RCC_CFGR |=(0b10<<0);


	/*
	 *     SETTING the multiplication value
	 *
			Bits 21:18 PLLMUL: PLL multiplication factor
			These bits are written by software to define the PLL multiplication factor. These bits can be
			written only when PLL is disabled.
			Caution: The PLL output frequency must not exceed 72 MHz.
			0000: PLL input clock x 2
			0001: PLL input clock x 3
			0010: PLL input clock x 4
			0110: PLL input clock x 8
	 * */

	RCC_CFGR |=(0b0110<<18);//mul * 8


	/*
	 * 		config PLL selector
	 *
		    Bit 16 PLLSRC: PLL entry clock source
			Set and cleared by software to select PLL clock source. This bit can be written only when
			PLL is disabled.
			0: HSI oscillator clock / 2 selected as PLL input clock
			1: HSE oscillator clock selected as PLL input clock
	 * */

	RCC_CFGR &=~(0b1<<16);//set it to HSI



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

	RCC_CFGR |=(0b100<<11);//divide by 2



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


	RCC_CFGR |=(0b100<<8);//divide by 2



	/*
	 * 		PLL Enable

	 *Bit 24 PLLON: PLL enable
						Set and cleared by software to enable PLL.
						Cleared by hardware when entering Stop or Standby mode. This bit can not be reset if the
						PLL clock is used as system clock or is selected to become the system clock.
						0: PLL OFF
						1: PLL ON
	 *
	 * */
	RCC_CR |=(0b1<<24);


	RCC_APB2ENR |=(0b1<<2);  //Turn on the clock for PORTA



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



