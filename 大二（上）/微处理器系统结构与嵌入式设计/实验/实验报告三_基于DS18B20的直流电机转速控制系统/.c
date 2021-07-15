#include <reg51.h>

typedef unsigned int uint;
typedef unsigned char uchar;

#define DATA P0
#define KEYMAT P1
uchar KeyValue;
uchar KeyState;
sbit Motor = P1^0;
sbit DSPORT=P3^7;
sbit E = P2^7;
sbit RW = P2^5;
sbit RS = P2^6;
sbit K1 = P3^1; // Start Motor
sbit K2 = P3^0; // Switch Motor's mode
sbit K3 = P3^2;
sbit K4 = P3^3;
float tp;
float tpn = 0;
uchar CNstr_1[] = "Temp:";
uchar NUMBERS[] = "0123456789";
uint Temperature[4] = {-1, -1, -1, -1};
uchar x;
uint MachineStatus = 0; // 0 represents Auto-Mode, 1 represents Manual-Mode
uint Motor_On_Running = 0;
uchar Gear = 0;
int count = 0;
int PWM_HIGH = 0;
int PWM_LOW = 10;
sbit t0 = P2^0;
sbit t1 = P2^1;

void delay(uint i);
void Init_CPU();
void DataPrograming(int temp);
void delay_1ms(uint y);
uchar Ds18b20Init();
void Ds18b20WriteByte(uchar dat);
uchar Ds18b20ReadByte();
void  Ds18b20ChangTemp();
void  Ds18b20ReadTempCom();
uint Ds18b20ReadTemp();
void Init_LCD1602();
void write_Data(uchar DAT);
void write_Command(uchar COMMAND);
void check_Busy();
void LCD1602_DisplayTemp();
void LCD1602_DisplayMachineStatus();
void GetKeyValue();
void Auto_GearSwitching();
void Manual_GearSwitching();
void MotorRunning();
void test();

void main()
{
	Init_CPU();
	while(1)
	{
		MotorRunning();
		GetKeyValue();
		
		DataPrograming(Ds18b20ReadTemp());
		
		if (Motor_On_Running)
		{
			if (!MachineStatus)
			{
				Auto_GearSwitching();
			}
			else
				Manual_GearSwitching();
		}
		LCD1602_DisplayTemp();
		LCD1602_DisplayMachineStatus();
		
	}		
}

void Init_CPU()
{
	Init_LCD1602();
	write_Command(0x80);
	// Write special string
	// Temp:
	for(x = 0; CNstr_1[x] != '\0'; x++)
	{
		write_Data(CNstr_1[x]);
	}
	// C
	write_Command(0x8b);
	write_Data('C');
	
	// Timer Initialization
	TMOD= 0x10; 
	TH1 = 0xFE;
	TL1 = 0x0C;
	ET1 = 1; 
	EA = 1;
	PT1=0;
	TR1 = 1;
	
	TH1 = 0xFE;
	TL1 = 0x0C;
	
	Motor = 0;
}

void delay(uint i)
{
	while(i--);	
}

void DataPrograming(int temp) 	 
{
	if(temp< 0)
  {
		temp = temp-1;
		temp =~ temp;
		tp = temp;
		temp = tp*0.0625*100+0.5;	
	}
 	else
	{			
		tp = temp;
		temp = tp*0.0625*100+0.5;	
	}
	
	tpn = temp % 10000 / 1000 *1000 + temp % 1000 / 100 * 100 +  temp % 100 / 10 * 10 + temp % 10 ;
	
	Temperature[0] = (int)tpn/1000;
	Temperature[1] = (int)tpn%1000/100;
	Temperature[2] = (int)tpn % 100 / 10;
	Temperature[3] = (int)tpn % 10;
}

