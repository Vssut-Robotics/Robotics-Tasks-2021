#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,10,9,8,7);
const int trigPin = 4;
const int echoPin = 3;
int buzz = 5;
long duration;
int distance;

void setup() {
  lcd.begin(16,2);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(13, OUTPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);

}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  
  if(distance>80){
    lcd.setCursor(0,0);
    lcd.print("You are safe!");
    lcd.setCursor(0,1);
    lcd.print("Dist. is ");
    lcd.print(distance);
    lcd.print("cm   ");
    delay(100);
  }

  if(distance <= 80 && distance >= 30)
  {
    lcd.setCursor(0,0);
    lcd.print("Warning!        ");
    lcd.setCursor(0,1);
    lcd.print("Dist. is ");
    lcd.print(distance);
    lcd.print("cm   ");
    delay(100);
    digitalWrite(13, HIGH);
  }
  
  else
  {
    digitalWrite(13, LOW); 
  }
  
  if(distance <= 30)
  {
    lcd.setCursor(0,0);
    lcd.print("Caution!        ");
    lcd.setCursor(0,1);
    lcd.print("Dist. is ");
    lcd.print(distance);
    lcd.print("cm   ");
    delay(100);
    digitalWrite(2, HIGH);
  tone(buzz, 2000);
  delay(100);
  noTone(buzz);
    delay(50);
  }
  
  else
  {
    digitalWrite(2, LOW); 
  }
 }
