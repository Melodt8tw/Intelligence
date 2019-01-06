// include the library code:
#include "pitches.h" //Melody
#include <LiquidCrystal.h> //LCD
#include "DHT.h"  //DHT

//LCD&DHT
#define DHT_Type DHT11      // DHT 11
//定義資料PIN腳
#define DHT11_PIN A0
//宣告物件
DHT DhtObj(DHT11_PIN, DHT_Type);
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
 
//buzzer
// notes in the melody:

int melody[] = {

  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};

int duration = 100;  // 500 miliseconds

int t=10;
int k;
int var=0;

//photocell
// LAB8 - 讀取光敏電阻 (v1)
int photocellPin = 2; // 光敏電阻 (photocell) 接在 anallog pin 2

int photocellVal = 0; // photocell variable

int minLight = 30;   // 最小光線門檻值

int ledPin =9;

int ledState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  lcd.begin(16, 2);

}

void loop() { 
  lcd.setCursor(0, 0); //LCD顯示溫溼度
  lcd.print("H = ");
  lcd.print(DhtObj.readHumidity());
  lcd.print("% ");

  lcd.setCursor(0, 1); 
  lcd.print("T = ");
  lcd.print(DhtObj.readTemperature());
  lcd.println("C ");

  
  

  photocellVal = analogRead(photocellPin); // 讀取光敏電阻並輸出到 Serial Port
  Serial.print("photocellVa=");
  Serial.println(photocellVal);

  if (photocellVal < minLight ) {
    
    digitalWrite(ledPin, HIGH); // turn on LED

    ledState = 1;
    
    var++;
    k=t-var;
    Serial.print("var=");
    Serial.println(var); //次數
    Serial.print("k=");
    Serial.println(k); //距離buzzer響起的秒數     
    // var++;
    // k=t-var;
    if(k==0){
      
      for (int thisNote = 0; thisNote < 8; thisNote++) {
        
    // 在 pin8 上輸出聲音，每個音階響 0.5 秒
        tone(8, melody[thisNote], duration);
    // 間隔一段時間後再播放下一個音階
        delay(100);
         }
      var=0;
    }
      

      }
  // 光線充足時關掉 LED
   if (photocellVal > minLight  ) {

    digitalWrite(ledPin, LOW); // turn off LED
    noTone(8);
    ledState = 0;
    var=0;

  } 
  Serial.print("ledState=");
  Serial.println(ledState); //次數

  delay(1000);
 
}
