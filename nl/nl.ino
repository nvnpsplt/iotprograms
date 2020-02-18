void setup() {
 pinMode(8,OUTPUT);
 pinMode(5,OUTPUT);

}

void loop() {
  digitalWrite(8,HIGH);
  delay(1000);
  digitalWrite(8,LOW);
  digitalWrite(5,HIGH);
  delay(1000);
  digitalWrite(5,LOW);
  
}
