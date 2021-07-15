#include <reg51.h>

typedef unsigned int uint;
typedef unsigned char uchar;

#define KEYMAT P1
#define DATA P0
uchar KeyValue;
uchar KeyState;
uchar NUMBERS[] = "0123456789 ";
sbit LA = P2^2;
sbit LB = P2^3;
sbit LC = P2^4;
sbit K1 = P3^1; // Set Clock Time
sbit K2 = P3^0; // Backspace
sbit K3 = P3^2; // Confirm
sbit K4 = P3^3; // Cancel the Clock
sbit E = P2^7;
sbit RW = P2^5;
sbit RS = P2^6;
sbit BUZZER = P1^5; // Clock
uint INSTANT_TIME[8] = {0, 0, 0, 0, 0, 0, 0, 0};
uint CLOCK_TIME[8] = {10, 10, 0, 10, 10, 0, 10, 10};
uint Second_T = 2000;
uint Second_Count = 0;
uint Temp = 0;
uchar Clock_Mode_State = 0;
uchar Confirm_State = 0;
uchar Clock_On_Running = 0;
uint c = 0;
uchar FLAG = 0;
sbit t = P2^0;

void delay_1ms(uint c);
void delay_10ms();
void MatrixKeyDown();
void DigDisplay(uint TIME_CODE[8]);
void GetKeyValue();
void Backspace();
void ClockWarning();
void Init_LCD1602();
void write_Data(uchar DAT);
void write_Command(uchar COMMAND);
void check_Busy();
void LCD1602_DisplayInstantTime();
void LCD1602_SetClockTime();

void main()
{
	TMOD = 0x10;
	TH1 = (65536 - 500) / 256;
	TL1 = (65536 - 500) % 256;
	
	EA = 1;
	ET1 = 1;
	TR1 = 1;
	
	EX1 = 1;
	IT1 = 1;
	PX1 = 1;
	Init_LCD1602();
	
	while(1)
	{
		GetKeyValue();
		if (!Clock_Mode_State)
			LCD1602_DisplayInstantTime();
		else
		{
			LCD1602_DisplayInstantTime();
			LCD1602_SetClockTime();
		}
		MatrixKeyDown();
		if (KeyState && Clock_Mode_State)
		{
			KeyState = 0;
			CLOCK_TIME[c] = KeyValue;
			if (c < 8)
				c++;
			if (c == 2 || c == 5)
				c++;
		}
		if (c == 8 && Confirm_State)
		{
			c = 0;
			Confirm_State = 0;
			Clock_On_Running = 1;
			write_Command(0xcf);
			write_Data(0x40);
		}
		if (Clock_On_Running)
			ClockWarning();
	}
}

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

void MatrixKeyDown()
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

void GetKeyValue()
{
	if(K1 == 0)
	{
		delay_10ms();
		if (K1 == 0)
		{
			Clock_Mode_State = 1;
			while(!K1);
		}
	}
	
	if(K2 == 0)
	{
		delay_10ms();
		if (K2 == 0)
		{
			Backspace();
			while(!K2);
		}
	}
	
	if(K3 == 0)
	{
		delay_10ms();
		if (K3 == 0)
		{
			Confirm_State = 1;
			while(!K3);
		}
	}
}

void Backspace()
{
	c--;
	if (c == 2 || c == 5)
		c--;
	CLOCK_TIME[c] = 10;
}

void Timer1_int() interrupt 3
{
	uint t, H, M, S;
	
	TH1 = (65536 - 500) / 256;
	TL1 = (65536 - 500) % 256;
	t = Second_Count;
	Temp++;
	if (Temp == Second_T)
	{
		Second_Count++;
		Temp = 0;
		
		// Update the time
		H = t/3600;
		M = (t%3600)/60;
		S = t%3600%60;
		
		INSTANT_TIME[0] = H/10;
		INSTANT_TIME[1] = H%10;
		
		INSTANT_TIME[3] = M/10;
		INSTANT_TIME[4] = M%10;
		
		INSTANT_TIME[6] = S/10;
		INSTANT_TIME[7] = S%10;
	}
	
	if (FLAG && Clock_On_Running)
		BUZZER = ~BUZZER;
}

void ClockWarning()
{
	uchar i;
	for(i = 0; i < 8;  i++)
	{
		if (INSTANT_TIME[i] != CLOCK_TIME[i])
		{
			return;
		}
	}
	FLAG = 1;
	t = 0;
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
	E = 1;
	delay_1ms(1);
	E = 0;
}

void write_Data(uchar DAT)
{
	check_Busy();
	E = 0;
	RS = 1;
	RW = 0;
	DATA = DAT;
	E = 1;
	delay_1ms(1);
	E = 0;
}

void Init_LCD1602()
{
	write_Command(0x38);
	write_Command(0x0c);
	write_Command(0x06);
	write_Command(0x01);
}

void LCD1602_DisplayInstantTime()
{
	uchar x;
	write_Command(0x80);
	write_Data(0x54);
	write_Data(0x69);
	write_Data(0x6d);
	write_Data(0x65);
	write_Data(0x3a);
	write_Data(0x20);
	for(x = 0; x < 8; x++)
	{
		if (x == 2 || x == 5)
		{
			write_Data(0x2d);
			continue;
		}
		write_Data(NUMBERS[INSTANT_TIME[x]]);
	}
}

void LCD1602_SetClockTime()
{
	uchar x;
	write_Command(0xc0);
	write_Data(0x43);
	write_Data(0x6c);
	write_Data(0x6f);
	write_Data(0x63);
	write_Data(0x6b);
	write_Data(0x3a);
	for(x = 0; x < 8; x++)
	{
		if (x == 2 || x == 5)
		{
			write_Data(0x2d);
			continue;
		}
		write_Data(NUMBERS[CLOCK_TIME[x]]);
	}
}

void int1_isr(void) interrupt 2
{
	uchar i;
	if (FLAG)
	{
		FLAG = 0;
		Clock_Mode_State = 0;
		write_Command(0xcf);
		write_Data(0x20);
		write_Command(0x01);
		for(i = 0; i < 8; i++)
		{
			if (c != 2 && c != 5)
				CLOCK_TIME[i] = 10;
		}
		t = 1;
	}
}