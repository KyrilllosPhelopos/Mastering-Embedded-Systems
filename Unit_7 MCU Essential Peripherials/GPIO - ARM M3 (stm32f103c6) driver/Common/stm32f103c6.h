/*
 * stm32f103c6.h
 *
 *  Created on: Sep 6, 2022
 *      Author: Kyrillos Sawiris
 */

#ifndef STM32F103C6_H_
#define STM32F103C6_H_

#include <stdint.h>


/*==========================================================
 	 	 Base addresses for AHB Peripherals
 ==========================================================*/
#define RCC_BASE       0x40021000

/*====================================================
 	 	 base addresses for APB2 Peripherals
==================================================== */
//GPIO A , B Fully included in LQFP48

#define GPIOA_BASE     0x40010800

#define GPIOB_BASE     0x40010C00

//GPIO C , D Partially  included in LQFP48

#define GPIOC_BASE     0x40011000

#define GPIOD_BASE     0x40011400

//GPIO E,F,G NOT included in LQFP48

#define GPIOE_BASE     0x40011800

#define GPIOF_BASE     0x40011C00

#define GPIOG_BASE     0x40012000

//AFIO
#define AFIO_BASE      0x40010000
//EXTI
#define EXTI_BASE      0x40010400


/*===================================================================
 * Peripheral Registers: RCC
 ===================================================================*/

typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
}RCC_TypeDef;

/*===================================================================
 * Peripheral Registers: GPIO
 ===================================================================*/

typedef struct
{
	volatile uint32_t   CRL;
	volatile uint32_t   CRH;
	volatile uint32_t   IDR;
	volatile uint32_t   ODR;
	volatile uint32_t   BSRR;
	volatile uint32_t   BRR;
	volatile uint32_t   LCKR;
}GPIO_TypeDef;

/*===================================================================
 * Peripheral Registers: AFIO
 ===================================================================*/

typedef struct
{
	volatile uint32_t	EVCR ;
	volatile uint32_t	MAPR ;
	volatile uint32_t	EXTICR1 ;
	volatile uint32_t	EXTICR2 ;
	volatile uint32_t	EXTICR3 ;
	volatile uint32_t	EXTICR4;
	volatile uint32_t	RESERVED;
	volatile uint32_t	MAPR2;

}AFIO_TypeDef;


/*===================================================================
 * Peripheral Registers: EXTI
 ===================================================================*/

typedef struct
{
	volatile uint32_t	IMR ;
	volatile uint32_t	EMR ;
	volatile uint32_t	RTSR;
	volatile uint32_t	FTSR ;
	volatile uint32_t	SWIER ;
	volatile uint32_t	PR;

}EXTI_TypeDef;


/*===================================================================
 * Peripheral Instants
 ===================================================================*/

#define GPIOA			((GPIO_TypeDef*)GPIOA_BASE)
#define GPIOB			((GPIO_TypeDef*)GPIOB_BASE)
#define GPIOC			((GPIO_TypeDef*)GPIOC_BASE)
#define GPIOD			((GPIO_TypeDef*)GPIOD_BASE)
#define GPIOE			((GPIO_TypeDef*)GPIOE_BASE)

#define RCC				((RCC_TypeDef*)RCC_BASE)

#define EXTI			((EXTI_TypeDef*)EXTI_BASE)

#define AFIO			((AFIO_TypeDef*)AFIO_BASE)


#endif /* STM32F103C6_H_ */
