#include <reg51.h>
#include <intrins.h>

typedef unsigned int uint;
typedef unsigned char uchar;

#define DATA P0
#define GPIO_KEY P1

sbit E = P2^7;
sbit RW = P2^5;
sbit RS = P2^6;
uchar NUMBERS[] = "0123456789";
uchar NAMES[] = "Wei Xin";
unsigned char KeyValue;
unsigned char KeyState;
uchar count = 0;

void delay_1ms(uint c)
{
  uchar a, b;
	for (; c > 0; c --)
		 for (b = 199; b > 0; b--)
		  	for(a = 1; a > 0; a--);
}

void delay_10ms()
{
	uchar a,b,c;
  for(c=1;c>0;c--)
		for(b=38;b>0;b--)
			for(a=130;a>0;a--);   
}

void check_Busy()
{
	uchar STATUS;
	do
	{
		STATUS = 0xff;
		E = 0;
		RS = 0;
		RW = 1;
		E = 1;
		STATUS = DATA;
	}while(STATUS & 0x80);
	E = 0;
}

void write_Command(uchar COMMAND)
{
	check_Busy();
	E = 0;
	RS = 0;
	RW = 0;
	DATA = COMMAND;
	delay_1ms(1);
	E = 1;
	delay_1ms(5);
	E = 0;
}

void write_Data(uchar DAT)
{
	check_Busy();
	E = 0;
	RS = 1;
	RW = 0;
	DATA = DAT;
	delay_1ms(1);
	E = 1;
	delay_1ms(5);
	E = 0;
}

void KeyDown(void)
{
	char a;
	GPIO_KEY=0x0f;
	if(GPIO_KEY!=0x0f)
	{
		delay_10ms();
		if(GPIO_KEY!=0x0f)
		{
			KeyState=1;
			GPIO_KEY=0X0F;
			switch(GPIO_KEY)
			{
				case(0X07):	KeyValue=0;break;
				case(0X0b):	KeyValue=1;break;
				case(0X0d): KeyValue=2;break;
				case(0X0e):	KeyValue=3;break;
			}
			GPIO_KEY=0XF0;
			delay_10ms();
			switch(GPIO_KEY)
			{
				case(0X70):	KeyValue=KeyValue;break;
				case(0Xb0):	KeyValue=KeyValue+4;break;
				case(0Xd0): KeyValue=KeyValue+8;break;
				case(0Xe0):	KeyValue=KeyValue+12;break;
			}
			while((a<50)&&(GPIO_KEY!=0xf0))
			{
				delay_10ms();
				a++;
			}
			a=0;
		}
	}
}

void Init_LCD1602()
{
	write_Command(0x38);
	write_Command(0x0c);
	write_Command(0x06);
	write_Command(0x01);
	write_Command(0x84);
}

void main()
{
	Init_LCD1602();
	while(1)
	{
		KeyDown();
		if (KeyState)
		{
			KeyState = 0;
			if (count < 8)
				write_Data(NUMBERS[KeyValue]);
			else
				write_Data(NAMES[KeyValue]);
			delay_1ms(1);
			count++;
			if (count == 8)
				write_Command(0xc3);
		}
	}
}