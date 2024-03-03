/*
    Copyright Claire Hopfensperger 2024

    Library headers for tilt switch helper functions
*/


#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif
#include <avr/io.h>
#include <util/delay.h>

// Prototypes
int checkState(int tiltSwitchPin);
int debouncedCheckState(int tiltSwitchPin);
void waitForTiltON(int tiltSwitchPin);
void waitForTiltOFF(int tiltSwitchPin);
void waitForStateChange(int tiltSwitchPin);
