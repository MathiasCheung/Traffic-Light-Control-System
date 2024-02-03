//pin number variables
int red = 4;
int yellow = 3;
int green = 2;

//7-segment display
int A = 5;
int B = 6;
int C = 7;
int D = 8;
int E = 9;
int F = 10;
int G = 11;

//button
int btnPin = 13;
uint8_t btnPrev;

void setup() {

  Serial.begin(9600);

  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  //7-segment
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);

  //button
  pinMode(btnPin, INPUT_PULLUP);

  btnPrev = digitalRead(btnPin);

}



void loop() {
  // put your main code here, to run repeatedly:
 
  //traffic light start
  trafficLight();
  
  //count down for pedestrian crossing
  countDown();
  

  resetCounter();


}


// method to controll traffic light
void trafficLight(){
    digitalWrite(red, HIGH);
    delay(4000);
    digitalWrite(red, LOW);

    digitalWrite(yellow, HIGH);
    delay(2000);
    digitalWrite(yellow, LOW);

    //checks if btn is pressed, stays on green light if btn is not press
    while(!btnPressed()){
      digitalWrite(green, HIGH);
    }


    delay(1000);
    digitalWrite(green, LOW);

    digitalWrite(yellow, HIGH);
    delay(2000);
    digitalWrite(yellow, LOW);

    digitalWrite(red, HIGH);
    delay(500);

}
   
    


// set up for 7-segment display
void zero() {
  digitalWrite(A, HIGH);
  digitalWrite(B,   HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E,   HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
}
void one()   {
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
   digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
   digitalWrite(G, LOW);
}
void two() {
  digitalWrite(A, HIGH);
  digitalWrite(B,   HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E,   HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
}
void three()   {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
   digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
   digitalWrite(G, HIGH);
}
void four() {
  digitalWrite(A, LOW);
  digitalWrite(B,   HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E,   LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}
void five()   {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
   digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
   digitalWrite(G, HIGH);
}
void six() {
  digitalWrite(A, HIGH);
  digitalWrite(B,   LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E,   HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}
void seven()   {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
   digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
   digitalWrite(G, LOW);
}
void eight() {
  digitalWrite(A, HIGH);
  digitalWrite(B,   HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E,   HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}
void nine()   {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
   digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
   digitalWrite(G, HIGH);
}

//////

//controll 7-segment display
void countDown() {
  nine();
   delay(1000);
  eight();
   delay(1000);
  seven();
  delay(1000);
  six();
   delay(1000);
  five();
   delay(1000);
  four();
   delay(1000);
  three();
   delay(1000);
  two();
   delay(1000);
  one();
   delay(1000);
  zero();
   delay(1000);
  
}

//reset 7-segment display
void resetCounter(){
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}


//checks for btn press
bool btnPressed(){
  uint8_t btn = digitalRead(btnPin);

 if (btn != btnPrev )
  {
    return true;
  }
  return false;
}





