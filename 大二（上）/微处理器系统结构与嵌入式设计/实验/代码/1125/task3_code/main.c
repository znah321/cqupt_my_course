/*******************************************************************************
*                 
*                 		       ���пƼ�
--------------------------------------------------------------------------------
* ʵ �� ��		 : 24C02EEPROM�洢����
* ʵ��˵��       : ʹ��LCD1602��ʾд������ݺͶ���������
* ���ӷ�ʽ       : ������ͼ
* ע    ��		 : 
*******************************************************************************/
#include<reg51.h>
#include"i2c.h"
#include"lcd.h"

//--����ʹ�õ�IO��--//
//�����IO
#define GPIO_DIG	P0
#define KEYMAT P1
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;
//����IO
sbit K1=P3^0;
sbit K2=P3^1;
sbit K3=P3^2;
sbit K4=P3^3;

//--����ȫ�ֱ���--//
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

//--����ȫ�ֺ���--//
void At24c02Write(unsigned char ,unsigned char );
unsigned char At24c02Read(unsigned char );
void Delay10ms(unsigned int c);   //��� 0us
void delay_10ms();
void MatrixKeyDown();
void LCD1602_Display();

/*******************************************************************************
* ������         : main
* ��������		 : ������
* ����           : ��
* ���         	 : ��
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
		if(K3 == 0)		 //����3����
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
* �� �� ��         : Delay10ms
* ��������		   : ��ʱ��������ʱ10ms
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/

void Delay10ms(unsigned int c)   //��� 0us
{
    unsigned char a, b;

	//--c�Ѿ��ڴ��ݹ�����ʱ���Ѿ���ֵ�ˣ�������for����һ��Ͳ��ø�ֵ��--//
    for (;c>0;c--)
	{
		for (b=38;b>0;b--)
		{
			for (a=130;a>0;a--);
		}          
	}       
}

/*******************************************************************************
* �� �� ��         : void At24c02Write(unsigned char addr,unsigned char dat)
* ��������		   : ��24c02��һ����ַд��һ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/

void At24c02Write(unsigned char addr,unsigned char dat)
{
	I2C_Start();
	I2C_SendByte(0xa0, 1);//����д������ַ
	I2C_SendByte(addr, 1);//����Ҫд���ڴ��ַ
	I2C_SendByte(dat, 0);	//��������
	I2C_Stop();
}
/*******************************************************************************
* �� �� ��         : unsigned char At24c02Read(unsigned char addr)
* ��������		   : ��ȡ24c02��һ����ַ��һ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/

unsigned char At24c02Read(unsigned char addr)
{
	unsigned char num;
	I2C_Start();
	I2C_SendByte(0xa0, 1); //����д������ַ
	I2C_SendByte(addr, 1); //����Ҫ��ȡ�ĵ�ַ
	I2C_Start();
	I2C_SendByte(0xa1, 1); //���Ͷ�������ַ
	num=I2C_ReadByte(); //��ȡ����
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