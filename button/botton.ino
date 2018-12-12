int val=0;

void setup() {
 
  //put your setup code here and run once;
  pinMode(3, INPUT);
  pinMode(12,OUTPUT);
}


void loop() {
  //put your setup code here and run repeatly;
  
  val=digitalRead(3);   
  digitalWrite(12,val);  
}
