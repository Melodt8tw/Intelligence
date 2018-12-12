/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

 
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
 for(int i=0;i<180;i++)
{ myservo.write(i);                  // sets the servo position according to the scaled value
  delay(30); 
} 
  for(int i=180;i<=180 and i>0;i--)
  {
 myservo.write(i);                  // sets the servo position according to the scaled value
  delay(30); 
  }
}
