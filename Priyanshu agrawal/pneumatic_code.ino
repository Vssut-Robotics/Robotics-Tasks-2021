int s1=2,s2=13,s3=7;
int k,p,n;
void setup()
{pinMode(2,OUTPUT);
pinMode(13,OUTPUT);
pinMode(7,OUTPUT);

  
}
void loop()
{
  p=random(2000);
  if(p%2==0)
  {digitalWrite(s1,HIGH);
  delay(350);
  digitalWrite(s1,LOW);
  delay(350);
  }
  k=random(2000);
  if(k%2==1)
  {digitalWrite(s2,HIGH);
  delay(350);
  digitalWrite(s2,LOW);
  delay(350);
  }
  n=random(2000);
  if(n%2==0)
  {
    digitalWrite(s3,HIGH);
  delay(350);
  digitalWrite(s3,LOW);
  delay(350);
  }
}
