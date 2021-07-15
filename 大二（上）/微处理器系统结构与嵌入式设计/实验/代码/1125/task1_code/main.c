#include "reg52.h"
#include"temp.h"	

typedef unsigned int u16;
typedef unsigned char u8;

sbit BUZZER = P1^5;
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;
char num=0;
u8 DisplayData[8];
u8 code smgduan[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
float tp;
float tpn = 0;
uchar flag = 0;
uint ctime = 10;

void delay(u16 i);
void datapros(int temp);
void DigDisplay();
void Delay1ms(uint y);
uchar Ds18b20Init();
void Ds18b20WriteByte(uchar dat);
uchar Ds18b20ReadByte();
void  Ds18b20ChangTemp();
void  Ds18b20ReadTempCom();
int Ds18b20ReadTemp();

void main()
{
	TMOD = 0x12;
	
	EA = 0;
	ET0 = 1;
	
	TH0 = 0x9c;
	TL0 = 0x9c;
	
	
	while(1)
	{
		datapros(Ds18b20ReadTemp());
		DigDisplay();
		if (flag == 1)
		{
			while(ctime-- > 0)
			{
				BUZZER = ~BUZZER;
				delay(5);
			}
		}
		ctime = 10;
	}		
}

void delay(u16 i)
{
	while(i--);	
}

void datapros(int temp) 	 
{
	if(temp< 0)
  {
		DisplayData[0] = 0x40;
		temp = temp-1;
		temp =~ temp;
		tp = temp;
		temp = tp*0.0625*100+0.5;	
	}
 	else
	{			
		DisplayData[0] = 0x00;
		tp = temp;
		temp = tp*0.0625*100+0.5;	
	}
	
	DisplayData[1] = smgduan[temp / 10000];
	DisplayData[2] = smgduan[temp % 10000 / 1000];
	DisplayData[3] = smgduan[temp % 1000 / 100] | 0x80;
	DisplayData[4] = smgduan[temp % 100 / 10];
	DisplayData[5] = smgduan[temp % 10];
	
	tpn = temp % 10000 / 1000 *1000 + temp % 1000 / 100 * 100 +  temp % 100 / 10 * 10 + temp % 10 ;
	if (tpn > 1400)
		flag = 1;
	else
		flag = 0;
}

void DigDisplay()
{
	u8 i;
	for(i=0;i<6;i++)
	{
		switch(i)
		{
			case(0):
				LSA=0;LSB=0;LSC=0; break;
			case(1):
				LSA=1;LSB=0;LSC=0; break;
			case(2):
				LSA=0;LSB=1;LSC=0; break;
			case(3):
				LSA=1;LSB=1;LSC=0; break;
			case(4):
				LSA=0;LSB=0;LSC=1; break;
			case(5):
				LSA=1;LSB=0;LSC=1; break;
		}
		P0=DisplayData[3];
		delay(100); 
		P0=0x00;
	}		
}

void Delay1ms(uint y)
{
	uint x;
	for( ; y>0; y--)
	{
		for(x=110; x>0; x--);
	}
}

uchar Ds18b20Init()
{
	uchar i;
	DSPORT = 0;			 //将总线拉低480us~960us
	i = 70;	
	while(i--);//延时642us
	DSPORT = 1;			//然后拉高总线，如果DS18B20做出反应会将在15us~60us后总线拉低
	i = 0;
	while(DSPORT)	//等待DS18B20拉低总线
	{
		Delay1ms(1);
		i++;
		if(i>5)//等待>5MS
		{
			return 0;//初始化失败
		}
	
	}
	return 1;//初始化成功
}

void Ds18b20WriteByte(uchar dat)
{
	uint i, j;

	for(j=0; j<8; j++)
	{
		DSPORT = 0;	     	  //每写入一位数据之前先把总线拉低1us
		i++;
		DSPORT = dat & 0x01;  //然后写入一个数据，从最低位开始
		i=6;
		while(i--); //延时68us，持续时间最少60us
		DSPORT = 1;	//然后释放总线，至少1us给总线恢复时间才能接着写入第二个数值
		dat >>= 1;
	}
}

uchar Ds18b20ReadByte()
{
	uchar byte, bi;
	uint i, j;	
	for(j=8; j>0; j--)
	{
		DSPORT = 0;//先将总线拉低1us
		i++;
		DSPORT = 1;//然后释放总线
		i++;
		i++;//延时6us等待数据稳定
		bi = DSPORT;	 //读取数据，从最低位开始读取
		/*将byte左移一位，然后与上右移7位后的bi，注意移动之后移掉那位补0。*/
		byte = (byte >> 1) | (bi << 7);						  
		i = 4;		//读取完之后等待48us再接着读取下一个数
		while(i--);
	}				
	return byte;
}

void  Ds18b20ChangTemp()
{
	Ds18b20Init();
	Delay1ms(1);
	Ds18b20WriteByte(0xcc);		//跳过ROM操作命令		 
	Ds18b20WriteByte(0x44);	    //温度转换命令
	//Delay1ms(100);	//等待转换成功，而如果你是一直刷着的话，就不用这个延时了
   
}

void  Ds18b20ReadTempCom()
{	

	Ds18b20Init();
	Delay1ms(1);
	Ds18b20WriteByte(0xcc);	 //跳过ROM操作命令
	Ds18b20WriteByte(0xbe);	 //发送读取温度命令
}

int Ds18b20ReadTemp()
{
	int temp = 0;
	uchar tmh, tml;
	Ds18b20ChangTemp();			 	//先写入转换命令
	Ds18b20ReadTempCom();			//然后等待转换完后发送读取温度命令
	tml = Ds18b20ReadByte();		//读取温度值共16位，先读低字节
	tmh = Ds18b20ReadByte();		//再读高字节
	temp = tmh;
	temp <<= 8;
	temp |= tml;
	return temp;
}