void delay_1ms(uint y)
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
	DSPORT = 0;			 //½«×ÜÏßÀ­µÍ480us~960us
	i = 60;	
	while(i--);//ÑÓÊ±642us
	DSPORT = 1;			//È»ºóÀ­¸ß×ÜÏß£¬Èç¹ûDS18B20×ö³ö·´Ó¦»á½«ÔÚ15us~60usºó×ÜÏßÀ­µÍ
	i = 0;
	while(DSPORT)	//µÈ´ýDS18B20À­µÍ×ÜÏß
	{
		delay_1ms(1);
		i++;
		if(i>5)//µÈ´ý>5MS
		{
			return 0;//³õÊ¼»¯Ê§°Ü
		}
	
	}
	return 1;//³õÊ¼»¯³É¹¦
}

void Ds18b20WriteByte(uchar dat)
{
	uint i, j;

	for(j=0; j<8; j++)
	{
		DSPORT = 0;	     	  //Ã¿Ð´ÈëÒ»Î»Êý¾ÝÖ®Ç°ÏÈ°Ñ×ÜÏßÀ­µÍ1us
		i++;
		DSPORT = dat & 0x01;  //È»ºóÐ´ÈëÒ»¸öÊý¾Ý£¬´Ó×îµÍÎ»¿ªÊ¼
		i=6;
		while(i--); //ÑÓÊ±68us£¬³ÖÐøÊ±¼ä×îÉÙ60us
		DSPORT = 1;	//È»ºóÊÍ·Å×ÜÏß£¬ÖÁÉÙ1us¸ø×ÜÏß»Ö¸´Ê±¼ä²ÅÄÜ½Ó×ÅÐ´ÈëµÚ¶þ¸öÊýÖµ
		dat >>= 1;
	}
}

uchar Ds18b20ReadByte()
{
	uchar byte, bi;
	uint i, j;	
	for(j=8; j>0; j--)
	{
		DSPORT = 0;//ÏÈ½«×ÜÏßÀ­µÍ1us
		i++;
		DSPORT = 1;//È»ºóÊÍ·Å×ÜÏß
		i++;
		i++;//ÑÓÊ±6usµÈ´ýÊý¾ÝÎÈ¶¨
		bi = DSPORT;	 //¶ÁÈ¡Êý¾Ý£¬´Ó×îµÍÎ»¿ªÊ¼¶ÁÈ¡
		/*½«byte×óÒÆÒ»Î»£¬È»ºóÓëÉÏÓÒÒÆ7Î»ºóµÄbi£¬×¢ÒâÒÆ¶¯Ö®ºóÒÆµôÄÇÎ»²¹0¡£*/
		byte = (byte >> 1) | (bi << 7);						  
		i = 4;		//¶ÁÈ¡ÍêÖ®ºóµÈ´ý48usÔÙ½Ó×Å¶ÁÈ¡ÏÂÒ»¸öÊý
		while(i--);
	}				
	return byte;
}

void  Ds18b20ChangTemp()
{
	Ds18b20Init();
	delay_1ms(1);
	Ds18b20WriteByte(0xcc);		//Ìø¹ýROM²Ù×÷ÃüÁî		 
	Ds18b20WriteByte(0x44);	    //ÎÂ¶È×ª»»ÃüÁî
	//delay_1ms(100);	//µÈ´ý×ª»»³É¹¦£¬¶øÈç¹ûÄãÊÇÒ»Ö±Ë¢×ÅµÄ»°£¬¾Í²»ÓÃÕâ¸öÑÓÊ±ÁË
   
}

void  Ds18b20ReadTempCom()
{	

	Ds18b20Init();
	//delay_1ms(1);
	Ds18b20WriteByte(0xcc);	 //Ìø¹ýROM²Ù×÷ÃüÁî
	Ds18b20WriteByte(0xbe);	 //·¢ËÍ¶ÁÈ¡ÎÂ¶ÈÃüÁî
}

