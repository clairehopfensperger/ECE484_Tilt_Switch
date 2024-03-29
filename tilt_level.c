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
#include "libLCD/hd44780.h"

int main(void)
{
    // Put tilt switch pins in arrays and set them as inputs.

    // B port tilt switch pins.
    const int numTiltSwitchesB = 2;
    int tiltSwitchesB[numTiltSwitchesB];
    tiltSwitchesB[0] = PB0;
    tiltSwitchesB[1] = PB1;
    setupTiltSwitchesB(numTiltSwitchesB, tiltSwitchesB);

    // D port tilt switch pins.
    const int numTiltSwitchesD = 2;
    int tiltSwitchesD[numTiltSwitchesD];
    tiltSwitchesD[0] = PD2;
    tiltSwitchesD[1] = PD3;
    setupTiltSwitchesD(numTiltSwitchesD, tiltSwitchesD);

    // Setting output pin (digital pin 13)
    DDRB |= _BV(DDB5);

    // Set up LCD
    LCD_Setup();
    LCD_Clear();

    while(1)
    {
        
        LCD_Clear();

        if (checkAllOn(numTiltSwitchesB, tiltSwitchesB, numTiltSwitchesD,
                tiltSwitchesD))
        {
            // Turning output pin on
            PORTB |= _BV(PORTB5);

            LCD_PrintString("Level!");
        }
        else
        {
            // Turning output pin off
            PORTB &= ~_BV(PORTB5);

            LCD_PrintString("Not Level.");
        }
        
        _delay_ms(250);
    }

}
