int s1,s2,s3,s4,s5,s6;
#define LF 3
#define LB 5
#define RF 6
#define RB 9
void forward()
{
  analogWrite(LF,150);
  analogWrite(LB,0);
  analogWrite(RF,150);
  analogWrite(RB,0);
}

void right()
{
  analogWrite(LF,100);
  analogWrite(LB,0);
  analogWrite(RF,0);
  analogWrite(RB,0);
}
void left()
{                                     
  analogWrite(LF,0);
  analogWrite(LB,0);
  analogWrite(RF,100);
  analogWrite(RB,0);
}
void sleft()
{
  analogWrite(LF,0);
  analogWrite(LB,0);
  analogWrite(RF,130);
  analogWrite(RB,0);
}
void sright()
{
  analogWrite(LF,130);
  analogWrite(LB,0);
  analogWrite(RF,0);
  analogWrite(RB,0);
}
void readsensor()
{
  
  
  s1=digitalRead(2);
  s2=digitalRead(4);
  s3=digitalRead(7);
  s4=digitalRead(8);
  s5=digitalRead(10);
  s6=digitalRead(11);
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
  readsensor();
if(s1==1 && s2==1 && s3==0 && s4==0 && s5==1 && s6==1)
{
  forward();
  
}
else if(s1==0 && s2==0 && s3==0 && s4==0 && s5==1 && s6==1)
{
  left();
}

else if(s1==1 && s2==1 && s3==0 && s4==0 && s5==0 && s6==0)
{
  readsensor();
  if(s1==1 && s2==1 && s3==0 && s4==0 && s5==1 && s6==1)
  {
    forward();
    readsensor();
if(s1==1 && s2==1 && s3==1 && s4==1 && s5==1 && s6==1)
  {
   analogWrite(LF,0);
  analogWrite(LB,0);
  analogWrite(RF,230);
  analogWrite(RB,0);
 
  }
  }
  else if(s1==1 && s2==1 && s3==1 && s4==1 && s5==1 && s6==1)
  {
   analogWrite(LF,200);
  analogWrite(LB,0);
  analogWrite(RF,0);
  analogWrite(RB,0);
 
  }
  else if(s1==1 && s2==1 && s3==0 && s4==0 && s5==0 && s6==0)
  right();
}
else if(s1==0 && s2==0 && s3==0 && s4==0 && s5==0 && s6==0)
{ 
analogWrite(LF,0);
  analogWrite(LB,0);
  analogWrite(RF,235);
  analogWrite(RB,0);
  delay(400);
//  readsensor();
//  if(s1==1 && s2==1 && s3==0 && s4==0 && s5==1 && s6==1)
//  {
//    left();
//  }
//  else if(s1==1 && s2==1 && s3==1 && s4==1 && s5==1 && s6==1)
//  {
//    left();
//  }
 
}

else if(s1==1 && s2==0 && s3==0 && s4==1 && s5==1 && s6==1)
{
  sleft();
}
else if(s1==1 && s2==1 && s3==1 && s4==0 && s5==0 && s6==1)
{
  sright();
}
else if(s1==0 && s2==0 && s3==1 && s4==1 && s5==1 && s6==1)
{
  sleft();
 
}
else if(s1==1 && s2==1 && s3==1 && s4==1 && s5==0 && s6==0)
{
   sright();
   
}
else if(s1==0 && s2==1 && s3==1 && s4==1 && s5==1 && s6==1)
{
  left();
 
}
else if(s1==1 && s2==1 && s3==1 && s4==1 && s5==1 && s6==0)
{
   right();
   
}
}
