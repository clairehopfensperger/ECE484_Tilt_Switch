/*
    Author: Claire Hopfensperger
    Year: 2024

    Library for tilt switch helper functions.
    Functions work for tilt switches in ports B and/or D.
*/

#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif
#include <avr/io.h>
#include <util/delay.h>
#include "tilt_switch.h"

//------------------------------------------------------------------------

/**
 * Sets port B tilt switch pins as input.
 * @param numTiltSwitches how many port B tilt switches are connected to the
 *      system.
 * @param tiltSwitches integer array of tilt switch pins.
*/
void setupTiltSwitchesB(int numTiltSwitchesB, int tiltSwitchesB[])
{
    for (int i = 0; i < numTiltSwitchesB; i++) {
        
        DDRB &= ~(1 << tiltSwitchesB[i]);
    }
}

/**
 * Sets port D tilt switch pins as input.
 * @param numTiltSwitches how many port D tilt switches are connected to the
 *      system.
 * @param tiltSwitches integer array of tilt switch pins.
*/
void setupTiltSwitchesD(int numTiltSwitchesD, int tiltSwitchesD[])
{
    for (int i = 0; i < numTiltSwitchesD; i++) {
        
        DDRD &= ~(1 << tiltSwitchesD[i]);
    }
}

//------------------------------------------------------------------------

/**
 * Checks the state of the tilt switch connected to tiltSwitchPin in port B.
 * @param tiltSwitchPin which pin the tilt switch is connected to.
 * @return An int being 1 or 0 representing a HIGH or LOW signal; HIGH (1)
 *      means the tilt switch is in its OFF state, and LOW (0) means its in
 *      its ON state.
*/
int checkStateB(int tiltSwitchPin)
{
    return (PINB & (1 << tiltSwitchPin));
}

/**
 * Checks the state of the tilt switch connected to tiltSwitchPin in port D.
 * @param tiltSwitchPin which pin the tilt switch is connected to.
 * @return An int being 1 or 0 representing a HIGH or LOW signal; HIGH (1)
 *      means the tilt switch is in its OFF state, and LOW (0) means its in
 *      its ON state.
*/
int checkStateD(int tiltSwitchPin)
{
    return (PIND & (1 << tiltSwitchPin));
}

//------------------------------------------------------------------------

/**
 * Waits until the port B tilt switch is tilted to its ON state. Can be used
 *      to halt the program.
 * @param tiltSwitchPin which pin the tilt switch is connected to.
*/
void waitForTiltOnB(int tiltSwitchPin)
{
    // Do nothing while tilt switch is in OFF state.
    while (checkStateB(tiltSwitchPin) == 1)
    {}
}

/**
 * Waits until the port D tilt switch is tilted to its ON state. Can be used
 *      to halt the program.
 * @param tiltSwitchPin which pin the tilt switch is connected to.
*/
void waitForTiltOnD(int tiltSwitchPin)
{
    // Do nothing while tilt switch is in OFF state.
    while (checkStateD(tiltSwitchPin) == 1)
    {}
}

//------------------------------------------------------------------------

/**
 * Waits until the port B tilt switch is tilted to its ON state. Can be used
 *      to halt the program.
 * @param tiltSwitchPin which pin the tilt switch is connected to.
*/
void waitForTiltOffB(int tiltSwitchPin)
{
    // Do nothing while tilt switch is in OFF state.
    while (checkStateB(tiltSwitchPin) == 0)
    {}
}

/**
 * Waits until the port D tilt switch is tilted to its ON state. Can be used
 *      to halt the program.
 * @param tiltSwitchPin which pin the tilt switch is connected to.
*/
void waitForTiltOffD(int tiltSwitchPin)
{
    // Do nothing while tilt switch is in OFF state.
    while (checkStateD(tiltSwitchPin) == 0)
    {}
}

//------------------------------------------------------------------------

/**
 * Waits until the port B tilt switch changes states. Can be used to
 *      halt the program.
 * @param tiltSwitchPin which pin the tilt switch is connected to.
*/
void waitForStateChangeB(int tiltSwitchPin)
{
    int oldState = checkStateB(tiltSwitchPin);
    int newState = checkStateB(tiltSwitchPin);

    while (oldState == newState)
    {
        newState = checkStateB(tiltSwitchPin);
    }
}

/**
 * Waits until the port D tilt switch changes states. Can be used to
 *      halt the program.
 * @param tiltSwitchPin which pin the tilt switch is connected to.
*/
void waitForStateChangeD(int tiltSwitchPin)
{
    int oldState = checkStateD(tiltSwitchPin);
    int newState = checkStateD(tiltSwitchPin);

    while (oldState == newState)
    {
        newState = checkStateD(tiltSwitchPin);
    }
}

//------------------------------------------------------------------------

/**
 * Checks if all of the tilt switches are in their ON state.
 * @param numTiltSwitchesB how many tilt switches are connected to port B.
 * @param numTiltSwitchesD how many tilt switches are connected to port D.
 * @param tiltSwitchesB integer array of tilt switch pins in port B.
 * @param tiltSwitchesD integer array of tilt switch pins in port D.
 * @return An int being 1 or 0, 1 (true) meaning all tilt switches are in ON state,
 *      0 (false) meaning not all tilt switches are in ON state.
*/
int checkAllOn(int numTiltSwitchesB, int tiltSwitchesB[], int numTiltSwitchesD,
        int tiltSwitchesD[])
{
    int on = 1;

    // Check tilt switches connected to port B
    for (int i = 0; i < numTiltSwitchesB; i++)
    {
        if (checkStateB(tiltSwitchesB[i]))
        {
            on = 0;
            return on;
        }
    }

    // Check tilt switches connected to port D
    for (int i = 0; i < numTiltSwitchesD; i++)
    {
        if (checkStateD(tiltSwitchesD[i]))
        {
            on = 0;
            return on;
        }
    }

    return on;
}
