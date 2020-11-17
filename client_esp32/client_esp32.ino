#include <WiFi.h>

WiFiClient client;

String myurl = "/";
void setup()
{
  Serial.begin(9600);

  WiFi.begin("surya","surya1827");
  while ((WiFi.status() != WL_CONNECTED))
  {
    Serial.print(".");
    delay(50);

  }
  Serial.println("WiFI Connected");
  Serial.print("Client IP Address:");
  Serial.println((WiFi.localIP()));

}


void loop()
{

    if (client.connect("192.168.1.107", 80)) 
    {
      myurl += "ClientID=1,message=madblocks";
      client.print(String("GET ") + myurl + " HTTP/1.1\r\n" +
                "Host: " + "192.168.1.107" + "\r\n" +
               "Connection: close\r\n\r\n");
      myurl="/";
    }
    delay(2000);

}
