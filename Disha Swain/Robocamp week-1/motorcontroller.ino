int button1=3;
int button2=2;
void setup()
{
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
}
void loop()
{
  if (digitalRead(button1)==1)
  {
    digitalWrite(10,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
  }
  
  if (digitalRead(button2)==1)
    {
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
  }
  
}
