 //Motor A
const int motorPin1 = 5; 
const int motorPin2 = 6; 
//Motor B
const int motorPin3 = 10; 
const int motorPin4 = 9;
//buttons
const int button1 = 11;
const int button2 = 12;
int buttonstate1 = 0;
int buttonstate2 = 0;
void setup(){
// Setting all Motors Pins as Output and buttons as input
pinMode(button1 , INPUT);
pinMode(button2 , INPUT);
pinMode(motorPin1, OUTPUT);
pinMode(motorPin2, OUTPUT);
pinMode(motorPin3, OUTPUT);
pinMode(motorPin4, OUTPUT);
}
void loop()
{
  buttonstate1 = digitalRead(button1);
  buttonstate2 = digitalRead(button2);
  if ((buttonstate1 == HIGH) && (buttonstate2 == LOW))
  {  
digitalWrite(motorPin1, HIGH);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, HIGH);
  }
if ((buttonstate1 == LOW)&&(buttonstate2 == HIGH))
  {
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, HIGH);
digitalWrite(motorPin3, HIGH);
digitalWrite(motorPin4, LOW); 
  }
  
}
    