uint Ds18b20ReadTemp()
{
	uint temp = 0;
	uchar tmh, tml;
	Ds18b20ChangTemp();			 	//ÏÈÐ´Èë×ª»»ÃüÁî
	Ds18b20ReadTempCom();			//È»ºóµÈ´ý×ª»»Íêºó·¢ËÍ¶ÁÈ¡ÎÂ¶ÈÃüÁî
	tml = Ds18b20ReadByte();		//¶ÁÈ¡ÎÂ¶ÈÖµ¹²16Î»£¬ÏÈ¶ÁµÍ×Ö½Ú
	tmh = Ds18b20ReadByte();		//ÔÙ¶Á¸ß×Ö½Ú
	temp = tmh;
	temp <<= 8;
	temp |= tml;
	return temp;
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

void LCD1602_DisplayTemp()
{
	write_Command(0x85);
	if (tpn > 0)
		write_Data('+');
	else if (tpn == 0)
		write_Command(0x86);
	else
		write_Data('-');
	
	for(x = 0; x < 4; x++)
	{
		if (Temperature[x] != -1)
			write_Data(NUMBERS[Temperature[x]]);
		if (x == 1)
			write_Data('.');
	}
}

void GetKeyValue()
{
	if(K1 == 0)
	{
		delay_1ms(10);
		if (K1 == 0)
		{
			if (Motor_On_Running == 0)
			{
				Motor_On_Running = 1;
				TR0 = 1;
			}
			else
			{
				TR0 = 0;
				Motor_On_Running = 0;
				Gear = 0;
				Motor = 0;
			}
			while(!K1);
		}
	}
	
	if(K2 == 0)
	{
		delay_1ms(10);
		if (K2 == 0)
		{
			if (MachineStatus == 0)
				MachineStatus = 1;
			else
			{
				Gear = 0;
				MachineStatus = 0;
				write_Command(0xc4);
				write_Data(0x20);
				write_Data(0x20);
			}
			while(!K2);
		}
	}
}

void LCD1602_DisplayMachineStatus()
{
	uchar Mode_str1[] = "Auto";
	uchar Mode_str2[] = "Manual";
	uchar Sstr1[] = "Gear:";
	
	write_Command(0x8d);
	if (Motor_On_Running == 0)
	{
		write_Data('O');
		write_Data('F');
		write_Data('F');
	}
	else
	{
		write_Data(0x20);
		write_Data('O');
		write_Data('N');
	}
	
	write_Command(0xc0);
	if (MachineStatus == 0)
	{
		for(x = 0; Mode_str1[x] != '\0'; x++)
			write_Data(Mode_str1[x]);
	}
	else
	{
		for(x = 0; Mode_str2[x] != '\0'; x++)
			write_Data(Mode_str2[x]);
	}
	
	write_Command(0xc9);
	for(x = 0; Sstr1[x] != '\0'; x++)
		write_Data(Sstr1[x]);
	
	if (Gear == 10)
	{
		write_Command(0xce);
		write_Data(NUMBERS[1]);
		write_Data(NUMBERS[0]);
	}
	else
	{
		write_Command(0xce);
		write_Data(0x20);
		write_Data(NUMBERS[Gear]);
	}
	
}

void Auto_GearSwitching()
{
	if (tpn <= 1400)
		Gear = 0;
	else if (tpn > 1400 && tpn <= 2200)
		Gear = 3;
	else if (tpn > 2200 && tpn <= 2400)
		Gear = 8;
	else if (tpn > 2400 && tpn <= 2600)
		Gear = 10;
}

void Manual_GearSwitching()
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
				case(0X70):	KeyValue = KeyValue+12;break;
				case(0Xb0):	KeyValue = KeyValue;break;
				case(0Xd0): KeyValue = KeyValue+4;break;
				case(0Xe0):	KeyValue = KeyValue+8;break;
			}
			while((a < 50)&&(KEYMAT != 0xf0))
			{
				delay_1ms(1);
				a++;
			}
			a = 0;
		}
	}
	//Gear = KeyValue;
}

void MotorRunning()
{
		//Gear = 3;
		PWM_HIGH = 1;
		if (count > (PWM_HIGH + PWM_LOW))
			count = 0;
		
		if (count < PWM_HIGH)
			Motor = 1;
		else
			Motor = 0;
}

void timer1_int() interrupt 3
{
	TH1 = 0xFE;
	TL1 = 0x0C;
	count++;
	t0 = ~t0;
}