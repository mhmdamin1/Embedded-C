/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
#include <stdint.h>

#define RCC_BASE        0x40021000
#define PORTA_BASE      0x40010800

#define RCC_APB2ENR          *((volatile uint32_t *)(RCC_BASE + 0x18))
#define GPIOA_CRH       *((volatile uint32_t *)(PORTA_BASE + 0x04))
#define GPIOA_ODR       *((volatile uint32_t *)(RCC_BASE + 0x0c))



int main(void)
{
	RCC_APB2ENR |= 1<<2;     // Enable RCC Clock for Port A
	GPIOA_CRH &= 0xff0fffff; // Get them 0 first before change it
	GPIOA_CRH |= 0x00200000; // Now we can set 2 safely for pin13 mode

	while (1)
	{
		/* Toggle Pin 13 */
		GPIOA_ODR |= 1<<13;
		for(int i = 0 ;i < 1000 ; i++);
		GPIOA_ODR &= ~(1<<13);
		for(int i = 0 ;i < 1000 ; i++);
	}

	return 0;
}