#include<reg51.h>	
typedef unsigned int uint;
typedef unsigned char uchar;

#define LED P0
sbit LA = P2^2;
sbit LB = P2^3;
sbit LC = P2^4;

uchar LED_CODE[11] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x0};
uint SEG_CODE[8][3] = {{1,1,1}, {1,1,0}, {1,0,1}, {1,0,0}, {0,1,1}, {0,1,0}, {0,0,1}, {0,0,0}};
uchar NUMBERS[8] = {10, 10, 10, 10, 10, 10, 10, 10};

uchar x = 0;

void delay(uint c);
void DigDisplay();

void main()
{
	uchar temp = 0;
	TMOD = 0x20;
	TH1 = 0xf3;
	TL1 = 0xf3;
	SCON = 0x50;
	PCON = 0x80;
	TR1 = 1;
	EA = 1;
	ES = 1;
	
	while(1)
	{
		DigDisplay();
	}
}

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
		LED = LED_CODE[NUMBERS[x]];
		delay(100);
		LED = 0x0;
	}
}

void Usart() interrupt 4
{
	uchar temp;
	temp = SBUF;
	RI = 0;
	
	NUMBERS[x] = temp - 48;
	x++;
	if (x == 8)
		x = 0;
}