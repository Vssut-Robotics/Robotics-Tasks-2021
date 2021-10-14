// C++ code
//
int s,i,t;

void setup()
{
  pinMode(2, INPUT);
  for(i = 3;i <= 13;i++) pinMode(i, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(3,HIGH);
  delayMicroseconds(10);
  digitalWrite(3,LOW);
  
  t = pulseIn(2,HIGH);
  
  s = t * 0.017 / 10 + 3;

  for(i = 4;i <= s;i++) digitalWrite(i,HIGH);
  delay(1000);
  for(int i = 4;i <= 13;i++) digitalWrite(i,LOW);
}
