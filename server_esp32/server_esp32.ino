#include <WiFi.h>
WiFiServer server(80);

WiFiClient client;

String myresultat;
String s;
String ReadIncomingRequest()
{
  while(client.available())
  {
    String ClientRequest = (client.readStringUntil('\r'));
    if ((ClientRequest.indexOf("HTTP/1.1")>0)&&(ClientRequest.indexOf("/favicon.ico")<0))
    {
      myresultat = ClientRequest;
      int index=myresultat.indexOf('/');
      s=myresultat.substring(index+1);
      int index2=s.indexOf("HTTP/1.1");
      s=s.substring(0,index2-1);
    }
  }
  return s;
}

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
  Serial.print("Server IP Address:");
  Serial.println((WiFi.localIP()));
  server.begin();
}


void loop()
{
  client = server.available();
  if (!client) 
  { 
    return; 
  }
  while(!client.available())
  {  
    delay(1); 
  }
  Serial.println((ReadIncomingRequest()));
  client.print("Thank You Data Received");
  delay(100);
  client.flush();
  delay(10);
  Serial.println("Client Disconnected");
  delay(500);
}
