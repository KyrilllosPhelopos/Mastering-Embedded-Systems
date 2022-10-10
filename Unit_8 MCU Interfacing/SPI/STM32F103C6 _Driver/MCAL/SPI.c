/*
 * SPI.c
 *
 *  Created on: Sep 25, 2022
 *      Author: Kyrillos Sawiris
 */



/*===========================================
 *				includes
 *===========================================*/
#include "SPI.h"
#include "GPIO.h"

/* ================================================================
					Generic Variables
 ================================================================ */

SPI_Config_t *G_SPI_Config[2] = {0, 0};

/* ================================================================
 	 	 	 	 	 	 Generic Macros
 ================================================================ */

#define SPI1_INDEX 		0
#define SPI2_INDEX 		1

#define SPI_SR_TXE		(uint16_t)(1<<1)
#define SPI_SR_RXNE		(uint16_t)(1<<0)

/*=============================================================================================
 * 						  FUNCTIONS Definitions
==========================================================================================*/



//
///******************************************************************************
// * \Name            : MCAL_SPI_Init
// * \Description     : Initialize the SPI module with parameters of the configuration struct
// * \Parameters (in) : - SPIx: which SPI we use
//						- Config: configuration struct
// * \Parameters (out): None
// * \Return value:   : None
// *******************************************************************************/


void MCAL_SPI_Init(SPI_TypeDef *SPIx, SPI_Config_t *Config)
{
	//Safety for register, Using this technique for protect the peripheral form working before the full configurations
	uint16_t tempReg_CR1 = 0;
	uint16_t tempReg_CR2 = 0;

	if(SPIx == SPI1)
	{
		// If SPI1 Put all configurations in the global config
		G_SPI_Config[SPI1_INDEX] = Config;

		/* 1. Open the SPI1 RCC Clock */
		RCC_SPI1_CLK_EN();
	}
	else if(SPIx == SPI2)
	{
		//If SPI2 Put all configurations in the global config
		G_SPI_Config[SPI2_INDEX] = Config;

		// 1. Open the SPI1 RCC Clock
		RCC_SPI2_CLK_EN();
	}

	/* 2. Enable the SPI */
	tempReg_CR1 |= (uint16_t)(1<<6); 	/* Bit 6 SPE: SPI enable */
	/* 3. Set Master or Slave */
	tempReg_CR1 |= Config->SPI_Mode;

	/* 4. Set Communication Mode */
	tempReg_CR1 |= Config->Communication_Mode;

	/* 5. Set Frame format */
	tempReg_CR1 |= Config->Frame_Format;

	/* 6. Set Data size */
	tempReg_CR1 |= Config->Frame_Size;

	/* 7. Set Clock Polarity */
	tempReg_CR1 |= Config->CLK_Polarity;

	/* 8. Set Clock Phase */
	tempReg_CR1 |= Config->CLK_Phase;

	/* 9. Set Slave Select Management */
	if(Config->NSS == NSS_HW_MASTER_SS_OUTPUT_ENABLED)
	{
		tempReg_CR2 |= Config->NSS;
	}
	else if(Config->NSS == NSS_HW_MASTER_SS_OUTPUT_DISABLED)
	{
		tempReg_CR2 &= Config->NSS;
	}
	else
	{
		tempReg_CR1 |= Config->NSS;
	}

	/* 10. Set BoudRate Pre-scaler */
	tempReg_CR1 |= Config->BaudRate_Prescaler;

	/* 11. Set Interrupt Type */
	if(Config->IRQ_Enable != IRQ_ENABLE_NONE)
	{
		tempReg_CR2 |= Config->IRQ_Enable;

		/* 12. Open the global Interrupt for each peripheral */
		if (SPIx == SPI1)
		{
			NVIC_IRQ35_SPI1_EN();
		}
		else if(SPIx == SPI2)
		{
			NVIC_IRQ36_SPI2_EN();
		}
	}

	/*13. Config your register using the temp register used to protect the configurations */
	SPIx->CR1 = tempReg_CR1;
	SPIx->CR2 = tempReg_CR2;


}

