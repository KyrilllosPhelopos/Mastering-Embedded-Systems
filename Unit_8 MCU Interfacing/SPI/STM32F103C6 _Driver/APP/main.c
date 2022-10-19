/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Kyrillos Sawiris 
 * @brief          : Main program body
 ******************************************************************************

 */

#include"stm32f103c6.h"
#include"GPIO.h"
#include"RCC.h"
#include"USART.h"
#include"SPI.h"


#define MCU_Act_As_Master


uint8_t data;

void clock_init()
{
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
	//RCC_USART1_CLK_EN();
	//RCC_SPI1_CLK_EN();

}


static void Kyrillos_IRQ_USART1_CallBack(void)
{
#ifdef MCU_Act_As_Master
	MCAL_UART_ReceiveData(USART1, &data, disable);
	MCAL_UART_SendData(USART1, &data, enable);

	/* ========= Send Data To SPI1 =========== */

	/* Slave Selection (Low), to listen  */
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);

	/* Send & Receive data */
	MCAL_SPI_TX_RX(SPI1, &data, SPI_enable);

	/* Slave Selection (High) idle mode */
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
#endif
}


int main(void)
{

	clock_init();




	USART_Config Uart1_Parameters;
	Uart1_Parameters.UART_MODE      = UART_MODE_TX_RX;
	Uart1_Parameters.Payload_Length = UART_Payload_Length_8B;
	Uart1_Parameters.Parity         = UART_Parity_NONE;
	Uart1_Parameters.StopBits       = UART_StopBits_1;
	Uart1_Parameters.BaudRate       = UART_BaudRate_115200;
	Uart1_Parameters.HwFlowCtl      = UART_HwFlowCtl_NONE;
	Uart1_Parameters.IRQ_Enable	    = UART_IRQ_Enable_RXNEIE ;
	Uart1_Parameters.P_IRQ_CallBack = Kyrillos_IRQ_USART1_CallBack;

	MCAL_UART_Init(USART1,&Uart1_Parameters);
	MCAL_UART_GPIO_Set_Pins(USART1);



	/* Configuration of SPI1 */
	SPI_Config_t SPI1_Config;

	/* Common Configuration */


	SPI1_Config.BaudRate_Prescaler = BAUDERATE_PRESCALER_8;
	SPI1_Config.CLK_Phase = CLK_PHASE_SECOND;
	SPI1_Config.CLK_Polarity = CLK_POLARITY_IDLE_HIGH;
	SPI1_Config.Frame_Format = FRAME_FORMAT_MSB_FIRST;
	SPI1_Config.Frame_Size = FRAME_SIZE_8BIT;
	SPI1_Config.Communication_Mode = COMMUNICATION_MODE_2LINE_FULL_DUPLEX;

#ifdef MCU_Act_As_Master





	SPI1_Config.SPI_Mode = SPI_MODE_MASTER;
	SPI1_Config.IRQ_Enable = IRQ_ENABLE_NONE;
	SPI1_Config.P_IRQ_CallBack = 0;
	SPI1_Config.NSS = NSS_SW_SSI_SET;	/* To Control when open & when close, Set as Active High */



	/* Configuration of SS */
	GPIO_PinConfig_t SS_Config;

	/* Configure SS at PA4 by GPIO */
	SS_Config.pinNumber = GPIO_PIN_4;
	SS_Config.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	SS_Config.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_10;

	MCAL_GPIO_Init(GPIOA, &SS_Config);
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);

#endif

	MCAL_SPI_Init(SPI1, &SPI1_Config);
	MCAL_SPI_GPIO_Set_Pins(SPI1);

	/* Force the slave select (High) idle mode */

	/* Loop forever */
	for(;;);
}
