#include"stm32f10x.h"

void RCC_Configuration(void);
void GPIO_Configuration(void);
void USART_Configuration(void);
void USART1_SendChar(char c);
void USART1_SendString(char *str);
char USART1_ReceiveChar(void);

int main(void)
{
    RCC_Configuration();
    GPIO_Configuration();
    USART_Configuration();

    while (1)
    {
        GPIOA->BSRR = 1 << 8; 
        USART1_SendString("Hello ESP32!");
        GPIOA->BSRR = 1 << (8 + 16);
        for (volatile int i = 0; i < 5000000; i++);
    }
}

void RCC_Configuration(void)
{
    RCC->APB2ENR |= (1 << 2) | (1 << 14);
}

void GPIO_Configuration(void)
{
    GPIOA->CRH &= ~(0xF << (4 * (9 - 8)));
    GPIOA->CRH |= (0xB << (4 * (9 - 8)));

	//Confi PA8, output mode, max speed 50 MHz, CNF = 00 (General purpose output push-pull)
    GPIOA->CRH &= ~(0xF << (4 * (8 - 8))); 
    GPIOA->CRH |= (0x3 << (4 * (8 - 8)));
}

void USART_Configuration(void)
{
    USART1->BRR = 72000000 / 115200;
    USART1->CR1 |= (1 << 13) | (1 << 3) | (1 << 2); // UE = 1, TE = 1, RE = 1
}

void USART1_SendChar(char c)
{
    USART1->DR = c;              
}

void USART1_SendString(char *str)
{
    while (*str) {
        while (!(USART1->SR & USART_SR_TXE)); 
        USART1->DR = *str++;
    }
    while (!(USART1->SR & USART_SR_TC));
}

char USART1_ReceiveChar(void)
{
    while (!(USART1->SR & USART_SR_RXNE));
    return (char)USART1->DR;             
}