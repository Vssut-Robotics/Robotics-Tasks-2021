#include<Servo.h>                                                              //CALLING SERVO FUNCTION FROM THE LIBRARY.
Servo motor;                                                                   //DEFINING THE SERVO VARIABLE.
int angle=0;                                                                   //INITIALLIZING THE ANGLE AS 0 DEGREE.
int input;                                                                     //ANOTHER VARIABLE USED LATER FOR INPUTTING THE VALUES FROM LDR SENSOR.
void setup() {
  Serial.begin(9600);
  motor.attach(9);                                                             //FOR CONNECTING THE CONTROLS OF TE MOTOR TO PWM PIN NO. 9.
  pinMode(A0,INPUT);                                                          //FOR DEFINING THIS PIN AS INPUT PIN.
}
void loop() {
  input=analogRead(A0);                                                       //STORE VALUES FROM LDR SENSOR.
  if(input<500)                                                                //COMPARISION IS MADE TO DARKNESS OF THE ROOM,THIS VALUE IS TO BE SET BY PROPE EXPERIMENTS THE VALUE PROVIDED IS JUST A RANDOM ONE.
  {
    for(angle=0;angle<=50;angle+=1)                                            //FOR MOVING IT TO A PARTICULAR ANGLE WITH AN ACCURACY OF 1 DEGREE(THE VALUE I.E. THE ONE WHICH IS PROVIDED IS AN ASSUMPTION).
    {
      motor.write(angle);                                                      //MOVE TO FINAL ANGLE IN A STEPWISE
      delay(20);                                                               //MAY BE TO ALLOW THE MOTOR TO MOVE ACCURATELY WITHOUT GETTING AN ERRORED FINAL ANGLE WHICH MAY BE ACQUIRED DUE TO INERTIA
    }
    delay(100);
    for(angle=50;angle>=0;angle-=1)                                            //SAME AS BEFORE ONLY ITS DONE FOR TAKING IT BACK TO INITIAL ANGLE
    {
      motor.write(angle);                                                      //MOVE TO FINAL ANGLE IN A STEPWISE
      delay(20);                                                               //MAY BE TO ALLOW THE MOTOR TO MOVE ACCURATELY WITHOUT GETTING AN ERRORED FINAL ANGLE WHICH MAY BE ACQUIRED DUE TO INERTIA
    }
  }
}
