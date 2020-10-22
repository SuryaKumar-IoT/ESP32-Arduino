#include "DHT.h"
#define DHTPIN 22
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);

void setup()
{
  Serial.begin(9600);
  Serial.println();
  delay(500);
  Serial.println("DHT TEST");
  delay(100);
  dht.begin();
  delay(1000);
}

void loop() 
{
   float h =dht.readHumidity();
   float t =dht.readTemperature();//0 c
   float tt=dht.readTemperature(true);//Fahrenheit

   if(isnan(h) ||isnan(t) || isnan(tt))
   {
      Serial.println("Error In reading Data");
      return;
   }

   Serial.print("Humidity:");
   Serial.print(h);
   Serial.print("\t Temperature (C):");
   Serial.print(t);
   Serial.print("\t Temperature (F):");
   Serial.println(tt);
   delay(5000);
}
