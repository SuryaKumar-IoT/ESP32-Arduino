void setup() 
{
  Serial.begin(9600);
  Serial.println("Password Comparision");
  delay(1000);
}

void loop()
{
  while(Serial.available()>0)
  {
    String ch=Serial.readString();
    Serial.print(ch);
    delay(100);
    ch.trim();
    if(ch=="surya")
    {
      Serial.println("Matched");
      delay(1000);
    }
    else
      Serial.println("Not Matched");
      
  }
}
