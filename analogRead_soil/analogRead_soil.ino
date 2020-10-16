/* 12 Bit Resolution */
void setup()
{
  Serial.begin(115200);
}

void loop() 
{
  int soil=map(analogRead(32),0,4095,100,0);
  Serial.print("Soil Moisture Value(%):");
  Serial.println(soil);
  delay(1000);
}
