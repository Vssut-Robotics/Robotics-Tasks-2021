#include"pitches.h"

//Notes input
const int noteCH = 9;
const int noteB = 8;
const int noteA = 7;
const int noteG = 6;
const int noteF = 5;
const int noteE = 4; 
const int noteD = 13;
const int noteCL = 12;

const int pinToInterrupt = 2;


unsigned long previousMillis = 0;

volatile int mspB = 600; //100 bpm in microsecond per beat
const int metroIncrement= 50;
const int minMetronome = 0;

volatile int powerState = HIGH;
volatile float counter_time= 1.024; //(64*256*1000)/16e6 to get 1.024ms every 256 clock cycles
volatile int overflowCount =0;
volatile int prevCount=0;
volatile bool playTone = false;

int startTime=0;
int currentTime=0;
int startCount=0;

// Custom Millis()

long frequencyCPU = 16000000L; //16MHz
long clockCyclesPerMicrosecond = frequencyCPU / 10000000L; //16

int prescaler = 64; 
int rollover = 256;

long MS_PER_TIMER2_OVERFLOW = ((prescaler * rollover) * 1000)/(frequencyCPU/1000); //1024 microseconds
long MILLIS_INC = 1.024; //MS_PER_TIMER2_OVERFLOW / 1000; // milliseconds

int FRACT_INC = 3; //(MS_PER_TIMER2_OVERFLOW % 1000) >> 3; // 
int FRACT_MAX = 125; //1000 >> 3; //125
volatile unsigned long custom_timer2_millis = 0;
volatile unsigned char custom_timer2_fract = 0;
volatile unsigned int custom_timer2_overflow_count = 0;

unsigned long custom_millis() //Custom millis function
{
    unsigned long m;
    uint8_t oldSREG = SREG;
    // disable interrupts while we read timer0_millis or we might get an
    // inconsistent value (e.g. in the middle of a write to timer2_millis)
    cli();
    m = custom_timer2_millis;
    SREG = oldSREG;
 
    return m;
}

ISR(TIMER2_OVF_vect){
    unsigned long m = custom_timer2_millis;
    unsigned char f = custom_timer2_fract;
 
    m += MILLIS_INC;
    f += FRACT_INC;
    if (f >= FRACT_MAX){
        f -= FRACT_MAX;
        m += 1;
    }
 
    custom_timer2_fract = f;
    custom_timer2_millis = m;
    custom_timer2_overflow_count++;

    overflowCount++;
    if(((overflowCount * counter_time) - prevCount) >= mspB){
    prevCount= overflowCount * counter_time;
    playTone= true;
  }
}


void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(noteCH, INPUT);
  pinMode(noteB, INPUT);
  pinMode(noteA, INPUT);
  pinMode(noteG, INPUT);
  pinMode(noteF, INPUT);
  pinMode(noteE, INPUT);
  pinMode(noteD, INPUT);
  pinMode(noteCL, INPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A5, INPUT);
  pinMode(A4, INPUT);
  attachInterrupt(digitalPinToInterrupt(pinToInterrupt), adjustTempoInterrupt, RISING);
//  attachInterrupt(digitalPinToInterrupt(powerButton), stateChange, RISING);

  TIMSK2 |= (1<< TOIE2);
  sei();
}

//SIGNAL(TIMER2_OVF_vect){
//  overflowCount++;
//  if(((overflowCount * counter_time) - prevCount) >= mspB){
//    prevCount= overflowCount * counter_time;
//    playTone= true;
//    Serial.println("TRUE");
//  }
//}

