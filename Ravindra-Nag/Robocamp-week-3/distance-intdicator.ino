// C++ code
//
int trig=3;
int echo=2;
int one = 13;
int two = 12;
int three =11;
int four = 10;
int five = 9;
int six = 8;
int seven = 7;
int eight = 6;
int nine = 5;
int ten = 4;
int distance;
long duration;
int n;


void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
}

void loop()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  duration = pulseIn(echo, HIGH);
  distance = (duration * 0.034)/2;

  n=(distance/20)+4;
  for( int i=4;i<=n;i++){
    digitalWrite(i, HIGH);
  }
  for( int i=4;i<=n;i++){
    digitalWrite(i, LOW);
  }
  
}