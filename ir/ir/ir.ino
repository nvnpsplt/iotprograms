int sensor =12;
int led =13;
void setup()
{
  pinMode(sensor,INPUT);
  pinMode(led,OUTPUT);
}
void loop(){
  int val =digitalRead(sensor);
  if(val == LOW)
  {
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }
}
