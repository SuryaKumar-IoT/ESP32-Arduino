/*
 * Relay Connections
 * 
 * Vcc - 3.3V
 * GND - GND
 * IN1,IN2,IN3,IN4= G23,G22,G21,G19
 * 
 * Control Device using Google Assistant
 * 
 * smart phone ->  cloud  <-  end device 
 * 
 * google assistant -> IFTTT ->  cloud  <- end device
 */
void setup() 
{
  pinMode(23,OUTPUT);
  pinMode(22,OUTPUT);
  pinMode(21,OUTPUT);
  pinMode(19,OUTPUT);
  digitalWrite(23,HIGH);
  digitalWrite(22,HIGH);
  digitalWrite(21,HIGH);
  digitalWrite(19,HIGH);

  Serial.begin(9600);
  Serial.println("");
  Serial.println("Load Control Using Serial");
  delay(500);
}

void loop()
{
  while(Serial.available()>0)
  {
    char ch= Serial.read();
    Serial.println("Received Char :"+String(ch));
    delay(50);
    if(ch=='A' || ch== 'a')
    {
      Serial.println("Light On");
      digitalWrite(23,LOW);
      digitalWrite(22,LOW);
      digitalWrite(21,LOW);
      digitalWrite(19,LOW);
    }
    else if(ch=='B' || ch=='b')
    {
      Serial.println("Light Off");
      digitalWrite(23,HIGH);
      digitalWrite(22,HIGH);
      digitalWrite(21,HIGH);
      digitalWrite(19,HIGH);
    }
    else
    {
      Serial.println("Incorrect Data");
    }
  }
}
