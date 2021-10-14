int animationspeed = 0;
void setup()
{
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop()
{
  animationspeed = 2000;// Wait for 2000 millisecond(s)
   for(int i=3; i<8; i++)
    {
     digitalWrite(i, HIGH);
     delay(animationspeed); 
     digitalWrite(i, LOW);
     delay(animationspeed);
    }
   for(int i=8; i>3; i--)
    {
     digitalWrite(i, HIGH);
     delay(animationspeed); 
     digitalWrite(i, LOW);
     delay(animationspeed);
    }
}