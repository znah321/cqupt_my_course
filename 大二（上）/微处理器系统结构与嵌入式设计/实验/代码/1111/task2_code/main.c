#include <reg51.h>
#include <intrins.h>

typedef unsigned int uint;
typedef unsigned char uchar;

sbit P1_0 = P1^0;
uchar count = 0;
uchar T = 4;
uchar HIGH = 3;


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
	count++;
	if (count == HIGH)
		P1_0 = 1;
	if (count == T)
	{
		count = 0;
		P1_0 = 0;
	}
}