#define LF 3
#define LB 5
#define RF 6
#define RB 9

void forward()
{
  analogWrite(LF,120);
  analogWrite(LB,0);
  analogWrite(RF,120);
  analogWrite(RB,0);
 
}
void pause()
{
  analogWrite(LF,0);
  analogWrite(LB,0);
  analogWrite(RF,0);
  analogWrite(RB,0);
}
void right()
{
  analogWrite(LF,120);
  analogWrite(LB,0);
  analogWrite(RF,0);
  analogWrite(RB,0);
}
void left()
{                                     
  analogWrite(LF,0);
  analogWrite(LB,0);
  analogWrite(RF,120);
  analogWrite(RB,0);
}
void sright()
{
  analogWrite(LF,80);
  analogWrite(LB,0);
  analogWrite(RF,0);
  analogWrite(RB,0);
}
void sleft()
{
  analogWrite(LF,0);
  analogWrite(LB,0);
  analogWrite(RF,80);
  analogWrite(RB,0);
}
void hardleft()
{
  analogWrite(LF,0);
  analogWrite(LB,0);
  analogWrite(RF,60);
  analogWrite(RB,0);
}
void hardright()
{
  analogWrite(LF,60);
  analogWrite(LB,0);
  analogWrite(RF,0);
  analogWrite(RB,0);
}
void setup() 
{
 Serial.begin(9600);
 pinMode(LF,OUTPUT);
 pinMode(LB,OUTPUT);
 pinMode(RF,OUTPUT);
 pinMode(RB,OUTPUT);
 pinMode(2,INPUT);
 pinMode(4,INPUT);
 pinMode(7,INPUT);
 pinMode(8,INPUT);
 pinMode(10,INPUT);
 pinMode(11,INPUT);
 
}

void loop()
{
  int s1,s2,s3,s4,s5,s6;
  s1=digitalRead(2);
  s2=digitalRead(4);
  s3=digitalRead(7);
  s4=digitalRead(8);
  s5=digitalRead(10);
  s6=digitalRead(11);

  if(s1==1 && s2==1 && s3==0 && s4==0 && s5==1 && s6==1)
  {
    forward();
  }
  else if(s1==0 && s2==0 && s3==0 && s4==0 &&  s5==0 && s6==0)
 {
  forward();
  delay(200);
 }
  else if(s1==1 && s2==1 && s3==0 && s4==0 && s5==0 && s6==0)
  {
    right();
  }
  else if(s1==0 && s2==0 && s3==0 && s4==0 && s5==1 && s6==1)
  {
    left();
  }
  else if(s1==1 && s2==1 && s3==1 && s4==0 && s5==0 &&s6==1)
  {
    sright();
  }
  else if(s1==1 && s2==0 && s3==0 && s4==1 && s5==1 && s6==1)
  {
    sleft();
  }
   else if(s1==1 && s2==1 && s3==1 && s4==1 && s5==0 &&s6==0)
  {
    sright();
  }
  else if(s1==0 && s2==0 && s3==1 && s4==1 && s5==1 && s6==1)
  {
    sleft();
  }
  else if(s1==1 && s2==0 && s3==0 && s4==0 && s5==0 && s6==0)
  {
    hardright();
  }
  else if(s1==0 && s2==0 && s3==0 && s4==0 && s5==0 && s6==1)
  {
    hardleft();
  }
}
