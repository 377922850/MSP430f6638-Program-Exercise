#include <msp430f6638.h>

void main(void)
{
	WDTCTL = WDTPW + WDTHOLD;
	P4DIR |= BIT4 + BIT5 + BIT6;          //P4.4 P4.5 P4.6 引脚选择为输出
	P4OUT = BIT4;                         //p4.4为高电平
	TA0CTL = TASSEL_1 + MC_1 + TACLR ;    //TA0控制寄存器：时钟源选择为ACLK 工作模式选择为增记数  清0
	TA0CCTL0 |= CCIE;                     //捕获/比较寄存器使能中断
	TA0CCR0 = 32768;                      //32768*f=1s
	_BIS_SR(LPM0_bits + GIE);             //进入低功耗模式LPM0  中断总使能
}

#pragma vector = TIMER0_A0_VECTOR
__interrupt void AT0LEDS(void)
{
	P4OUT <<= 1;
	if(P4OUT == BIT7)                     //==1000 0000
		{
		   P4OUT == BIT4;                 //==0001 0000
		}
}

