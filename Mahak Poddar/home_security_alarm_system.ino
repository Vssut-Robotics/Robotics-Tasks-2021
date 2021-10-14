int LED1=12;
int GND1=13;
int LED2=8;
int GND2=9;
int pirOutput=5;
void setup()
{
  Serial.begin(9600);
  pinMode(LED1,OUTPUT);
  pinMode(GND1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(GND2,OUTPUT);
  pinMode(pirOutput,INPUT);
 
  digitalWrite(pirOutput,LOW);
  digitalWrite(GND1,LOW);
  digitalWrite(GND2,LOW);
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  delay(15000);
  digitalWrite(LED1,HIGH);
}
void loop()
{
  if(digitalRead(pirOutput)==HIGH)
  {
    digitalWrite(LED2,HIGH);
    Serial.println("OK");
    delay(1000);
    Serial.println("ATD+91xxxxxxxxxx;");//add target mobile number in place of xxxxxxxxxx
    delay(15000);
    Serial.println("ATH");
    digitalWrite(LED2,LOW);
    delay(1000);
  }
}
