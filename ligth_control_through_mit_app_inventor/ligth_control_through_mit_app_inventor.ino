#include "WiFi.h"
#include "ThingSpeak.h"

char ssid[]="surya";
char pwd[]="surya1827";

WiFiClient client;
void setup()
{
  pinMode(23,OUTPUT);
  digitalWrite(23,HIGH);
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
  int light=ThingSpeak.readFloatField(1194164,1);
  int statuscode=ThingSpeak.getLastReadStatus();
  if(statuscode== 200)
  {
    Serial.println("Light Status:"+String(light));
    if(light==1)
    {
      Serial.println("Light ON");
      digitalWrite(23,LOW);
    }
    else if(light==0)
    {
      Serial.println("Light OFF");
      digitalWrite(23,HIGH);
    }
    else
    {
      Serial.println("Incorrect Data");
    }
  }
  else
  {
    Serial.println("Problem in Reading Data with Error Code: "+String(statuscode));
  }
  delay(1000);
}
