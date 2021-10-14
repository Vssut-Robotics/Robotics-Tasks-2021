//initializing and declaring led columns
  int column[16]={13,12,11,10,9,8,7,6,5,4,3,2,1,0,A5,A4};
//initializing and declaring led rows
  int row[4]={A3,A2,A1,A0};
 void setup()
{
 //setting columns to ouput
  for(int i = 0; i<16; i++)
  {
    pinMode(column[i], OUTPUT);
  }
  //setting rows to output
  for(int i = 0; i<4; i++)
  {
    pinMode(row[i], OUTPUT);
  }
}
void loop()
{
  blinkingfullcube();
  rowwiseblink();
  columnwiseblink();
  propeller();
  delay(2000);
}
//********functions*********
//for turn all LED cube off
void turnalloff()
 { 
  for(int i = 0; i<4; i++)
   {
     digitalWrite(row[i],HIGH);
   }
  for(int i = 0; i<16; i++)
   {
     digitalWrite(column[i],LOW);
   }
 }
//for turn all LED cube on
void turnallon()
{ 
   for(int i = 0; i<4; i++)
  {
    digitalWrite(row[i], LOW);
  }
  for(int i = 0; i<16; i++)
  {
    digitalWrite(column[i],HIGH);
  }
}
//for blinking of full LED cube
void blinkingfullcube()
{
  int i = 150;
  while(i != 0)
  {
    turnallon();
    delay(i);
    turnalloff();
    delay(i);
    i-=5;
  }
}
// for row wise blinking of LED cube
void rowwiseblink()
{
  int a= 75;
  for(int i = 5; i>= 0; i--)
  {
    turnallon();
    for(int i = 4; i>=0; i--)
    {
      digitalWrite(row[i-1], LOW);
      delay(a);
  }
    for(int i = 0; i<4; i++)
    {
      digitalWrite(row[i], HIGH);
      delay(a);
    }
      for(int i = 0; i<4; i++)
    {
      digitalWrite(row[i], LOW);
      delay(a);
    }
    for(int i = 4; i>=0; i--)
    {
      digitalWrite(row[i-1], HIGH);
      delay(a);
    }
  }
}
//for column wise blinking of LED cube
void columnwiseblink()
{
  int a=150;
  while(a!=0)
  {
    turnallon();
    digitalWrite(column[15],LOW);
    digitalWrite(column[14],LOW);
    digitalWrite(column[13],LOW);
    digitalWrite(column[12],LOW);
    delay(a);
    digitalWrite(column[11],LOW);
    digitalWrite(column[10],LOW);
    digitalWrite(column[9],LOW);
    digitalWrite(column[8],LOW);
    delay(a);
    digitalWrite(column[7],LOW);
    digitalWrite(column[6],LOW);
    digitalWrite(column[5],LOW);
    digitalWrite(column[4],LOW);
    delay(a);
    digitalWrite(column[3],LOW);
    digitalWrite(column[2],LOW);
    digitalWrite(column[1],LOW);
    digitalWrite(column[0],LOW);
    delay(a);
    turnalloff();  
    digitalWrite(column[3],HIGH);
    digitalWrite(column[2],HIGH);
    digitalWrite(column[1],HIGH);
    digitalWrite(column[0],HIGH);
    delay(a);
    digitalWrite(column[4],HIGH);
    digitalWrite(column[5],HIGH);
    digitalWrite(column[6],HIGH);
    digitalWrite(column[7],HIGH);
    delay(a);
    digitalWrite(column[8],HIGH);
    digitalWrite(column[9],HIGH);
    digitalWrite(column[10],HIGH);
    digitalWrite(column[11],HIGH);
    delay(a);
    digitalWrite(column[12],HIGH);
    digitalWrite(column[13],HIGH);
    digitalWrite(column[14],HIGH);
    digitalWrite(column[15],HIGH);
    delay(a);
    turnallon();
    digitalWrite(column[0],LOW);
    digitalWrite(column[1],LOW);
    digitalWrite(column[2],LOW);
    digitalWrite(column[3],LOW);
    delay(a);
    digitalWrite(column[4],LOW);
    digitalWrite(column[5],LOW);
    digitalWrite(column[6],LOW);
    digitalWrite(column[7],LOW);
    delay(a);
    digitalWrite(column[8],LOW);
    digitalWrite(column[9],LOW);
    digitalWrite(column[10],LOW);
    digitalWrite(column[11],LOW);
    delay(a);
    digitalWrite(column[12],LOW);
    digitalWrite(column[13],LOW);
    digitalWrite(column[14],LOW);
    digitalWrite(column[15],LOW);
    delay(a);
    turnalloff();
    digitalWrite(column[15],HIGH);
    digitalWrite(column[14],HIGH);
    digitalWrite(column[13],HIGH);
    digitalWrite(column[12],HIGH);
    delay(a);
    digitalWrite(column[11],HIGH);
    digitalWrite(column[10],HIGH);
    digitalWrite(column[9],HIGH);
    digitalWrite(column[8],HIGH);
    delay(a);
    digitalWrite(column[7],HIGH);
    digitalWrite(column[6],HIGH);
    digitalWrite(column[5],HIGH);
    digitalWrite(column[4],HIGH);
    delay(a);
    digitalWrite(column[3],HIGH);
    digitalWrite(column[2],HIGH);
    digitalWrite(column[1],HIGH);
    digitalWrite(column[0],HIGH);
    delay(a);
    a-=5;  
  }
}
//turn columns off
void turnColumnsOff()
{
  for(int i = 0; i<16; i++)
  {
    digitalWrite(column[i], LOW);
  }
}
// for propellering of LED cube
void propeller()
{
  turnalloff();
  int a = 90;
  for(int y = 4; y>0; y--)
  {
    for(int i = 0; i<6; i++)
    {
      //turn on layer
      digitalWrite(row[y-1], HIGH);
      turnColumnsOff();
      digitalWrite(column[0], HIGH);
      digitalWrite(column[5], HIGH);
      digitalWrite(column[10],HIGH);
      digitalWrite(column[15],HIGH);
      delay(a);
      turnColumnsOff();
      digitalWrite(column[4], HIGH);
      digitalWrite(column[5], HIGH);
      digitalWrite(column[10],HIGH);
      digitalWrite(column[11],HIGH);
      delay(a);
      turnColumnsOff();
      digitalWrite(column[6], HIGH);
      digitalWrite(column[7], HIGH);
      digitalWrite(column[8], HIGH);
      digitalWrite(column[9], HIGH);
      delay(a);
      turnColumnsOff();
      digitalWrite(column[3], HIGH);
      digitalWrite(column[6], HIGH);
      digitalWrite(column[9], HIGH);
      digitalWrite(column[12],HIGH);
      delay(a);
      turnColumnsOff();
      digitalWrite(column[2], HIGH);
      digitalWrite(column[6], HIGH);
      digitalWrite(column[9], HIGH);
      digitalWrite(column[13],HIGH);
      delay(a);
      turnColumnsOff();
      digitalWrite(column[1], HIGH);
      digitalWrite(column[5], HIGH);
      digitalWrite(column[10],HIGH);
      digitalWrite(column[14],HIGH);
      delay(a);
    }
  }
}
