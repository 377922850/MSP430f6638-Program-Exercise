#include <msp430f6638.h>

void main(void)
{
	WDTCTL = WDTPW + WDTSSEL_1 + WDTCNTCL + WDTIS_5;        //��Կ+ACLK+���Ź�����+2^13/32768��250ms����һ�Σ�
	while(1)
	{
		WDTCTL = WDTPW + WDTSSEL_1 + WDTCNTCL + WDTIS_5;    //ι��
	}
}
