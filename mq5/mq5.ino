#include <ESP8266WiFi.h>
BearSSL::WiFiClientSecure client;

const char* ssid = "nvn";
const char* password = "12345678";

const char* host = "maker.ifttt.com";
const int httpsPort = 443;
const char trigger[ ]  = "dustbin_alert";
const char APIKey[ ]   = "cyKcUrO9_7wR-G7N_NfdA8";

float sensor=A0;
float gas_value;

void setup() {
pinMode(sensor,INPUT);
  
  Serial.begin(115200);
  Serial.println();
  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  WiFiClientSecure client;
}

void loop() {
gas_value=analogRead(sensor);
Serial.println(gas_value);
delay(1000);

if(gas_value >= 300)
{
  Serial.print("connecting to ");
  Serial.println(host);
  const int API_TIMEOUT = 10000;
  client.setInsecure();
  client.setTimeout(API_TIMEOUT);
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return;
  }


  String url = String("/trigger/") + trigger + String("/with/key/") + APIKey;

  Serial.print("requesting URL: ");
  Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: BuildFailureDetectorESP8266\r\n" +
               "Connection: close\r\n\r\n");

  Serial.println("request sent");
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("headers received");
      break;
    }
  }
  String line = client.readStringUntil('\n');

  Serial.println("reply was:");
  Serial.println("==========");
  Serial.println(line);
  Serial.println("==========");
  Serial.println("Message Sent Successfully");
  delay(3000);
}
}
