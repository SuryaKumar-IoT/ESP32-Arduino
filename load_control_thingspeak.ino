#include "ESP8266WiFi.h"
#include "ThingSpeak.h"

WiFiClient client;

void setup()
{
  pinMode(D8,OUTPUT);
  Serial.begin(115200);
  Serial.println();
  connect_wifi();
  Serial.println("Connecting to ThingSpeak Cloud");
  delay(300);
  ThingSpeak.begin(client);
  Serial.println("ThingSpeak Connected");
  delay(1000);
}

void loop() 
{
  int light_status=ThingSpeak.readFloatField(1565604,1,"FIJR5PY5O43NORUR");
  int sta=ThingSpeak.getLastReadStatus();
  if(sta==200)
  {
    Serial.print("Light Status from Cloud:");
    Serial.println(light_status);
    delay(1000);    
    if(light_status==1)
    {
      digitalWrite(D8,HIGH);
    }
    else
      digitalWrite(D8,LOW);
  }
  else
  {
    Serial.println("Error in Reading Data from Cloud");
    delay(500);
  }
}
void connect_wifi()
{
  Serial.println("Connecting to WiFi Network");
  delay(1000);
  WiFi.disconnect();
  delay(300);
  WiFi.begin("surya","surya1827");
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println("WiFi Connected");
  Serial.print("IP Address:");
  Serial.println(WiFi.localIP());
  delay(500);
}
