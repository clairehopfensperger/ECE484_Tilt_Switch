/*
    Author: Claire Hopfensperger
    Year: 2024

    Prototypes for tilt switch helper functions library.
    Functions work for tilt switches in ports B and/or D.
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

void waitForTiltOnB(int tiltSwitchPin);
void waitForTiltOnD(int tiltSwitchPin);

void waitForTiltOffB(int tiltSwitchPin);
void waitForTiltOffD(int tiltSwitchPin);

void waitForStateChangeB(int tiltSwitchPin);
void waitForStateChangeD(int tiltSwitchPin);

int checkAllOn(int numTiltSwitchesB, int tiltSwitchesB[], int numTiltSwitchesD,
        int tiltSwitchesD[]);
