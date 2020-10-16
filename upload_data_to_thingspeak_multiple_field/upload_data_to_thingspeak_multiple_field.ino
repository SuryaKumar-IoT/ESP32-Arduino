#include "WiFi.h"
#include "ThingSpeak.h"
const char* ssid ="surya";
const char* pwd ="surya1827";

WiFiClient client;

void setup()
{
  Serial.begin(9600);
  connect_wifi();
  ThingSpeak.begin(client);
}

void loop() 
{
  int n=random(1,100);
  int m=random(1,100);
  ThingSpeak.setField(1,n);
  ThingSpeak.setField(2,m);
  int x = ThingSpeak.writeFields(1184993,"YIC03P5VSTUIBGG3");
  if(x == 200)
  {
    Serial.println("Channel update successful.");
  }
  else
  {
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
  delay(20000);
}

void connect_wifi()
{
  Serial.println();
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  delay(1000);
  WiFi.begin(ssid,pwd);

  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }

  Serial.println();
  Serial.println("WiFi Connected");
  delay(1000);
  Serial.print("IP Address:");
  Serial.println(WiFi.localIP());
  delay(1000);
}
