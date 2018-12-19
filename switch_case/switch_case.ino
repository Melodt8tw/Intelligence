void setup() {
   Serial.begin(9600);

  for (int thisPin = 8; thisPin <= 10; thisPin++) {
    pinMode(thisPin, OUTPUT);

  }      

}


void loop() {
  if (Serial.available() > 0) {

    int inByte = Serial.read();

    switch (inByte) {

    case '1':   

      digitalWrite(8, HIGH);
      delay(1500);

      break;

    case '2':   

      digitalWrite(9, HIGH);
      delay(1500);

      break;

    case '3':   

      digitalWrite(10, HIGH);
      delay(1500);
      break;

      case '4':   

      digitalWrite(10, HIGH);
      digitalWrite(8, HIGH);
      delay(1500);
      break;
      
      case '5':   

      digitalWrite(9, HIGH);
      digitalWrite(8, HIGH);
      delay(1500);
      break;
      
      case '6':   

      digitalWrite(10, HIGH);
      digitalWrite(9, HIGH);
      delay(1500);
      break;

      case '7':   

      digitalWrite(10, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(8, HIGH);
      delay(1500);
      break;


    default:

      // 關掉所有的 LED
      for (int thisPin = 8; thisPin <= 10; thisPin++) {

        digitalWrite(thisPin, LOW);

      }

    }

  }

}
