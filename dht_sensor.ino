#include "DHT.h"
DHT dht(D7,DHT11);
void setup()
{
  dht.begin();
  Serial.begin(115200);
  Serial.println("DHT TEST");
  delay(2000);
  
}

void loop()
{
  float temp=dht.readTemperature();
  float hum= dht.readHumidity();
  if(isnan(temp) || isnan(hum))
  {
    Serial.println("Error in reading");
    delay(500);
    return;
  }
  Serial.print("Temperature:");
  Serial.print(temp);
  Serial.print(",Humidity:");
  Serial.println(hum);
  delay(2000);  
}
