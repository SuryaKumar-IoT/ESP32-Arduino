#include "WiFi.h"
const char* ssid="abhi";
const char* pwd="abhi1827";
void setup()
{
  Serial.begin(9600);
  Serial.println();
  WiFi.disconnect();
  Serial.println("Creating HotSpot");
  delay(500);
  WiFi.softAP(ssid,pwd);
  Serial.print("IP ADDRESS: ");
  Serial.println(WiFi.softAPIP());
  delay(5000);
}

void loop() 
{

}
