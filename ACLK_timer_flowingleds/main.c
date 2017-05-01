#include <msp430f6638.h>

unsigned int counter=0;
void main(void)
{
	//WDTCTL = WDTPW + WDTSSEL_1 + WDTTMSEL + WDTCNTCL + WDTIS_4;
	P4OUT = BIT4;
	WDTCTL = WDT_ADLY_1000;
	P4DIR |= BIT4 + BIT5 + BIT6;
	SFRIE1 |= WDTIE;
	_BIS_SR(LPM3_bits+GIE);
}

#pragma vector = WDT_VECTOR
__interrupt void aclk_flowingleds(void)
{
	P4OUT <<= 1;
	counter++;
	if(counter == 3);
	P4OUT = BIT4;
}
