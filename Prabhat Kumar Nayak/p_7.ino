int pinUp = 4;
int pinDown = 5;
int pinLeft = 6;
int pinRight = 7;
int pinButton = 8;

//Variables
int buttonState = 0;
int buttonCounter = 0;
int debugProgram = 1;


void setup() {
  Serial.begin(9600);
  pinMode(pinUp, OUTPUT);
  pinMode(pinDown, OUTPUT);
  pinMode(pinLeft, OUTPUT);
  pinMode(pinRight, OUTPUT);
  pinMode(pinButton, INPUT_PULLUP);
}


//Blink light functions
void blink_pinUp (int onDelay, int offDelay) {
  digitalWrite(pinUp, HIGH);
  delay(onDelay);
  digitalWrite(pinUp, LOW);
  delay(offDelay);
}

void blink_pinDown (int onDelay, int offDelay) {
  digitalWrite(pinDown, HIGH);
  delay(onDelay);
  digitalWrite(pinDown, LOW);
  delay(offDelay);
}

void blink_pinLeft (int onDelay, int offDelay) {
  digitalWrite(pinLeft, HIGH);
  delay(onDelay);
  digitalWrite(pinLeft, LOW);
  delay(offDelay);
}

void blink_pinRight (int onDelay, int offDelay) {
  digitalWrite(pinRight, HIGH);
  delay(onDelay);
  digitalWrite(pinRight, LOW);
  delay(offDelay);
}

// Lights on functions
void on_pinUp () {
  digitalWrite(pinUp, HIGH);
  //delay(25);
}

void on_pinDown () {
  digitalWrite(pinDown, HIGH);
  //delay(25);
}

void on_pinLeft () {
  digitalWrite(pinLeft, HIGH);
 // delay(25);
}

void on_pinRight () {
  digitalWrite(pinRight, HIGH);
  //delay(25);
}

// Lights off functions
void off_pinUp () {
  digitalWrite(pinUp, LOW);
  //delay(25);
}

void off_pinDown () {
  digitalWrite(pinDown, LOW);
  //delay(25);
}

void off_pinLeft () {
  digitalWrite(pinLeft, LOW);
  //delay(25);
}

void off_pinRight () {
  digitalWrite(pinRight, LOW);
  //delay(25);
}

void all_on () {
  digitalWrite(pinUp, HIGH);
  digitalWrite(pinLeft, HIGH);
  digitalWrite(pinRight, HIGH);
  digitalWrite(pinDown, HIGH);
}

void all_off () {
  digitalWrite(pinUp, LOW);
  digitalWrite(pinLeft, LOW);
  digitalWrite(pinRight, LOW);
  digitalWrite(pinDown, LOW);
}


void konami_code(int onDelay, int offDelay) {



blink_pinUp(onDelay,offDelay);
blink_pinUp(onDelay,offDelay);
blink_pinDown(onDelay,offDelay);
blink_pinDown(onDelay,offDelay);
blink_pinLeft(onDelay,offDelay);
blink_pinRight(onDelay,offDelay);
blink_pinLeft(onDelay,offDelay);
blink_pinRight(onDelay,offDelay);

}

void lights_UDLR(int onDelay) {
on_pinUp();
on_pinDown();
delay(onDelay);
off_pinUp();
off_pinDown();
on_pinLeft();
on_pinRight();
delay(onDelay);
off_pinLeft();
off_pinRight();
}

void lights_alt_onoff(int onDelay) {
all_on();
delay(onDelay);
}





void loop() {             

//Debug

if (debugProgram == 1) {
//Serial.println("Debugging Traffic Light Program");
Serial.print("Button Counter:");
Serial.println(buttonCounter);
}


//End Debug

  //Read button state (pressed or not pressed?)
  buttonState = digitalRead(pinButton);

  //If button pressed...
  if (buttonState == HIGH) { 
    if ( buttonCounter == 0) {
      konami_code(500,500);
      buttonCounter++; //next function
    }
    else if ( buttonCounter == 1) {
      lights_UDLR(2000);
      buttonCounter++; //next function
    }
        else if ( buttonCounter == 2) {
      lights_alt_onoff(1000);
      buttonCounter++; //next function
    }
        else if ( buttonCounter == 3) {
      all_on();
      buttonCounter++; //next function
    }
        else if ( buttonCounter == 4) {
      all_off();
      buttonCounter == 0;
       }
    }    
  }

