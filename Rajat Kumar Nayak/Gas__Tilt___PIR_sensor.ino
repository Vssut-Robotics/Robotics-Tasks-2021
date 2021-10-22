const int buzz=6;  
const int pir_out=7;  //PIR OUT SIGNAL
const int temp=A0;
const int gas=A1;
const int red_led=8;      
const int green_led=10;
const int sensorThres = 120;
const int motorPin = 2;
int switchState = 0;
void setup()
{
   pinMode(pir_out,INPUT);
   pinMode(temp,INPUT);
   pinMode(gas,INPUT);
   pinMode(motorPin, OUTPUT);
   pinMode(red_led,INPUT);   
   pinMode(green_led,INPUT);
   Serial.begin(9600);
   digitalWrite(green_led,LOW);
   digitalWrite(red_led,LOW);
}   
void loop()
{
    int gas_response=analogRead(gas);
    int temp_response=analogRead(temp);

    /*TEMPERATURE  AND GAS SENSOR*/
    
    if((temp_response>318)|| (gas_response>sensorThres))
    {
        digitalWrite(red_led,HIGH);
        digitalWrite(green_led,LOW);
        tone(6,200);
        delay(500);
        noTone(11);
        delay(500);
    }
    else if ((temp_response>(287) & temp_response<318)|| (gas_response<sensorThres))
    {
        digitalWrite(green_led,HIGH);
        digitalWrite(red_led,LOW);
    }
    /*PIR SENSOR*/
    switchState = digitalRead(pir_out);
  
    if (switchState == HIGH) {
        digitalWrite(motorPin, LOW);
        digitalWrite(red_led,HIGH);
        digitalWrite(green_led,LOW);
        tone(6,200);
        delay(500);
        noTone(11);
        delay(500);
    }
    else {
        digitalWrite(motorPin, HIGH);
        digitalWrite(green_led,HIGH);
        digitalWrite(red_led,LOW);
    }
}
