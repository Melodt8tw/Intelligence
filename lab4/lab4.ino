int potPin = 3; // select the input pin for the potentiometer
int ledPinA = 9;
int ledPinB = 5;
int ledPinC = 3;

void setup() {
  Serial.begin(9600);


}

void loop() {
  int sensorValue = analogRead(potPin);
  
        Serial.println(sensorValue, DEC);
   sensorValue = sensorValue/4;
  analogWrite(ledPinA, sensorValue);
  delay(150);

   int sensorValueB = analogRead(potPin);
   Serial.println(sensorValueB, DEC);
  sensorValueB = (sensorValueB;
   analogWrite(ledPinB, sensorValueB);
  delay(150);
  
  
  
}