void loop() {
    
  // put your main code here, to run repeatedly:

//  unsigned long currentMillis = millis(); 
//  if ((digitalRead(noteCH) == HIGH) && (digitalRead(noteB) == HIGH) && (digitalRead(noteA) == HIGH) && (digitalRead(noteG) == HIGH) && (digitalRead(noteF) == HIGH) && (digitalRead(noteE) == HIGH) && (digitalRead(noteD) == HIGH) && (digitalRead(noteCL) == HIGH))
//    {
//      //record initial time
//      startTime == custom_millis();
//      
//      //while all high record current time
//      while ((digitalRead(noteCH) == HIGH) && (digitalRead(noteB) == HIGH) && (digitalRead(noteA) == HIGH) && (digitalRead(noteG) == HIGH) && (digitalRead(noteF) == HIGH) && (digitalRead(noteE) == HIGH) && (digitalRead(noteD) == HIGH) && (digitalRead(noteCL) == HIGH)){
//      currentTime == custom_millis();
//        //if and time difference > 30 second, turn off and break/exit
//        if(currentTime - startTime > 10000)
//        {
//          powerState == LOW;
//          break;
//        }
//      } 
//    }

if ((digitalRead(noteCH) == HIGH) && (digitalRead(noteB) == HIGH) && (digitalRead(noteA) == HIGH) && (digitalRead(noteG) == HIGH) && (digitalRead(noteF) == HIGH) && (digitalRead(noteE) == HIGH) && (digitalRead(noteD) == HIGH) && (digitalRead(noteCL) == HIGH))
    {
      if (startCount == 0){
          startTime = custom_millis();
          startCount = 1;
        }
        currentTime = custom_millis();
      if (currentTime - startTime >= 60000){
         powerState = LOW;
      }
    }
    
  if (powerState == HIGH){
    Serial.println("if");
    digitalWrite(A0,HIGH);
    
    if(playTone ==true){
      tone(10,NOTE_C4,20);
  //    Serial.println("in the loop");
      playTone=false;
    }
  
    while ((digitalRead(noteCH) == LOW) && (digitalRead(noteB) == HIGH) && (digitalRead(noteA) == HIGH) && (digitalRead(noteG) == HIGH) && (digitalRead(noteF) == HIGH) && (digitalRead(noteE) == HIGH) && (digitalRead(noteD) == HIGH) && (digitalRead(noteCL) == HIGH)){
      tone(11, NOTE_C5);
      startCount=0;
  //    Serial.println("note c");
    }
    
    while ((digitalRead(noteCH) == HIGH) && (digitalRead(noteB) == LOW) && (digitalRead(noteA) == HIGH) && (digitalRead(noteG) == HIGH) && (digitalRead(noteF) == HIGH) && (digitalRead(noteE) == HIGH) && (digitalRead(noteD) == HIGH) && (digitalRead(noteCL) == HIGH)){
      tone(11, NOTE_B4);
      startCount=0;
  //    Serial.println("note b");
    }
    
    while ((digitalRead(noteCH) == HIGH) && (digitalRead(noteB) == HIGH) && (digitalRead(noteA) == LOW) && (digitalRead(noteG) == HIGH) && (digitalRead(noteF) == HIGH) && (digitalRead(noteE) == HIGH) && (digitalRead(noteD) == HIGH) && (digitalRead(noteCL) == HIGH)){
      tone(11, NOTE_A4);
      startCount=0;      
  //    Serial.println("note a");
    }
    
    while ((digitalRead(noteCH) == HIGH) && (digitalRead(noteB) == HIGH) && (digitalRead(noteA) == HIGH) && (digitalRead(noteG) == LOW) && (digitalRead(noteF) == HIGH) && (digitalRead(noteE) == HIGH) && (digitalRead(noteD) == HIGH) && (digitalRead(noteCL) == HIGH)){
      tone(11, NOTE_G4);
      startCount=0;
  //    Serial.println("note g");
    }
    
    while ((digitalRead(noteCH) == HIGH) && (digitalRead(noteB) == HIGH) && (digitalRead(noteA) == HIGH) && (digitalRead(noteG) == HIGH) && (digitalRead(noteF) == LOW) && (digitalRead(noteE) == HIGH) && (digitalRead(noteD) == HIGH) && (digitalRead(noteCL) == HIGH)){
      tone(11, NOTE_F4);
      startCount=0;
  //    Serial.println("note f");
    }
  
    while ((digitalRead(noteCH) == HIGH) && (digitalRead(noteB) == HIGH) && (digitalRead(noteA) == HIGH) && (digitalRead(noteG) == HIGH) && (digitalRead(noteF) == HIGH) && (digitalRead(noteE) == LOW) && (digitalRead(noteD) == HIGH) && (digitalRead(noteCL) == HIGH)){
      tone(11, NOTE_E4);
      startCount=0;
  //    Serial.println("note e");
    }
  
    while ((digitalRead(noteCH) == HIGH) && (digitalRead(noteB) == HIGH) && (digitalRead(noteA) == HIGH) && (digitalRead(noteG) == HIGH) && (digitalRead(noteF) == HIGH) && (digitalRead(noteE) == HIGH) && (digitalRead(noteD) == LOW) && (digitalRead(noteCL) == HIGH)){
      tone(11, NOTE_D4);
      startCount=0;
  //    Serial.println("note d");
    }
  
    while ((digitalRead(noteCH) == HIGH) && (digitalRead(noteB) == HIGH) && (digitalRead(noteA) == HIGH) && (digitalRead(noteG) == HIGH) && (digitalRead(noteF) == HIGH) && (digitalRead(noteE) == HIGH) && (digitalRead(noteD) == HIGH) && (digitalRead(noteCL) == LOW)){
      tone(11, NOTE_C4);
      startCount=0;
  //    Serial.println("note c2");
    }
  
  // Handling chords
  
  //C major
    while ((digitalRead(noteCH) == HIGH) && (digitalRead(noteB) == HIGH) && (digitalRead(noteA) == HIGH) && (digitalRead(noteG) == LOW) && (digitalRead(noteF) == HIGH) && (digitalRead(noteE) == LOW) && (digitalRead(noteD) == HIGH) && (digitalRead(noteCL) == LOW)){
      digitalWrite(A1, HIGH); //Enables chords
      digitalWrite(A3, LOW);
      digitalWrite(A2, LOW);
      tone(11, NOTE_C4);
      startCount=0;
      //Arduino 2 plays NOTE_E4
      //Arduino 3 plays NOTE_G4
    }
  
  //D minor
    while ((digitalRead(noteCH) == HIGH) && (digitalRead(noteB) == HIGH) && (digitalRead(noteA) == LOW) && (digitalRead(noteG) == HIGH) && (digitalRead(noteF) == LOW) && (digitalRead(noteE) == HIGH) && (digitalRead(noteD) == LOW) && (digitalRead(noteCL) == HIGH)){
      digitalWrite(A1, HIGH); //Enables chords
      digitalWrite(A3, LOW);
      digitalWrite(A2, HIGH);
      tone(11, NOTE_D4);
      startCount=0;
      //Arduino 2 plays NOTE_F4
      //Arduino 3 plays NOTE_A4
    }
  
  //E minor
    while ((digitalRead(noteCH) == HIGH) && (digitalRead(noteB) == LOW) && (digitalRead(noteA) == HIGH) && (digitalRead(noteG) == LOW) && (digitalRead(noteF) == HIGH) && (digitalRead(noteE) == LOW) && (digitalRead(noteD) == HIGH) && (digitalRead(noteCL) == HIGH)){
      digitalWrite(A1, HIGH); //Enables chords
      digitalWrite(A3, HIGH);
      digitalWrite(A2, LOW);
      tone(11, NOTE_E4);
      startCount=0;
      //Arduino 2 plays NOTE_G4
      //Arduino 3 plays NOTE_B4
    }
  
  //F major
    while ((digitalRead(noteCH) == LOW) && (digitalRead(noteB) == HIGH) && (digitalRead(noteA) == LOW) && (digitalRead(noteG) == HIGH) && (digitalRead(noteF) == LOW) && (digitalRead(noteE) == HIGH) && (digitalRead(noteD) == HIGH) && (digitalRead(noteCL) == HIGH)){
      digitalWrite(A1, HIGH); //Enables chords
      digitalWrite(A3, HIGH);
      digitalWrite(A2, HIGH);
      tone(11, NOTE_F4);
      //Arduino 2 plays NOTE_A4
      //Arduino 3 plays NOTE_C5
    }
  
   //nothing
    if ((digitalRead(noteCH) == HIGH) && (digitalRead(noteB) == HIGH) && (digitalRead(noteA) == HIGH) && (digitalRead(noteG) == HIGH) && (digitalRead(noteF) == HIGH) && (digitalRead(noteE) == HIGH) && (digitalRead(noteD) == HIGH) && (digitalRead(noteCL) == HIGH)){
      digitalWrite(A1, LOW); //Disables chords
  //    digitalWrite(A3, LOW);
  //    digitalWrite(A2, LOW);
      //Arduino 2 plays nothing
      //Arduino 3 plays nothing
    }  
    
    delay(100);
    noTone(11);
  //  digitalWrite(A1, LOW); //Mutes arduino 2 and 3
    
  //  if (currentMillis - previousMillis >= mspB ){
  //    tone(10,NOTE_C4,20);
  //    previousMillis = currentMillis;
  //  }
  //  noTone(5);
  //  tone(5, NOTE_C4);
  }
  else{
    digitalWrite(A0,LOW);
    Serial.println("else");
  }
}

void adjustTempoInterrupt(){
// if button 1 clicked, increase tempo
// if button 2 clicked, decrease tempo

if(digitalRead(A5) == HIGH && digitalRead(A4) == LOW)
{
  mspB += metroIncrement;
   Serial.println(mspB);
}
else if (digitalRead(A5) == LOW && digitalRead(A4) == HIGH)
{
  mspB -= metroIncrement;
  Serial.println(mspB);
}

}
