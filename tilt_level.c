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
#define TILT1 PD7
#define TILT2 PD6
#define TILT3 PD5
#define TILT4 PD4

int main(void)
{
    // Setting output pin to show when plane is level (digital pin 8)
    DDRB |= _BV(DDB0);

    

    while(1)
    {
        // Turning output pin on
        PORTB |= _BV(PORTB0);

        _delay_ms(100);

        // Turning output pin off
        PORTB &= ~_BV(PORTB0);

        _delay_ms(100);
    }


}
