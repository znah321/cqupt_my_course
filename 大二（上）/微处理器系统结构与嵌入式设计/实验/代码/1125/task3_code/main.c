/*******************************************************************************
*                 
*                 		       普中科技
--------------------------------------------------------------------------------
* 实 验 名		 : 24C02EEPROM存储试验
* 实验说明       : 使用LCD1602显示写入的数据和读出的数据
* 连接方式       : 见连接图
* 注    意		 : 
*******************************************************************************/
#include<reg51.h>
#include"i2c.h"
#include"lcd.h"

//--定义使用的IO口--//
//数码管IO
#define GPIO_DIG	P0
#define KEYMAT P1
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;
//按键IO
sbit K1=P3^0;
sbit K2=P3^1;
sbit K3=P3^2;
sbit K4=P3^3;

//--定义全局变量--//
unsigned char wordCode0[6] = "write:";
unsigned char wordCode1[6] = " read:"; 
uchar NUMBERS[] = "0123456789_";
uchar list[10] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
uchar read_list[10];
uchar KeyValue;
uchar KeyState = 0;
uchar m = 0;
uchar ADDR_write = 0;
uchar clist = 0;
uchar mode = 0;

//--声明全局函数--//
void At24c02Write(unsigned char ,unsigned char );
unsigned char At24c02Read(unsigned char );
void Delay10ms(unsigned int c);   //误差 0us
void delay_10ms();
void MatrixKeyDown();
void LCD1602_Display();

/*******************************************************************************
* 函数名         : main
* 函数功能		 : 主函数
* 输入           : 无
* 输出         	 : 无
*******************************************************************************/

void main()
{
	unsigned int num0 = 0,num1 = 0,n;

	LcdInit();

	LcdWriteCom(0x80);
	for(n=0; n<6; n++)
	{
		LcdWriteData(wordCode0[n]);
	}
	LcdWriteCom(0x80 + 0x40);
	for(n=0; n<6; n++)
	{
		LcdWriteData(wordCode1[n]);
	}
	
	LCD1602_Display();
	
	while(1)
	{
		if(K3 == 0)		 //按键3按下
		{
			Delay10ms(1);
			if(K3 == 0)
			{
				LcdWriteCom(0x86+0x40);
				for(m = 0; m < 10; m++)
				{
					LcdWriteData(NUMBERS[At24c02Read(m)]);
					delay_10ms();
				}
			}
			while((n < 50)&&(K3 == 0))
			{
				n++;
				Delay10ms(1);	
			}			
			n = 0;
		}
			
		MatrixKeyDown();
		if (KeyState)
		{
			KeyState = 0;
			list[clist] = KeyValue;
			clist++;
			At24c02Write(ADDR_write,KeyValue);
			ADDR_write++;
		}
		
		LCD1602_Display();
	}
}									 

/*******************************************************************************
* 函 数 名         : Delay10ms
* 函数功能		   : 延时函数，延时10ms
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/

void Delay10ms(unsigned int c)   //误差 0us
{
    unsigned char a, b;

	//--c已经在传递过来的时候已经赋值了，所以在for语句第一句就不用赋值了--//
    for (;c>0;c--)
	{
		for (b=38;b>0;b--)
		{
			for (a=130;a>0;a--);
		}          
	}       
}

/*******************************************************************************
* 函 数 名         : void At24c02Write(unsigned char addr,unsigned char dat)
* 函数功能		   : 往24c02的一个地址写入一个数据
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/

void At24c02Write(unsigned char addr,unsigned char dat)
{
	I2C_Start();
	I2C_SendByte(0xa0, 1);//发送写器件地址
	I2C_SendByte(addr, 1);//发送要写入内存地址
	I2C_SendByte(dat, 0);	//发送数据
	I2C_Stop();
}
/*******************************************************************************
* 函 数 名         : unsigned char At24c02Read(unsigned char addr)
* 函数功能		   : 读取24c02的一个地址的一个数据
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/

unsigned char At24c02Read(unsigned char addr)
{
	unsigned char num;
	I2C_Start();
	I2C_SendByte(0xa0, 1); //发送写器件地址
	I2C_SendByte(addr, 1); //发送要读取的地址
	I2C_Start();
	I2C_SendByte(0xa1, 1); //发送读器件地址
	num=I2C_ReadByte(); //读取数据
	I2C_Stop();
	return num;	
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

void LCD1602_Display()
{
	if (mode == 0)
	{
		LcdWriteCom(0x86);
		for (m = 0; m < 10; m++)
		{
			LcdWriteData(NUMBERS[list[m]]);
		}
	}
	
	if (mode == 1)
	{
		LcdWriteCom(0x86 + 0x40);
		for (m = 0; m < 10; m++)
		{
			LcdWriteData(NUMBERS[read_list[m]]);
		}
	}
}