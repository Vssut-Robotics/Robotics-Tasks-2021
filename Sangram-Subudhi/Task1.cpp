// C++ code
//
void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
   if(digitalRead(2)==1)
   {
     digitalWrite(13,HIGH);
   }
  else
  {
    digitalWrite(13,LOW);
  }
}