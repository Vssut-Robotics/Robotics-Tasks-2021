// Motor A
const int motorPin1  = 5;  
const int motorPin2  = 6;
//Motor B
const int motorPin3  = 10; 
const int motorPin4  = 11;  

const int buttonPin1 = 2; 
const int buttonPin2 = 13; 
 
void setup(){ 
// Setting all Motors Pins as Output
pinMode(motorPin1, OUTPUT);
pinMode(motorPin2, OUTPUT);
pinMode(motorPin3, OUTPUT);
pinMode(motorPin4, OUTPUT);
pinMode(buttonPin1, INPUT);
pinMode(buttonPin2, INPUT);

} 
void loop(){
  int buttonState1 = digitalRead(buttonPin1); 
  int buttonState2 = digitalRead(buttonPin2);

  if(buttonState1 == HIGH){
digitalWrite(motorPin1, HIGH);
digitalWrite(motorPin2, LOW);
digitalWrite(motorPin3, HIGH);
digitalWrite(motorPin4, LOW); 
  }
    if(buttonState2 == HIGH){
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, HIGH);
digitalWrite(motorPin3, LOW);
digitalWrite(motorPin4, HIGH); 
  }
  
}
