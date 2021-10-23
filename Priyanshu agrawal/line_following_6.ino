void setup() {
  Serial.begin(9600);
  
  pinMode(2,INPUT);
  pinMode(4,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(12,INPUT);
  pinMode(13,INPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
}

int s1,s2,s3,s4,s5,s6;
int L1=3;
int L2=5;
int R1=6;
int R2=9;
void forword()
{
  analogWrite(L1,100);
  analogWrite(L2,0);
  analogWrite(R1,100);
  analogWrite(R2,0);
  
}
void slightleft()
{
  analogWrite(L1,0);
  analogWrite(L2,0);
  analogWrite(R1,90);
  analogWrite(R2,0);
}
void slightright()
{
  analogWrite(L1,90);
  analogWrite(L2,0);
  analogWrite(R1,0);
  analogWrite(R2,0);
}
void sharpright()
{
  analogWrite(L1,120);
  analogWrite(L2,0);
  analogWrite(R1,0);
  analogWrite(R2,0);
}
void sharpleft()
{
  analogWrite(L1,0);
  analogWrite(L2,0);
  analogWrite(R1,120);
  analogWrite(R2,0);
}

void loop() {
s1=digitalRead(2);
s2=digitalRead(4);
s3=digitalRead(7);
s4=digitalRead(8);
s5=digitalRead(12);
s6=digitalRead(13);

if(s1==1&&s2==1&&s3==0&&s4==0&&s5==1&&s6==1)
{
  forword();
  
}
else if(s1==1&&s2==1&&s3==1&&s4==0&&s5==0&&s6==1)
{
  slightright();
}
else if(s1==1&&s2==0&&s3==0&&s4==1&&s5==1&&s6==1)
{
  slightleft();
}
else if(s1==1&&s2==1&&s3==0&&s4==0&&s5==0&&s6==0)
{
  sharpright();
  
}
else if(s1==0&&s2==0&&s3==0&&s4==0&&s5==1&&s6==1)
{
  sharpleft();
}
else if(s1==0&&s2==0&&s3==1&&s4==1&&s5==1&&s6==1)
{
  slightleft();
}
else if(s1==1&&s2==1&&s3==1&&s4==1&&s5==0&&s6==0)
{
  slightright();
}
else if(s1==1&&s2==1&&s3==1&&s4==0&&s5==0&&s6==0)
{
  slightright();
}
else if(s1==0&&s2==0&&s3==0&&s4==1&&s5==1&&s6==1)
 {
  slightleft();
 }
 if(s1==0&&s2==0&&s3==0&&s4==0&&s5==0&&s6==0)
 {
 forword();
 }
 if(s1==1&&s2==0&&s3==0&&s4==0&&s5==0&&s6==1)
 {
  forword();
 }

}
