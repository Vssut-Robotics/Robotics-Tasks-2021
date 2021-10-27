int LED01  = 1;
int LED02  = 2;
int LED03  = 3;
int LED04  = 4;
int LED05  = 5;
int LED06  = 6;
int LED07  = 7;
int LED08  = 8;
int LED09  = 9;
int LED10  = 10;

void setup(){
	pinMode(LED01, OUTPUT);
	pinMode(LED02, OUTPUT);
	pinMode(LED03, OUTPUT);
	pinMode(LED04, OUTPUT);
	pinMode(LED05, OUTPUT);
	pinMode(LED06, OUTPUT);
	pinMode(LED07, OUTPUT);
	pinMode(LED08, OUTPUT);
	pinMode(LED09, OUTPUT);
	pinMode(LED10, OUTPUT);
}

void loop(){
	digitalWrite(LED01, HIGH);
	delay(250);

	digitalWrite(LED01, LOW);
	delay(100);
	digitalWrite(LED02, HIGH);
	delay(250);
	
	digitalWrite(LED02, LOW);
	delay(100);
	digitalWrite(LED03, HIGH);
	delay(250);

	digitalWrite(LED03, LOW);
	delay(100);
	digitalWrite(LED04, HIGH);
	delay(250);

	digitalWrite(LED04, LOW);
	delay(100);
	digitalWrite(LED05, HIGH);
	delay(250);

	digitalWrite(LED05, LOW);
	delay(100);
	digitalWrite(LED06, HIGH);
	delay(250);

	digitalWrite(LED06, LOW);
	delay(100);
	digitalWrite(LED07, HIGH);
	delay(250);

	digitalWrite(LED07, LOW);
	delay(100);
	digitalWrite(LED08, HIGH);
	delay(250);

	digitalWrite(LED08, LOW);
	delay(100);
	digitalWrite(LED09, HIGH);
	delay(250);

	digitalWrite(LED09, LOW);
	delay(100);
	digitalWrite(LED10, HIGH);
	delay(250);

	digitalWrite(LED10, LOW);
	delay(100);
}