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
 * Sets B port tilt switch pins as input.
 * @param numTiltSwitches how many tilt switches are connected to the system.
 * @param tiltSwitches integer array of tilt switch pins.
*/
void setupTiltSwitchesB(int numTiltSwitchesB, int tiltSwitchesB[])
{
    for (int i = 0; i < numTiltSwitchesB; i++) {
        
        DDRB &= ~(1 << tiltSwitchesB[i]);
    }
}

/**
 * Sets D port tilt switch pins as input.
 * @param numTiltSwitches how many tilt switches are connected to the system.
 * @param tiltSwitches integer array of tilt switch pins.
*/
void setupTiltSwitchesD(int numTiltSwitchesD, int tiltSwitchesD[])
{
    for (int i = 0; i < numTiltSwitchesD; i++) {
        
        DDRD &= ~(1 << tiltSwitchesD[i]);
    }
}

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

// /**
//  * NOT TESTED YET
//  * Checks what state the tilt switch connected to tiltSwitchPin is in in a
//  *      debounched manner.
//  * @param tiltSwitchPin which pin the tilt switch is connected to.
//  * @return An int being 1 or 0 representing a HIGH or LOW signal; HIGH (1)
//  *      means the tilt switch is in its OFF state, and LOW (0) means its in
//  *      its ON state.
// */
// int debouncedCheckState(int tiltSwitchPin)
// {
// 	int tilt_state;

// 	if (checkState(tiltSwitchPin) == 1)
// 	{
// 		/* software debounce */
// 		_delay_ms(50);
		
//         if (checkState(tiltSwitchPin) == 0)
// 		{
// 			tilt_state = 0;
// 		}
//         else
//         {
//             tilt_state = 1;
//         }
// 	}
// 	else
// 	{
// 		tilt_state = 1;
// 	}

// 	return tilt_state;
// }

// /**
//  * Waits until the tilt switch is tilted to its ON state. Can be used to halt
//  *      the program.
//  * @param tiltSwitchPin which pin the tilt switch is connected to.
// */
// void waitForTiltON(int tiltSwitchPin)
// {
//     // Do nothing while tilt switch is in OFF state.
//     while (checkState(tiltSwitchPin) == 1)
//     {}
// }

// /**
//  * Waits until the tilt switch is tilted to its OFF state. Can be used to halt
//  *      the program.
//  * @param tiltSwitchPin which pin the tilt switch is connected to.
// */
// void waitForTiltOFF(int tiltSwitchPin)
// {
//     // Do nothing while tilt switch is in OFF state.
//     while (checkState(tiltSwitchPin) == 0)
//     {}
// }

// /**
//  * Waits until the tilt switch changes states. Can be used to halt the
//  *      program.
//  * @param tiltSwitchPin which pin the tilt switch is connected to.
// */
// void waitForStateChange(int tiltSwitchPin)
// {
//     int oldState = checkState(tiltSwitchPin);
//     int newState = checkState(tiltSwitchPin);

//     while (oldState == newState)
//     {
//         newState = checkState(tiltSwitchPin);
//     }
// }

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
