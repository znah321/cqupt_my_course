#include <reg51.h>
#include <intrins.h>

typedef unsigned int uint;
typedef unsigned char uchar;

#define LED P0
sbit LA = P2^2;
sbit LB = P2^3;
sbit LC = P2^4;

sbit K1 = P3^1;
sbit K2 = P3^0;

uint LED_CODE[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
uint PRESSED_TIMES = 0;

void delay_10ms(uint i)
// Function:Deay 10*i ms
{
	uchar a, b;
	for (;i>0;i--)
	{
		for (b=38;b>0;b--)
		{
			for (a=130;a>0;a--);
		}         
	}     
}

void get_KeyValue()
// Function:Find the pressed key's number
{
	if(K1 == 0)
	{
		delay_10ms(1);
		if (K1 == 0)
		{
			PRESSED_TIMES++;
			while(!K1);
		}
	}
	
	if(K2 == 0)
	{
		delay_10ms(1);
		if (K2 == 0)
		{
			PRESSED_TIMES = 0;
			while(!K2);
		}
	}
}

void main()
{
	LA = 0; LB = 0; LC = 0;
	while(1)
	{
		get_KeyValue();
		LED = LED_CODE[PRESSED_TIMES % 10];
		//LED = 0xff;
		delay_10ms(1);
	}
}
	