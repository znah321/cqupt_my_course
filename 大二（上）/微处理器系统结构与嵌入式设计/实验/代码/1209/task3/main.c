#include <reg51.h>

typedef unsigned int uint;
typedef unsigned char uchar;
uchar message[] = "wei_xin 2019210258\r\n";
uchar i = 0;

void main()
{
	TMOD = 0x20;
	TH1 = 0xf3;
	TH1 = 0xf3;
	SCON = 0x50;
	PCON = 0x00;  
	TR1 = 1;

	while(1)
	{
		for(; message[i] != '\0'; i++)
		{
			SBUF = message[i];
			while(TI == 0);
			TI = 0;
		}
		i = 0;
	}
}