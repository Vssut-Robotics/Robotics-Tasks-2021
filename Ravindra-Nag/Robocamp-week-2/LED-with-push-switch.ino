void setup(){
  pinMode(7,INPUT);
  pinMode(3,OUTPUT);
}

void loop(){
  int signal=digitalRead(7);
  digitalWrite(3,signal);
}