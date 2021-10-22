int led=9;
int vib=8;
int vibval;
void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
pinMode(vib,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
vibval=digitalRead(vib);
Serial.println(vibval);
if(vibval==0){
  digitalWrite(led,HIGH);
  delay(4000);
}
if(vibval==1){
  digitalWrite(led,LOW);
}
}
