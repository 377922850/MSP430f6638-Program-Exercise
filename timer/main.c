#include <msp430.h> 

/*
 * main.c
 */
void main(void)
	{
		WDTCTL = WDTPW + WDTHOLD;                            //�رտ��Ź�
		P1DIR |= BIT0;                                       //p1.0Ϊ���
		P3DIR |= BIT4;                                       //p3.4Ϊ���
		P1SEL |= BIT0;                                       //p1.0ѡ��Ϊ��Χģ��    ACLK
		P3SEL |= BIT4;                                       //p3.4ѡ��Ϊ��Χģ��    SMCLK
		while(BAKCTL & LOCKIO)                               //��������
		BAKCTL &= ~(LOCKIO);
		P7SEL |= BIT2 + BIT3;                                //p7.2 p7.3ѡ��Ϊ��Χģ��   XT2OUT  XT2IN
		UCSCTL6 &= ~(XT2OFF);                                //��XT2
		UCSCTL6 &= ~(XT1OFF);                                //��XT1
		UCSCTL6 |= XCAP_3;                                   //�����ڽӵ���

		do
		{
			UCSCTL7 &= ~(XT2OFFG + XT1LFOFFG + DCOFFG);      //������ϱ�־λ
			SFRIFG1 = ~OFIFG;                                //��������ܱ�־λ
		}while (SFRIFG1 & OFIFG);                            //

		UCSCTL6 &= ~XT2DRIVE0;                               //
		UCSCTL4 |= SELA_0 + SELS_5;                          //
		while(1);
	}
