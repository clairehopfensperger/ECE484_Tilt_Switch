/*
    Copyright Claire Hopfensperger 2024

    Making a tilt switch controller that moves characters on an LCD.
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
    // Put tilt switch pins in an array.
    const int numTiltSwitches = 4;
    int tiltSwitches[numTiltSwitches];
    tiltSwitches[0] = PD3;
    tiltSwitches[1] = PD2;
    tiltSwitches[2] = PB1;
    tiltSwitches[3] = PB0;

    // Set tilt switch pins as input
    for (int i = 0; i < numTiltSwitches; i++) {
	    DDRD &= ~(1 << tiltSwitches[i]);
    }

    // Set up LCD
    LCD_Setup();
    int column = 0;
    int row = 0;
    LCD_GotoXY(column, row);
    LCD_PrintChar('!');

    while(1)
    {
        // // Move character up
        // if (checkState(tiltSwitches[0]))
        // {
        //     if (row + 1 > 1)
        //     {
        //         row = row;
        //     }
        //     else 
        //     {
        //         row++;
        //     }
            
        //     LCD_Clear();
        //     LCD_GotoXY(column, row);
        //     LCD_PrintChar('!');
        // }

        // // Move character left
        // if (checkState(tiltSwitches[1]))
        // {
        //     if (column - 1 < 0)
        //     {
        //         column = column;
        //     }
        //     else 
        //     {
        //         column--;
        //     }

        //     LCD_Clear();
        //     LCD_GotoXY(column, row);
        //     LCD_PrintChar('!');
        // }

        // Move character right
        if (checkState(tiltSwitches[2]))
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

        // // Move character down
        // if (checkState(tiltSwitches[3]))
        // {
        //     if (row - 1 < 0)
        //     {
        //         row = row;
        //     }
        //     else 
        //     {
        //         row--;
        //     }

        //     LCD_Clear();
        //     LCD_GotoXY(column, row);
        //     LCD_PrintChar('!');
        // }

        _delay_ms(500);
    }

}
