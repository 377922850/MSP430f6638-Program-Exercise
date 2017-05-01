/********************************
key input use watchdog(看门狗按键输入)
********************************/

#include <msp430f6638.h>

typedef unsigned int u16;            //declare the data type definition

void delay(u16 duration)             //delay function
{
	u16 i;
	for(i=0;i<5000*duration;i++);
}

void keycontrol()
{
	if((P4IN &= BIT2) == 0)          //confirm keydown:P4.2
	{
		delay(20);                   //delay 20ms : eliminate key shake
		if((P4IN &= BIT2) == 0)      //confirm keydown again
		{
			delay(20);
			P4OUT <<= 1;           //reverse P4.4
			if (P4OUT == BIT7)
			{
				P4OUT = BIT4;
			}
		}
	 	while((P4IN &= BIT2) == 0);  //confirm keyup : P4.2
		delay(20);                   //delay 20ms : eliminate key shake
	}

	else if((P4IN &= BIT3) == 0)     //confirm keydown :P4.3
	{
		delay(20);                   //delay 20ms : eliminate key shake
		if((P4IN &= BIT3) == 0)      //confirm keydown again
		{
			delay(20);
			P4OUT ^= BIT5;           //reverse P4.5
		}
		while((P4IN &= BIT3) == 0);  //confirm keyup : P4.3
		delay(20);                   //delay 20ms : eliminate key shake
	}
}

void main(void)
{
    P4DIR &= ~(BIT2 + BIT3);         // Set P4.2 P4.3 for input
    P4DIR |= BIT4 + BIT5 + BIT6 +BIT7;     // Set P4.4 P4.5 P4.6 for output
    P4OUT = BIT4;
    while(1)
    {
    	keycontrol();                // keycontrol function
    	WDTCTL = WDTPW + WDTCNTCL;   // Timer Clear
    }
}
