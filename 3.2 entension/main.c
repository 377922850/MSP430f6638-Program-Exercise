/*******************************************
reverse led use RISE interrupt (外部中断翻转led)
*******************************************/

#include <msp430f6638.h>

typedef unsigned int u16;

u16 counter1,counter2;

void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer
	P4DIR |= BIT4+BIT5+BIT6;    // Set P4.4 P4.5 P4.6 for output
	P4DIR &= ~(BIT2+BIT3);      // Set P4.2 P4.3 for input
	P4IE |= BIT2+BIT3;          // Allow P4.2 P4.3 interrupt
	P4IES &= ~(BIT2+BIT3);      // P4.2 P4.3选择上升沿触发
	P4IFG &= ~(BIT2 + BIT3);    // 清除标志位
	_enable_interrupt();        // 使能GIE
	while(1);
}

// 中断服务程序
#pragma vector = PORT4_VECTOR;
__interrupt void KEYCONTROL(void)
{
	if((P4IFG&BIT2) == BIT2)
	{
		P4IFG &= ~BIT2;          //清除中断标志
		counter1++;
		P4OUT ^= BIT4;           //P4.4反转
	}
	else if((P4IFG&BIT3) == BIT3)
	{
		P4IFG &= ~BIT3;         //清除中断标志
		counter2++;
		P4OUT ^= BIT5;          //P4.5反转
	}
}
