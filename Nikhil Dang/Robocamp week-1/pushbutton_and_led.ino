// C++ code
//
int state=0;
void setup()
{
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
  
}

void loop()
{
  bool value=digitalRead(2);
  if(value==HIGH)
  {state=1-state;
   digitalWrite(3,state);
   value=LOW;
   delay(100);
  }
  
  
    
 

}
