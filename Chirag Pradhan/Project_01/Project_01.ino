#include "thingProperties.h"

void setup() {
  Serial.begin(9600);
  delay(1500);
  initProperties();

  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  ArduinoCloud.update();


}

void onBloodyLogicChange() {
  if (bloodyLogic == true)
  {
    Serial.println("Preparing Bloody Logic");
    Serial.println("Preparing Digital Martini");
    digitalWrite(LED_BUILTIN, HIGH);
    pumpOn(2, 2);
    pumpOn(3, 2);
    pumpOn(5, 1);
    Serial.println("Bloody Logic Ready!");
    digitalWrite(LED_BUILTIN, LOW);
  }

}


void onDigitalMartiniChange() {
  if (digitalMartini == true)
  {
    Serial.println("Preparing Digital Martini");
    digitalWrite(LED_BUILTIN, HIGH); 
    delay(1000); 
    pumpOn(3, 1);
    pumpOn(4, 3);
    pumpOn(2, 1);
    Serial.println("Digital Martini Ready!");
    digitalWrite(LED_BUILTIN, LOW);
  }
}


void onRobot75Change() {
  if (robot75 == true)
  {
    Serial.println("Preparing Robot 75");
    digitalWrite(LED_BUILTIN, HIGH); 
    delay(1000); 
    pumpOn(5, 3);
    pumpOn(2, 1);
    pumpOn(4, 1);
    Serial.println("Robot 75 Ready!");
    digitalWrite(LED_BUILTIN, LOW);
  }
}


void onRobotOnTheBeachChange() {
  if (robotOnTheBeach == true)
  {
    Serial.println("Preparing Robot on the Beach");
    digitalWrite(LED_BUILTIN, HIGH); 
    delay(1000); 
    pumpOn(5, 2);
    pumpOn(2, 1);
    pumpOn(3, 1);
    pumpOn(4, 1);
    Serial.println("Robot on the Beach Ready!");
    digitalWrite(LED_BUILTIN, LOW);
  }
}


void onCyberPunchChange() {
  if (cyberPunch == true)
  {
    Serial.println("Preparing Cyber Punch");
    digitalWrite(LED_BUILTIN, HIGH); 
    delay(1000); 
    pumpOn(2, 1);
    pumpOn(4, 2);
    pumpOn(3, 1);
    pumpOn(2, 2);
    Serial.println("Cyber Punch Ready!");
    digitalWrite(LED_BUILTIN, LOW); 
  }
}

void pumpOn(int duration, int pin)
{
  Serial.println("");
  digitalWrite(pin, HIGH);
  Serial.print("Turning On Pump - ");
  Serial.print(pin);
  Serial.print(" For ");
  Serial.print(duration);
  Serial.println("Seconds");
  Serial.println("");
  
  delay(duration);
  digitalWrite(2, LOW);
  delay(1000);
}
