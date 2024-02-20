#include"header.h"

#define CS0 (1<<7)

unsigned short int mcp3204AdcRead(unsigned char chnum)
{
 	unsigned short int result=0;
	unsigned char byteH=0,byteL=0,channel=0;

	channel=chnum<<6;
	//select slave for comm.
	IOCLR0=CS0;	
		 
	//start bit & select sGL mode
	spi0(0x06);
	byteH=spi0(channel);
	byteL=spi0(0x00);

	IOSET0=CS0;				   //deselect slave
	byteH &=0x0f;			  //masking higher nibble
	result=(byteH <<8)|byteL;//merge string
	return result;

}