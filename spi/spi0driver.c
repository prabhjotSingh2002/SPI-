#include"header.h"

#define CS0 (1<<7)

void spi0init(void)
{
 	PINSEL0|=0x1500;//P0.4->CLK0,P0.5->MISO0,P0.6->MOSI0
	IODIR0|=CS0;	//P0.7(CS0)->OUT DIR

	IOSET0|=(1<<7);//CS0->DESELECT SLAVE

	S0SPCR=0X20;//CPOL=CPHA=0;Master mode selected;MSB first selected
	S0SPCCR=150;//SPI0 freq. is 100kbps

}

/*spi0 transfer function*/
#define SPIF ((S0SPSR>>7)&1)

unsigned char spi0(unsigned char data)
{
 	S0SPDR=data;
	while(SPIF==0);
	return S0SPDR;//data from slave
}


