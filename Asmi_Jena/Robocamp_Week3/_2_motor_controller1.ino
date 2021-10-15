// C++ code
//
int i,a = 0,b = 0;
void setup()
{
  pinMode(6, INPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, INPUT);
  for(i = 1;i <= 4;i++) digitalWrite(i,LOW);
}

void loop()
{
  a = 0;
  while(a == 0 && b == 0){
  	a = digitalRead(6);
    b = digitalRead(5);
  }
  if(a == 1){
    digitalWrite(1,HIGH);
    digitalWrite(2,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(3,LOW);
    a = 0;
  }
  if(b == 1){
    digitalWrite(1,LOW);
    digitalWrite(2,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(3,HIGH);
    b = 0;
  }
}