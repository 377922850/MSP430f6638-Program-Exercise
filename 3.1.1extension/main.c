/*****************************
led  twinkle in turn (led иак╦)
*****************************/

#include <msp430f6638.h>

typedef volatile unsigned int u16;       //declare the data type definition

u16 a[]={BIT4,BIT5,BIT6};

void delay(u16 duration)                 //time delay function
{
	u16 i;
	for(i=0;i<duration*5000;i++);
}

void main(void)
{
	WDTCTL = WDTPW +WDTHOLD;
	P4DIR |= BIT4 + BIT5 + BIT6;
	u16 i,j;
	while(1)
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<5;j++)
			{
				P4OUT = a[i];
				delay(2);
				P4OUT ^= a[i];
				delay(2);
			}
		}
	}
}
