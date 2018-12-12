
#include <Ultrasonic.h>

 

#define TRIGGER_PIN  12

#define ECHO_PIN     13

 
07
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
08
 
09
void setup()
10
{
11
  Serial.begin(9600);
12
}
13
 
14
void loop()
15
{
16
  float cmMsec, inMsec;
17
  long microsec = ultrasonic.timing();
18
 
19
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM); // 計算距離，單位: 公分
20
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN); // 計算距離，單位: 英吋
21
  Serial.print("MS: ");
22
  Serial.print(microsec);
23
  Serial.print(", CM: ");
24
  Serial.print(cmMsec);
25
  Serial.print(", IN: ");
26
  Serial.println(inMsec);
27
  delay(1000);
28
}
