#include <reg51.h>
#include <intrins.h>

typedef unsigned int uint;
typedef unsigned char uchar;

#define LED P1

void delay(uint ms)
	// Input Variable: ms
{
	uint i;
	while(ms--)
		for(i = 125; i>0; i--);
}

void main()
{
	LED = 0xfe;
	while(1)
	{
		LED = _crol_(LED,1); 
		delay(100); // Delay 0.5s
	}
}