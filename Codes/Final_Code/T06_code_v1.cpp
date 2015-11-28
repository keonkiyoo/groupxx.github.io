// Version 1 Code to run on the T06 Board
// Shadman Samin, Nathan Pham, Keon Yoo, Dusan Micic
// The code runs an arduino header files which includes all the basic Arduino Libraries to run the commands.

#include <Arduino.h>

void setup(); // Setup to initialize all the Pins
void loop(); // Main function to run the while loop statement
int led = 9;

void TriggerRead(int echoPin); // This parts sends 10 us Triggers into the HC-SR04
long PulseWidth(int echoPin); // Waits for an interrupt signal and counts the length of the interrupt
int constantDistance = 30; // constant distance that can be changed


void setup() {
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}

void loop() {
  if (PulseWidth(8) < constantDistance || PulseWidth(10) < constantDistance || PulseWidth(11) < constantDistance) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
  delay(100); // Gives the Sensor enough time so that trigger does not overlap with the Echo signal
}

void TriggerRead(int echoPin) {
  pinMode(echoPin, OUTPUT);
  digitalWrite(echoPin, LOW); 
  delayMicroseconds(5); 
  digitalWrite(echoPin, HIGH);
  delayMicroseconds(20); // 10 us++ is sent just for safety that the trigger is long enuf
  digitalWrite(echoPin, LOW);
}

long PulseWidth(int echoPin) {
  long duration, distance;
  TriggerRead(echoPin);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH); // Interrupt reads the length of the pulse
  distance = (duration / 2) / 29.1;
  return distance;
}
