#include <msp430f6638.h>

void main(void)
{	WDTCTL = WDTPW + WDTHOLD;

	while(BAKCTL&LOCKIO)
		BAKCTL&=~(LOCKIO);
	UCSCTL6&=~(XT1OFF);
	UCSCTL6|=XCAP_3;
	do
	{
		UCSCTL7&=~(XT2OFFG+XT1LFOFFG+DCOFFG);
		SFRIFG1&=~OFIFG;
	}while(SFRIFG1&OFIFG);

	
	UCA1CTL1 |= UCSWRST;
	UCA1CTL1 |= UCSSEL_1;                     //1048576
	UCA1BR0 = 0x03;                           // 32kHz/9600=3.41
	UCA1BR1 = 0x00;
	UCA1MCTL = UCBRS_3+UCBRF_0;               // UCBRS = round[(N-INT(N))×8] = 3
    P8SEL|=BIT2+BIT3;
    UCA1CTL1 &= ~UCSWRST;                     // 初始化复位USCI_A1状态机
    UCA1IE |= UCRXIE;                         // 使能USCI_A1接收中断
    _BIS_SR(LPM3_bits + GIE);    // 进入LPM3，使能全局中断

}

#pragma vector=USCI_A1_VECTOR
__interrupt void USCI_A1_ISR(void)
{
	switch(UCA1IV)
	{
	case 0: break;
	case 2:while(!(UCA1IFG&UCTXIFG));                // USCI_A1发送缓冲是否准备就绪
		   UCA1TXBUF = UCA1RXBUF;                     // 将接收到的字符传递给发送缓冲
		   break;
	case 4:break;
	}

}

