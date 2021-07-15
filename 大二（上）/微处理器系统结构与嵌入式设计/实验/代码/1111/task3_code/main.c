#include <reg51.h>
#include <intrins.h>

typedef unsigned int uint;
typedef unsigned char uchar;

sbit BUZZER = P1^5;
uint count = 0;
uint T = 10000;

void main()
{
	TMOD = 0x12;
	TR0 = 1;
	
	EA = 1;
	ET0 = 1;
	TR0 = 1;
	
	TH0 = 0x9c;
	TL0 = 0x9c;
	while(1);
}

void timer0_int() interrupt 1
{
	if (count < T)
	{
		BUZZER = ~BUZZER;
		count++;
	}
	else if (count >= T && count < 2*T)
		count++;
	else
		count = 0;
}