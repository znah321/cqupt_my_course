#ifndef __I2C_H_
#define __I2C_H_

#include<reg51.h>

//---�ض���ؼ���---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

//--����ʹ�õ�IO��--//
sbit I2C_SCL = P2^1;
sbit I2C_SDA = P2^0;

//--����ȫ�ֱ���--//
void I2C_Delay10us();
void I2C_Start();
void I2C_Stop();
uchar I2C_SendByte(uchar dat, uchar ack);
uchar I2C_ReadByte();

#endif
