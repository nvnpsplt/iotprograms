#include<SoftwareSerial.h>

SoftwareSerial bt(2,3); 
void setup() {
  bt.begin(9600);   
  Serial.begin(9600);   
}
void loop() {
  
    if (bt.available()) 
    {
     Serial.write(bt.read());   
    }
}
