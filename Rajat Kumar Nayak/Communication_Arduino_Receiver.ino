#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";
boolean button_state = 0;
int led_pin = 3;
void setup() {
	pinMode(6, OUTPUT);
	Serial.begin(9600);
	radio.begin();
	radio.openReadingPipe(0, address);   //Setting the address at which we will receive the data
	radio.setPALevel(RF24_PA_MIN);       //Set Power Amplifier (PA) level to one of four levels.
	radio.startListening();              //This sets the module as receiver
}
void loop()
{
	if (radio.available())              //Looking for the data.
	{
		radio.read(&button_state, sizeof(button_state));    //Reading the data
	if(button_state == HIGH)
	{
		digitalWrite(6, HIGH);
	}
	else
	{
		digitalWrite(6, LOW);
	}
	delay(5);
}
