/* Program for Rotating a Servo Motor in response to change in intensity
of light*/
#include<Servo.h> // Include the servo library for Arduino
int lightval; // Declare a variable to store value from the LDR
int lightpin=A0; // Pin to Which LDR is connected
int tm=100; // Interval duration
int servopin=9; // Pin to which Servo is connected
Servo myservo; // Declaring object of servo
int angle; // Variable for angle
void setup() {
pinMode(lightpin,INPUT); // Setting LDR as INPUT
myservo.attach(servopin); // Attaching the servo to the pin 9
pinMode(servopin,OUTPUT); // Declaring servo as output
}
void loop() {
lightval=analogRead(lightpin); // Read the current value from LDR
delay(tm); // Give a delay of 100ms
angle= lightval/5; // Calculate the angle
myservo.write(angle); // Move the servo head to that angle
}
