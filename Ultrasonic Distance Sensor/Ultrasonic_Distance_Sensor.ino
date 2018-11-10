//
// Ultrasonic Distance Sensor
//
// Description of the project
// Developed with [embedXcode](http://embedXcode.weebly.com)
//
// Author 		Michael Lema
// 				Michael Lema
//
// Date			11/10/18 5:18 PM
// Version		1
//
// Copyright	© Michael Lema, 2018
// Licence		MIT
//
// See         ReadMe.txt for references
//

#include "Arduino.h"

/*
* Reference: https://www.parallax.com/sites/default/files/downloads/28015-PING-Sensor-Product-Guide-v2.0.pdf
* Note: Cannot accurately measure the distance to an object that is more than 3 meters away
* Program:  http://learn.parallax.com/KickStart
 */

const int pingPin = 11;
unsigned int duration, inches;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    pinMode(pingPin, OUTPUT); // Set pin to OUTPUT
    digitalWrite(pingPin, LOW); // Ensure pin is low
    delayMicroseconds(2);
    digitalWrite(pingPin, HIGH); // Start ranging
    delayMicroseconds(5); // With 5 microsecond burst
    digitalWrite(pingPin, LOW); // End Ranging
    pinMode(pingPin, INPUT); //  Set pin to INPUT
    duration = pulseIn(pingPin, HIGH); // Read echo pulse
    inches = duration / 74 / 2; // Convert to inches
    Serial.println(inches); // Display Result
    delay(200); // Short Delay
}
