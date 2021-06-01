/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include <stdlib.h>
#include "stm32f1xx.h"
#include "FreeRTOS.h"
#include "ledDebBoard.h"
/*
LED_BLUE_DEB		A4
LED_GREEN_DEB		B0
LED_YELLOW_DEB		C1
LED_RED_DEB			C0

BUTTON_DEB_1		A3
BUTTON_DEB_2		A2

POTENTIOMETR_DEB	A0

RX_PIN_DEB			A10
TX_PIN_DEB			A9
*/


void taskLedRedBlink(){
	static uint8_t state = 0;
	for(;;){
		ledRedDeb(state);
		state = state ? 0 : 1;
		uartSendData("red task\n", sizeof("red task\n"));
		vTaskDelay((rand()%900)+100);
	}
}

void taskLedYellowBlink(){
	static uint8_t state = 0;
	for(;;){
		ledYellowDeb(state);
		state = state ? 0 : 1;
		//uartSendData("yellow task\n");
		uartSendData("yellow task\n", sizeof("yellow task\n"));
		vTaskDelay((rand()%900)+100);
	}
}

void taskLedGreenBlink(){
	static uint8_t state = 0;
	for(;;){
		ledGreenDeb(state);
		state = state ? 0 : 1;
		uartSendData("green task\n", sizeof("green task\n"));
		vTaskDelay((rand()%900)+100);
	}
}

void taskLedBlueBlink(){
	static uint8_t state = 0;
	for(;;){
		ledBlueDeb(state);
		state = state ? 0 : 1;
		uartSendData("blue task\n", sizeof("blue task\n"));
		vTaskDelay((rand()%900)+100);

	}
}



int main(void)
{
	initDebLed();
	uartDebInit();
	xTaskCreate(taskLedRedBlink, "LED_R_BLINK", 32, NULL, 3, NULL);
	xTaskCreate(taskLedYellowBlink, "LED_Y_BLINK", 32, NULL, 3, NULL);
	xTaskCreate(taskLedGreenBlink, "LED_G_BLINK", 32, NULL, 3, NULL);
	xTaskCreate(taskLedBlueBlink, "LED_B_BLINK", 32, NULL, 3, NULL);
	vTaskStartScheduler();
	for(;;);
}
