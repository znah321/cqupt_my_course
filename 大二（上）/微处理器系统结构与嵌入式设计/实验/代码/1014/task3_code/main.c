#include <reg51.h>
#include <intrins.h>

typedef unsigned int uint;
typedef unsigned char uchar;

#define LED P0
#define KEYMAT P1
sbit LA = P2^2;
sbit LB = P2^3;
sbit LC = P2^4;

uint LED_CODE[13] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x76,0x06,0x40};
uint SEG_CODE[8][3] = {{1,1,1}, {1,1,0}, {1,0,1}, {1,0,0}, {0,1,1}, {0,1,0}, {0,0,1}, {0,0,0}};
uchar KeyPosition = -1;
uint NumberList[8] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
uchar count, i;

void delay_10ms(uchar k); // Delay 10*k ms
void delay();
void get_KeyValue(); // Get the button's position
void dig_Display(uchar count); // Display LED

void main()
{
	count = 0;
	while(1)
	{
		get_KeyValue();
		dig_Display(count);
		//ttt();
		count++;
	}
}

void delay(uint j)
{
	while(j-- > 0);
}

void delay_10ms(uchar k)
// Function:Deay 10*i ms
{
	uchar a, b;
	for (;k>0;k--)
	{
		for (b=38;b>0;b--)
		{
			for (a=130;a>0;a--);
		}         
	}     
}

void dig_Display(uchar count)
{
	uint c, temp, CONSIST_TIME, x;	
	temp = count;
	x = 1;
	CONSIST_TIME = 25;
	while(CONSIST_TIME-- > 0)
	{
		for(c = 0; c < 8 ; c++)
		{
			LC = SEG_CODE[c][0];LB = SEG_CODE[c][1];LA = SEG_CODE[c][2];
			LED = NumberList[temp%8];
			delay(100);
			LED = 0x0;
			temp++;
		}
	}
}

void get_KeyValue()
{
	// Get the key's row number
	KEYMAT = 0x0f;
	if (KEYMAT != 0x0f)
	{
		delay_10ms(1);
		KEYMAT = 0x0f;
		if(KEYMAT != 0x0f)
		{
			switch(KEYMAT)
			{
				// Row number
				case 0x07:KeyPosition = 0;break;
				case 0x0b:KeyPosition = 1;break;
				case 0x0d:KeyPosition = 2;break;
				case 0x0e:KeyPosition = 3;break;
			}
		}
	}
	
	// Get the key's column number
	KEYMAT = 0xf0;
	if (KEYMAT != 0xf0)
	{
		delay_10ms(1);
		KEYMAT = 0xf0;
		if (KEYMAT != 0xf0)
		{
			switch(KEYMAT)
			{
				case 0x70:KeyPosition = KeyPosition;while(KEYMAT == 0x70);break;
				case 0xb0:KeyPosition = KeyPosition + 4;while(KEYMAT == 0xb0);break;
				case 0xd0:KeyPosition = KeyPosition + 8;while(KEYMAT == 0xd0);break;
				case 0xe0:KeyPosition = KeyPosition + 12;while(KEYMAT == 0xe0);break;
			}
			// Change the NumberList
			i = 0;
			while(1)
			{
				if (NumberList[i] != 0x0)	i++;
				else	break;
			}
			NumberList[i] = LED_CODE[KeyPosition];
		}
	}
}
void ttt()
{
	uchar j = 10;
	for(i = 0; i < 8; i++)
	{
		LA = SEG_CODE[i][2];LB = SEG_CODE[i][1];LC = SEG_CODE[i][0];
		LED = NumberList[i];
		while(j-- > 0);
		LED = 0x0;
	}
}