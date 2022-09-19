/*
 * RCC.c
 *
 *  Created on: Sep 16, 2022
 *      Author: phelp
 */

#include "RCC.h"


// PPRE2[2:0]: APB high-speed prescaler (APB2)
//Set and cleared by software to control the division factor of the APB High speed clock (PCLK2).
//0xx: HCLK not divided
//100: HCLK divided by 2
//101: HCLK divided by 4
//110: HCLK divided by 8
//111: HCLK divided by 16

const uint8_t APBPresTuble[8U] = {0,0,0,0,1,2,3,4};


//Bits 7:4 HPRE[3:0]: AHB prescaler
//Set and cleared by software to control AHB clock division factor.
//0xxx: SYSCLK not divided
//1000: SYSCLK divided by 2
//1001: SYSCLK divided by 4
//1010: SYSCLK divided by 8
//1011: SYSCLK divided by 16
//1100: SYSCLK divided by 64
//1101: SYSCLK divided by 128
//1110: SYSCLK divided by 256
//1111: SYSCLK divided by 512

const uint8_t AHBPResTuble [16U] = {0,0,0,0,0,0,0,1,2,3,4,5,6,7,8,9};

uint32_t MECAL_RCC_GetSys_Freq()
{

//	Bits 3:2 SWS[1:0]: System clock switch status
//	Set and cleared by hardware to indicate which clock source is used as system clock.
//	00: HSI oscillator used as system clock
//	01: HSE oscillator used as system clock
//	10: PLL used as system clock
//	11: Not applicable

	switch((RCC->CFGR >>2) & 0b11)
	{
	case 0 :
		return  HSI_CLK;
		break;
	case 1:
		return  HSE_CLK;
		break;
	case 2:
		return (uint32_t) 16000000UL;
		break;
	default:
		break;
	}
return -1;
}
uint32_t MECAL_RCC_GetHCLK_Freq()
{
	return (MECAL_RCC_GetSys_Freq() >>AHBPResTuble[((RCC->CFGR >>4) & 0xf)]);
}
uint32_t MECAL_RCC_GetPCLK1_Freq()
{
	return (MECAL_RCC_GetHCLK_Freq() >>APBPresTuble[((RCC->CFGR >>8) & 0b111)]);
}
uint32_t MECAL_RCC_GetPCLK2_Freq()
{
	return (MECAL_RCC_GetHCLK_Freq() >>APBPresTuble[((RCC->CFGR >>11) & 0b111)]);
}

