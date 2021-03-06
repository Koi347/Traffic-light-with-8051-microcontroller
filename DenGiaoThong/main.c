#include"main.h"
#include"..\lib\delay.h"

unsigned char code Code7Seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

// Khai bao ket noi
sbit DEN_DO = P0^0;
sbit DEN_VANG = P0^1;
sbit DEN_XANH = P0^2;
#define LED_CHUC P2
#define LED_DVI  P3

void main()
{
	signed char i;

	while(1)
	{
	 	// Den do
		DEN_DO = 1;			// Bat den do
		DEN_XANH = 0;
		DEN_VANG = 0;
		for(i=20;i>=0;i--)
		{
			LED_CHUC = Code7Seg[i/10];
			LED_DVI = Code7Seg[i%10]; 
			Delay_ms(1000);	
		}

		// Den xanh
		DEN_DO = 0;			
		DEN_XANH = 1;
		DEN_VANG = 0;
		for(i=15;i>=0;i--)
		{
			LED_CHUC = Code7Seg[i/10];
			LED_DVI = Code7Seg[i%10]; 
			Delay_ms(1000);	
		}

		// Den vang
		DEN_DO = 0;			
		DEN_XANH = 0;
		DEN_VANG = 1;
		for(i=5;i>=0;i--)
		{
			LED_CHUC = Code7Seg[i/10];
			LED_DVI = Code7Seg[i%10]; 	
			Delay_ms(1000);
		}
	}
}