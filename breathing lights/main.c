#include <msp430f6638.h>

typedef volatile unsigned int u16;
#define onespeed 2;                        //set the onespeed for 2
#define totaltime 700                      //set the totaltime for 700
char lightsign;                            //the sign of the light
int nowtime=0;                             //initially the on time of the light

void delay(u16 duration)          //delay function £º one duration equals 1ms
{
	u16 i;
	for(i=0 ; i<duration*5000 ; i++);
}

void controllight()                        //control the statement of light function
{
	if(nowtime > totaltime)
	{
		nowtime = totaltime;
		lightsign = 1;
	}
	else if(nowtime < 0)
	{
		nowtime = 0;
		lightsign = 0;
	}
}

void speedcontrol()                        //control speed function
{
	if(lightsign == 0)
		{
		nowtime += onespeed;
		}
	else if(lightsign == 1)
		{
		nowtime -= onespeed;
		}
}

void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	           //Stop watchdog timer
	P4DIR = 0x10;
	P4OUT = 0x10;
	while(1)
	{
		controllight();
		speedcontrol();
		P4OUT = 0X10;
		delay(nowtime);
		P4OUT = 0x00;
		delay(totaltime - nowtime);
	}
}

	
