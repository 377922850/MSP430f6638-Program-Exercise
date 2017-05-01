#include <msp430f6638.h>

typedef volatile unsigned int u16;

u16 counter=0;

void delay(u16 duration)
{
	u16 i;
	for(i=0;i<5000*duration;i++);
}

void main(void)
{
	WDTCTL = WDTPW + WDTHOLD;     //stop watchdog timer
	P4DIR |= BIT4 + BIT5 + BIT6;  //set P4.4 P4.5 P4.6 for output
	P4DIR &= ~BIT2;               //set P4.2 for input
    P4OUT = BIT4;
	P4IE |= BIT2;                 //allow P4.2 interrupt
	P4IES |= BIT2;                //P4.2ѡ���½��ش���
	P4IFG = 0X00;                 //�����־λ
	_enable_interrupt();          //ʹ��GIE
	while(1)
	{
		if(counter == 3)
			{
				counter = 0;
				P4OUT = BIT4;
			}
	}
}

//interrupt function
#pragma vector = PORT4_VECTOR
__interrupt void keycontrol(void)
{
	P4OUT <<= 1;
	counter++;
	P4IFG &= ~BIT2;
}
