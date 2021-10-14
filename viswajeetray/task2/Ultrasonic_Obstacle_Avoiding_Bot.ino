#include <Servo.h> //Servo motor library
#include <NewPing.h> //Ultrasonic sensor function library

int LeftForward = A1;// L293D control pins
int LeftBackward = A2;
int RightForward = A3;
int RightBackward = A4;

int trig_pin= 6; //sensor pins - analog input 1
int echo_pin= 7; //analog input 2
#define maximum_distance 200
int sp=250;// assingning the speed of motors

boolean goesForward = false;
int distance = 100;

NewPing sonar(trig_pin, echo_pin, maximum_distance); //NewPing setup of pins and maximum distance.

Servo myservo; //servo name

void setup(){
  pinMode(RightForward, OUTPUT);
  pinMode(LeftForward, OUTPUT);
  pinMode(LeftBackward, OUTPUT);
  pinMode(RightBackward, OUTPUT);
  myservo.attach(8); //servo pin
  myservo.write(90);
  delay(2000);
  distance = readPing();
  delay(100);
}

void loop(){
  int distanceRight = 0;
  int distanceLeft = 0;
   if (distance <= 10){
    moveStop(); // obstacle probably on the route forward, so stop
    delay(300);
    moveBackward();
    delay(400);
    moveStop();
    delay(300);
    distanceRight = lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(300);
    if (distance >= distanceLeft){
      turnRight(); // calculate in which direction the obstacle is more far
      moveStop();
    }
    else{
      turnLeft();
      moveStop();
    }
  }
  else{
    moveForward(); 
  }
    distance = readPing();
}

int lookLeft(){  
  myservo.write(50);
  delay(500);
  int distance = readPing();
  delay(100);
  myservo.write(115);
  return distance;
}

int lookRight(){
  myservo.write(170);
  delay(500);
  int distance = readPing();
  delay(100);
  myservo.write(115);
  return distance;
  delay(100);
}

int readPing(){ //reading the distance
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}

void moveStop(){
  analogWrite(RightForward, 0);
  analogWrite(LeftForward, 0);
  analogWrite(RightBackward, 0);
  analogWrite(LeftBackward, 0);
}

void moveForward(){
  if(!goesForward){
    goesForward=true;
    analogWrite(LeftForward, sp);
    analogWrite(RightForward, sp);
    analogWrite(LeftBackward, 0);
    analogWrite(RightBackward, 0); 
  }
}

void moveBackward(){
  goesForward=false;
  analogWrite(LeftBackward, 0);
  analogWrite(RightBackward, 0);
  analogWrite(LeftForward, sp);
  analogWrite(RightForward, sp);
}

void turnRight(){
  analogWrite(LeftForward, sp);
  analogWrite(RightBackward, sp);
  analogWrite(LeftBackward, 0);
  analogWrite(RightForward, 0);
  delay(500);
  analogWrite(LeftForward, sp);
  analogWrite(RightForward, sp);
  analogWrite(LeftBackward, 0);
  analogWrite(RightBackward, 0);
}

void turnLeft(){
  analogWrite(LeftBackward, sp);
  analogWrite(RightForward, sp);
  analogWrite(LeftForward, 0);
  analogWrite(RightBackward, 0);
  delay(500);
  analogWrite(LeftForward, sp);
  analogWrite(RightForward, sp);
  analogWrite(LeftBackward, 0);
  analogWrite(RightBackward, 0);
}
