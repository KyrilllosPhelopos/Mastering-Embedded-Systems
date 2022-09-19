/*
 * USART.c
 *
 *  Created on: Sep 16, 2022
 *      Author: phelp
 */


/*===========================================
 *				includes
 *===========================================*/
#include "USART.h"
#include "stm32f103c6.h"
#include "RCC.h"
#include "GPIO.h"


USART_Config* Global_USART_Config[3] = {0,0,0};

/*=============================================================================================
 * 						  FUNCTIONS Definitions
==========================================================================================*/

//
///******************************************************************************
// * \Name            : MCAL_UART_Init
// * \Description     : Initialize the uart module with parameters of the configuration struct
// * \Parameters (in) : - USARTx: which uart we use
//						- UART_Config: configuration struct
// * \Parameters (out): None
// * \Return value:   : None
// *******************************************************************************/

void MCAL_UART_Init(USART_TypeDef* USARTx, USART_Config* UART_Config)
{
	//enable the clock to the module
	//1. Enable the USART by writing the UE bit in USART_CR1 register to 1.
	//2. Enable USART TX/RX engines according to the USART_Mode configuration item
	//3. Program the M bit in USART_CR1 to define the word length.
	//4. Program the number of stop bits in USART_CR2.
	//5. program the parity type in USART_CR1
	//6. program the control flow in USART_CR3
	//7. Select the desired baud rate using the USART_BRR register.
	//8. ENABLE / DISABLE Interrupt




	uint32_t BRR , pclk;//to be used to in setting boud rate

	//enable clk for the corresponding USART
	if (USARTx ==USART1)
	{
		RCC_USART1_CLK_EN();
		Global_USART_Config[0] = UART_Config;
	}
	else if (USARTx ==USART2)
	{
		RCC_USART2_CLK_EN();
		Global_USART_Config [1]= UART_Config;
	}
	else if (USARTx ==USART3)
	{
		RCC_USART3_CLK_EN();
		Global_USART_Config [2]= UART_Config;
	}


	//1. Enable the USART by writing the UE bit in USART_CR1 register to 1.

	/*Bit 13 UE: USART enable
	When this bit is cleared the USART prescalers and outputs are stopped and the end of the
	current
	byte transfer in order to reduce power consumption. This bit is set and cleared by software.
	0: USART prescaler and outputs disabled
	1: USART enabled*/
	USARTx->CR1 |=1<<13;

	//  2. Enable USART TX/RX engines according to the USART_Mode configuration item
	USARTx->CR1 |= UART_Config->UART_MODE;

	//	3. Program the M bit in USART_CR1 to define the word length.

	/*Bit 12 M: Word length
	This bit determines the word length. It is set or cleared by software.
	0: 1 Start bit, 8 Data bits, n Stop bit
	1: 1 Start bit, 9 Data bits, n Stop bit*/
	USARTx->CR1|= UART_Config->Payload_Length;

	//	4. Program the number of stop bits in USART_CR2.

	/*Bits 13:12 STOP: STOP bits
	These bits are used for programming the stop bits.
	00: 1 Stop bit
	01: 0.5 Stop bit
	10: 2 Stop bits
	11: 1.5 Stop bit*/
	USARTx->CR2 |=UART_Config->StopBits;

	//   5. program the parity type in USART_CR1

	USARTx->CR1 |=UART_Config->Parity;

	//   6. program the control flow in USART_CR3
	/*Bit 9 CTSE: CTS enable
	0: CTS hardware flow control disabled
	1: CTS mode enabled

	Bit 8 RTSE: RTS enable
	0: RTS hardware flow control disabled
	1: RTS interrupt enabled*/
	USARTx->CR3 |=UART_Config->Parity;

	//	7. Select the desired baud rate using the USART_BRR register.

	if(USARTx == USART1)
		pclk = MECAL_RCC_GetPCLK2_Freq();
	else
		pclk = MECAL_RCC_GetPCLK1_Freq();

	BRR = UART_BRR_Register(pclk, UART_Config->BaudRate);
	USARTx->BRR = BRR;

	//   8. ENABLE / DISABLE Interrupt
	if (UART_Config->IRQ_Enable != UART_IRQ_Enable_NONE)
	{
		USARTx->CR1 |= (UART_Config->IRQ_Enable);

		/* Enable NVIC for USARTx IRQ */
		if (USARTx == USART1)
			NVIC_IRQ37_USART1_EN();

		else if (USARTx == USART2)
			NVIC_IRQ38_USART2_EN();

		else if (USARTx == USART3)
			NVIC_IRQ39_USART3_EN();
	}
}


