/*
 * main.h
 *
 * Created: 4/02/2017 19:19:29
 *  Author: Robbie
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 16000000UL

#include <avr/io.h>
#include "Libraries/FastLED-master/FastLED.h"
#include <util/delay.h>
#include <avr/interrupt.h>

//Hardware defines for the ATTiny84A
#ifdef (__AVR_ATtiny84A__)
#define LEDPIN 2
#define LEDPORT PORTA
#define ANALOGPIN 0
#define ANALOGPORT PORTA
//Hardware defines for the ATmega328P
#elif defined(__AVR_ATmega328P__)

#endif

//Cycle timings for the WS2812B 
#define T0H 64		//0.4탎
#define T0L 136		//0.85탎
#define T1H 128		//0.8탎
#define T1L 72		//0.45탎
#define Treset 8000 //50탎

//Defines for library/Code


//Macro's



//Function Prototypes
static void Setup(void);
void visualize_music(float);
int compute_average(int *avgs, int len);

void initADC(void);
void startADC(void);
void stopADC();

#endif /* MAIN_H_ */