#include <reg51.h>

typedef unsigned int uint;
typedef unsigned char uchar;

#define LED P0
#define KEYMAT P1

sbit LA = P2^2;
sbit LB = P2^3;
sbit LC = P2^4;

uint LED_CODE[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
uint SEG_CODE[8][3] = {{1,1,1}, {1,1,0}, {1,0,1}, {1,0,0}, {0,1,1}, {0,1,0}, {0,0,1}, {0,0,0}};
uchar KeyPosition = -1;
uint NumberList[8] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
uchar i;

void delay(uchar j)
{
	while(j-- > 0);
}

void delay_10ms(uint k)
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

void dig_Display()
{
	for(i = 0; i < 8; i++)
	{
		LA = SEG_CODE[i][2];LB = SEG_CODE[i][1];LC = SEG_CODE[i][0];
		LED = NumberList[i];
		delay(10);
		LED = 0x0;
	}
}


void main()
{
	while(1)
	{
		get_KeyValue();
		dig_Display();
	}
}
