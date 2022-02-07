int switch1=23;
int switch2=22;
void setup() 
{
  pinMode(switch1,INPUT);
  pinMode(switch2,INPUT);
  Serial.begin(9600);
}

void loop() 
{
  if(digitalRead(switch1)==0)
  {
    Serial.println("Button 1");
  }
  else if(digitalRead(switch2)==0)
  {
    Serial.println("Button 1");
  }
}
