#include "WiFi.h"
#include "ThingSpeak.h"

char ssid[]="surya";
char pwd[]="surya1827";

WiFiClient client;
void setup()
{
  Serial.begin(9600);
  Serial.println();
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  Serial.println("Connecting to WiFi Network");
  WiFi.begin(ssid,pwd);

  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }

  Serial.println();
  Serial.println("WiFi Connected");
  Serial.println("IP Address"+ String(WiFi.localIP()));
  delay(1000);
  ThingSpeak.begin(client);
}

void loop()
{
  float soil=ThingSpeak.readFloatField(1191279,1);
  float temp=ThingSpeak.readFloatField(709806,1);
  float hum=ThingSpeak.readFloatField(12397,3);
  int statuscode=ThingSpeak.getLastReadStatus();
  if(statuscode== 200)
  {
    Serial.println("Soil Humidity Value:"+String(soil));
    Serial.println("Temperature Value:"+String(temp));
    Serial.println("Humidity Value:"+String(hum));
  }
  else
  {
    Serial.println("Problem in Reading Data with Error Code: "+String(statuscode));
  }
  delay(5000);
}
