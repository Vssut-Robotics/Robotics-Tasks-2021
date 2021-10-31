/*
 4x4x4 LED Cube 
  Columns
  [(x,y)-Pin]
  (1,1)-13
  (1,2)-12
  (1,3)-11
  (1,4)-10
  (2,1)-9
  (2,2)-8
  (2,3)-7
  (2,4)-6
  (3,1)-5
  (3-2)-4
  (3-3)-3
  (3,4)-2
  (4,1)-1
  (4,2)-0
  (4,3)-A5
  (4,4)-A4
  Rows
  [Row-Pin]
  a-A0
  b-A1
  c-A2
  d-A3
*/
//initializing and declaring led column
  int column[16]={13,12,11,10,9,8,7,6,5,4,3,2,1,0,A5,A4};
//initializing and declaring led layers
  int row[4]={A3,A2,A1,A0};

  int time = 1000;
 
void setup()
{
  //setting column to ouput
  for(int i = 0; i<16; i++)
  {
    pinMode(column[i], OUTPUT);
  }
  //setting row to output
  for(int i = 0; i<4; i++)
  {
    pinMode(row[i], OUTPUT);
  }
}

void loop()
{
  turnEverythingOff();                         //turn all off
  flickering();                                //flicker pattern 
  delay(time);
  turnEverythingOff();                         //turn all off      
  rowLayerBlinking();                          //row layer blink pattern
  delay(time);
  turnEverythingOff();                         //turn all off
  columnLayerBlinking();                       //column layer blink pattern
  delay(time);
  turnEverythingOff();                         //turn all off
  propeller();                                 //propeller pattern
  delay(time);
  turnEverythingOff();                         //turn all off
  delay(2000);
}

////////////////////////////////////////////////turn all off
void turnEverythingOff()
 {
   for(int i = 0; i<16; i++)
   {
     digitalWrite(column[i], 1);
   }
   for(int i = 0; i<4; i++)
   {
     digitalWrite(row[i], 0);
   }
 }
 
////////////////////////////////////////////////turn all on
void turnEverythingOn()
{
  for(int i = 0; i<16; i++)
  {
    digitalWrite(column[i], 0);
  }
  for(int i = 0; i<4; i++)
  {
    digitalWrite(row[i], 1);
  }
}

//////////////////////////////////////////////turn columns off
void turnColumnsOff()
{
  for(int i = 0; i<16; i++)
  {
    digitalWrite(column[i], 0);
  }
}

/////////////////////////////////////////////flickering
void flickering()
{
  int i = 125;
  while(i != 0)
  {
    turnEverythingOn();
    delay(i);
    turnEverythingOff();
    delay(i);
    i = i-5;
  }
}

/////////////////////////////////////////////row layer blinking
void rowLayerBlinking()
{
  turnEverythingOff();
  int x = 500, j=2;
  while(j > 0)
  {
    int i;
    for(i = 0; i<4; i++)
    {
    digitalWrite(row[i], 1);
    delay(x);
    turnColumnsOff();
    }
     for(i = 4; i>0; i--)
    {
    digitalWrite(row[i-1], 1);
    delay(x);
    turnColumnsOff();
    }
    j--;
  } 
}

/////////////////////////////////////////////column layer blinking
void columnLayerBlinking()
{
  turnEverythingOff();
  int x = 500, j=2;
  while(j > 0)
  {
    int i;
    for(i = 0; i<16; i=i+4)
      {
       digitalWrite(column[i], 1);
       digitalWrite(column[i+1], 1);
       digitalWrite(column[i+2], 1);
       digitalWrite(column[i+3], 1);
       delay(x);
       turnColumnsOff();
      } 
    for(i = 15; i>=0; i=i-4)
      {
       digitalWrite(column[i], 1);
       digitalWrite(column[i-1], 1);
       digitalWrite(column[i-2], 1);
       digitalWrite(column[i-3], 1);
       delay(x);
       turnColumnsOff();
      }
    j--;
  } 
}

/////////////////////////////////////////////propeller
void propeller()
{
  turnEverythingOff();
  int x = 150;
  for(int i = 0; i<6; i++)
  {
      //position 1
      turnColumnsOff();
      digitalWrite(column[0], 1);
      digitalWrite(column[5], 1);
      digitalWrite(column[10], 1);
      digitalWrite(column[15], 1);
      delay(x);
      //position 2
      turnColumnsOff();
      digitalWrite(column[4], 1);
      digitalWrite(column[5], 1);
      digitalWrite(column[10], 1);
      digitalWrite(column[11], 1);
      delay(x);
      //position 3
      turnColumnsOff();
      digitalWrite(column[6], 1);
      digitalWrite(column[7], 1);
      digitalWrite(column[8], 1);
      digitalWrite(column[9], 1);
      delay(x);
      //position 4
      turnColumnsOff();
      digitalWrite(column[3], 1);
      digitalWrite(column[6], 1);
      digitalWrite(column[9], 1);
      digitalWrite(column[12], 1);
      delay(x);
      //position 5
      turnColumnsOff();
      digitalWrite(column[2], 1);
      digitalWrite(column[6], 1);
      digitalWrite(column[9], 1);
      digitalWrite(column[13], 1);
      delay(x);
      //position 6
      turnColumnsOff();
      digitalWrite(column[1], 1);
      digitalWrite(column[5], 1);
      digitalWrite(column[10], 1);
      digitalWrite(column[14], 1);
      delay(x);
  } 
}
