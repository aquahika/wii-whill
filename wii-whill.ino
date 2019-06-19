#include <Wire.h>
#include <SoftwareSerial.h>
#include "WHILL.h"
#include "Nunchuk.h"


SoftwareSerial ss(7,6);  // TX pin 7, RX pin 6
WHILL whill(&ss);


void setup() {
    Serial.begin(9600);
    Wire.begin();
    // nunchuk_init_power(); // A1 and A2 is power supply
    nunchuk_init();
    pinMode(LED_BUILTIN,OUTPUT);
}
void loop() {
    if (nunchuk_read()) {
        // Work with nunchuk_data
//        Serial.print(nunchuk_joystickX());
//        Serial.print(",");
//        Serial.print(nunchuk_joystickY());
//        Serial.print(",");
//        Serial.print(nunchuk_buttonZ());
//        Serial.println("");
        whill.refresh();

        int x = nunchuk_joystickX();
        int y = nunchuk_joystickY();

        if(abs(x)<10)x=0;
        if(abs(y)<10)y=0;

        if((x!=0) || (y!=0)){
          whill.setJoystick(x,y);      // Turn Right
        }

        digitalWrite(LED_BUILTIN,nunchuk_buttonZ());
    }
    delay(10);
}
