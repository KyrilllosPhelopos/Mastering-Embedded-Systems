/*
 * USART.h
 *
 *  Created on: Sep 16, 2022
 *      Author: phelp
 */

#ifndef USART_H_
#define USART_H_


//============================================
//-----------------Includes-------------------
//============================================
#include "stm32f103c6.h"
#include "GPIO.h"
#include "RCC.h"

typedef struct
{
	uint8_t    UART_MODE; //which mode will the uart be used to
						// values based on @ref UART_MODE_def

	uint32_t	BaudRate;//specify the baud rate of sending/receiving
						//values based on @ref UART_BAUDRate_def

	uint8_t		Payload_Length;	//specify the number of the data bits
							 	//values based on @ref UART_Payload_Length_def

	uint8_t		Parity;	//specify the type of the parity
						//value based on @ref UART_Partity_def

	uint8_t		StopBits;//specify the number of stop bits
						 // value set based on @ref UART_StopBits_def

	uint8_t		HwFlowCtl;// Specifies whether the hardware flow control mode is enabled or disabled
						 // based on @Ref UART_HwFlowCtl_define

	uint8_t		IRQ_Enable;	// enable or disable the interrupt
							// set based on @Ref UART_IRQ_define

	void (* P_IRQ_CallBack)(void);	// the call back function which will be called once the IRQ Happen
}USART_Config;



/*======================================================================
 * 						@ref UART_MODE_def
 *=======================================================================*/
#define UART_MODE_TX		(uint32_t)(1<<3);
#define UART_MODE_RX		(uint32_t)(1<<2);
#define UART_MODE_TX_RX		(uint32_t) (1<<3)|(1<<2);

/*======================================================================
 * 						@ref UART_BAUDRate_def
 *=======================================================================*/
#define UART_BaudRate_2400			2400
#define UART_BaudRate_9600			9600
#define UART_BaudRate_19200			19200
#define UART_BaudRate_57600			57600
#define UART_BaudRate_115200		115200
#define UART_BaudRate_230400		230400
#define UART_BaudRate_460800		460800
#define UART_BaudRate_921600		921600
#define UART_BaudRate_225000		2250000
#define UART_BaudRate_4500000		4500000

/*======================================================================
 * 						@ref UART_Payload_Length_def
 *=======================================================================*/
#define UART_Payload_Length_8B		(uint32_t)(0)
#define UART_Payload_Length_9B		(uint32_t)(1<<12)

/*======================================================================
 * 						@ref UART_Partity_def
 *=======================================================================*/
#define UART_Parity_NONE			(uint32_t)(0)
#define UART_Parity_EVEN			((uint32_t)(1<<10)) 		// Bit 10 PCE: Parity control enable
																// Bit 9 : 0 to be EVEN

#define UART_Parity_ODD				((uint32_t)(1<<10 | 1<<9)) 	// Bit 10 PCE: Parity control enable
																// Bit 9 : 1 to be ODD

/*======================================================================
 * 						@ref UART_StopBits_def
 *=======================================================================*/
//Bits 13:12 STOP: STOP bits
//These bits are used for programming the stop bits.
//00: 1 Stop bit
//01: 0.5 Stop bit
//10: 2 Stop bits
//11: 1.5 Stop bit
#define UART_StopBits_half			(uint32_t)(1<<12)
#define UART_StopBits_1				(uint32_t)(0)
#define UART_StopBits_1_half		(uint32_t)(0b11<<12)
#define UART_StopBits_2				(uint32_t)(0b10<<12)

/*======================================================================
 * 						@ref UART_HwFlowCtl_define
 *=======================================================================*/


#define UART_HwFlowCtl_NONE			(uint32_t)(0)
#define UART_HwFlowCtl_RTS			(uint32_t)(1<<8)	// Bit 8 RTSE: RTS enable
#define UART_HwFlowCtl_CTS			(uint32_t)(1<<9) 	// Bit 9 CTSE: CTS enable
#define UART_HwFlowCtl_RTS_CTS		(uint32_t)(1<<8 | 1<<9)
/*======================================================================
 * 						@ref UART_IRQ_Enable_define
 *=======================================================================*/
