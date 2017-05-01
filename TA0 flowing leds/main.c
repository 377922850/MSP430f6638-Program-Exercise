#include <msp430f6638.h>

void main(void)
{
	WDTCTL = WDTPW + WDTHOLD;
	P4DIR |= BIT4 + BIT5 + BIT6;          //P4.4 P4.5 P4.6 ����ѡ��Ϊ���
	P4OUT = BIT4;                         //p4.4Ϊ�ߵ�ƽ
	TA0CTL = TASSEL_1 + MC_1 + TACLR ;    //TA0���ƼĴ�����ʱ��Դѡ��ΪACLK ����ģʽѡ��Ϊ������  ��0
	TA0CCTL0 |= CCIE;                     //����/�ȽϼĴ���ʹ���ж�
	TA0CCR0 = 32768;                      //32768*f=1s
	_BIS_SR(LPM0_bits + GIE);             //����͹���ģʽLPM0  �ж���ʹ��
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

