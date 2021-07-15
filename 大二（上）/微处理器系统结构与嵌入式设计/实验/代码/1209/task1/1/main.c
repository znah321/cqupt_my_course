#include <reg51.h>

typedef unsigned int uint;
typedef unsigned char uchar;

uchar temp = 0;

void main()
{
	TMOD = 0x20;
	TH1 = 0xfd;
	TH1 = 0xfd;
	SCON = 0x40;
	PCON = 0x80;
	TR1 = 1;
	P1 = 0xff;
	
	EA = 1;
	ET1 = 1;
	while(1);
}

void timer1_int() interrupt 4
{
	temp = P1;
	SBUF = temp;
	TI = 0;
}