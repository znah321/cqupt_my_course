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
	DSPORT = 0;			 //����������480us~960us
	i = 70;	
	while(i--);//��ʱ642us
	DSPORT = 1;			//Ȼ���������ߣ����DS18B20������Ӧ�Ὣ��15us~60us����������
	i = 0;
	while(DSPORT)	//�ȴ�DS18B20��������
	{
		Delay1ms(1);
		i++;
		if(i>5)//�ȴ�>5MS
		{
			return 0;//��ʼ��ʧ��
		}
	
	}
	return 1;//��ʼ���ɹ�
}

void Ds18b20WriteByte(uchar dat)
{
	uint i, j;

	for(j=0; j<8; j++)
	{
		DSPORT = 0;	     	  //ÿд��һλ����֮ǰ�Ȱ���������1us
		i++;
		DSPORT = dat & 0x01;  //Ȼ��д��һ�����ݣ������λ��ʼ
		i=6;
		while(i--); //��ʱ68us������ʱ������60us
		DSPORT = 1;	//Ȼ���ͷ����ߣ�����1us�����߻ָ�ʱ����ܽ���д��ڶ�����ֵ
		dat >>= 1;
	}
}

uchar Ds18b20ReadByte()
{
	uchar byte, bi;
	uint i, j;	
	for(j=8; j>0; j--)
	{
		DSPORT = 0;//�Ƚ���������1us
		i++;
		DSPORT = 1;//Ȼ���ͷ�����
		i++;
		i++;//��ʱ6us�ȴ������ȶ�
		bi = DSPORT;	 //��ȡ���ݣ������λ��ʼ��ȡ
		/*��byte����һλ��Ȼ����������7λ���bi��ע���ƶ�֮���Ƶ���λ��0��*/
		byte = (byte >> 1) | (bi << 7);						  
		i = 4;		//��ȡ��֮��ȴ�48us�ٽ��Ŷ�ȡ��һ����
		while(i--);
	}				
	return byte;
}

void  Ds18b20ChangTemp()
{
	Ds18b20Init();
	Delay1ms(1);
	Ds18b20WriteByte(0xcc);		//����ROM��������		 
	Ds18b20WriteByte(0x44);	    //�¶�ת������
	//Delay1ms(100);	//�ȴ�ת���ɹ������������һֱˢ�ŵĻ����Ͳ��������ʱ��
   
}

void  Ds18b20ReadTempCom()
{	

	Ds18b20Init();
	Delay1ms(1);
	Ds18b20WriteByte(0xcc);	 //����ROM��������
	Ds18b20WriteByte(0xbe);	 //���Ͷ�ȡ�¶�����
}

int Ds18b20ReadTemp()
{
	int temp = 0;
	uchar tmh, tml;
	Ds18b20ChangTemp();			 	//��д��ת������
	Ds18b20ReadTempCom();			//Ȼ��ȴ�ת������Ͷ�ȡ�¶�����
	tml = Ds18b20ReadByte();		//��ȡ�¶�ֵ��16λ���ȶ����ֽ�
	tmh = Ds18b20ReadByte();		//�ٶ����ֽ�
	temp = tmh;
	temp <<= 8;
	temp |= tml;
	return temp;
}