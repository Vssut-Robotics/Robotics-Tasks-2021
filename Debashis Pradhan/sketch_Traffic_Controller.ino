/*
  4-Way Traffic Controller 
  Taffic Signal1(Red, Yellow, Green) = {2, 3, 4}
  Taffic Signal2(Red, Yellow, Green) = {5, 6, 7}
  Taffic Signal3(Red, Yellow, Green) = {8, 9, 10}
  Taffic Signal4(Red, Yellow, Green) = {11, 12, 13}
*/
int signal1[] = {2, 3, 4};
int signal2[] = {5, 6, 7};
int signal3[] = {8, 9, 10};
int signal4[] = {11, 12, 13};

int redDelay = 10000;
int yellowDelay = 2500;

void setup() 
{
  // Declaring all the LED's as output
  for (int i = 0; i < 3; i++)
  {
    pinMode(signal1[i], OUTPUT);
    pinMode(signal2[i], OUTPUT);
    pinMode(signal3[i], OUTPUT);
    pinMode(signal4[i], OUTPUT);
  }
}

void loop() 
{
  // Making Green at signal 1 and Red at other signals for 10 seconds
  digitalWrite(signal1[0], LOW);
  digitalWrite(signal1[2], HIGH);
  digitalWrite(signal2[0], HIGH);
  digitalWrite(signal3[0], HIGH);
  digitalWrite(signal4[0], HIGH);
  delay(redDelay);

  // Making Yellow at signal 1 & signal 2 and Red at other signals remain as it is for 2.5 seconds
  digitalWrite(signal1[1], HIGH);
  digitalWrite(signal1[2], LOW);
  digitalWrite(signal2[1], HIGH);
  digitalWrite(signal2[0], LOW);
  delay(yellowDelay);
  digitalWrite(signal1[1], LOW);
  digitalWrite(signal2[1], LOW);

  // Making Green at signal 2 and Red at other signals for 10 seconds
  digitalWrite(signal1[0], HIGH);
  digitalWrite(signal2[0], LOW);
  digitalWrite(signal2[2], HIGH);
  digitalWrite(signal3[0], HIGH);
  digitalWrite(signal4[0], HIGH);
  delay(redDelay);

  // Making Yellow at signal 2 & signal 3 and Red at other signals remain as it is for 2.5 seconds
  digitalWrite(signal2[1], HIGH);
  digitalWrite(signal2[2], LOW);
  digitalWrite(signal3[1], HIGH);
  digitalWrite(signal3[0], LOW);
  delay(yellowDelay);
  digitalWrite(signal2[1], LOW);
  digitalWrite(signal3[1], LOW);

  // Making Green at signal 3 and Red at other signals for 10 seconds
  digitalWrite(signal1[0], HIGH);
  digitalWrite(signal2[0], HIGH);
  digitalWrite(signal3[0], LOW);
  digitalWrite(signal3[2], HIGH);
  digitalWrite(signal4[0], HIGH);
  delay(redDelay);

  // Making Yellow at signal 3 & signal 4 and Red at other signals remain as it is for 2.5 seconds
  digitalWrite(signal3[1], HIGH);
  digitalWrite(signal3[2], LOW);
  digitalWrite(signal4[1], HIGH);
  digitalWrite(signal4[0], LOW);
  delay(yellowDelay);
  digitalWrite(signal3[1], LOW);
  digitalWrite(signal4[1], LOW);

  // Making Green at signal 4 and Red at other signals for 10 seconds
  digitalWrite(signal1[0], HIGH);
  digitalWrite(signal2[0], HIGH);
  digitalWrite(signal3[0], HIGH);
  digitalWrite(signal4[0], LOW);
  digitalWrite(signal4[2], HIGH);
  delay(redDelay);

  // Making Yellow at signal 4 & signal 1 and Red at other signals remain as it is for 2.5 seconds
  digitalWrite(signal4[1], HIGH);
  digitalWrite(signal4[2], LOW);
  digitalWrite(signal1[1], HIGH);
  digitalWrite(signal1[0], LOW);
  delay(yellowDelay);
  digitalWrite(signal4[1], LOW);
  digitalWrite(signal1[1], LOW);
}
