/*
 *	main.c
 *
*Created on: jul 21, 2025
 *     Author: Mohamed amin 
 */

#include <stdint.h>


#define SYSCTL_RCGC2_R	*((volatile uint32_t *)(0x400FE108))

#define  GPIO_PORTF_DIR_R	*((volatile uint32_t *)(0x40025400))
#define	 GPIO_PORTF_DEN_R	*((volatile uint32_t *)(0x4002551C))
#define  GPIO_PORTF_DATA_R	*((volatile uint32_t *)(0x400253FC))

char str[] = "Learn-in-depth: Ahmed Azazy";

int main(void )
{
	
	uint32_t i ; 
	//Enable GPIOF clock
	SYSCTL_RCGC2_R |= (1<<5);
	//Delay until PORTF is ready
	for(i = 0 ; i < 200 ; i ++){}
	
	
	//Enable PF3
	GPIO_PORTF_DEN_R |= (1<<3);
	//set PF3 as output
	GPIO_PORTF_DIR_R |=(1<<3);
	
	
	while(1)
	{
		GPIO_PORTF_DATA_R |=(1<<3);
		for(i = 0 ; i < 200000 ; i ++){}
		GPIO_PORTF_DATA_R &=~(1<<3);
		for(i = 0 ; i < 200000 ; i ++){}			
	}
	
	return 0;
}