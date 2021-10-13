// C++ code
//
int motorPin1 = 5;
int motorPin2 = 6;
int motorPin3 = 9;
int motorPin4 = 10;
int buttonC = 11;
int buttonAC = 12;


void setup()
{
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(buttonC, INPUT);
  pinMode(buttonAC, INPUT);
}

void loop()
{
  
  // Anti-Clockwise button
  if( digitalRead(buttonAC) == HIGH){
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
  }
  // Clockwise button
  if( digitalRead(buttonC) == HIGH){
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
  }
}