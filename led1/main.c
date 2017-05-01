#include <msp430f6638.h>

typedef unsigned int u16;

void main(void)
{
	P1DIR = 0x01;     // 使P1.0为输出
	P1OUT = 0x00;     // 使P1.0为低电平
}