//
///******************************************************************************
// * \Name            : MCAL_SPI_DeInit
// * \Description     : DeInit the SPI module
// * \Parameters (in) : - SPIx: which SPI we use
// * \Parameters (out): None
// * \Return value:   : None
//
void MCAL_SPI_DeInit(SPI_TypeDef *SPIx)
{
	if (SPIx == SPI1)
	{
		NVIC_IRQ35_SPI1_DI();
		RCC_SPI1_CLK_DI();
	}
	else if(SPIx == SPI2)
	{
		NVIC_IRQ36_SPI2_DI();
		RCC_SPI2_CLK_DI();
	}
}

//
///******************************************************************************
// * \Name            : MCAL_SPI_GPIO_Set_Pins
// * \Description     : Init the pins used in the SPI module
// * \Parameters (in) : - SPIx: which SPI we use
// * \Parameters (out): None
// * \Return value:   : None
//
void MCAL_SPI_GPIO_Set_Pins(SPI_TypeDef *SPIx)
{

	GPIO_PinConfig_t SPI_GPIO_Config;

	/* Depending the recommendation in data sheet -> Table 25. SPI 	*/
	/*  "SPI pin-out"    "Configuration"     "GPIO configuration" 	*/
	if (SPIx == SPI1)
	{
		if(G_SPI_Config[SPI1_INDEX]->SPI_Mode == SPI_MODE_MASTER) /* Master */
		{
			/* PA4 : SPI1_NSS */
			switch (G_SPI_Config[SPI1_INDEX]->NSS)
			{
			/* Input */
			case NSS_HW_MASTER_SS_OUTPUT_DISABLED:
				/* Hardware Master/Slave Input Floating */
				SPI_GPIO_Config.pinNumber = GPIO_PIN_4;
				SPI_GPIO_Config.GPIO_MODE = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOA, &SPI_GPIO_Config);
				break;

				/* Output */
			case NSS_HW_MASTER_SS_OUTPUT_ENABLED:
				/* Hardware Master/NNS Output Alternate function push-pull */
				SPI_GPIO_Config.pinNumber = GPIO_PIN_4;
				SPI_GPIO_Config.GPIO_MODE = GPIO_MODE_AFIO_OUT_PP;
				SPI_GPIO_Config.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_10;
				MCAL_GPIO_Init(GPIOA, &SPI_GPIO_Config);
				break;
			}

			/* PA5 : SPI1_SCK */
			/* Master Alternate function push-pull */
			SPI_GPIO_Config.pinNumber = GPIO_PIN_5;
			SPI_GPIO_Config.GPIO_MODE = GPIO_MODE_AFIO_OUT_PP;
			SPI_GPIO_Config.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_10;
			MCAL_GPIO_Init(GPIOA, &SPI_GPIO_Config);

			/* PA6 : SPI1_MISO */
			/* Full duplex / master Input floating / Input pull-up */
			SPI_GPIO_Config.pinNumber = GPIO_PIN_6;
			SPI_GPIO_Config.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &SPI_GPIO_Config);

			/* PA7 : SPI1_MOSI */
			/* Full duplex / master Alternate function push-pull */
			SPI_GPIO_Config.pinNumber = GPIO_PIN_7;
			SPI_GPIO_Config.GPIO_MODE = GPIO_MODE_AFIO_OUT_PP;
			SPI_GPIO_Config.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_10;
			MCAL_GPIO_Init(GPIOA, &SPI_GPIO_Config);
		}
		else /* Slave */
		{
			/* PA4 : SPI1_NSS */
			if(G_SPI_Config[SPI1_INDEX]->NSS == NSS_HW_SLAVE)
			{
				/* Hardware Master/Slave Input Floating */
				SPI_GPIO_Config.pinNumber = GPIO_PIN_4;
				SPI_GPIO_Config.GPIO_MODE = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOA, &SPI_GPIO_Config);
			}

			/* PA5 : SPI1_SCK */
			/* Slave Input floating */
			SPI_GPIO_Config.pinNumber = GPIO_PIN_5;
			SPI_GPIO_Config.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &SPI_GPIO_Config);

			/* PA6 : SPI1_MISO */
			/* Full duplex / slave (point to point) Alternate function push-pull */
			SPI_GPIO_Config.pinNumber = GPIO_PIN_6;
			SPI_GPIO_Config.GPIO_MODE = GPIO_MODE_AFIO_OUT_PP;
			SPI_GPIO_Config.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_10;
			MCAL_GPIO_Init(GPIOA, &SPI_GPIO_Config);

			/* TODO Full duplex / slave (multi-slave) Alternate function open drain */

			/* PA7 : SPI1_MOSI */
			/* Full duplex / slave Input floating / Input pull-up */
			SPI_GPIO_Config.pinNumber = GPIO_PIN_7;
			SPI_GPIO_Config.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOA, &SPI_GPIO_Config);
		}
	}
	else if(SPIx == SPI2)
	{
		if(G_SPI_Config[SPI2_INDEX]->SPI_Mode == SPI_MODE_MASTER) /* Master */
		{
			/* PB12 : SPI2_NSS */
			switch (G_SPI_Config[SPI2_INDEX]->NSS)
			{
			/* Input */
			case NSS_HW_MASTER_SS_OUTPUT_DISABLED:
				/* Hardware Master/Slave Input Floating */
				SPI_GPIO_Config.pinNumber = GPIO_PIN_12;
				SPI_GPIO_Config.GPIO_MODE = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOB, &SPI_GPIO_Config);
				break;

				/* Output */
			case NSS_HW_MASTER_SS_OUTPUT_ENABLED:
				/* Hardware Master/NNS Output Alternate function push-pull */
				SPI_GPIO_Config.pinNumber = GPIO_PIN_12;
				SPI_GPIO_Config.GPIO_MODE = GPIO_MODE_AFIO_OUT_PP;
				SPI_GPIO_Config.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_10;
				MCAL_GPIO_Init(GPIOB, &SPI_GPIO_Config);
				break;
			}

			/* PB13 : SPI2_SCK */
			/* Master Alternate function push-pull */
			SPI_GPIO_Config.pinNumber = GPIO_PIN_13;
			SPI_GPIO_Config.GPIO_MODE = GPIO_MODE_AFIO_OUT_PP;
			SPI_GPIO_Config.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_10;
			MCAL_GPIO_Init(GPIOB, &SPI_GPIO_Config);

			/* PB14 : SPI2_MISO */
			/* Full duplex / master Input floating / Input pull-up */
			SPI_GPIO_Config.pinNumber = GPIO_PIN_14;
			SPI_GPIO_Config.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &SPI_GPIO_Config);

			/* PB15 : SPI2_MOSI */
			/* Full duplex / master Alternate function push-pull */
			SPI_GPIO_Config.pinNumber = GPIO_PIN_15;
			SPI_GPIO_Config.GPIO_MODE = GPIO_MODE_AFIO_OUT_PP;
			SPI_GPIO_Config.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_10;
			MCAL_GPIO_Init(GPIOB, &SPI_GPIO_Config);
		}
		else /* Slave */
		{
			/* PB12 : SPI2_NSS */
			if(G_SPI_Config[SPI2_INDEX]->NSS == NSS_HW_SLAVE)
			{
				/* Hardware Master/Slave Input Floating */
				SPI_GPIO_Config.pinNumber = GPIO_PIN_12;
				SPI_GPIO_Config.GPIO_MODE = GPIO_MODE_INPUT_FLO;
				MCAL_GPIO_Init(GPIOB, &SPI_GPIO_Config);
			}

			/* PB13 : SPI2_SCK */
			/* Slave Input floating */
			SPI_GPIO_Config.pinNumber = GPIO_PIN_13;
			SPI_GPIO_Config.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &SPI_GPIO_Config);

			/* PB14 : SPI2_MISO */
			/* Full duplex / slave (point to point) Alternate function push-pull */
			SPI_GPIO_Config.pinNumber = GPIO_PIN_14;
			SPI_GPIO_Config.GPIO_MODE = GPIO_MODE_AFIO_OUT_PP;
			SPI_GPIO_Config.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_10;
			MCAL_GPIO_Init(GPIOB, &SPI_GPIO_Config);

			/* TODO Full duplex / slave (multi-slave) Alternate function open drain */

			/* PB15 : SPI2_MOSI */
			/* Full duplex / slave Input floating / Input pull-up */
			SPI_GPIO_Config.pinNumber = GPIO_PIN_15;
			SPI_GPIO_Config.GPIO_MODE = GPIO_MODE_INPUT_FLO;
			MCAL_GPIO_Init(GPIOB, &SPI_GPIO_Config);
		}
	}
}
//
///******************************************************************************
// * \Name            : MCAL_SPI_Send_Data
// * \Description     : send data using SPI module
// * \Parameters (in) : - SPIx: which SPI we use
//                      - pTxBuffer: Buffer to be sent
//                      - Polling_Mechanism: Mechanism to be used
// * \Parameters (out): None
// * \Return value:   : None
//
void MCAL_SPI_Send_Data(SPI_TypeDef *SPIx, uint16_t *pTxBuffer, enum Polling_Mechanism Polling_En)
{

	if(Polling_En == SPI_enable)
	{
		/* Wait for transmission complete */
		while(! (SPIx->SR & SPI_SR_TXE));
	}

	/* Start transmission, Write data to SPI data register */
	SPIx->DR = *(pTxBuffer);
}


