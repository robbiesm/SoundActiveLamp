/*
 * function.c
 *
 * Created: 14/02/2017 13:12:10
 *  Author: Robbie
 */
#include "main.h"

void setupIO(void)
{
	//PA1 ADC input
	//PA2 Pixel output
	//PA3 button input with interrupt & internal input Pull-up
	//PA7 Indication l\e\d\ output
	userDDR = (1<<PIXELPIN) | (1<<LEDPIN);	//set pixel and LED output
	userPort = (1<<BUTTONPIN);				//set button Pull-up
}
void initTimer1(void)
{

}

void visualize_music(float fade_scale)
{
	
}

//Compute average of a int array, given the starting pointer and the length
int compute_average(int *avgs, int len) {
	int sum = 0;
	for (int i = 0; i < len; i++)
	sum += avgs[i];

	return (int)(sum / len);
}



// void cycleDelay(uint8_t cycles)
// {
// 	//init + start Timer1 en wacht op interrupt op OCF1A -> return
// 	
// 	OCR1AH = 0xFF00 & cycles;
// 	OCR1AL = 0x00FF & cycles;
// 	
// 	while ((TIFR1 & (1<<OCF1A)) == 0); //Do nothing
// 	return;
// }

/*ADC functions*/
void initADC(void)
{
	//ADC setup from tutorial
	ADMUX |= (1<<REFS0) | (1<<MUX0);		//ADC1 with AVcc on PA0
	ADCSRA |= (1<<ADEN) | (1<<ADATE) | (7<<ADPS2);	//ADC enable, Auto trgger enable, ClkDiv 128
	ADCSRB |= (1<<ADTS1) | (1<<ADTS0);	//Auto trigger on TC0 CMA
	DIDR0 |= (1<<ADC1D);				//Disalbe Digital input on PA1
}

void startADC(void)
{
	ADCSRA |= (1<<ADSC);
	sei();
}

void stopADC(void)
{
	ADCSRA &= (0<<ADSC);
	//cli();
}