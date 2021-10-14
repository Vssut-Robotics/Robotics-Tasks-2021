int state1 = 0;
int state2 = 0;
int dc1 = 5;
int dc2 = 6;
int push = 7;
int push2 = 4;

void setup()
{
  pinmode (dc1,OUTPUT);
  pinmode (dc2,OUTPUT);
  pinmode (push1,Input);
  pinmode (push2,Input);
 }
void loop ()
{ 
  state1 = digitalRead (push1);
  state2 = digitalRead (push2);  
  if (state1 = = HIGH);
  {
    digitalwrite (dc1,HIGH);
    digitalwrite (dc2,LOW);
  }
  else
  {
    digitalwrite (dc1,LOW);
    digitalwrite (dc2,LOW);
  } 
  if (state2 = = HIGH);
  {
    digitalwrite (dc1,LOW);
    digitalwrite (dc2,HIGH);
  }
  else
  {
    digitalwrite (dc1,LOW);
    digitalwrite (dc2,LOW);
}
