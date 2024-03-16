/*
    Copyright Claire Hopfensperger 2024

    Making a XY plane level with tilt switches.
*/


#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif
#include <avr/io.h>
#include <util/delay.h>
#include "libTiltSwitch/tilt_switch.h"

// Defining tilt switch pins
// #define TILT1 PD2
// #define TILT2 PD3
// #define TILT3 PD4
// #define TILT4 PD5

//# define numTiltSwitches 4

int main(void)
{
    // // Put tilt switch pins in an array.
    // const int numTiltSwitches = 4;
    // const int tiltSwitches[numTiltSwitches] = {PD2, PD3, PD4, PD5};
    
    // Put tilt switch pins in an array.
    const int numTiltSwitches = 4;
    int tiltSwitches[numTiltSwitches];
    tiltSwitches[0] = PD2;
    tiltSwitches[1] = PD3;
    tiltSwitches[2] = PD4;
    tiltSwitches[3] = PD5;

    for (int i = 0; i < numTiltSwitches; i++) {
        // Set tilt switch pins as input
	    DDRD &= ~(1 << tiltSwitches[i]);
    }
    
    // Setting output pin to show when plane is level (digital pin 8)
    DDRB |= _BV(DDB0);

    while(1)
    {
        
        if (checkAllOn(numTiltSwitches, tiltSwitches))
        {
            // Turning output pin on
            PORTB |= _BV(PORTB0);
        }
        else
        {
            // Turning output pin off
            PORTB &= ~_BV(PORTB0);
        }
        
        _delay_ms(100);
    }

}
