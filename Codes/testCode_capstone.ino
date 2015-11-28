int led = 9;
String Total, Space; 

void TriggerRead(int echoPin);
long PulseWidth(int echoPin);
int constantDistance = 30;


void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  Space = String(' ');
  Total = String();
  digitalWrite(led, LOW);
}

void loop() {
  Total = PulseWidth(5) + Space + PulseWidth(6) + Space + PulseWidth(7);
  Serial.println(Total);
 
  if (PulseWidth(5) < constantDistance || PulseWidth(6) < constantDistance || PulseWidth(7) < constantDistance) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }


  delay(100);

}

void TriggerRead(int echoPin) {
  pinMode(echoPin, OUTPUT);
  digitalWrite(echoPin, LOW);  // Added this line
  delayMicroseconds(5); // Added this line
  digitalWrite(echoPin, HIGH);
  delayMicroseconds(20); // Added this line
  digitalWrite(echoPin, LOW);
}

long PulseWidth(int echoPin) {
  long duration, distance;
  TriggerRead(echoPin);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  return distance;
}
