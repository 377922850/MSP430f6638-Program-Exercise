#include <msp430f6638.h>

typedef unsigned int u16;

void main(void)
{
	P1DIR = 0x01;     // ʹP1.0Ϊ���
	P1OUT = 0x00;     // ʹP1.0Ϊ�͵�ƽ
}

