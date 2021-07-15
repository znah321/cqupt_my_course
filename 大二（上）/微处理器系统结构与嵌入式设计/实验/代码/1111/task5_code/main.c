#include <reg51.h>
#include <intrins.h>

typedef unsigned int uint;
typedef unsigned char uchar;

sbit LED_1 = P2^7;
sbit LED_2 = P2^0;

uint T_1 = 10000;
uint T_2 = 50000;
count1 = 0;
count2 = 0;

void main()
{
	TMOD = 0x03;
	EA = 1;
	ET0 = 1;
	
	TR0 = 1;
	TR1 = 1;
	
	TH0 = 0x9c;
	TL0 = 0x9c;
	
	while(1);
}

void T0_int() interrupt 1
{
	TH0 = 0x9c;
	TL0 = 0x9c;

	// LED_1
	if (count1 <= T_1)
		count1++;
	else
	{
		LED_1 = ~LED_1;
		TR1= 0;
	}
	
	// LED_2
	if (count2 <= T_2)
		count2++;
	else
	{
		LED_2 = ~LED_2;
		TR1 = 1;
		count1 = 0;
		count2 = 0;
	}
}