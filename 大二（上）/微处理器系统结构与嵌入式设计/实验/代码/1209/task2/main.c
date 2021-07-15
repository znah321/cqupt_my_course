#include <reg51.h>
#include <string.h>

typedef unsigned int uint;
typedef unsigned char uchar;

uchar temp;
uchar tempstr[8];
uchar c = 0;

void delay(uint c)
{
	while(c-- > 0);
}

uint compare(uchar str1[8], uchar str2[8])
{
	uchar j;
	for(j = 0; j < 8; j++)
	{
		if (str1[j] != str2[j])
		{
			return 0;
		}
	}
	return 1;
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

	while(1);
}

void timer1_int() interrupt 4
{
	uchar i, flag = 0;
	
	temp = SBUF;
	RI = 0;
	
	switch(temp)
	{
		case '0':P2 = 0xfe;break;
		case '1':P2 = 0xfd;break;
		case '2':P2 = 0xfb;break;
		case '3':P2 = 0xf7;break;
		case '4':P2 = 0xef;break;
		case '5':P2 = 0xdf;break;
		case '6':P2 = 0xbf;break;  
		case '7':P2 = 0x7f;break;
	}
	tempstr[c] = temp;
	c++;
	
	if (compare("01234567", tempstr))
	{
		for(i = 0; i < 10; i++)
		{
			P2 = 0x0;
			delay(30000);
			P2 = 0xff;
			delay(30000);
			
		}
		c = 0;
		for(i = 0; i< 8; i++)
		{
			tempstr[i] = '\0';
		}
	}
	
	SBUF = temp;
	while(!TI);
	TI = 0;						 
}