#define UART_IRQ_Enable_NONE		(uint32_t)(0)

//Bit 7 TXEIE: TXE interrupt enable
//This bit is set and cleared by software.
//0: Interrupt is inhibited
//1: A USART interrupt is generated whenever TXE=1 in the USART_SR register
#define UART_IRQ_Enable_TXE			(uint32_t)(1<<7)	// Bit 7 TXEIE: TXE interrupt enable // Transmit data register empty
//Bit 6 TCIE: Transmission complete interrupt enable
//This bit is set and cleared by software.
//0: Interrupt is inhibited
//1: A USART interrupt is generated whenever TC=1 in the USART_SR register

#define UART_IRQ_Enable_TC			(uint32_t)(1<<6)	// Bit 6 TCIE: Transmission complete interrupt enable // Transmission complete

//Bit 5 RXNEIE: RXNE interrupt enable
//This bit is set and cleared by software.
//0: Interrupt is inhibited
//1: A USART interrupt is generated whenever ORE=1 or RXNE=1 in the USART_SR registe
#define UART_IRQ_Enable_RXNEIE		(uint32_t)(1<<5)	// Bit 5 RXNEIE: RXNE interrupt enable // Received data ready to be read
//Bit 8 PEIE: PE interrupt enable
//This bit is set and cleared by software.
//0: Interrupt is inhibited
//1: A USART interrupt is generated whenever PE=1 in the USART_SR register
#define UART_IRQ_Enable_PE			(uint32_t)(1<<8)	// Bit 8 PEIE: PE interrupt enable // Parity error



enum Polling_Mechanism
{
	disable,
	enable
};


/* ================================================================ */
/* ===================== BaudRate Calculation ===================== */
/* ================================================================ */

// USARTDIV = fclk / (16 * Baudrate)
// USARTDIV_MUL100 = uint32((100 * fclk ) / ( 16 * Baudrate) == (25 * fclk) / (4 * Baudrate))
// DIV_Mantissa_MUL100 = Integer Part (USARTDIV) * 100
// DIV_Mantissa = Integer Part (USARTDIV)
// DIV_Fraction = (( USARTDIV_MUL100 - DIV_Mantissa_MUL100 ) *16) / 100

#define USARTDIV(_PCLK_, _BAUD_)				(uint32_t) (_PCLK_/(16 * _BAUD_ ))
#define USARTDIV_MUL100(_PCLK_, _BAUD_)			(uint32_t) ((25 * _PCLK_ ) / (4 * _BAUD_))
#define Mantissa_MUL100(_PCLK_, _BAUD_)			(uint32_t) (USARTDIV(_PCLK_, _BAUD_) * 100)
#define Mantissa(_PCLK_, _BAUD_)				(uint32_t) (USARTDIV(_PCLK_, _BAUD_ ))
#define DIV_Fraction(_PCLK_, _BAUD_)			(uint32_t) (((USARTDIV_MUL100(_PCLK_, _BAUD_) - Mantissa_MUL100(_PCLK_, _BAUD_) )*16) / 100)
#define UART_BRR_Register(_PCLK_, _BAUD_)		(( Mantissa (_PCLK_, _BAUD_ ) ) << 4 )|((DIV_Fraction(_PCLK_, _BAUD_)) & 0xF )




/*==================================================================================
------------------------------USART APIS--------------------------------------
=================================================================================== */

void MCAL_UART_Init(USART_TypeDef* USARTx, USART_Config* UART_Config);

void MCAL_UART_DeInit(USART_TypeDef* USARTx);

void MCAL_UART_GPIO_Set_Pins(USART_TypeDef* USARTx);

void MCAL_UART_SendData(USART_TypeDef* USARTx, uint16_t* pTxBuffer, enum Polling_Mechanism PollingEn);
void MCAL_UART_ReceiveData(USART_TypeDef* USARTx, uint16_t* pRxBuffer, enum Polling_Mechanism PollingEn);

void MCAL_UART_WAIT_TC(USART_TypeDef* USARTx);


#endif /* USART_H_ */
