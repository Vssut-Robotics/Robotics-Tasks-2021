int b = 0, w = 1, a = 0;
int c = 0;
int LF1 = 10, LB1 = 11, RF1 = 3, RB1 = 5;

void forward(int sp=80,float sf=1.08)
{
analogWrite(LF1,sp);
analogWrite(LB1,0);
analogWrite(RF1,sp*sf);
analogWrite(RB1,0);
}
void pause()
{
  analogWrite(LF1, 0);
  analogWrite(LB1, 0);
  analogWrite(RF1, 0);
  analogWrite(RB1, 0);
}
void right()
{
  analogWrite(LF1, 80);
  analogWrite(LB1, 0);
  analogWrite(RF1, 0);
  analogWrite(RB1, 0);
}
void slightleft()
{
  analogWrite(LF1, 0);
  analogWrite(LB1, 0);
  analogWrite(RF1, 80);
  analogWrite(RB1, 0);
  }
void left()
{
  analogWrite(LF1, 0);
  analogWrite(LB1, 80);
  analogWrite(RF1, 80);
  analogWrite(RB1, 0);
  }
void uturn()
{
  analogWrite(LF1, 80);
  analogWrite(LB1, 0);
  analogWrite(RF1, 0);
  analogWrite(RB1, 80);
}
void back(int sp=80,float sf=1.17)
{
analogWrite(LB1,sp);
analogWrite(LF1,0);
analogWrite(RB1,sp*sf);
analogWrite(RF1,0);
}
void hardright()
{
  analogWrite(LF1, 0);
  analogWrite(LB1, 80);
  analogWrite(RF1, 60);
  analogWrite(RB1, 0);
}

