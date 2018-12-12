#include "DHT.h"  

//定義傳感器型號
#define DHT_Type DHT11      // DHT 11
//#define DHT_Type DHT22    // DHT 22

//定義資料PIN腳
#define DHT11_PIN A0

//宣告物件
DHT DhtObj(DHT11_PIN, DHT_Type);

void setup()
{
  Serial.begin(9600);
  delay(3000);
}

void loop()
{
  Serial.print("Humidity Value = ");
  Serial.print(DhtObj.readHumidity());
  Serial.print("% , ");
  
  Serial.print("Temperature Value = ");
  Serial.print(DhtObj.readTemperature());
  Serial.println("C ");
  
  delay(2000);
}
