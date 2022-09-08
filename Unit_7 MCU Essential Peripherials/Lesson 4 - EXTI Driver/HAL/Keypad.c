/*
 * Keypad.c
 *
 * Created: 9/4/2022 11:10:29 PM
 *  Author: Kyrillos Sawiris 
 */ 


#include "Keypad.h"

int Key_padRow[] = {R0, R1, R2, R3}; //rows of the keypad
int Key_padCol[] = {C0, C1, C2, C3};//columns


/*============================================
				Keypad_init()
1. set direction of the rowes as input
2. set direction of columns as output
===========================================*/
void Keypad_init(){
	GPIO_PinConfig_t PinConfig;

	PinConfig.pinNumber = R0;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_2;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.pinNumber = R1;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_2;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.pinNumber = R2;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_2;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.pinNumber = R3;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_2;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.pinNumber = C0;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_2;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.pinNumber = C1;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_2;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.pinNumber = C2;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_2;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	PinConfig.pinNumber = C3;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = OUTPUT_SPEED_2;
	MCAL_GPIO_Init(KEYPAD_PORT, &PinConfig);

	MCAL_GPIO_WritePort(KEYPAD_PORT, 0xFF);

}

/*=============================================
					Keypad_getkey()
make a nested loop 
				 only there are one col to accept input from it 
				 by looping througth the rows
==============================================*/
char Keypad_getkey(){
	int i,j;
	for (i = 0; i < 4; i++){
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[0], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[1], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[2], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[3], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, Key_padCol[i], GPIO_PIN_RESET);
		for(j = 0; j < 4; j++){
			if (MCAL_GPIO_ReadPin(KEYPAD_PORT, Key_padRow[j]) == 0)
			{
				while(MCAL_GPIO_ReadPin(KEYPAD_PORT, Key_padRow[j]) == 0);
				switch(i){
				case (0):
						if (j == 0) return '7';
						else if (j == 1) return '4';
						else if (j == 2) return '1';
						else if (j == 3) return '?';
				break;
				case (1):
						if (j == 0) return '8';
						else if (j == 1) return '5';
						else if (j == 2) return '2';
						else if (j == 3) return '0';
				break;
				case (2):
						if (j == 0) return '9';
						else if (j == 1) return '6';
						else if (j == 2) return '3';
						else if (j == 3) return '=';
				break;
				case (3):
						if (j == 0) return '/';
						else if (j == 1) return '*';
						else if (j == 2) return '-';
						else if (j == 3) return '+';
				break;
				}
			}
		}
	}
	return 'A';
}
