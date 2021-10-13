#include<Servo.h>
int r,angle;
Servo myservo;

void setup()
{
  pinMode(6, OUTPUT);
  pinMode(A0,INPUT);
  myservo.attach(6);
}

void loop()
{
  r=analogRead(A0);
  delay(100);
  myservo.write(r);
}