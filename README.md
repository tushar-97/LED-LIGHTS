# LED-LIGHTS
This is a basic project to control a strip of led lights using what's being played on the speakers and what is being displayed on the screen.

.ino file is to be opened using the Arduino IDE. You will need to create a folder with the same name and put this file in it for it to work.

.pde file is to be opened using Processing IDE and needs to be running at all times.

Basic Working:
The processing code is continuously calculating the amount of red,green and blue pixels on the screen and putting their values on the serial stream. The arduino code picks up these values and the lights the led light accordingly. After playing around with my sound sensor I deicded to keep the threshold at 150 which was in between the range of values I was getting. When the sound senosr detects a reading above 150 the led's light up.

I welcome all suggestions for making the code more effective.