//
///******************************************************************************
// * \Name            : MCAL_UART_DeInit
// * \Description     : deinitialize the uart module
// * \Parameters (in) : - USARTx: which uart we use
// * \Parameters (out): None
// * \Return value:   : None
// *******************************************************************************/


void MCAL_UART_DeInit(USART_TypeDef* USARTx)
{
	//1. Reset clk
	//2. disable interrupt
	if (USARTx == USART1)
	{
		RCC_USART1_CLK_DI();
		NVIC_IRQ37_USART1_DI();
	}

	else if (USARTx == USART3)
	{
		RCC_USART2_CLK_DI();
		NVIC_IRQ38_USART2_DI();
	}

	else if (USARTx == USART2)
	{
		RCC_USART3_CLK_DI();
		NVIC_IRQ39_USART3_DI();
	}
}


//
///******************************************************************************
// * \Name            : MCAL_UART_GPIO_Set_Pins
// * \Description     : setting the PINs used with the uart as recommended
// * \Parameters (in) : - USARTx: which uart we use
//						- UART_Config: configuration struct
// * \Parameters (out): None
// * \Return value:   : None
// *******************************************************************************/


void MCAL_UART_GPIO_Set_Pins(USART_TypeDef* USARTx  )
{

	GPIO_PinConfig_t Pin_Config;

	if (USARTx == USART1)
	{
		// PA9 Tx
		// PA10 Rx
		// PA11 CTS
		// PA12 RTS

		// PA9 Tx
		Pin_Config.pinNumber = GPIO_PIN_9;
		Pin_Config.GPIO_MODE = GPIO_MODE_AFIO_OUT_PP;
		Pin_Config.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_10;
		MCAL_GPIO_Init(GPIOA, &Pin_Config);

		// PA10 Rx
		Pin_Config.pinNumber = GPIO_PIN_10;
		Pin_Config.GPIO_MODE = GPIO_MODE_AFIO_IN;
		MCAL_GPIO_Init(GPIOA, &Pin_Config);

		if (Global_USART_Config[0]->HwFlowCtl == UART_HwFlowCtl_CTS || Global_USART_Config[0]->HwFlowCtl == UART_HwFlowCtl_RTS_CTS)
		{
			// PA11 CTS
			Pin_Config.pinNumber = GPIO_PIN_11;
			Pin_Config.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &Pin_Config);
		}

		if (Global_USART_Config[0]->HwFlowCtl == UART_HwFlowCtl_RTS || Global_USART_Config[0]->HwFlowCtl == UART_HwFlowCtl_RTS_CTS)
		{
			// PA12 RTS
			Pin_Config.pinNumber = GPIO_PIN_12;
			Pin_Config.GPIO_MODE = GPIO_MODE_AFIO_OUT_PP;
			Pin_Config.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_10;
			MCAL_GPIO_Init(GPIOA, &Pin_Config);
		}

	}
	else if (USARTx == USART2)
	{
		// PA2 Tx
		// PA3 Rx
		// PA0 CTS
		// PA1 RTS

		// PA2 Tx
		Pin_Config.pinNumber = GPIO_PIN_2;
		Pin_Config.GPIO_MODE = GPIO_MODE_AFIO_OUT_PP;
		Pin_Config.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_10;
		MCAL_GPIO_Init(GPIOA, &Pin_Config);

		// PA3 Rx
		Pin_Config.pinNumber = GPIO_PIN_3;
		Pin_Config.GPIO_MODE = GPIO_MODE_AFIO_IN;
		MCAL_GPIO_Init(GPIOA, &Pin_Config);

		if (Global_USART_Config[1]->HwFlowCtl || Global_USART_Config[1]->HwFlowCtl == UART_HwFlowCtl_CTS)
		{
			// PA0 CTS
			Pin_Config.pinNumber = GPIO_PIN_0;
			Pin_Config.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &Pin_Config);
		}



		if (Global_USART_Config[1]->HwFlowCtl == UART_HwFlowCtl_RTS || Global_USART_Config[1]->HwFlowCtl == UART_HwFlowCtl_RTS_CTS)
		{
			// PA1 RTS
			Pin_Config.pinNumber = GPIO_PIN_1;
			Pin_Config.GPIO_MODE = GPIO_MODE_AFIO_OUT_PP;
			Pin_Config.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_10;
			MCAL_GPIO_Init(GPIOA, &Pin_Config);
		}

	}
	else if (USARTx == USART3)
	{
		// PB10 Tx
		// PB11 Rx
		// PA13 CTS
		// PA14 RTS

		// PB10 Tx
		Pin_Config.pinNumber = GPIO_PIN_10;
		Pin_Config.GPIO_MODE = GPIO_MODE_AFIO_OUT_PP;
		Pin_Config.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_10;
		MCAL_GPIO_Init(GPIOB, &Pin_Config);

		// PB11 Rx
		Pin_Config.pinNumber = GPIO_PIN_11;
		Pin_Config.GPIO_MODE = GPIO_MODE_AFIO_IN;
		MCAL_GPIO_Init(GPIOB, &Pin_Config);

		if (Global_USART_Config[2]->HwFlowCtl || Global_USART_Config[2]->HwFlowCtl == UART_HwFlowCtl_CTS)
		{
			// PA11 CTS
			Pin_Config.pinNumber = GPIO_PIN_13;
			Pin_Config.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &Pin_Config);
		}



		if (Global_USART_Config[2]->HwFlowCtl == UART_HwFlowCtl_RTS || Global_USART_Config[2]->HwFlowCtl == UART_HwFlowCtl_RTS_CTS)
		{
			// PA12 RTS
			Pin_Config.pinNumber = GPIO_PIN_14;
			Pin_Config.GPIO_MODE = GPIO_MODE_AFIO_OUT_PP;
			Pin_Config.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_10;
			MCAL_GPIO_Init(GPIOA, &Pin_Config);
		}
	}
}



