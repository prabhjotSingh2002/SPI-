#include"header.h"

						
#define SW1 ((IOPIN0>>15) &1 ) 		   //changing mode
#define SW2 ((IOPIN0>>16) &1 ) 		   //on & off in manual

#define LED1 (1<<17)  
#define LED2 (1<<18)  

 //mode ---     0->automatic &	1 -> manual
 int mode=0;

int ledStatus=0;

int main()
{
	char s[20]={0};
 	short int temp;
	float per=0;
	lcdinit();
	uart0init(9600);
	spi0init();
	IODIR0|=LED1|LED2;
	uart0txString("MCP3204 ADC \r\n");

  	
	while(1)
	{

		//ADC READING STUFF
	 	temp=mcp3204AdcRead(2);
		//delayms(100);
		sprintf1(s,temp) ;
		 uart0txString(s); 
		uart0txString("\r\n");

		 //LDR CALCULATION STUFF
		 per=((4095.00f-temp)/4095.00f);
		 per=per*100.00f;
		  clearstr(s,20);
		  sprintf1(s,(int)per);
		 lcdString(s);
		 lcdString("%");
		
		//delayms(100);
		//CHANGE MODE
		  if(SW1==0)
		  {
		   		while(SW1==0);
					 if(mode==1)
					 {
					  	 mode=0;
						 uart0txString("Auto \r\n");
						 delayms(90);
					 }
					 else
					 {
					      mode=1;
						  uart0txString("manual \r\n");
						  delayms(90);
					 }
		  }


		  //main lightning code
		 if(mode==0)
		 {
				//0->automatic
				uart0txString("auto \r\n");
				 IOSET0|=LED2	;
				if((int)per<30)
				{
				 	//on light
					 IOCLR0|=LED1;
					 ledStatus=1;
					 uart0txString("led on \r\n");
					 delayms(90);
				}
				else
				{
					//off light
					 IOSET0|=LED1	;
					 ledStatus=0;
					 uart0txString("led off \r\n");
					 delayms(90);		
				}		

		 }
		 if(mode==1)
		 {
			  // 1 -> manual
			  uart0txString("manual \r\n");
				IOCLR0|=LED2;
				if(SW2==0)
				{
						while(SW2==0);
						if(ledStatus==0)
						{
					  	    IOCLR0|=LED1;
							ledStatus=1;
							uart0txString("led on \r\n");
					        delayms(90);
						}
						else
						{
						   	IOSET0|=LED1;
							ledStatus=0;
							uart0txString("led off \r\n");
					         delayms(90);
						}

				}
		 }
		//delayms(1000);
		lcdcmd(0x01);
	}
	
}


	   