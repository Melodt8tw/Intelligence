int potPin = 3; // select the input pin for the potentiometer
int ledPinA = 9;
int ledPinB = 5;
int ledPinC = 3;

void setup() {
  Serial.begin(9600);


}

void loop() {
  int sensorValue = analogRead(potPin);
   sensorValue = sensorValue/4;
  if  (sensorValue > 0 ) analogWrite(ledPinA, sensorValue);
  delay(150);
  if  (sensorValue > 85) analogWrite(ledPinB, sensorValue);
  delay(150);
  if (sensorValue > 170) analogWrite(ledPinC, sensorValue);
   delay(150);
  
  
}
