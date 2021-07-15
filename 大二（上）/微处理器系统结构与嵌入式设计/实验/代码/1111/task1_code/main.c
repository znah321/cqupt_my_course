#include <reg51.h>
#include <intrins.h>

typedef unsigned int uint;
typedef unsigned char uchar;

sbit K3 = P3^2;
sbit K4 = P3^3;

void delay1(uchar i)
{
	while(i--);	
}

void Delay(uint i)
{
	uint j;
	for(; i > 0; i--)
		for(j = 0; j < 125; j++);
}

void Int_Init()
{
	EA = 1;
	EX0 = 1;
	EX1 = 1;
	IT0 = 1;
	IT1 = 1;
	PX0 = 0;
	PX1 = 1;
}

void main()
{
	uint display[8] = {0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f};
	uchar a;
	Int_Init();
	for(;;)
	{
		for(a = 0; a < 8; a++)
		{
			Delay(100);
			P2 = display[a];
		}
	}
}

void int0_isr(void) interrupt 0
{
	for(;;)
	{
		P2 = 0x0f;
		Delay(400);
		P2 = 0xf0;
		Delay(400);
	}
}

void int1_isr(void) interrupt 2
{
	uchar m;
	for(m = 0; m < 5; m++)
	{
		P2 = 0;
		Delay(500);
		P2 = 0xff;
		Delay(500);
	}
}