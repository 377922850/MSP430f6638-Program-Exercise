#include <msp430f6638.h>

void main(void)
{
	WDTCTL = WDTPW + WDTSSEL_1 + WDTCNTCL + WDTIS_5;        //密钥+ACLK+看门狗清零+2^13/32768（250ms重启一次）
	while(1)
	{
		WDTCTL = WDTPW + WDTSSEL_1 + WDTCNTCL + WDTIS_5;    //喂狗
	}
}
