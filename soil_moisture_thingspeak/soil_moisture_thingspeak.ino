#include "WiFi.h"
#include "ThingSpeak.h"
const char* ssid="surya";
const char* pwd="surya1827";
WiFiClient client;

void setup() 
{
  pinMode(34,INPUT);
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
  Serial.print("Soil Moisture Value:");
  int soil=map(analogRead(34),0,4095,100,0);
  Serial.println(soil);
  

  /*int x=ThingSpeak.writeField(1191279,1,soil,"IL81ZATATZV73JVX");
  if(x==200)
  {
    Serial.println("Channel Updated Successfully");
  }
  else
  {
    Serial.println("Error In Uploading Data");
  }*/
  
}
