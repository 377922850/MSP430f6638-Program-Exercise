/*********************************************
按下KEY1，LED6 LED7逐渐变亮 按下KEY2，LED6 LED7逐渐变暗
*********************************************/

#include <msp430f6638.h>

volatile unsigned int i,duty=50;

void delay(unsigned int duration)
{
	for(i=0;i<duration*5000;i++);
}

void darken(void)
{
	if(TB0CCR4 > 0)
	{
		TB0CCR4 -= duty;
		TB0CCR5 -= duty;
	}
	
}

void lighten(void)
{
	if(TB0CCR4 < 1200)
	{
		TB0CCR4 += duty;
		TB0CCR5 += duty;
	}

}

void keycontrol()
{
	if((P4IN &= BIT2) == 0)          //confirm keydown:P4.2
	{
		delay(20);                   //delay 20ms : eliminate key shake
		if((P4IN &= BIT2) == 0)      //confirm keydown again
		{
			delay(20);
			lighten();
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
			darken();
		}
		while((P4IN &= BIT3) == 0);  //confirm keyup : P4.3
		delay(20);                   //delay 20ms : eliminate key shake
	}
}

void TB0SEL(void)                              //timer TB0 set up function
{
	P4DIR |= BIT4 + BIT5;
	P4SEL |= BIT4 + BIT5;
	P4DIR &= ~(BIT2+BIT3);
	TB0CTL = TBSSEL_1 + MC_1 + TBCLR;
	TB0CCR0 = 1200;                            //T = 1200*(1/32768)=0.0366s
	TB0CCTL4 = OUTMOD_7;
	TB0CCR4 = 1200;
	TB0CCTL5 = OUTMOD_7;
	TB0CCR5 = 1200;
}

void main (void)
{
	WDTCTL = WDTPW + WDTHOLD;
	TB0SEL();
    while(1)
    {
    	keycontrol();
    }
}
