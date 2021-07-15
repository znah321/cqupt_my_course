#include <reg51.h>
#include <intrins.h>


typedef unsigned int uint;
typedef unsigned char uchar;

#define KEYMAT P1
#define LED P0
uchar KeyValue;
uchar KeyState;
sbit LA = P2^2;
sbit LB = P2^3;
sbit LC = P2^4;
sbit K1 = P3^1; // Set Clock Time
sbit K2 = P3^0; // Backspace
sbit K3 = P3^2; // Confirm
sbit K4 = P3^3; // Cancel the Clock
sbit Clock_Mode_Led = P2^7; // Clock Mode Indicator
sbit Timer_Led = P2^6; // Timer Mode Indicator
sbit Clock_Led = P2^0; // Clock On-Working Indicator
sbit BUZZER = P1^5; // Clock
uchar LED_CODE[12] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x0,0x40};
uchar SEG_CODE[8][3] = {{1,1,1}, {1,1,0}, {1,0,1}, {1,0,0}, {0,1,1}, {0,1,0}, {0,0,1}, {0,0,0}};
uint INSTANT_TIME[8] = {0, 0, 11, 0, 0, 11, 0, 0};
uint CLOCK_TIME[8] = {10, 10, 11, 10, 10, 11, 10, 10};
uint Second_T = 2000;
uint Second_Count = 0;
uint Temp = 0;
uchar Clock_Mode_State = 0;
uchar Confirm_State = 0;
uchar Clock_On_Running = 0;
uint c = 0;
uchar FLAG = 0;

void delay(uint i);
void delay_1ms(uint c);
void delay_10ms();
void MatrixKeyDown();
void DigDisplay(uint TIME_CODE[8]);
void GetKeyValue();
void Backspace();
void ClockWarning();

void main()
{
	TMOD = 0x10;
	TH1 = (65536 - 500) / 256;
	TL1 = (65536 - 500) % 256;
	
	EA = 1;
	ET1 = 1;
	TR1 = 1;
	
	Timer_Led = ~Timer_Led;
	//Clock_Led = 1;
	
	while(1)
	{
		GetKeyValue();
		if (!Clock_Mode_State)
			DigDisplay(INSTANT_TIME);
		else
			DigDisplay(CLOCK_TIME);
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
			Clock_Mode_State = 0;
			Confirm_State = 0;
			Clock_On_Running = 1;
			Timer_Led = ~Timer_Led;
			Clock_Mode_Led = ~Clock_Mode_Led;
			Clock_Led = ~Clock_Led;
		}
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
		delay_10ms();
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
			delay_10ms();
			switch(KEYMAT)
			{
				case(0X70):	KeyValue = KeyValue;break;
				case(0Xb0):	KeyValue = KeyValue+4;break;
				case(0Xd0): KeyValue = KeyValue+8;break;
				case(0Xe0):	KeyValue = KeyValue+12;break;
			}
			while((a < 50)&&(KEYMAT != 0xf0))
			{
				delay_10ms();
				a++;
			}
			a = 0;
		}
	}
	

}

void delay(uint i)
{
	while(i-- > 0);
}

void DigDisplay(uint TIME_CODE[8])
{
	uchar c;
	for(c = 0; c < 8; c++)
	{
		LC = SEG_CODE[c][0];LB = SEG_CODE[c][1];LA = SEG_CODE[c][2];
		LED = LED_CODE[TIME_CODE[c]];
		if (c == 2 || c == 5)
			LED = 0x40;
		delay(100);
		LED = 0x0;
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
			Clock_Mode_Led = ~Clock_Mode_Led;
			Timer_Led = ~Timer_Led;
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
	
	if(K4 == 0)
	{
		delay_10ms();
		if (K4 == 0)
		{
			FLAG = 0;
			while(!K4);
		}
	}
}

void Backspace()
{
	c--;
	if (c == 2 || c == 5)
		c--;
	CLOCK_TIME[c] = 0;
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
	uchar i, CONSIST_TIME = 10;
	for(i = 0; i < 8;  i++)
	{
		if (INSTANT_TIME[i] != CLOCK_TIME[i])
		{
			return;
		}
	}
	FLAG = 1;
}