# Tilt_Switch

## How Tilt Switches Work

## Basic Tilt Switch Setup with Arduino
***NOTE: the tilt switch shown in the setup image is not the tilt switch I interfaced with, it was just the only one available on Tinkercad.***
<br><br>
<p align = "center">
  <img src = "https://github.com/clairehopfensperger/ECE484_Tilt_Switch/blob/main/media/tilt_swich_setup.png" width = 600>
</p>
<br>
By using digitalRead() with the pin connected to the tilt switch, you will get either a HIGH or LOW (1 or 0) signal. The LOW signal correlates to when the switch is in its "ON state" and the connection iside the switch is in place, and the HIGH signal correlates to when the switch is in its "OFF state" and the connection inside the switch is broken.
