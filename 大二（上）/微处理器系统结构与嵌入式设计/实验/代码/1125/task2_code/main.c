/**************************************************************************************
*		              DS1302时钟实验												  *
实现现象：下载程序后，数码管显示时钟数据
注意事项：																				  
***************************************************************************************/

#include "reg52.h"			 //此文件中定义了单片机的一些特殊功能寄存器
#include"ds1302.h"	

typedef unsigned int u16;	  //对数据类型进行声明定义
typedef unsigned char u8;

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;
sbit buzz = P1^5;

char num=0;
u8 DisplayData[8];
u8 code smgduan[11]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x40};
u8 code clock[8] = {1,0,10,1,5,10,3,0};
u8 flag = 0;
u8 c;
u16 ctime = 10;

/*******************************************************************************
* 函 数 名         : delay
* 函数功能		   : 延时函数，i=1时，大约延时10us
*******************************************************************************/
void delay(u16 i)
{
	while(i--);	
}


/*******************************************************************************
* 函 数 名         : datapros()
* 函数功能		   : 时间读取处理转换函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/

void datapros() 	 
{
   	Ds1302ReadTime();
	DisplayData[0] = TIME[2]/16;				//时
	DisplayData[1] = TIME[2]&0x0f;				 
	DisplayData[2] = 10;
	DisplayData[3] = TIME[1]/16;				//分
	DisplayData[4] = TIME[1]&0x0f;	
	DisplayData[5] = 10;
	DisplayData[6] = TIME[0]/16;				//秒
	DisplayData[7] = TIME[0]&0x0f;
	
	if (flag == 1 && DisplayData[7] == clock[7] + 2)
			flag = 0;
	
	for(c = 0; c < 8; c++)
	{
		if (DisplayData[c] != clock[c])
			return;
	}
	flag = 1;
}


/*******************************************************************************
* 函数名         :DigDisplay()
* 函数功能		 :数码管显示函数
* 输入           : 无
* 输出         	 : 无
*******************************************************************************/
void DigDisplay()
{
	u8 i;
	for(i=0;i<8;i++)
	{
		switch(i)	 //位选，选择点亮的数码管，
		{
			case(0):
				LSA=0;LSB=0;LSC=0; break;//显示第0位
			case(1):
				LSA=1;LSB=0;LSC=0; break;//显示第1位
			case(2):
				LSA=0;LSB=1;LSC=0; break;//显示第2位
			case(3):
				LSA=1;LSB=1;LSC=0; break;//显示第3位
			case(4):
				LSA=0;LSB=0;LSC=1; break;//显示第4位
			case(5):
				LSA=1;LSB=0;LSC=1; break;//显示第5位
			case(6):
				LSA=0;LSB=1;LSC=1; break;//显示第6位
			case(7):
				LSA=1;LSB=1;LSC=1; break;//显示第7位	
		}
		P0=smgduan[DisplayData[7-i]];//发送数据
		delay(100); //间隔一段时间扫描	
		P0=0x00;//消隐
	}		
}

/*******************************************************************************
* 函 数 名       : main
* 函数功能		 : 主函数
* 输    入       : 无
* 输    出    	 : 无
*******************************************************************************/
void main()
{	
	Ds1302Init();
	while(1)
	{
		datapros();	 //数据处理函数
		DigDisplay();//数码管显示函数
		if (flag == 1)
		{
			while (ctime-- > 0)
			{
				buzz = ~buzz;
				delay(10);
			}
			ctime = 10;
		}
	}		
}

