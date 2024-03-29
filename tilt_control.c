/*
    Copyright Claire Hopfensperger 2024

    Making a tilt switch controller that moves characters on an LCD.
    !! DOES NOT WORK RIGHT NOW !!
*/

#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include "libTiltSwitch/tilt_switch.h"
#include "libLCD/hd44780.h"

// #define TILT_UP PD3
// #define TILT_LEFT PD2
// #define TILT_RIGHT PB1
// #define TILT_DOWN PB0

int main(void)
{
    // Put tilt switch pins in arrays and set them as inputs.

    // B port tilt switch pins.
    const int numTiltSwitchesB = 2;
    int tiltSwitchesB[numTiltSwitchesB];
    tiltSwitchesB[0] = PB0;  // up
    tiltSwitchesB[1] = PB1;  // right
    setupTiltSwitchesB(numTiltSwitchesB, tiltSwitchesB);

    // D port tilt switch pins.
    const int numTiltSwitchesD = 2;
    int tiltSwitchesD[numTiltSwitchesD];
    tiltSwitchesD[0] = PD2;  // down
    tiltSwitchesD[1] = PD3;  // left
    setupTiltSwitchesD(numTiltSwitchesD, tiltSwitchesD);

    // Setting output pin (digital pin 13)
    DDRB |= _BV(DDB5);

    // Set up LCD
    LCD_Setup();
    int column = 0;
    int row = 0;
    LCD_GotoXY(column, row);
    LCD_PrintChar('!');

    while(1)
    {
        // Move character up
        if (checkStateB(tiltSwitchesB[0]))
        {
            if (row - 1 < 0)
            {
                row = row;
            }
            else 
            {
                row--;
            }
            
            LCD_Clear();
            LCD_GotoXY(column, row);
            LCD_PrintChar('!');
        }

        // Move character left
        if (checkStateD(tiltSwitchesD[1]))
        {
            if (column - 1 < 0)
            {
                column = column;
            }
            else 
            {
                column--;
            }

            LCD_Clear();
            LCD_GotoXY(column, row);
            LCD_PrintChar('!');
        }

        // Move character right
        if (checkStateB(tiltSwitchesB[1]))
        {
            if (column + 1 > 15)
            {
                column = column;
            }
            else 
            {
                column++;
            }

            LCD_Clear();
            LCD_GotoXY(column, row);
            LCD_PrintChar('!');
        }

        // Move character down
        if (checkStateD(tiltSwitchesD[0]))
        {
            if (row + 1 > 1)
            {
                row = row;
            }
            else 
            {
                row++;
            }

            LCD_Clear();
            LCD_GotoXY(column, row);
            LCD_PrintChar('!');
        }

        _delay_ms(500);
    }

}
