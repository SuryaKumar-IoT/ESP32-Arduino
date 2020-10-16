#include "WiFi.h"

const char* ssid ="surya";
const char* pwd="surya1827";
 
void setup()
{
  Serial.begin(9600);
  WiFi.disconnect();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid,pwd);

  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("WiFi Connected");
  Serial.println("IP Address: ");
  Serial.println(WiFi.localIP());
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:

}
