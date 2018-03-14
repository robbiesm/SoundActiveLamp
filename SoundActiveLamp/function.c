/*
 * function.c
 *
 * Created: 14/02/2017 13:12:10
 *  Author: robbi
 */
#include "main.h"
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

void initTimer1(void)
{
	//Timer1 (16bit) Klaarmaken voor delay berekening
	//TCCR1A &= (0<<WGM11) & (0<<WGM10); Forcing WGM[1:0] at 0
	TCCR1B |= (1<<WGM12) | (1<<CS10);	
}
void cycleDelay(uint8_t cycles)
{
	//init + start Timer1 en wacht op interrupt op OCF1A -> return
	
	OCR1AH = 0xFF00 & cycles;
	OCR1AL = 0x00FF & cycles;
	
	while ((TIFR1 & (1<<OCF1A)) == 0); //Do nothing
	return;
}

/*ADC functions*/
void initADC(void)
{
	//ADC setup from tutorial
	ADMUX |= (1<<REFS0) | (1<<ADLAR);		//ADC0 with AVcc
	ADCSRA |= (1<<ADEN) | (1<<ADATE) | (7<<ADPS2);
	ADCSRB |= (1<<ADTS1) | (1<<ADTS0);		
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