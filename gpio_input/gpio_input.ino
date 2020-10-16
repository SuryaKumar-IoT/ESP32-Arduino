void setup() 
{
  pinMode(23,INPUT);
  Serial.begin(9600);
}

void loop() 
{
  Serial.println(digitalRead(23));
  delay(1000);
}