//
///******************************************************************************
// * \Name            : MCAL_UART_SendData
// * \Description     : send data using uart
// * \Parameters (in) : - USARTx: which uart we use
//						- pTxBuffer: pointer to data to be send
//						- PollingEn: is polling mechanism will be used or not
// * \Parameters (out): None
// * \Return value:   : None
// *******************************************************************************/

void MCAL_UART_SendData(USART_TypeDef* USARTx, uint16_t* pTxBuffer, enum Polling_Mechanism PollingEn)
{

	/* 1. Wait until TXE flag is set in the SR */
	if (PollingEn == enable)
	{

		while (!(USARTx->SR & 1<<7));
	}

	/* 2. Check the USART_WordLength item for 9-bit or 8-bit in a frame */
	if(USARTx == USART1)
	{
		if (Global_USART_Config[0]->Payload_Length == UART_Payload_Length_8B)
		{
			USARTx->DR = (*pTxBuffer) & (uint8_t)0xFF ;
		}
		else if (Global_USART_Config[0]->Payload_Length == UART_Payload_Length_9B)
		{
			USARTx->DR = (*pTxBuffer) & (uint16_t)0x1FF ;
		}
	}

	if(USARTx == USART2)
	{
		if (Global_USART_Config[1]->Payload_Length == UART_Payload_Length_8B)
		{
			USARTx->DR = (*pTxBuffer) & (uint8_t)0xFF ;
		}
		else if (Global_USART_Config[1]->Payload_Length == UART_Payload_Length_9B)
		{
			USARTx->DR = (*pTxBuffer) & (uint16_t)0x1FF ;
		}
	}

	if(USARTx == USART3)
	{
		if (Global_USART_Config[2]->Payload_Length == UART_Payload_Length_8B)
		{
			USARTx->DR = (*pTxBuffer) & (uint8_t)0xFF ;
		}
		else if (Global_USART_Config[2]->Payload_Length == UART_Payload_Length_9B)
		{
			USARTx->DR = (*pTxBuffer) & (uint16_t)0x1FF ;
		}
	}


	//
	///******************************************************************************
	// * \Name            : MCAL_UART_ReceiveData
	// * \Description     : receive data from the uart
	// * \Parameters (in) : - USARTx: which uart we use
	//						- PollingEn: is polling mechanism will be used or not
	// * \Parameters (out):
	//                      - pTxBuffer: pointer to data to be received
	// * \Return value:   : None
	// *******************************************************************************/


}
void MCAL_UART_ReceiveData(USART_TypeDef* USARTx, uint16_t* pRxBuffer, enum Polling_Mechanism PollingEn)
{
	/* 1. Wait until RXNE flag is set in the SR */
	if (PollingEn == enable)
	{
		while (!(USARTx->SR & 1<<5));
	}

	/* 2. Check the USART_WordLength item for 9-bit or 8-bit in a frame */

	//


	//USART1

	if(USARTx ==USART1)
	{
		if (Global_USART_Config[0]->Payload_Length == UART_Payload_Length_9B)
		{
			if (Global_USART_Config[0]->Parity == UART_Parity_NONE)
			{
				/* All 9 bits are data */
				*pRxBuffer = USARTx->DR ;
			}
			else
			{
				/* Just least byte is data */
				*pRxBuffer = USARTx->DR & (uint8_t)0xFF ;
			}
		}
		/* 8 Bits Data */
		else
		{
			if (Global_USART_Config[0]->Parity == UART_Parity_NONE)
			{
				/* All 8 bits are data */
				*pRxBuffer = USARTx->DR & (uint8_t)0xFF  ;
			}
			else
			{
				/* just least 7 bits are data */
				*pRxBuffer = USARTx->DR & (uint8_t)0x7F ;
			}
		}


	}

	//--------------------------
	//USART2

	if(USARTx ==USART2)
	{
		if (Global_USART_Config[1]->Payload_Length == UART_Payload_Length_9B)
		{
			if (Global_USART_Config[1]->Parity == UART_Parity_NONE)
			{
				/* All 9 bits are data */
				*pRxBuffer = USARTx->DR ;
			}
			else
			{
				/* Just least byte is data */
				*pRxBuffer = USARTx->DR & (uint8_t)0xFF ;
			}
		}
		/* 8 Bits Data */
		else
		{
			if (Global_USART_Config[1]->Parity == UART_Parity_NONE)
			{
				/* All 8 bits are data */
				*pRxBuffer = USARTx->DR & (uint8_t)0xFF  ;
			}
			else
			{
				/* just least 7 bits are data */
				*pRxBuffer = USARTx->DR & (uint8_t)0x7F ;
			}
		}


	}

	//-----------
	//USART3

	if(USARTx ==USART3)
	{
		if (Global_USART_Config[2]->Payload_Length == UART_Payload_Length_9B)
		{
			if (Global_USART_Config[2]->Parity == UART_Parity_NONE)
			{
				/* All 9 bits are data */
				*pRxBuffer = USARTx->DR ;
			}
			else
			{
				/* Just least byte is data */
				*pRxBuffer = USARTx->DR & (uint8_t)0xFF ;
			}
		}
		/* 8 Bits Data */
		else
		{
			if (Global_USART_Config[2]->Parity == UART_Parity_NONE)
			{
				/* All 8 bits are data */
				*pRxBuffer = USARTx->DR & (uint8_t)0xFF  ;
			}
			else
			{
				/* just least 7 bits are data */
				*pRxBuffer = USARTx->DR & (uint8_t)0x7F ;
			}
		}


	}


}


void MCAL_UART_WAIT_TC(USART_TypeDef* USARTx)
{
	/* Wait till TC flag is set in the SR */
	while(!(USARTx->SR & 1<<6));
}


void USART1_IRQHandler (void)
{
	Global_USART_Config[0]->P_IRQ_CallBack();
}

void USART2_IRQHandler (void)
{
	Global_USART_Config[1]->P_IRQ_CallBack();
}

void USART3_IRQHandler (void)
{
	Global_USART_Config[2]->P_IRQ_CallBack();
}
