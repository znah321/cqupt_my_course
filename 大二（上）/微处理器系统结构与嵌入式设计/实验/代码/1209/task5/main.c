#include <reg51.h>
#include <string.h>

typedef unsigned int uint;
typedef unsigned char uchar;

uchar temp;
uchar tempstr[8] = {10, 10, 10, 10, 10, 10, 10, 10};
uchar c = 0;

#define LED P0
sbit LA = P2^2;
sbit LB = P2^3;
sbit LC = P2^4;

uchar LED_CODE[11] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x0};
uint SEG_CODE[8][3] = {{1,1,1}, {1,1,0}, {1,0,1}, {1,0,0}, {0,1,1}, {0,1,0}, {0,0,1}, {0,0,0}};

void delay(uint c)
{
	while(c-- > 0);
}

void DigDisplay()
{
	uchar x;
	for(x = 0; x < 8; x++)
	{
		LC = SEG_CODE[x][0];LB = SEG_CODE[x][1];LA = SEG_CODE[x][2];
		LED = LED_CODE[tempstr[x]];
		delay(100);
		LED = 0x0;
	}
}

void main()
{
	TMOD = 0x20;
	TH1 = 0xf3;
	TH1 = 0xf3;
	SCON = 0x50;
	PCON = 0x80;
	
	P2 = 0xff;
	
	EA = 1;
	ES = 1;
	TR1 = 1;

	while(1)
	{
		DigDisplay();
	}
}

void timer1_int() interrupt 4
{
	
	temp = SBUF;
	RI = 0;
	
	tempstr[c] = temp - 48;
	c++;
	if (c == 8)
		c = 0;
	
	// Test the data
	SBUF = temp;
	while(!TI);
	TI = 0;						 
}