#include"avr\io.h"
#include"avr\delay.h"
#include "define.h"
#include "type.h"

#define zero 0b00111111
#define one 0b00110000
#define two 0b01011011
#define three 0b01111001
#define four 0b01110100
#define five 0b01101101
#define six 0b01100111
#define seven 0b01111000
#define eight 0b01111111
#define nine 0b01111101
void main(void)
{
	/*u8 arr[10]={zero, one, two, three, four, five, six, seven, eight, nine};
		DDRA= 0b11111111;
		DDRC= 0b11111111;
	while(1)
	{
		PORTC=0;
		for(u8 u=0; u<=9; u++)
		{
			for(u8 i=0; i<=9; i++)
				{
					PORTA= arr[i];
					if(u!=0 && i==0)
					{
						PORTC= arr[u];
						_delay_ms(200);

					}
					else
					{
						_delay_ms(200);
					}

				}

		}
	}


}
	/*u16 arr[10]={zero, one, two, three, four, five, six, seven, eight, nine};
	//DDRA= 0b11111111;
	DDRC= 0b11111111;
//	PORTA = zero;
	while(1)
	{
		for(int i=0; i<=9; i++)
		{
			//PORTA= arr[i];
			PORTC= arr[i];
			_delay_ms(500);
			//PORTA = 0;
		}
	}
}*/
	/*DDRA= 0b11111111;
	PORTA = six;
	DDRA= 0b00000000;
	PORTA= 0b00000001;
	DDRD= 0b00001000;
	while(1)
	{
		u16 x = GET_BIT(PINA, 0);
		if(x==0)
		{
			PORTD= 0b00001000;
			_delay_ms(500);
		}
		else if(x==1)
		{
			PORTD= 0b00000000;
			_delay_ms(500);
		}
	}
}
	*/


	//APPLICATION
	u16 x;
	//Input
	DDRA= 0b00000000;
		PORTA= 0b00000001;
		//Out put
		//Set Pin direction
		DDRD= 0b00000010;
		//Set Port value
		PORTD= 0b00000000;
		while(1)
		{
			           //Get pin
			x = GET_BIT(PINA, 0);
			if(x==0)
			{
				/*_delay_us(400);
				if((1&(PINA >> (0)))==0)
				{*/
				//Set Pin Value
					PORTD= 0b00000010;
					//Toggle PORT
					//PORTD= ~PORTD;
				//}

				//	PORTD= 0b00000000;
					_delay_ms(400);
			}
		else if(x==1)
			{
			//Set Port value
			PORTD= 0b00000000;
				//_delay_ms(400);
			}
		}
}

