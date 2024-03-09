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
By using digitalRead() with the pin connected to the tilt switch, you will get either a HIGH or LOW (1 or 0) signal. The LOW signal correlates to when the switch is in its "ON state" and has a closed connection, and the HIGH signal correlates to when the switch is in its "OFF state" and has an opened connection. The HIGH signal correlates to the "OFF state" and the LOW signal correlates to the "ON state" due to the Arduino's active low digital inputs through pull-up resistors.
