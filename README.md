# IoT_blinds
Isn't it annoying to go to the window and open or close blinds mannually?

This project automates window blinds and allows you to open and close blinds using Google Home voice command or a button on yor phone.

It doesn't allow to rise blinds.. yet. (TO DO)

Things you will need:
- ESP12E MCU with HW-588A modules
- usb wire, charger 5v
- DC motor, 5V
- electric wires (ex. 22 gauge)

Tools:
- 3D printer
- Phillips screwdriver 
- soldering iron

Installation:
- Install Arduino IDE
- Adjust IDE for ESP8266, in Tools-> board-> choose NodeMCU 1.0 (ESP 12e Module)
- Install Blynk app, add device, create a token
- Change id, token & wifi info in dev/blinder/blinder.ino
- 3D print the hardware part
- Solder wires to the motor
- Connect wires to HW-588A module using screwdriver 
  https://github.com/Veroni/IoT_blinds/blob/00d3cb376f71c08740fde7f776eae96accebd6fa/esp_hw-588A_motor.jpg
- Connect ESP to computer and flash the code
- Attach hardware piece to the motor and then to the blinds
- Test the Blynk button
- Enjoy the laziness! 

Too lazy to open an app and press a button on your phone? Not a problem! Follow next steps for the voice command:

For the Google Home Assistant use IFTTT:
- Create IFTTT account
- Connect IFTTT to your Google Home account -> settings -> works with google -> IFTTT
- Go to IFTTT account, create a new applet
- If This -> Google Assistant -> activate scene -> open blinds (or whatewer command you prefer)
- Then that ->  Webhooks -> Make a webrequest -> url (change blynk url using the correct location server and tokens)
- Repeat that for closing blinds
- Enjoy opening/closing blinds with Google Home Assistant 
