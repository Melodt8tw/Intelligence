int potPin = A3;
int ledPin1 = 4; 
int ledPin2 = 5; 
int ledPin3 = 6; 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(potPin,INPUT);
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(potPin);
  Serial.println(sensorValue, DEC);
  //sensorValue = sensorValue/4; // convert from 0-1024 to 0-255
  if (sensorValue==0){
    digitalWrite(ledPin1,LOW);
    digitalWrite(ledPin2,LOW);
    digitalWrite(ledPin3,LOW);
  }else if(sensorValue<=312&&sensorValue>0){
    digitalWrite(ledPin1,HIGH);
    digitalWrite(ledPin2,LOW);
    digitalWrite(ledPin3,LOW);
    }  
  else if(sensorValue>312&&sensorValue<=624)
  {
    digitalWrite(ledPin1,HIGH);
    digitalWrite(ledPin2,HIGH);
    digitalWrite(ledPin3,LOW);
    }
  else if(sensorValue>=1000){

    digitalWrite(ledPin1,HIGH);
    digitalWrite(ledPin2,HIGH);
    digitalWrite(ledPin3,HIGH);
    }
  //analogWrite(ledPin, l_sensorValue);
  

  delay(150);


}
