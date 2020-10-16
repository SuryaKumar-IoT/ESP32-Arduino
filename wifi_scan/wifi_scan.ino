/*RSSI : Received Signal Strenght Indicator
 * ssid -sERVICE SET IDENTIFER
 * RSSI (-minus value )
 * -50 strenght id more when compared to -70
 */

#include "WiFi.h"

void setup()
{
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  Serial.println("Scanning WiFi Networks");
  delay(100);
}

void loop() 
{
  int a= WiFi.scanNetworks();
  if(a==0)
    Serial.println("No Networks Found");
  else
  {
    Serial.print(a);
    Serial.println(" WiFi Networks Found");
    Serial.println();
    for (int i=0;i<a;i++)
    {
      Serial.print(i+1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" ( ");
      Serial.print(WiFi.RSSI(i));
      Serial.println(")");
      delay(100);
    }
  }
  Serial.println();
  delay(1000);
}
