#include <IRremote.h>
#include <Servo.h>
#include <SoftwareSerial.h>

//Standard
const unsigned long BAUD_RATE = 9600;
//DC Motor
int var_speed;
const int speedPinOne = 10; // Pin 9 on the IC
const int speedPinTwo = 9; // Pin 1 on the IC
const int m1PinOne = 7; // Pin 15 on the IC
const int m1PinTwo = 6; // Pin 10 on the IC
const int m2PinOne = 3; //Pin 2 on the IC
const int m2PinTwo = 4; // Pin 7 on the IC
//Servos
int left = 5; //Left 
int right = 11; //Right
Servo leftServo; //Servo on the left side of the car
Servo rightServo; //Servo on the right side of the car
//Ultrasonic
int echo = 12;
int trig = 8;
//IR Controls
int IR_RECEIVE_PIN = A0;
long lastPressTime = 0;
boolean chargeMode = true;
long dis = 25.0;
int dur = 5000;

void setup() {
  Serial.begin(BAUD_RATE);
  delay(100);
  
  //Servo Setup!
  leftServo.attach(left);
  rightServo.attach(right);

  for(int i = 0; i <= 13; i++){
    if(i != echo && i != 0){
      pinMode(i, OUTPUT);
    }
    else{
     pinMode(i, INPUT);
    }
  }
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  var_speed = 255;
}

void loop() {
  // put your main code here, to run repeatedly:
  idle();
  if (IrReceiver.decode()) {
    if(1){
      charge();
    }
      IrReceiver.printIRResultShort(&Serial);
      IrReceiver.resume(); // Continue receiving
  }
  
  
} 

void idle() {;
  turnRight();
  hornsUp();
  //Serial.println("Right");
}

void forward(){
  digitalWrite(speedPinOne, var_speed); //200 Is our test speed and default speed for both motors
  digitalWrite(speedPinTwo, var_speed);
  digitalWrite(m1PinOne, HIGH);
  digitalWrite(m1PinTwo, LOW);
  digitalWrite(m2PinOne, HIGH);
  digitalWrite(m2PinTwo, LOW);
}

void turnRight(){
  digitalWrite(speedPinOne, var_speed); //200 Is our test speed and default speed for both motors
  digitalWrite(speedPinTwo, var_speed);
  digitalWrite(m1PinOne, LOW); //15
  digitalWrite(m1PinTwo, HIGH);  //10
  digitalWrite(m2PinOne, HIGH); //2
  digitalWrite(m2PinTwo, LOW);  //7
  
}

void reverse(){
  digitalWrite(speedPinOne, var_speed); //200 Is our test speed and default speed for both motors
  digitalWrite(speedPinTwo, var_speed);
  digitalWrite(m1PinOne, LOW); //15
  digitalWrite(m1PinTwo, HIGH);  //10
  digitalWrite(m2PinOne, LOW); //2
  digitalWrite(m2PinTwo, HIGH);  //7
}

void pause(){
  digitalWrite(speedPinOne, LOW); //200 Is our test speed and default speed for both motors
  digitalWrite(speedPinTwo, LOW);
  digitalWrite(m1PinOne, LOW); //15
  digitalWrite(m1PinTwo, LOW);  //10
  digitalWrite(m2PinOne, LOW); //2
  digitalWrite(m2PinTwo, LOW);  //7
}

void hornsDown(){
  leftServo.write(120);
  rightServo.write(60);
}

void hornsUp(){
  leftServo.write(160);
  rightServo.write(20);
}

void charge(){
  pause();
  hornsDown();
  delay(2000);
  scream(dur);
  forward();
  while(true){
    if(ultraSonic(dis)){
      Serial.println("break");
      break;
    } 
  }
  reverse();
  delay(500);
  idle();
}

boolean ultraSonic(long dist){
  /*pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  long duration, inches;

  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);

  pinMode(echo,INPUT);
  //Sets reading pin
  duration = pulseIn(echo, HIGH);
  inches = microsecondsToInches(duration);
  
  if(inches <= distance){
    //beep();
    return true;
  }
  */
  long duration, distance;


  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration / 58.2;
  Serial.print("distance: ");
  Serial.println(distance);
  delay(100);

  if(distance <= dist){
    //beep();
    Serial.println("True");
    return true;
  }
  else{
    return false;
  }

  

  
}

long microsecondsToInches(long microseconds){
  return microseconds / 74 / 2;
}

void scream(int d){
  tone(13, 100, d);
  delay((rand()%500) + 3000);
}