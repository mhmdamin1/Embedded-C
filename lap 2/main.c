// MOHAMED AMIIN
#include "Platform_Types.h"

#define SET_BIT(reg,position) (reg |= (1 << position))
#define CLR_BIT(reg,position) (reg &= ~(1 << position))
#define TGL_BIT(reg,position) (reg ^= (1 << position))


#define SYSCTL_RCGC2_R    *((vuint32_t*)0x400FE108)
#define GPIO_PORTF_DIR_R  *((vuint32_t*)0x40025400)
#define GPIO_PORTF_DATA_R  *((vuint32_t*)0x400253FC)
#define GPIO_PORTF_DEN_R  *((vuint32_t*)0x4002551c)

 



int main(void)
{
	uint32_t delayCount = 0;
	/* Enable system Clock */
	SYSCTL_RCGC2_R = (vuint32_t) 0x00000020;
	/* small Delay untill start */
	for(delayCount = 0; delayCount < 200; delayCount++);
	
	/* Enable the GPIO and configure as Output */
	SET_BIT(GPIO_PORTF_DIR_R,3);
	SET_BIT(GPIO_PORTF_DEN_R,3);
	
	/*Toggle the LED*/
	while(1)
	{
		TGL_BIT(GPIO_PORTF_DATA_R, 3);
		/* Delay so it can be seen */
		for(delayCount = 0; delayCount < 20000; delayCount++);
	}
	
	return 0;
}