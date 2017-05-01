/**************************************
led  twinkle at the same time (led иак╦)
**************************************/
#include <msp430f6638.h>

typedef volatile unsigned int u16;

void delay(u16 duration)
{
	u16 i;
	for(i=0;i<5000*duration;i++);
}

void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	           //Stop watchdog timer
	P4DIR |= 0X70;
	while(1)
	{
		P4OUT ^= BIT4 + BIT5 + BIT6;
		delay(20);
	}
}

