#include <reg51.h>
#include <intrins.h>

#define LED P0
sbit LA = P2^2;
sbit LB = P2^3;
sbit LC = P2^4;

typedef unsigned int uint;
typedef unsigned char uchar;

uint LED_CODE[8] = {0x0, 0x76, 0x06, 0x40, 0x5b, 0x3f, 0x06, 0x6f}; //0,H,I,-,2,0,1,9
uint SEG_CODE[8][3] = {{1,1,1}, {1,1,0}, {1,0,1}, {1,0,0}, {0,1,1}, {0,1,0}, {0,0,1}, {0,0,0}};

void delay(uint i)
{
	while(i-- > 0);
}

void DigDisplay(uint i)
{
	uint c, temp, CONSIST_TIME;	
	temp = i;
	CONSIST_TIME = 15;
	while(CONSIST_TIME-- > 0)
	{
		for(c = 0; c < 8 ; c++)
		{
			LC = SEG_CODE[c][0];LB = SEG_CODE[c][1];LA = SEG_CODE[c][2];
			LED = LED_CODE[temp%8];
			delay(100);
			LED = 0x0;
			temp++;
		}
	}
}

void main()
{
	uint i = 0;
	while(1)
	{
		DigDisplay(i);
		i++;
	}
}
