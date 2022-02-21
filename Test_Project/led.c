#include"avr\io.h"
#include"avr\delay.h"

/* main(void)
{
	while(1)
	{
		//Set Pint direction
		DDRA=0b11111111;
		for(int i=1; i<=32; i=i*2)
		{
			//LED on
			PORTA =i;
			_delay_ms(500);
		}
		//It could be done by Shifting
		for(int k=32; k>=1; k=k/2)
		{
			//LED on
			PORTA = k;
			_delay_ms(500);
		}
	}
}
*/
