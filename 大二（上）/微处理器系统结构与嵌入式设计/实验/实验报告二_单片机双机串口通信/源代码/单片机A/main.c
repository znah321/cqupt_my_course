#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int
#define KEYMAT P1	

uchar KeyState = 0;
uchar KeyValue;

void MatrixKeyDown();
void delay_1ms(uint c);

void main()
{
	uchar temp = 0;
	
	KeyValue=0;
	TMOD = 0x20;
	TH1 = 0xf3;
	TL1 = 0xf3;
	SCON = 0x40;
	PCON = 0x80;
	TR1 = 1;
	P1 = 0xf0;
	ES =1;
	EA = 1;
	
	while(1)
	{
		MatrixKeyDown();
		
		if(KeyState==1)
		{
			temp = KeyValue + 48;
			SBUF = temp;	
			KeyState=0;
		}
	}
}

void MatrixKeyDown(void)
{
	char a;
	KEYMAT = 0x0f;
	if(KEYMAT != 0x0f)
	{
		delay_1ms(1);
		if(KEYMAT != 0x0f)
		{
			KeyState = 1;
			KEYMAT = 0X0F;
			switch(KEYMAT)
			{
				case(0X07):	KeyValue = 0;break;
				case(0X0b):	KeyValue = 1;break;
				case(0X0d): KeyValue = 2;break;
				case(0X0e):	KeyValue = 3;break;
			}
			KEYMAT = 0XF0;
			delay_1ms(1);
			switch(KEYMAT)
			{
				case(0X70):	KeyValue = KeyValue;break;
				case(0Xb0):	KeyValue = KeyValue+4;break;
				case(0Xd0): KeyValue = KeyValue+8;break;
				case(0Xe0):	KeyValue = KeyValue+12;break;
			}
			while((a < 50)&&(KEYMAT != 0xf0))
			{
				delay_1ms(1);
				a++;
			}
			a = 0;
		}
	}
}

void delay_1ms(uint c)
{
  uchar a, b;
	for (; c > 0; c --)
		 for (b = 199; b > 0; b--)
		  	for(a = 1; a > 0; a--);
}

void int1() interrupt 4
{
	TI = 0;
}
