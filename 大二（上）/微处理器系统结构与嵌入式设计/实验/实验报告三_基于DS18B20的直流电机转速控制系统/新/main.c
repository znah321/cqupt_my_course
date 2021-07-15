#include <reg52.h>
#include <temp.h>	
#include <i2c.h>
#define LED P0
//----------λ����----------//
sbit LED7 = P2^7;//��־LED��LED�����ʾ�Զϵ�ǰAT24C02�д洢�ĵ�λ���У�Ϩ���ʾ�����¶ȵ�����λ
sbit PWM = P1^0;//ֱ���������
sbit k4 = P3^3;//��������K4�������л�ģʽ
sbit LA = P2^2;
sbit LB = P2^3;
sbit LC = P2^4;

//----------ȫ�ֱ���----------//
unsigned char timer1;
int PWM_high = 0;//�ߵ�ƽ������ʱ��
int PWM_low = 10;//�͵�ƽ������ʱ�䣬10����ʱ��ʱ��5ms
float temperature = 0;//��ǰ�¶�
int Mode = 0;//ModeΪ0���Զϵ�ǰAT24C02�д洢�ĵ�λ����
uchar LED_CODE[12] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x0,0x40}; // 0-9������ʾ�ַ����ַ�"-"��Ӧ�ı���
uchar SEG_CODE[8][3] = {{1,1,1}, {1,1,0}, {1,0,1}, {1,0,0}, {0,1,1}, {0,1,0}, {0,0,1}, {0,0,0}}; // ����
uint DTemp[8] = {10, 10, 10, 10, 10, 10, 10, 1}; // LED��̬��ʾ�����֣�ǰ4λΪ�¶ȣ����һλ��ʾ��λ

//----------�����б�----------//
void Int1Init();//�ⲿ�жϳ�ʼ��
void Time1Config();//��ʱ����ʼ��
void delay(uint i);//��ʱ����
void Motor_speed();//���ת�ٺ���
void datapros(int temp);//�¶ȴ�����
void temp_select();//�¶ȿ��Ƶ�λ����
void DigDisplay();//LED����ܶ�̬��ʾ����
void Set_Gear();//����PWM_high�Ĵ�С���õ�λ

//----------Main����----------//
void main()
{	
	Time1Config();
	Int1Init();
	Ds18b20Init();
	PWM_high=At24c02Read(1);//��ȡEEPROM��ַ1�ڵ����ݱ�����PWM_high��
	while(1)
	{
		Set_Gear();
		DigDisplay();		
		Motor_speed();
		if(Mode==0)
		//Mode=0��ʾ��ת��ά�ֶϵ�ǰ�ĵ�λ���������¶Ƚ��е�������ʱLED7������
		{
			LED7=0;
		}
		else
		//Mode=1��ʾ�������¶ȵ�����λ����ʱLED7��Ϩ��
		{
			LED7=1;
			temp_select();
		}
	
	}
}

void delay(uint i)
{
	while(i--);	
}

void Time1Config()
{
	TMOD= 0x10;
	TH1 = 0xFE;//��ʱ0.5ms
	TL1 = 0x0C;
	ET1 = 1;
	EA = 1;
	PT1=0;
	TR1 = 1;
}

void Motor_speed()
{
	if (timer1 > (PWM_high + PWM_low)) 
		timer1 = 0;
	
	if (timer1 < PWM_high)
	//�����ʱ�ڸߵ�ƽʱ���ڣ���PWM����ߵ�ƽ
		PWM = 1;
	else
	//����ڵ͵�ƽʱ���ڣ���PWM����͵�ƽ
		PWM=0;
}
void Time1() interrupt 3
{
	TH1 = 0xFE;
	TL1 = 0x0C;
	timer1++;
}

void datapros(int temp) 	 
{
	float tp, tp100;  
	if(temp< 0)				//���¶�ֵΪ����
  {
		//��Ϊ��ȡ���¶���ʵ���¶ȵĲ��룬���Լ�1����ȡ�����ԭ��
		temp=temp-1;
		temp=~temp;
		tp=temp;
		temp=tp*0.0625*100+0.5;	
		tp=tp*0.0625;	
		//������С�����*100��+0.5���������룬��ΪC���Ը�����ת��Ϊ���͵�ʱ���С����
		//��������Զ�ȥ���������Ƿ����0.5����+0.5֮�����0.5�ľ��ǽ�1�ˣ�С��0.5�ľ�
		//�����0.5��������С������档
		temperature=tp;
	}
 	else
 	{			
		tp=temp;//��Ϊ���ݴ�����С�������Խ��¶ȸ���һ�������ͱ���
		//����¶���������ô����ô������ԭ����ǲ���������
		temp=tp*0.0625*100+0.5;		
		tp=tp*0.0625;		
		//������С�����*100��+0.5���������룬��ΪC���Ը�����ת��Ϊ���͵�ʱ���С����
		//��������Զ�ȥ���������Ƿ����0.5����+0.5֮�����0.5�ľ��ǽ�1�ˣ�С��0.5�ľ�
		//�����0.5��������С������档
		temperature=tp;
	}
		
	tp100 = temp % 10000 / 1000 *1000 + temp % 1000 / 100 * 100 +  temp % 100 / 10 * 10 + temp % 10 ;
	DTemp[0] = (int)tp100/1000;
	DTemp[1] = (int)tp100%1000/100;
	DTemp[2] = (int)tp100%100/10;
	DTemp[3] = (int)tp100%10;
}

void temp_select(void)
{
	datapros(Ds18b20ReadTemp());
	if (temperature < 20)
	{
		PWM_high = 0;
		At24c02Write(1,PWM_high);//�ڵ�ַ1��д������PWM_high
	}
	if ((temperature < 26) && (temperature >= 20))
	{
		PWM_high = 60;
		At24c02Write(1,PWM_high);//�ڵ�ַ1��д������PWM_high
	}
	if (temperature >= 26)
	{
		PWM_high=52;
		At24c02Write(1,PWM_high);//�ڵ�ַ1��д������PWM_high
	}
}

void DigDisplay()
{
	uchar c;
	for(c = 0; c < 8; c++)
	{
		LC = SEG_CODE[c][0];LB = SEG_CODE[c][1];LA = SEG_CODE[c][2];
		if (c != 1)
			LED = LED_CODE[DTemp[c]];
		else
			LED = LED_CODE[DTemp[c]] | 0x80;
		delay(100);
		LED = 0x0;
	}
}

void Set_Gear()
{
	switch(PWM_high)
	{
		case 0:DTemp[7] = 0;break;
		case 60:DTemp[7] = 1;break;
		case 52:DTemp[7] = 2;break;
	}
}

void Int1Init()
{
	IT1=1;
	EX1=1;
	PX1=1;
	EA=1;
}

void Int1()	interrupt 2
{
	delay(100);
	if (k4 == 0)
		Mode = !Mode;
}
