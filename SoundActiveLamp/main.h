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
//#include <avr/iotn84a.h>
#include <avr/interrupt.h>

#if defined(__AVR_ATmega328P__)
	#define userPort
	#define PIXELPIN 2
	#define ANALOGPIN 1
	#define BUTTONPIN 3
	#define LEDPIN 7

#elif defined(__AVR_ATtiny84A__)
	#define userPort PORTA
	#define userDDR  DDRA
	
	#define ANALOGPIN 1			//ADC1 input
	#define BUTTONPIN 3			//PCINT0, source3
	#define PIXELPIN 6			//16bit Timer1 outputA
	#define LEDPIN 7			//8bit Timer0 outputB
#endif

//Cycle timings for the WS2812B 
#define T0H 		//0.4탎
#define T0L 		//0.85탎
#define T1H 		//0.8탎
#define T1L 		//0.45탎
#define Treset		//60탎

//Defines for library/Code
#define Pixels	60


//Macro's



//Function Prototypes
static void Setup(void);
void setupIO(void);
void visualize_music(float);
int compute_average(int *avgs, int len);
void initTimer1(void);
void initADC(void);
void startADC(void);
void stopADC();

#endif /* MAIN_H_ */