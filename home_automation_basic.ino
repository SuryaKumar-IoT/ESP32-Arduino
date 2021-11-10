void setup()
{
  pinMode(D8,OUTPUT);
  Serial.begin(115200);
  Serial.println();
  Serial.println("Basic Home Automation");
  delay(1000);
}

void loop() 
{
  while(Serial.available()>0)
  {
    String ch=Serial.readString();
    Serial.print(ch);
    delay(100);
    if(ch=="on")
    {
      Serial.println("Light ON");
      digitalWrite(D8,HIGH);
    }
    else if(ch=="off")
    {
      Serial.println("Light Off");
      digitalWrite(D8,LOW);
    }
  }
}
