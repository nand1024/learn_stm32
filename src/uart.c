#include "stm32f1xx.h"
#include "uart.h"
#include "mQueue.h"
#include "FreeRTOS.h"
#include "semphr.h"
static type_virt_mem uart_queue_rx;
static type_virt_mem uart_queue_tx;

SemaphoreHandle_t uartResLock_tx = NULL;

void uartDebInit(){
	const uint32_t UART_BUS_CLK_FREQ = 8000000;
	const uint32_t UART_BAUDRATE = 9600;
	uartResLock_tx = xSemaphoreCreateMutex();
	queue_init(&uart_queue_rx);
	queue_init(&uart_queue_tx);

	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

	GPIOA->CRH |= GPIO_CRH_MODE9_1;
	GPIOA->CRH &= ~GPIO_CRH_CNF9;
	GPIOA->CRH |= GPIO_CRH_CNF9_1;

	GPIOA->CRH &= ~GPIO_CRH_MODE10;
	GPIOA->CRH &= ~GPIO_CRH_CNF10;
	GPIOA->CRH |= GPIO_CRH_CNF10_0;

	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
	USART1->CR1 |= (USART_CR1_TE | USART_CR1_RE);
	USART1->CR1 |= (USART_CR1_TCIE | USART_CR1_RXNEIE);
	USART1->BRR = UART_BUS_CLK_FREQ / UART_BAUDRATE;
	USART1->CR1 |= USART_CR1_UE;
	NVIC_EnableIRQ(USART1_IRQn);
}

void uartSendData(uint8_t *data, uint16_t len){
	if(xSemaphoreTake(uartResLock_tx, 30) == pdTRUE){
		if(len > 1)queue_put_data(&data[1], len-1, &uart_queue_tx);
		while(!(USART1->SR & USART_SR_TXE));
		USART1->DR = data[0];
		xSemaphoreGive(uartResLock_tx);
	}

}

void USART1_IRQHandler(){
	uint8_t data_rx, data_tx;
	if(USART1->SR & USART_SR_TC){
		USART1->SR &= ~USART_SR_TC;
		if(queue_get_data(&data_tx, 1, &uart_queue_tx)){
			USART1->DR = data_tx;
		}
	}
	if(USART1->SR & USART_SR_RXNE){
		USART1->SR &= ~USART_SR_RXNE;
		data_rx = USART1->DR;
		queue_put_data(&data_rx, 1, &uart_queue_rx);
	}
}
