/*******************************************************************
TBO��ʱ�� ������ģʽ ACLK��32768hz�� P4.4 P4.5��� CCR4 CCR5 T=1s ռ�ձ� 75% 25%
*******************************************************************/

#include <msp430f6638.h>

void main (void)
{
	WDTCTL = WDTPW + WDTHOLD;                     //close watchdog timer
	P4DIR |= BIT4 + BIT5;
	P4SEL |= BIT4 + BIT5;
	TB0CTL = TASSEL_1 + MC_1 + TACLR;             //ACLK ������ģʽ ��0
	TB0CCTL4 = OUTMOD_7;                          //����Ϊ����ģʽ7      ��λ ��λ
	TB0CCTL5 = OUTMOD_7;
	TB0CCR0 = 32768;                              //T = 32768*(1/f)*(2^ID) = 1s
	TB0CCR4 = 24576;                              //t��  = 24576*(1/f)*(2^ID) = 0.75s
	TB0CCR5 = 8192;	                              //t��  = 8192*(1/f)*(2^ID) = 0.25s
}

