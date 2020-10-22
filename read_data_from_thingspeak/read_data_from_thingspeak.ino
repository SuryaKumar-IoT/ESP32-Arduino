#include "WiFi.h"
#include "ThingSpeak.h"

WiFiClient client;
char ssid[]="surya";
char pwd[]="surya1827";
void setup() 
{
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  Serial.println("Soil Moisture Sensor Test");
  delay(1000);  
  Serial.println("Connecting to WiFi Network");
  delay(1000);
  WiFi.begin(ssid,pwd);

  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.println("WiFi Connected");
  Serial.print("IP Address :");
  Serial.println(WiFi.localIP());
  delay(1000);
  ThingSpeak.begin(client);
  delay(1000);
}

void loop()
{
  float temp = ThingSpeak.readFloatField(1184993,1,"NNJDU8ZQBWAFXPP5");  
  float hum = ThingSpeak.readFloatField(1184993,2,"NNJDU8ZQBWAFXPP5");
  int statusCode = ThingSpeak.getLastReadStatus();
  if(statusCode == 200)
  {
    Serial.println("Temperature: " + String(temp) + " deg C, Humidity:"+String(hum));
  }
  else
  {
    Serial.println("Problem reading channel"); 
  }

}
