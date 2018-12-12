//ping
const int trig = 5;
const int echo = 7;
const int inter_time = 1000;
int time = 0;

//buzzer
#include "pitches.h"
int thisNote = 0;
int melody[] = {

  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};

int duration = 250;  // 500 miliseconds

//DHT
#include "DHT.h" 
#define DHT_Type DHT11  
#define DHT11_PIN A0
DHT DhtObj(DHT11_PIN, DHT_Type);

void setup() {

 Serial.begin(9600);   //ping
  pinMode (trig, OUTPUT);
  pinMode (echo, INPUT);
 

}

void loop() {
  
  Serial.print("Humidity Value = ");  //DHT
  Serial.print(DhtObj.readHumidity());
  Serial.print("% , ");
  
  Serial.print("Temperature Value = ");
  Serial.print(DhtObj.readTemperature());
  Serial.println("C ");

 if (DhtObj.readHumidity() >= 90)
    {
      for (int thisNote = 0; thisNote < 8; thisNote++) {
      tone(8, melody[thisNote], duration);
      delay(1000);
      }
    }
 

  float duration, distance; //ping
  digitalWrite(trig, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig, LOW);
  duration = pulseIn (echo, HIGH);
  distance = (duration/2)/29;
  Serial.print("Data:");
  Serial.print (time/1000);
  Serial.print(", d = ");
  Serial.print(distance);
  Serial.println(" cm");
  time = time + inter_time;
  delay(inter_time);

if (distance <= 10)
   {
    tone(8, melody[7], duration);
    
    delay(500);
   }
   if (distance >10 and distance <20 )
   {
    tone(8, melody[1], duration);
    delay(500);
   }
   
 delay(500); //每0.5秒偵測一次
}
