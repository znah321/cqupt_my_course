#include <reg51.h>
typedef unsigned int uint;
typedef unsigned char uchar;

sbit beep = P1^5;
uchar flag = 0;
uchar temp;

void delay_1ms(uint c)
{
  uchar a, b;
	for (; c > 0; c --)
		 for (b = 199; b > 0; b--)
		  	for(a = 1; a > 0; a--);
}

void main()
{
	TMOD = 0x20;
	TH1 = 0xf3;
	TH1 = 0xf3;
	SCON = 0x50;
	PCON = 0x80;
	
	EA = 1;
	ES = 1;
	TR1 = 1;
	
	while(1)
	{
		if (flag == 1)
		{
			beep = ~beep;
			delay_1ms(1);
		}
	}
}

void timer1_int() interrupt 4
{
	temp = SBUF;
	RI = 0;
	
	if (temp == '0')
		flag = 0;
	if (temp == '1')
		flag = 1;
	
	SBUF = temp;
	while(!TI);
	TI = 0;
}
