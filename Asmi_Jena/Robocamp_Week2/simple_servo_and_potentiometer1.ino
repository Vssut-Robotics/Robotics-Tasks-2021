#include<Servo.h>

int sensorValue = 0;

int outputValue = 0;

Servo servo_4;

void setup()
{
  pinMode(A2, INPUT);
  servo_4.attach(4);
}

void loop()
{
  sensorValue = analogRead(A2);
  outputValue = map(sensorValue,0,1023,0,180);
  servo_4.write(outputValue);
  delay(10);
}