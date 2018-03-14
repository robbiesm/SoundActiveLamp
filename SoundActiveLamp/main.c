
/*
 * SoundActiveLamp.c
 *
 * Versie met fastLED library
 *
 * voorzie "power save mode" waarin de LED's minder fel branden (max 50% -> 128 ipv 256)
 *
 * Created: 26/01/2017 11:46:20
 * Author : Robbie Smedts
 */ 
#include "main.h"


int main(void)
{
	uint8_t mode = 0;
	float fade_scale = 1.2;
	
	Setup();

	while (1)
	{
		switch(mode) {
			case 0:
				visualize_music(fade_scale);
			break;
			case 1:
				//Stand alone
				//Full on and color fade//
			break;
			case 2:
				//Stand alone
				//Full on and color fade bottom -> top//
			break;
			default:
				//Do nothing
			break;
		}
	}
}

static void Setup(void)
{

}