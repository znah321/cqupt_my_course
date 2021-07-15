#include <reg52.h>
#include <temp.h>	
#include <i2c.h>
#define LED P0
//----------位定义----------//
sbit LED7 = P2^7;//标志LED，LED亮起表示以断电前AT24C02中存储的档位运行，熄灭表示根据温度调整档位
sbit PWM = P1^0;//直流电机开关
sbit k4 = P3^3;//独立按键K4，用于切换模式
sbit LA = P2^2;
sbit LB = P2^3;
sbit LC = P2^4;

//----------全局变量----------//
unsigned char timer1;
int PWM_high = 0;//高电平持续的时间
int PWM_low = 10;//低电平持续的时间，10个定时器时间5ms
float temperature = 0;//当前温度
int Mode = 0;//Mode为0：以断电前AT24C02中存储的档位运行
uchar LED_CODE[12] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x0,0x40}; // 0-9、不显示字符、字符"-"对应的编码
uchar SEG_CODE[8][3] = {{1,1,1}, {1,1,0}, {1,0,1}, {1,0,0}, {0,1,1}, {0,1,0}, {0,0,1}, {0,0,0}}; // 段码
uint DTemp[8] = {10, 10, 10, 10, 10, 10, 10, 1}; // LED动态显示的数字，前4位为温度，最后一位表示档位

//----------函数列表----------//
void Int1Init();//外部中断初始化
void Time1Config();//定时器初始化
void delay(uint i);//延时函数
void Motor_speed();//电机转速函数
void datapros(int temp);//温度处理函数
void temp_select();//温度控制档位函数
void DigDisplay();//LED数码管动态显示函数
void Set_Gear();//根据PWM_high的大小设置档位

//----------Main函数----------//
void main()
{	
	Time1Config();
	Int1Init();
	Ds18b20Init();
	PWM_high=At24c02Read(1);//读取EEPROM地址1内的数据保存在PWM_high中
	while(1)
	{
		Set_Gear();
		DigDisplay();		
		Motor_speed();
		if(Mode==0)
		//Mode=0表示：转速维持断电前的档位，不根据温度进行调整，此时LED7会亮起
		{
			LED7=0;
		}
		else
		//Mode=1表示：根据温度调整档位，此时LED7会熄灭
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
	TH1 = 0xFE;//定时0.5ms
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
	//如果计时在高电平时间内，则PWM输出高电平
		PWM = 1;
	else
	//如果在低电平时间内，则PWM输出低电平
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
	if(temp< 0)				//当温度值为负数
  {
		//因为读取的温度是实际温度的补码，所以减1，再取反求出原码
		temp=temp-1;
		temp=~temp;
		tp=temp;
		temp=tp*0.0625*100+0.5;	
		tp=tp*0.0625;	
		//留两个小数点就*100，+0.5是四舍五入，因为C语言浮点数转换为整型的时候把小数点
		//后面的数自动去掉，不管是否大于0.5，而+0.5之后大于0.5的就是进1了，小于0.5的就
		//算加上0.5，还是在小数点后面。
		temperature=tp;
	}
 	else
 	{			
		tp=temp;//因为数据处理有小数点所以将温度赋给一个浮点型变量
		//如果温度是正的那么，那么正数的原码就是补码它本身
		temp=tp*0.0625*100+0.5;		
		tp=tp*0.0625;		
		//留两个小数点就*100，+0.5是四舍五入，因为C语言浮点数转换为整型的时候把小数点
		//后面的数自动去掉，不管是否大于0.5，而+0.5之后大于0.5的就是进1了，小于0.5的就
		//算加上0.5，还是在小数点后面。
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
		At24c02Write(1,PWM_high);//在地址1内写入数据PWM_high
	}
	if ((temperature < 26) && (temperature >= 20))
	{
		PWM_high = 60;
		At24c02Write(1,PWM_high);//在地址1内写入数据PWM_high
	}
	if (temperature >= 26)
	{
		PWM_high=52;
		At24c02Write(1,PWM_high);//在地址1内写入数据PWM_high
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
