int ledPin = 2;
//The following values will be recalculated.
int maxValLeft = 1000;
int thresholdLeft = 500;
int maxValRight = 1000;
int thresholdRight = 500;

int MAX_PWM_A = 250;
int MAX_PWM_B = 240;

// Motor pins
int AIN_1 = 3;
int AIN_2 = 4;
int BIN_1 = 5;
int BIN_2 = 6;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  //Set the threshold for the lightsensor according to the current environment.
  maxValLeft = analogRead(A4);
  thresholdLeft = maxValLeft - 40;
  maxValRight = analogRead(A5);
  thresholdRight = maxValRight - 40;
  // Set the motor pins to output
  pinMode(AIN_1, OUTPUT);
  pinMode(AIN_2, OUTPUT);
  pinMode(BIN_1, OUTPUT);
  pinMode(BIN_2, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
//  go_backward(3000);
//  dont_move(6000);
//  turn_left(3000);
//  go_forward(3000);
//  turn_right(3000);
  // read the input on analog pins:
  int sensorValueLeft = analogRead(A4);
  int sensorValueRight = analogRead(A5);
  // print out the value you read:
  Serial.print(sensorValueLeft);
  Serial.print("-----");
  Serial.println(sensorValueRight);
  if (sensorValueLeft < thresholdLeft && sensorValueRight < thresholdRight)
  {
    turn_right(1000);
  } else if (sensorValueLeft < thresholdLeft) {
    turn_right(1000);  
  } else if (sensorValueRight < thresholdRight) {
    turn_left(1000);
  } else {
    go_forward(100);
  }
}

void go_forward(int duration) {
  analogWrite(AIN_1, MAX_PWM_A);
  digitalWrite(AIN_2, LOW);
  analogWrite(BIN_1, MAX_PWM_B);
  digitalWrite(BIN_2, LOW);
  delay(duration);
}

void go_backward(int duration) {
  analogWrite(AIN_1, LOW);
  digitalWrite(AIN_2, MAX_PWM_A);
  analogWrite(BIN_1, LOW);
  digitalWrite(BIN_2, MAX_PWM_B);
  delay(duration);
}

void turn_left(int duration) {
  analogWrite(AIN_1, LOW);
  digitalWrite(AIN_2, LOW);
  analogWrite(BIN_1, MAX_PWM_B);
  digitalWrite(BIN_2, LOW);
  delay(duration);
}

void turn_right(int duration) {
  analogWrite(AIN_1, MAX_PWM_A);
  digitalWrite(AIN_2, LOW);
  analogWrite(BIN_1, LOW);
  digitalWrite(BIN_2, LOW);
  delay(duration);
}

void dont_move(int duration) {
  analogWrite(AIN_1, 0);
  digitalWrite(AIN_2, 0);
  analogWrite(BIN_1, 0);
  digitalWrite(BIN_2, 0);
  delay(duration);
}
