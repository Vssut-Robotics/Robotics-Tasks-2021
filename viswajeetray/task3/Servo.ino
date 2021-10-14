// C+ Code
//
#include<Servo.h> 
int r,angle ;
Servo myservo;


void setup()
{
  pinMode(9, OUTPUT);
  pinMode(A0, INPUT);
  myservo.attach(9);
}



void loop()
{
  myservo.write(15);
  delay(1000);
  myservo.write(180);
  delay(1000);
}