void setup()
{

  Serial.begin(9600);
  pinMode(LF1, OUTPUT);
  pinMode(LB1, OUTPUT);
  pinMode(RF1, OUTPUT);
  pinMode(RB1, OUTPUT);
  pinMode(2, INPUT);
  pinMode(4, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  pinMode(9, INPUT);
  pinMode(6, INPUT);

}

void loop()
{

  int d1, d2, d3, d4, d5, d6, d7, d8;
  d1 = digitalRead(13);
  d2 = digitalRead(12);
  d3 = digitalRead(8);
  d4 = digitalRead(7);
  d5 = digitalRead(4);
  d6 = digitalRead(2);
  d7 = digitalRead(9);
  d8 = digitalRead(6);
  Serial.print(d1);
  Serial.print(d2);
  Serial.print(d3);
  Serial.print(d4);
  Serial.print(d5);
  Serial.print(d6);
  Serial.print(d7);
  Serial.print(d8);
  Serial.print("\n");
 if (d1 == b && d2 == b && d3 == b && d4 == b && d5 == b && d6 == w && d7 == w && d8 == w||d1 == b && d2 == b && d3 == b && d4 == b && d5 == b && d6 == b && d7 == b && d8 == b)
  {
    left();
    delay(400);
  }
 
  else if (d1 == b && d2 == b && d3 == b && d4 == w && d5 == w && d6 == w && d7 == w && d8 == w||d1 == b && d2 == b && d3 == b && d4 == b && d5 == b && d6 == w && d7 == w && d8 == w || d1 == b && d2 == b && d3 == b && d4 == b && d5 == w && d6 == w && d7 == w && d8 == w)
  {
    slightleft();
    delay(400);
  }
  else if (d1 == b && d2 == b && d3 == b && d4 == b && d5 == b && d6 == b && d7 == w && d8 == w||d1 == b && d2 == b && d3 == b && d4 == b && d5 == b && d6 == b && d7 == b && d8 == w)
  {
    slightleft();
    delay(400);
  }
 
  else if (d1 == w && d2 == b && d3 == b && d4 == w && d5 == w && d6 == w && d7 == w && d8 == w||d1 == w && d2 == w && d3 == w && d4 == w && d5 == w && d6 == w && d7 == b&& d8 == w)
  {
    slightleft();
    delay(400);
  }

  else if (d1 == w && d2 == w && d3 == b && d4 == b && d5 == b && d6 == w && d7 == w&& d8 == w||d1 == w && d2 == w && d3 == w && d4 == b && d5 == b && d6 == b && d7 == b&& d8 == w)
  {
    slightleft();
    delay(400);
  }
 
  else if (d1 == w && d2 == w && d3 == b && d4 == b && d5 == w && d6 == w && d7 == w && d8 == w||d1 == b && d2 == b && d3 == w && d4 == w && d5 == w && d6 == w && d7 == w && d8 == w)
  {
    slightleft();
    delay(400);
  }
 
  else if (d1 == w && d2 == b && d3 == b && d4 == b && d5 == w && d6 == w && d7 == w && d8 == w)
  {
    slightleft();
    delay(400);
  }
  else if (d1 == w && d2 == b && d3 == b && d4 == b && d5 == b && d6 == b && d7 == w && d8 == w || d1 == b && d2 == b && d3 == b && d4 == b && d5 == b && d6 == b && d7 == w && d8 == w)
  {
    slightleft();
    delay(400);
  }
  else if(d1 == w && d2 == w && d3 == w && d4 == w && d5 == w && d6 == w && d7 == w && d8 == w)
  {
    uturn();
    delay(400);
    }
  else if (d1 == w && d2 == w && d3 == w && d4 == b && d5 == b && d6 == w && d7 == w && d8 == w)
  {
    forward();
  }
  else if (d1 == b && d2 == b && d3 == b && d4 == b && d5 == b && d6 == b && d7 == b && d8 == b)
  {
    forward();
    delay(300);
  }
   else if (d1 == w && d2 == w && d3 == b && d4 == b && d5 == b && d6 == b && d7 == w && d8 == w)
  {
    forward();
    delay(300);
  }
  else if (d1 == w && d2 == b && d3 == w && d4 == b && d5 == b && d6 == w && d7 == b && d8 == w)
  {
    forward();
    delay(300);
  }
  else if (d1 == b && d2 == w && d3 == w && d4 == b && d5 == b && d6 == w && d7 == w && d8 == b)
  {
    forward();
    delay(300);
  }

  else if (d1 == w && d2 == w && d3 == w && d4 == b && d5 == w && d6 == b && d7 == b && d8 == b)
  {
    right();
    delay(400);
  }
  else if (d1 == w && d2 == w && d3 == w && d4 == w && d5 == w && d6 == w && d7 == b && d8 == w)
  {
    right();
    delay(400);
  } 
  else if (d1 == w && d2 == w && d3 == w && d4 == w && d5 == b && d6 == b && d7 == b && d8 == b)
  {
    right();
    delay(400);
  }
  else if (d1 == w && d2 == w && d3 == w && d4 == b && d5 == b && d6 == b && d7 == b && d8 == b)
  {
    right();
    delay(400);
  }
  else if (d1 == w && d2 == w && d3 == w && d4 == w && d5 == b && d6 == b && d7 == w && d8 == w)
  {
    right();
    delay(400);
  }
  else if (d1 == w && d2 == w && d3 == b && d4 == b && d5 == b && d6 == b && d7 == b && d8 == b)
  {
    right();
    delay(400);
  }
  else if (d1 == w && d2 == b && d3 == b && d4 == b && d5 == b && d6 == b && d7 == b && d8 == b)
  {
    right();
    delay(400);
  }
  else if (d1 == w && d2 == w && d3 == w && d4 == w && d5 == w && d6 == b && d7 == b && d8 == w)
  {
    right();
    delay(400);
  }
  else if (d1 == w && d2 == w && d3 == w && d4 == w && d5 == b && d6 == b && d7 == w && d8 == w)
  {
    right();
    delay(400);
  }
  else if (d1 == w && d2 == w && d3 == w && d4 == w && d5 == w && d6 == w && d7 == b && d8 == b)
  {
    right();
    delay(400);
  }
  else if (d1 == w && d2 == w && d3 == w && d4 == w && d5 == b && d6 == b && d7 == b && d8 == w)
  {
    right();
    delay(400);
  }
   else if (d1 == w && d2 == w && d3 == w && d4 == w && d5 == b && d6 == w && d7 == b && d8 == w)
  {
    right();
    delay(400);
  }
 else if (d1 == w && d2 == b && d3 == b && d4 == b && d5 == b && d6 == b && d7 == w && d8 == w)
  {
    right();
    delay(400);
  }
 else if (d1 == w && d2 == b && d3 == b && d4 == b && d5 == b && d6 == w && d7 == w && d8 == w)
  {
    right();
    delay(400);
  }
}
}
