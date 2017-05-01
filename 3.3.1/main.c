/**************************************
以XT1作为ACLK时钟源，将P1.0管脚作为ACLK的输出
以XT2作为SMCLK时钟源，将P3.4管脚作为SMCLK的输出
**************************************/

#include <msp430f6638.h>

void main(void)
{
	WDTCTL = WDTPW + WDTHOLD;                            //关闭开门狗
	P1DIR |= BIT0;                                       //p1.0为输出
	P3DIR |= BIT4;                                       //p3.4为输出
    P1SEL |= BIT0;                                       //p1.0选择为外围模块    ACLK
    P3SEL |= BIT4;                                       //p3.4选择为外围模块    SMCLK

    while(BAKCTL & LOCKIO)                               //解锁引脚
    	BAKCTL &= ~(LOCKIO);
    P7SEL |= BIT2 + BIT3;                                //p7.2 p7.3选择为外围模块   XT2OUT  XT2IN
    UCSCTL6 &= ~(XT1OFF);                                //打开XT1
    UCSCTL6 &= ~(XT2OFF);                                //打开XT2
    UCSCTL6 |= XCAP_3;                                   //配置内接电容

    do
    {
    	UCSCTL7 &= ~(XT2OFFG + XT1LFOFFG + DCOFFG);      //清除故障标志位
    	SFRIFG1 = ~OFIFG;                                //清除故障总标志位
    }
    while (SFRIFG1 & OFIFG);                             //检查振荡器故障标志位

    UCSCTL6 &= ~(XT1DRIVE_3);                            //设定XT1驱动
    UCSCTL6 &= ~XT2DRIVE0;                               //设定XT2驱动
    UCSCTL4 |= SELA_0 + SELS_5;                          //ACLK=XT1  SMCLK=XT2

    _BIS_SR(LPM0_bits);                                  //进入低功耗模式0
}
