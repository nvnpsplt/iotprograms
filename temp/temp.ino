int temppin=1;

void setup() {
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float val=analogRead(temppin);
  float mv =(val/1024)*5000;
  float cel =(mv/10);
  Serial.print("Temperature is ");
  Serial.println(cel);

  if(cel > 25)
  {
    digitalWrite(13,HIGH);
  }
  else
  {
    digitalWrite(13,LOW);
  }
}
