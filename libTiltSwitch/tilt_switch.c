/*
    Copyright Claire Hopfensperger 2024

    Library for tilt switch helper functions
*/


#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif
#include <avr/io.h>
#include <util/delay.h>
#include "tilt_switch.h"

/**
 * Checks what state the tilt switch connected to tiltSwitchPin is in.
 * @param tiltSwitchPin which pin the tilt switch is connected to.
 * @return An int being 1 or 0 representing a HIGH or LOW signal; HIGH (1)
 *      means the tilt switch is in its ON state, and LOW (0) means its in
 *      its OFF state.
*/
int checkState(int tiltSwitchPin)
{
    return (PIND & (1 << tiltSwitchPin));
}

/**
 * Checks what state the tilt switch connected to tiltSwitchPin is in in a
 *      debounched manner.
 * @param tiltSwitchPin which pin the tilt switch is connected to.
 * @return An int being 1 or 0 representing a HIGH or LOW signal; HIGH (1)
 *      means the tilt switch is in its ON state, and LOW (0) means its in
 *      its OFF state.
*/
int debouncedCheckState(int tiltSwitchPin)
{
	int tilt_state;

	if (checkState(tiltSwitchPin) == 1)
	{
		/* software debounce */
		_delay_ms(15);
		
        if (checkState(tiltSwitchPin) == 0)
		{
			tilt_state = 0;
		}
        else
        {
            tilt_state = 1;
        }
	}
	else
	{
		tilt_state = 1;
	}

	return tilt_state;
}

/**
 * Waits until the tilt switch is tilted to its ON state. Can be used to halt
 *      the program.
 * @param tiltSwitchPin which pin the tilt switch is connected to.
*/
void waitForTiltON(int tiltSwitchPin)
{
    // Do nothing while tilt switch is in OFF state.
    while (checkState(tiltSwitchPin) == 1)
    {}
}

/**
 * Waits until the tilt switch is tilted to its OFF state. Can be used to halt
 *      the program.
 * @param tiltSwitchPin which pin the tilt switch is connected to.
*/
void waitForTiltOFF(int tiltSwitchPin)
{
    // Do nothing while tilt switch is in OFF state.
    while (checkState(tiltSwitchPin) == 0)
    {}
}

/**
 * Waits until the tilt switch changes states. Can be used to halt the
 *      program.
 * @param tiltSwitchPin which pin the tilt switch is connected to.
*/
void waitForStateChange(int tiltSwitchPin)
{
    int oldState = checkState(tiltSwitchPin);
    int newState = checkState(tiltSwitchPin);

    while (oldState == newState)
    {
        newState = checkState(tiltSwitchPin);
    }
}
