#include <reg51.h>
#include <intrins.h>

#define LED P0
sbit LA = P2^2;
sbit LB = P2^3;
sbit LC = P2^4;
sbit X = P2^1;
typedef unsigned int uint;
typedef unsigned char uchar;

// 数码管码表
uint LED_CODE[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

// 延时函数
void delay(uint i)
{
	while(i-- > 0);
}

void main()
{
	uint i, x;
	while(1)
	{
		for(i = 0; i < 8; i++)
		{
			switch(i)
			{
				case 0:
					LA = 0; LB = 0; LC = 0;LED = LED_CODE[8];break;
				case 1:
					LA = 1; LB = 0; LC = 0;LED = LED_CODE[5];break;
				case 2:
					LA = 0; LB = 1; LC = 0;LED = LED_CODE[2];break;
				case 3:
					LA = 1; LB = 1; LC = 0;LED = LED_CODE[0];break;
				case 4:
					LA = 0; LB = 0; LC = 1;LED = LED_CODE[1];break;
				case 5:
					LA = 1; LB = 0; LC = 1;LED = LED_CODE[2];break;
				case 6:
					LA = 0; LB = 1; LC = 1;LED = LED_CODE[9];break;
				case 7:		
					LA = 1; LB = 1; LC = 1;LED = LED_CODE[1];break;
			}
			delay(5);
			LED = 0x0;
		}
	}
}