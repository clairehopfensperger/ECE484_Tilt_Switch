/*
    Author: Claire Hopfensperger
    Year: 2024

    Program used to test tilt switch library functions not tested in
    other programs.
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
        
        // test port b on and off detection

        waitForTiltOffB(tiltSwitchesB[0]);
        LCD_Clear();
        LCD_PrintString("port B tilt off");
        _delay_ms(2000);

        waitForTiltOnB(tiltSwitchesB[0]);
        LCD_Clear();
        LCD_PrintString("port B tilt on");
        _delay_ms(2000);

        // test port d on and off detection

        waitForTiltOffD(tiltSwitchesD[0]);
        LCD_Clear();
        LCD_PrintString("port D tilt off");
        _delay_ms(2000);

        waitForTiltOnD(tiltSwitchesD[0]);
        LCD_Clear();
        LCD_PrintString("port D tilt on");
        _delay_ms(2000);

        // test port b and d state change functions

        waitForStateChangeB(tiltSwitchesB[0]);
        LCD_Clear();
        LCD_PrintString("port B state change");
        _delay_ms(2000);

        waitForStateChangeD(tiltSwitchesD[0]);
        LCD_Clear();
        LCD_PrintString("port D state change");
        _delay_ms(2000);
    }
}
