

void setup()
{
  pinMode(A1,INPUT);
  pinMode(3,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
	int val=analogRead(A1);
    int inp=map(val,0,1023,0,180);
  analogWrite(3,inp);
  
}
