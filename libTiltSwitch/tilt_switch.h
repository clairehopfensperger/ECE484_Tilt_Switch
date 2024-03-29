/*
    Copyright Claire Hopfensperger 2024

    Library headers for tilt switch helper functions
*/


#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif
#include <avr/io.h>
#include <util/delay.h>
#include "IO_Macros.h"

// Prototypes
void setupTiltSwitchesB(int numTiltSwitches, int tiltSwitches[]);
void setupTiltSwitchesD(int numTiltSwitches, int tiltSwitches[]);

int checkStateB(int tiltSwitchPin);
int checkStateD(int tiltSwitchPin);

// int debouncedCheckState(int tiltSwitchPin);

// void waitForTiltON(int tiltSwitchPin);

// void waitForTiltOFF(int tiltSwitchPin);

// void waitForStateChange(int tiltSwitchPin);

int checkAllOn(int numTiltSwitchesB, int tiltSwitchesB[], int numTiltSwitchesD,
        int tiltSwitchesD[]);
