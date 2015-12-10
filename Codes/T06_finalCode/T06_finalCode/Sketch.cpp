// Final Code - T06 Smart Cane
// Authors: Shadman Samin, Nathan Pham, Keon Yoo, Shadman Samin 
// Algorithm to find the distance between sensors and obstacles

#include <Arduino.h>

void setup();
void loop(); // Function for While(1) loop


// Initialization of the pin
int echo1 = 5; // ATMEGA328P Pin PD5
int echo2 = 6; // ATMEGA328P Pin PD6 
int echo3 = 7; // ATMEGA328P Pin PD7
int Motor = 8; // ATMEGA328P Pin PB0

void TriggerRead(int echoPin); // Function to send 10 us (atleast) long 
long PulseWidth(int echoPin);  // Function to hear the Echo pin and calculate the distance


int constantDistance_1 = 10; // The sensor one should have atleast 50 cm or less to detect obstacles
int constantDistance_2 = 5; // The sensor two should have atleast 20 cm or less to detect obstacles
int constantDistance_3 = 10; // The sensor three should have atleast 20 cm or less to detect obstacles
int i = 1;

void setup() {
  pinMode(Motor, OUTPUT); // Declare the LED as an output pin
  digitalWrite(Motor, LOW); //Declare the LED to be LOW initially
}

void loop() { 
// The continuous while loop continuously hears for the outputs from the sensors 1,2,3, and adjusts the conditional statements
// to avoid random errors which often is caused by random jitters. So we avoid very low values and ignore them.
// If either of the three sensors senses objects it turns on the motors to alert the user.	


	if((PulseWidth(echo2) < constantDistance_2) || (PulseWidth(echo3) < constantDistance_3)){
		digitalWrite(Motor, HIGH); // Turn on the motor if they fall within range
		}
	else {
		digitalWrite(Motor, LOW); //  Turn it off if it is not within range
	}
}

// Send atleast 10 us trigger
void TriggerRead(int echoPin) {
  delay(20);
  pinMode(echoPin, OUTPUT);
  digitalWrite(echoPin, LOW);  // Added this line
  delayMicroseconds(10); // Added this line
  digitalWrite(echoPin, HIGH);
  delayMicroseconds(20); // Added this line
  digitalWrite(echoPin, LOW);
}

// after the trigger is sent the program waits for a pulse, and using interrupts and a counter within the arduino librarfy it measures the length 
// of the pulse 
long PulseWidth(int echoPin) {
  long duration, distance;
  TriggerRead(echoPin);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  
  // ... The ultrasonic sensors waits for a pulse to come back and the pulse width gives us the length of the pulse.
  // Using the duration of the pulse we can measure the distance travelled. 
    // The speed of sound is 340 m/s or 29 microseconds per centimeter.
    // The ping travels out and back, so to find the distance of the
    // object we take half of the distance travelled.
  // Hence, Distance = (0.5*Duration)/29.1
  
  distance = (duration / 2) / 29.4;
  return distance;
}
