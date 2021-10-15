// C++ code
//
int trig =3;
int echo = 2;
int led1 = 13;
int led2 = 12;
int led3 =11;
int led4 = 10;
int led5 = 9;
int led6 = 8;
int led7 = 7;
int led8 = 6;
int led9 = 5;
int led10 = 4;


void setup(){ 
  
  pinMode(3, OUTPUT);
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  
  long duration, distance;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(20);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration*0.034/2;

  if (distance >= 0)
  {
    digitalWrite(led1, HIGH);
  }
  else
  {
    digitalWrite(led1, LOW);
  }

  if (distance >= 40)
  {
    digitalWrite(led2, HIGH);
  }
  else
  {
    digitalWrite(led2, LOW);
  }

  if (distance >= 60)
  {
    digitalWrite(led3, HIGH);
  }
  else
  {
    digitalWrite(led3, LOW);
  }

  if (distance >= 80)
  {
    digitalWrite(led4, HIGH);
  }
  else
  {
    digitalWrite(led4, LOW);
  }

  if (distance >= 100)
  {
    digitalWrite(led5, HIGH);
  }
  else
  {
    digitalWrite(led5, LOW);
  }

  if (distance >= 120)
  {
    digitalWrite(led6, HIGH);
  }
  else
  {
    digitalWrite(led6, LOW);
  }

  if (distance >= 140)
  {
    digitalWrite(led7, HIGH);
  }
  else
  {
    digitalWrite(led7, LOW);
  }

  if (distance >= 160)
  {
    digitalWrite(led8, HIGH);
  }
  else
  {
    digitalWrite(led8, LOW);
  }

  if (distance >= 180)
  {
    digitalWrite(led9, HIGH);
  }
  else
  {
    digitalWrite(led9, LOW);
  }

  if (distance >= 200)
  {
    digitalWrite(led10, HIGH);
  }
  else
  {
    digitalWrite(led10, LOW);
  }

}