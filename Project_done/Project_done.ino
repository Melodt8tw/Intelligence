// include the library code:
#include "pitches.h"  //buzzer
#include <LiquidCrystal.h> //LCD
#include "DHT.h"  //DHT

//LCD&DHT
#define DHT_Type DHT11      // DHT 11
#define DHT11_PIN A0  //定義資料PIN腳
//宣告物件
DHT DhtObj(DHT11_PIN, DHT_Type);
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
 
//buzzer
// notes in the melody:
int melody[] = {

  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};

int duration = 100;  // 100 miliseconds

//設定變數，計算倒數計時
int t=10;
int k;
int var=0;

//photocell
int photocellPin = 2; // 光敏電阻 (photocell) 接在 anallog pin 2
int photocellVal = 0; // photocell variable
int minLight = 30;   // 最小光線門檻值
int ledPin =9; //led 接在 digital pin 9
int ledState = 0; //ledState variable

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  lcd.begin(16, 2);  // 初始化 LCD，一行 16 的字元，共 2 行

}

void loop() { 
  lcd.setCursor(0, 0);  //第一行LCD顯示溼度
  lcd.print("H = ");
  lcd.print(DhtObj.readHumidity());
  lcd.print("% ");

  lcd.setCursor(0, 1); //第二行LCD顯示溫度
  lcd.print("T = ");
  lcd.print(DhtObj.readTemperature());
  lcd.print("C ");
  lcd.print(k);

  
  

  photocellVal = analogRead(photocellPin); // 讀取光敏電阻並輸出到 Serial Port
  Serial.print("photocellVa=");
  Serial.println(photocellVal);

  // 光線不足時打開 LED
  if (photocellVal < minLight ) {
    
    digitalWrite(ledPin, HIGH); // turn on LED

    ledState = 1;
    
    var++;
    k=t-var;
    Serial.print("var="); //輸出 次數到 Serial Port
    Serial.println(var); 
    Serial.print("k="); //輸出 距離buzzer響起的秒數到 Serial Port
    Serial.println(k); 

    //如果k倒數至0，buzzer響起
    if(k==0){
      for (int thisNote = 0; thisNote < 8; thisNote++)
             {
              tone(8, melody[thisNote], duration); // 在 pin8 上輸出聲音，每個音階響 0.1 秒 
              delay(100);
             }
      var=0; //歸0重新計算
         }
    }
    
  // 光線充足時關掉 LED
   if (photocellVal > minLight  ) {

    digitalWrite(ledPin, LOW); // turn off LED
    noTone(8); //關掉 digital pin 8 訊號
    ledState = 0;
    var=0;

  } 
  Serial.print("ledState=");//輸出 ledState到 Serial Port
  Serial.println(ledState); 

  delay(1000);
 
}
