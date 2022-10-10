/*
 * RCC.h
 *
 *  Created on: Sep 16, 2022
 *      Author: phelp
 */

#ifndef RCC_H_
#define RCC_H_

#include "stm32f103c6.h"
#include "GPIO.h"


#define HSI_CLK  (uint16_t) 8000000UL
#define HSE_CLK  (uint16_t) 16000000UL
//==============================================================
//-----------------------APIS----------------------------------
//==============================================================

uint32_t MECAL_RCC_GetSys_Freq();
uint32_t MECAL_RCC_GetHCLK_Freq();
uint32_t MECAL_RCC_GetPCLK1_Freq();
uint32_t MECAL_RCC_GetPCLK2_Freq();

#endif /* RCC_H_ */
