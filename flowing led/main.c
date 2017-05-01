#include <msp430f6638.h>

typedef unsigned int u16;

void delay(u16 duration)    //延时函数
{
	u16 a;
	for(a = 0 ; a < 5000 * duration ; a ++);
}

void main(void)
{
	u16 i;
	P2DIR = 0xff;           //P2全部为输出
	P2OUT = 0x01;           //开始是只有P2.0亮
	while(1)
	{
		for(i=0;i<7;i++)
		{
			P2OUT <<= 1;    //0000 0001 -> 0000 0010 -> 0000 0100 -> 0000 1000 -> 0001 0000 ->0010 0000 ->0100 0000 -> 1000 0000
			delay(100);
		}
		for(i=0;i<7;i++)
		{
			P2OUT >>= 1;
			delay(100);
		}
	}
}
