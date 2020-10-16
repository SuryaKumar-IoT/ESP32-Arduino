char temp[20];
int i=0;
void setup() 
{
  Serial.begin(9600);
  Serial.println("Password Comparision");
  delay(1000);
}

void loop()
{
  Serial.println("Enter Password:");
  begin:
    if(Serial.available()>0)
      goto xx;
    else
      goto begin;
  xx:
  while(Serial.available()>0)
  {
    char ch=Serial.read();
    delay(100);
    if(ch!='#')
    {
      temp[i]=ch;
      i++;
    }
    else
    {
      temp[i]='\0';
      i=0;
      Serial.print("Password Entered :");
      Serial.println(temp);
      if(!strcmp(temp,"surya"))
      {
        Serial.println("Password Matched");
        delay(1000);
      }
      else
        Serial.println("Not Matched");
    }
  }
}