///******************************************************************************
// * \Name            : MCAL_SPI_Recieve_Data
// * \Description     : receiving data SPI module
// * \Parameters (in) : - SPIx: which SPI we use
//                      - pTxBuffer: Buffer to be sent
//                      - Polling_Mechanism: Mechanism to be used
// * \Parameters (out): None
// * \Return value:   : None
//
void MCAL_SPI_Recieve_Data(SPI_TypeDef *SPIx, uint16_t *pRxBuffer, enum Polling_Mechanism Polling_En)
{
	if(Polling_En == SPI_enable)
	{
		/* Wait for reception complete */
		while(! (SPIx->SR & SPI_SR_RXNE));
	}

	/* Start reception, Write data to SPI data register */
	*(pRxBuffer) = SPIx->DR;
}

///******************************************************************************
// * \Name            : MCAL_SPI_TX_RX
// * \Description     : Transmit and Receive Data
// * \Parameters (in) : - SPIx: which SPI we use
//                      - pTxBuffer: Buffer to be sent
//                      - Polling_Mechanism: Mechanism to be used
// * \Parameters (out): None
// * \Return value:   : None
//
void MCAL_SPI_TX_RX(SPI_TypeDef *SPIx, uint16_t *pTxBuffer, enum Polling_Mechanism Polling_En)
{
	if(Polling_En == SPI_enable)
	{
		/* Wait for transmission complete */
		while(! (SPIx->SR & SPI_SR_TXE));
	}

	/* Start transmission, Write data to SPI data register */
	SPIx->DR = *(pTxBuffer);

	/* =================================================== */

	if(Polling_En == SPI_enable)
	{
		/* Wait for reception complete */
		while(! (SPIx->SR & SPI_SR_RXNE));
	}

	/* Start reception, Write data to SPI data register */
	*(pTxBuffer) = SPIx->DR;
}

/* ================================================================ */
/* ================= IRQ Function Definitions ===================== */
/* ================================================================ */

void SPI1_IRQHandler(void)
{
	struct S_IRQ_SRC IRQ;

	IRQ.TXE = ((SPI1->SR & (1<<1)) >> 1);
	IRQ.RXNE = ((SPI1->SR & (1<<0)) >> 0);
	IRQ.ERRI = ((SPI1->SR & (1<<4)) >> 4);

	G_SPI_Config[SPI1_INDEX]->P_IRQ_CallBack(IRQ);
}


void SPI2_IRQHandler(void)
{
	struct S_IRQ_SRC IRQ;

	IRQ.TXE = ((SPI2->SR & (1<<1)) >> 1);
	IRQ.RXNE = ((SPI2->SR & (1<<0)) >> 0);
	IRQ.ERRI = ((SPI2->SR & (1<<4)) >> 4);

	G_SPI_Config[SPI2_INDEX]->P_IRQ_CallBack(IRQ);
}




