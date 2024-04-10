# Tilt Switch

A tilt switch is a type of switch that opens and closes based on its angle of tilt. A tilt switch is in its "ON state" when the switch is a closed connection, and it is in its "OFF state" when the switch is an open connection. The specific tilt switch I interfaced with was the SW-520D.
<br>

[SW-520D Tilt Switch Data Sheet](https://www.sunrom.com/download/676.pdf)
<br><br>

## How Tilt Switches Work

<h3 align = "center"> Vertical Tilt Switch Diagram </h3>
<p align = "center">
  <img src = "https://github.com/clairehopfensperger/ECE484_Tilt_Switch/blob/main/media/vertical_tilt_switch_diagram.JPG" width = 600>
  <br>
  When a tilt switch is oriented vertically, it is in its "ON state" and acts as a closed connection until it is tilted more than 45 degrees in any direction which then causes the tilt switch to change to its "OFF state" and have an open connection.
</p>
<br>

<h3 align = "center"> Horizontal Tilt Switch Diagram </h3>
<p align = "center">
  <img src = "https://github.com/clairehopfensperger/ECE484_Tilt_Switch/blob/main/media/horizontal_tilt_switch_diagram.JPG" width = 600>
  <br>
  When a tilt switch is oriented horizontally, it is in its "ON state" and acts as a closed connection when it is tilted more than 10 degrees toward its pins, and it is in its "OFF state" and has an open connection when it is tilted more than 10 degrees toward the top of the switch.
</p>

<br>

## Basic Tilt Switch Setup with Arduino
***NOTE: the tilt switch shown in the setup image is not the tilt switch I interfaced with, it was just the only one available on Tinkercad.***
<br><br>
<p align = "center">
  <img src = "https://github.com/clairehopfensperger/ECE484_Tilt_Switch/blob/main/media/tilt_swich_setup.png" width = 600>
</p>
<br>
In the Arduino IDE, by using digitalRead() with the pin connected to the tilt switch, you will get either a HIGH or LOW (1 or 0) signal. The LOW signal correlates to when the switch is in its "ON state" and has a closed connection, and the HIGH signal correlates to when the switch is in its "OFF state" and has an opened connection. The HIGH signal correlates to the "OFF state" and the LOW signal correlates to the "ON state" due to the Arduino's active low digital inputs through pull-up resistors.
<br><br>

## Using the Tilt Switch Library
In order to use the tilt switch library, make sure you have `#include "libTiltSwitch/tilt_switch.h"` at the top of your program.
<br><br>
You will also need to configure which pins you are using your tilt switches with. For example, in the code snippet below, I am adding Arduino digital pins 8 and 9 (PB0 and PB1) to my tiltSwitchesB array for future use.
```c
// B port tilt switch pins.
const int numTiltSwitchesB = 2;
int tiltSwitchesB[numTiltSwitchesB];
tiltSwitchesB[0] = PB0;
tiltSwitchesB[1] = PB1;
setupTiltSwitchesB(numTiltSwitchesB, tiltSwitchesB);
```
Check out **tilt_level.c**, **tilt_control.c**, and **tilt_test.c** to see more examples of how to use the tilt switch library.
<br><br>

## Running Programs on the Arduino UNO R3
When compiling and uploading programs to the Arduino, adjust the **compile_script.py** to match your system directories and files. First, change the `path_win_avr` variable to match the path of where their avr package is located. Then, adjust the `files_to_compile`, `directories`, and `file_to_compile` variables to match what files you are compiling and uploading to the Arduino. 
<br> 

For example, as seen below, my main file I am compiling is 'tilt_test' as included in `files_to_compile` and `file_to_compile`, and the other files I must compile with it are 'libTiltSwitch/tilt_switch' (the tilt switch library files) and 'libLCD/HD44780' (the LCD library files) as included in `files_to_compile`. I also included what directories those files are within in the `directories` variable.

```py
# tilt test
files_to_compile = ['tilt_test', 'libTiltSwitch/tilt_switch', 'libLCD/HD44780'] 
directories = ['libTiltSwitch', 'libLCD']
file_to_compile = 'tilt_test'
```

Once the **compile_script.py** is adjusted, go to the terminal, navigate to where all of the program files and compile script are, and run `python3 compile_script.py 4 [COM]` where [COM] is the name of your computer's COM port that your Arduino is plugged into. If the compile script ran successfully, the program is compiled and uploaded to the Arduino now!
<br><br>

## Iterfacing Project
Check out the [wiki](https://github.com/clairehopfensperger/ECE484_Tilt_Switch/wiki) for information on the project!
