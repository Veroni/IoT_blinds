/* This part is controlling blinds with a dc motor, esp8266, HW588A 
 * Using Blynk for controlling from the phone
 * Pictures for 3D printed parts will be added later
 * This part is opening blinds only, it doesn't rise them
 * Part with rising blinds will be added later
 */

// enabling or disabling prints
//#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "" //"your id here"
#define BLYNK_DEVICE_NAME "blinder"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
char ssid[] = "";
char pass[] = "";
char auth[] = ""; //"your Blynk auth token"

const int pwmMotor = 5;
const int dirMotor = 0;

int motorSpeed = 200;

void setup() {
  Serial.begin(115200);
  Serial.println("Serial begin");

  pinMode(pwmMotor, OUTPUT);
  pinMode(dirMotor, OUTPUT);

  Serial.println("Motor SHield Initialized");
  Blynk.begin(auth, ssid, pass);
  delay(5000);
}

BLYNK_WRITE(V5) // Executes when the value of virtual pin 5 changes
{
  if(param.asInt() == 1)
  {
    // execute this code if the switch widget is now ON
    Serial.println("Opening Blinds");
    digitalWrite(pwmMotor, motorSpeed);
    digitalWrite(dirMotor, LOW);
    Blynk.virtualWrite(V1,1);  // Turn the widget attached to V1 On
    Blynk.virtualWrite(V2,1);  // Turn the widget attached to V2 On
    delay(1500);
    Serial.println("Stop blinds");
    digitalWrite(pwmMotor, 0);
    digitalWrite(dirMotor, LOW);
    Blynk.virtualWrite(V2,0);  // Turn the widget attached to V2 Off
    delay(5);
  }
  else
  {
    // execute this code if the switch widget is now OFF
    Serial.println("Closing blinds");
    digitalWrite(pwmMotor, motorSpeed);
    digitalWrite(dirMotor, HIGH);
    Blynk.virtualWrite(V1,0);  // Turn the widget attached to V1 Off
    Blynk.virtualWrite(V2,1);  // Turn the widget attached to V2 On
    delay(1500);
    Serial.println("Stop blinds");
    digitalWrite(pwmMotor, 0);
    digitalWrite(dirMotor, LOW);
    Blynk.virtualWrite(V2,0);  // Turn the widget attached to V2 Off
    delay(5);   
  }
}

void loop() {
  Blynk.run();
}
