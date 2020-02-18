 int IRPin = 3; // declaring pin 3 to read digital input

//Variables:
int value; //save the digital value sent by ir led


void setup(){
  
  pinMode(IRPin, INPUT);  //Set pin 3 as 'input'
  pinMode(13,OUTPUT);
  Serial.begin(115200);       //Begin serial communication

}

void loop(){
  
  value = digitalRead(IRPin);         //Read and save digital value from ir sensor              //Print value
 if (value == LOW)
 {
  Serial.println("Motion Detedted");
  digitalWrite(13,HIGH);
 }
 else{
   Serial.println("No Motion Detedted");
    digitalWrite(13,LOW);
  
 }
}
