#include<msp430f6638.h>

typedef unsigned int u16;

void delay(u16 duration)
{
	u16 i;
	for(i=0 ; i < 5000 * duration ; i++);
}

void main(void)
{
	P4DIR = 0x10;
	P4OUT = 0x10;
	while(1)
	{
		if(P4IN & 0x10 == 0)
		{
			delay(20);
			if(P4IN & 0x10 == 0)
			{
				while(P4IN & 0x10 == 0);
				if(P4IN & 0x10 == 1)
				{
					delay(20);
					P4OUT ^= 0x10;
				}

			}
		}
	}
}
