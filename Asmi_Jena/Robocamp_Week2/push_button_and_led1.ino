void setup()
{
  Serial.begin (9600);
  pinMode(2,INPUT);
  pinMode(7,OUTPUT);
}

void loop()
{
  if(digitalRead(2)== 1)
  
    digitalWrite(7,HIGH);
  if (digitalRead(2)==0)
    digitalWrite (7,LOW);
    
  
}