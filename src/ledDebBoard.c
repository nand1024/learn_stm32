
#include "stm32f1xx.h"


void initDebLed(){
	RCC->APB2ENR |= (RCC_APB2ENR_IOPAEN|
					 RCC_APB2ENR_IOPBEN|
					 RCC_APB2ENR_IOPCEN);
	//BLUE_LED
	GPIOA->CRL |= GPIO_CRL_MODE4_1;
	GPIOA->CRL &= ~GPIO_CRL_CNF4;
	//GREEN_LED
	GPIOB->CRL |= GPIO_CRL_MODE0_1;
	GPIOB->CRL &= ~GPIO_CRL_CNF0;
	//YELLOW_LED
	GPIOC->CRL |= GPIO_CRL_MODE1_1;
	GPIOC->CRL &= ~GPIO_CRL_CNF1;
	//RED_LED
	GPIOC->CRL |= GPIO_CRL_MODE0_1;
	GPIOC->CRL &= ~GPIO_CRL_CNF0;
}

void ledBlueDeb(uint8_t val){
	if(val){
		GPIOA->ODR |= GPIO_ODR_ODR4;
	}else{
		GPIOA->ODR &= ~GPIO_ODR_ODR4;
	}
}

void ledGreenDeb(uint8_t val){
	if(val){
		GPIOB->ODR |= GPIO_ODR_ODR0;
	}else{
		GPIOB->ODR &= ~GPIO_ODR_ODR0;
	}
}

void ledYellowDeb(uint8_t val){
	if(val){
		GPIOC->ODR |= GPIO_ODR_ODR1;
	}else{
		GPIOC->ODR &= ~GPIO_ODR_ODR1;
	}
}

void ledRedDeb(uint8_t val){
	if(val){
		GPIOC->ODR |= GPIO_ODR_ODR0;
	}else{
		GPIOC->ODR &= ~GPIO_ODR_ODR0;
	}
}
