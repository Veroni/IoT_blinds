# IoT_blinds
Isn't it annoying to go to the window and open or close blinds mannually?
This project automates the window blinds and allows you to open and close blinds using Google Home voice command or a button on yor phone.
It doesn't allow to rise blinds.. yet. (TO DO)

Things you will need:
- ESP12E MCU with HW-588A modules
- Case for 4 AA batteries
- 4 AA batteries, 5v
- DC motor, 5V
- electric wires (ex. 22 gauge)

Tools:
- 3D printer
- Phillips screwdriver 
- soldering iron

Installation:
- Install Arduino IDE
- Adjust IDE for ESP8266, in Tools-> board-> choose NodeMCU 1.0 (ESP 12e Module)
- Install Blynk app, add device, create the token
- Change the token & wifi info in dev/blinder/blinder.ino
- 3D print the hardware part
- Solder wires to the motor
- Connect wires to HW-588A module using screwdriver
- Connect ESP to computer and flash the code
- Attach hardware piece to the motor and then to the blinds
- Test the Blynk button
- Enjoy the laziness! 

Too lazy to open an app and press a button on your phone? Not a problem! Follow next steps:
For the Google Home Assistant use IFTTT:
- Create IFTTT account
- Create a new applet
- If This -> Google Assistant -> activate scene -> open blinds (or whatewer command you prefer)
- Then that ->  Webhooks -> Make a webrequest -> url (change blynk url using the correct location server and tokens)
- Repeat that for closing blinds
- Enjoy opening blinds with Google Home Assistant 
