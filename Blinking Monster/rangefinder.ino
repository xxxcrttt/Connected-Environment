/*
  Ping))) Sensor

  This sketch reads a PING))) ultrasonic rangefinder and returns the distance
  to the closest object in range. To do this, it sends a pulse to the sensor to
  initiate a reading, then listens for a pulse to return. The length of the
  returning pulse is proportional to the distance of the object from the sensor.

  The circuit:
  - +V connection of the PING))) attached to +5V
  - GND connection of the PING))) attached to ground
  - SIG connection of the PING))) attached to digital pin 7

  created 3 Nov 2008
  by David A. Mellis
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Ping
*/

// this constant won't change. It's the pin number of the sensor's output:
const int pingPin = 7;

#include <Wire.h>

//This constant wont change. It is the pin number of the sensor's output.
const int trigPin = 9;
const int echoPin = 10;
const int LED = 13; // keep the LED at pin 13
const boolean debug = true; // variable to show hide debug info

// establish variables for duration of the ping, and the distance result in cm
long duration, cm;
int blinkrate = 0;


void setup() {
  // initialize serial communication:
  if(debug){
    Serial.begin(9600);
    Serial.println("Starting Blinker");
  }
  pinMode(LED, OUTPUT);
  pinMode(trigPin, OUTPUT); // set trigPin = output
  pinMode(echoPin, INPUT); // set echoPin = input
}

void loop() {
  //triggers the ultrasonic rangefinder
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  cm = microsecondsToCentimeters(duration);

  // blinks the LED according to the distance of an object from the sensor;
  if (cm < 100) {
    if (cm < 30 ) {
      blinkrate = map(cm, 1, 30, 10, 300);
    }
    else if (cm < 90) {
      blinkrate = map(cm, 30, 90, 300, 1000);
    }
    else {
      blinkrate = 0;
    }

    if(debug) {
      Serial.print(" cm: ");
      Serial.print(cm);
      Serial.print(" blinkrate: ");
      Serial.println(blinkrate);
    }
    digitalWrite(LED, HIGH); // turn the LED on
    delay(blinkrate); // wait for a second
    digitalWrite(LED, LOW); // turn the LED off
    delay(blinkrate);
    }

    delay(20);
}


// helper funciton: converting the duration od echo to a cm   
long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}
