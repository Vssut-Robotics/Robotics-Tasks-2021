int Motor = 8;
int BUTTON = 7;


void setup()
{
  pinMode(BUTTON, INPUT);
  pinMode(Motor, OUTPUT);
}

void loop()
{ 
  if(digitalRead(BUTTON) == 1) 
  { 
  	digitalWrite(Motor, HIGH);
  }
    if (digitalRead(BUTTON) == 0)
    {
      digitalWrite(Motor, LOW);
    }
  }

