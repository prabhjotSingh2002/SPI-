#include <LPC21xx.H>

void uart0init(unsigned int baud);
void uart0tx(unsigned char data);
unsigned char uart0rx(void);
void uart0rxString(unsigned char*p,unsigned int bytes );
 void uart0txString(unsigned char *p);

 void lcddata(unsigned char data);
 void lcdcmd(unsigned char data);
 void lcdinit(void);
 void lcdString(char *ptr);
 void cgram1(void);
 void cgram2(void);

 void delayms(unsigned int ms);
 void delaysec(unsigned int s);

 void spi0init(void);
 unsigned char spi0(unsigned char data);

 void strrev2(char *p,char *q);
 void sprintf2(char *s,float n);
 int sprintf1(char *s,int num);

 void clearstr(unsigned char *s,int n);

unsigned short int mcp3204AdcRead(unsigned char chnum);
void uart0txString(unsigned char *p);


