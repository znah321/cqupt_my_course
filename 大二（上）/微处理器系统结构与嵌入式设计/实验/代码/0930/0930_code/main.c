#include <reg51.h>
#include <intrins.h>

#define LED P2

typedef unsigned char uchar;
typedef unsigned int uint;


void delay()
{
	uint i, j;
	i = 5000;
	j = 5000;
	while(i > 0)
	{
		while(j > 0)
			j--;
		i--;
	}
}

void main()
{
	uint i;
	LED = 0x7f;
	delay();
	while(1)
	{
		for(i = 0;i < 7; i++)
		{
			LED = _cror_(LED, 1);
			delay();
		}
		for(i = 0;i < 7; i++)
		{
			LED = _crol_(LED, 1);
			delay();
		}
	}
}