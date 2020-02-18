
int sensor = 0;
void setup() {
  Serial.begin(9600);

}

void loop() {
  int a = analogRead(sensor);
  float b = (a / 1024) * 5000;
  float c = b / 10;
  Serial.println(c);
  delay(1000);
}
