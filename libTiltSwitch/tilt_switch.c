/*
    Copyright Claire Hopfensperger 2024

    Library for tilt switch helper functions.
    Assumes tilt switch is in Arduino port D.
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
 *      means the tilt switch is in its OFF state, and LOW (0) means its in
 *      its ON state.
*/
int checkState(int tiltSwitchPin)
{
    return (PIND & (1 << tiltSwitchPin));  // tilt switch must be in port D
}

/**
 * NOT TESTED YET
 * Checks what state the tilt switch connected to tiltSwitchPin is in in a
 *      debounched manner.
 * @param tiltSwitchPin which pin the tilt switch is connected to.
 * @return An int being 1 or 0 representing a HIGH or LOW signal; HIGH (1)
 *      means the tilt switch is in its OFF state, and LOW (0) means its in
 *      its ON state.
*/
int debouncedCheckState(int tiltSwitchPin)
{
	int tilt_state;

	if (checkState(tiltSwitchPin) == 1)
	{
		/* software debounce */
		_delay_ms(50);
		
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

/**
 * Checks if all of the tilt switches are in their ON state.
 * @param numTiltSwitches how many tilt switches are connected to the system.
 * @param tiltSwitches integer array of tilt switch pins.
 * @return An int being 1 or 0, 1 (true) meaning all tilt switches are in ON state,
 *      0 (false) meaning not all tilt switches are in ON state.
*/
int checkAllOn(int numTiltSwitches, int tiltSwitches[])
{
    int on = 1;
    for (int i = 0; i < numTiltSwitches; i++)
    {
        if (checkState(tiltSwitches[i]))
        {
            on = 0;
            return on;
        }
    }
    return on;
}
