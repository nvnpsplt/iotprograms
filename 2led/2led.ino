void setup() {
 pinMode(8,OUTPUT);
 pinMode(9,OUTPUT);

}

void loop() {
 digitalWrite(8,HIGH);
 delay(2000);
 digitalWrite(8,LOW);
 digitalWrite(9,HIGH);
 delay(2000);
 digitalWrite(9,LOW);
}
