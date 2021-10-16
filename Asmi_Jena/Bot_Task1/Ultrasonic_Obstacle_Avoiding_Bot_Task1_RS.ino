#include <Servo.h>
int MR1 = 7; //right side motor R1
int MR2 = 6; //right side motor R2
int ML1 = 8; //left side motor L1
int ML2 = 9; //Left side motor L2
int trig = 11;
int echo = 12;
Servo sensor;
float dist;
int angles[] = {0,180}; //defined angle for the servo motor
float avg; 
float temp;//temporary variable
float distavg; //variable for average distance 

//command for ultrasonic sensor

float ultrasonic()
{
  int time;
  float distance;
  digitalWrite(trig, LOW);
  digitalWrite(echo, LOW);
  delay(2);
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  time = pulseIn(echo,HIGH,30000);
  distance = 343*0.0001*(time/2); // distance in centimeters
  return distance;
  delay(3000);
}

void loop()
{
    float total = 0;
    for(int i=0; i<30; i++) //total 30 inputs from the ultrasonic sensor is taken and then the avg is calculated for better accuracy and this data is used for the motion of the wheel
    {
      dist=ultrasonic();
      total += dist;
    }
    distavg = total/30;
    Serial.println(distavg);    
    if(distavg > 30.0)
    {
        forward();
    }
    //for servo
    else 
    {
        stop(); //when the for condition is not satisfied the bot stops 
        Serial.println("stopped");
        delay(1000);
        int flag=0;
        for(int i=0; i<2; i++) //for moving the servo 
        {
            sensor.write(angles[i]);
            delay(1000);
            float detect=0;
            for(int j=0; j<20; j++) // 20 distances are taken and their avg is calculated for better accuracy
            {
                temp = ultrasonic();
                detect += temp;
            }
            avg=detect/20;
            if(avg >= 30.0 && i==0) //if obstacle is present on left side
            {
                for (int i=0; i<130; i++)
                {
                    right();
                    Serial.println("right");              
                }    
                stop();
                flag = 1;
                delay(2000);
                break;
            }
            else if(avg >= 30.0 && i == 1) //if obstacle is present on right side
            {
                for (int i=0; i<130; i++)
                {
                    left();
                    Serial.println("left");
                }    
                stop();     
                flag = 2;
                delay(2000);   
                break;
            }
            delay(300);  
        }
        if(flag !=1 && flag !=2) // if obstacle is present on both left and right side
        {
            for (int i=0; i<200; i++)
            {
                backward();
                Serial.println("back");
            }    
            stop();    
            delay(2000);    
        }
        sensor.write(100);
    }
  delay(400);    
 }

//command for forward motion

void forward()
{
    digitalWrite(ML1, HIGH); //L1 motor is set to high 
    digitalWrite(ML2, LOW); //L2 motor is set to low
    digitalWrite(MR1, HIGH); //R1 motor is set to high
    digitalWrite(MR2, LOW); //R2 motor is set to low
}

//command for backward motion

void backward()
{
    digitalWrite(ML1, LOW); //L1 motor is set to low
    digitalWrite(ML2, HIGH); //L2 motor is set to high
    digitalWrite(MR1, LOW ); //R1 motor is set to low
    digitalWrite(MR2, HIGH); //R2 motor is set to high
}

//command for rightward motion

void right()
{
    digitalWrite(ML1, HIGH); //L1 motor is set to high
    digitalWrite(ML2, LOW); //L2 motor is set to low
    digitalWrite(MR1, LOW); //R1 motor is set to low
    digitalWrite(MR2, HIGH); //R2 motor is set to high
}

//command for leftward motion

void left()
{
    digitalWrite(ML1, LOW); //L1 motor is set to low
    digitalWrite(ML2, HIGH);//L2 motor is set to high
    digitalWrite(MR1, HIGH);//R1 motor is set to high
    digitalWrite(MR2, LOW);//R2 motor is set to low
}

//command to stop the bot

void stop()
{
    digitalWrite(ML1, LOW); //L1 motor is set to low
    digitalWrite(ML2, LOW); //L2 motor is set to low
    digitalWrite(MR1, LOW); //R1 motor is set to low
    digitalWrite(MR2, LOW); //R2 motor is set to low
}

void setup()
{
    pinMode(ML1, OUTPUT);
    pinMode(ML2, OUTPUT);
    pinMode(MR1, OUTPUT);
    pinMode(MR2, OUTPUT);
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    sensor.attach(5);
    Serial.begin(9600);
}
