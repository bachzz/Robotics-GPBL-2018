#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include "musical_notes.h"
#include "songs.h"

SoftwareSerial BT(10, 11); //TX, RX respetively
LiquidCrystal lcd(7, 8, 2, 3, 4, 5);
String readvoice;


void setup() {
 BT.begin(9600);
 Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(speakerPin, OUTPUT); // sets the speakerPin to be an output 
 lcd.begin(16, 2);
 face_default();
}
//-----------------------------------------------------------------------//  

// music


void catcall() {
  for (int i=1000; i<5000; i=i*1.05) {
    beep(speakerPin,i,10);
  }
 delay(300);
 
  for (int i=1000; i<3000; i=i*1.03) {
    beep(speakerPin,i,10);
  }
  for (int i=3000; i>1000; i=i*.97) {
    beep(speakerPin,i,10);
  }
}

void beep (int speakerPin, float noteFrequency, long noteDuration)
{    
  int x;
  // Convert the frequency to microseconds
  float microsecondsPerWave = 1000000/noteFrequency;
  // Calculate how many HIGH/LOW cycles there are per millisecond
  float millisecondsPerCycle = 1000/(microsecondsPerWave * 2);
  // Multiply noteDuration * number or cycles per millisecond
  float loopTime = noteDuration * millisecondsPerCycle;
  // Play the note for the calculated loopTime.
  for (x=0;x<loopTime;x++)   
          {   
              digitalWrite(speakerPin,HIGH); 
              delayMicroseconds(microsecondsPerWave); 
              digitalWrite(speakerPin,LOW); 
              delayMicroseconds(microsecondsPerWave); 
          } 
}   
void r2D2_1(){
          beep(speakerPin, note_A7,100); //A 
          beep(speakerPin, note_G7,100); //G 
          beep(speakerPin, note_E7,100); //E 
          beep(speakerPin, note_C7,100); //C
          beep(speakerPin, note_D7,100); //D 
          beep(speakerPin, note_B7,100); //B 
          beep(speakerPin, note_F7,100); //F 
          beep(speakerPin, note_C8,100); //C 
          beep(speakerPin, note_A7,100); //A 
          beep(speakerPin, note_G7,100); //G 
          beep(speakerPin, note_E7,100); //E 
          beep(speakerPin, note_C7,100); //C
          beep(speakerPin, note_D7,100); //D 
          beep(speakerPin, note_B7,100); //B 
          beep(speakerPin, note_F7,100); //F 
          beep(speakerPin, note_C8,100); //C 
}
void r2D2_2(){
          beep(speakerPin, note_E7,100); //E 
          beep(speakerPin, note_C7,100); //C
          beep(speakerPin, note_G7,100); //G 
          beep(speakerPin, note_C7,100); //C        
          beep(speakerPin, note_D7,100); //D            
          beep(speakerPin, note_F7,100); //F 
          beep(speakerPin, note_C8,100); //C         
          
          beep(speakerPin, note_E7,100); //E  
          beep(speakerPin, note_F7,100); //F 
          beep(speakerPin, note_C8,100); //C       
          beep(speakerPin, note_G7,100); //G 
}

void closeEncounters() {
          beep(speakerPin, note_Bb5,300); //B b
          delay(50);
          beep(speakerPin, note_C6,300); //C
          delay(50);
          beep(speakerPin, note_Ab5,300); //A b
          delay(50);
          beep(speakerPin, note_Ab4,300); //A b
          delay(50);
          beep(speakerPin, note_Eb5,500); //E b   
          delay(500);     
          
          beep(speakerPin, note_Bb4,300); //B b
          delay(100);
          beep(speakerPin, note_C5,300); //C
          delay(100);
          beep(speakerPin, note_Ab4,300); //A b
          delay(100);
          beep(speakerPin, note_Ab3,300); //A b
          delay(100);
          beep(speakerPin, note_Eb4,500); //E b   
          delay(500);  
          
          beep(speakerPin, note_Bb3,300); //B b
          delay(200);
          beep(speakerPin, note_C4,300); //C
          delay(200);
          beep(speakerPin, note_Ab3,300); //A b
          delay(500);
          beep(speakerPin, note_Ab2,300); //A b
          delay(550);
          beep(speakerPin, note_Eb3,500); //E b      
}
void laugh2() {
          beep(speakerPin, note_C6,200); //C
          beep(speakerPin, note_E6,200); //E  
          beep(speakerPin, note_G6,200); //G 
          beep(speakerPin, note_C7,200); //C 
          beep(speakerPin, note_C6,200); //C
          delay(50);
          beep(speakerPin, note_C6,200); //C
          beep(speakerPin, note_E6,200); //E  
          beep(speakerPin, note_G6,200); //G 
          beep(speakerPin, note_C7,200); //C 
          beep(speakerPin, note_C6,200); //C
          delay(50);
          beep(speakerPin, note_C6,50); //C
          delay(50);
          beep(speakerPin, note_C6,50); //C
          delay(50);
          beep(speakerPin, note_C6,50); //C
          delay(50);
          beep(speakerPin, note_C6,50); //C
          delay(50);
          beep(speakerPin, note_C6,50); //C
          delay(50);
          beep(speakerPin, note_C6,50); //C
          delay(50);
          beep(speakerPin, note_C6,50); //C
          

          
}
void squeak() {
  for (int i=100; i<5000; i=i*1.45) {
    beep(speakerPin,i,60);
  }
  delay(10);
  for (int i=100; i<6000; i=i*1.5) {
    beep(speakerPin,i,20);
  }
}

void ohhh() {
  for (int i=1000; i<2000; i=i*1.02) {
    beep(speakerPin,i,10);
  }
  for (int i=2000; i>1000; i=i*.98) {
    beep(speakerPin,i,10);
  }
}

void uhoh() {
  for (int i=1000; i<1244; i=i*1.01) {
    beep(speakerPin,i,30);
  }
  delay(200);
  for (int i=1244; i>1108; i=i*.99) {
    beep(speakerPin,i,30);
  }
}

void laugh() {
  for (int i=1000; i<2000; i=i*1.10) {
    beep(speakerPin,i,10);
  }
  delay(50);
  for (int i=1000; i>500; i=i*.90) {
    beep(speakerPin,i,10);
  }
  delay(50);
  for (int i=1000; i<2000; i=i*1.10) {
    beep(speakerPin,i,10);
  }
  delay(50);
  for (int i=1000; i>500; i=i*.90) {
    beep(speakerPin,i,10);
  }
  delay(50);
    for (int i=1000; i<2000; i=i*1.10) {
    beep(speakerPin,i,10);
  }
  delay(50);
  for (int i=1000; i>500; i=i*.90) {
    beep(speakerPin,i,10);
  }
  delay(50);
    for (int i=1000; i<2000; i=i*1.10) {
    beep(speakerPin,i,10);
  }
  delay(50);
  for (int i=1000; i>500; i=i*.90) {
    beep(speakerPin,i,10);
  }
  delay(50);
}

// directions & LCD

void straight(){
    analogWrite (9, 140);
    analogWrite (6, 175);
    delay(1000);
    analogWrite (9, 0);
    analogWrite (6, 0);
    delay(1);
  }
void left(){
   analogWrite (9, 0);
   analogWrite (6, 70);
   delay (1000); 
   analogWrite (9, 0);
   analogWrite (6, 0);
   delay(1);
}
void right(){
    analogWrite (9,60);
    analogWrite (6,0);
    delay (1000);
    analogWrite (9, 0);
    analogWrite (6, 0);
    delay(1);
}
void pause(){
   analogWrite (9, 0);
   analogWrite (6, 0);
   delay (1000); 
}
void small_circle(){
  analogWrite (9,100);
  analogWrite (6,40);
  delay (6000);
  pause();
}
void big_circle(){
  analogWrite (9,150);
  analogWrite (6,100);
  delay (1000);
}
void reverse_circle(){
  analogWrite (9,50);
  analogWrite (6,150);
  delay (1000);
}
void triangle(){
  analogWrite (9, 100);
  analogWrite (6, 125);/*straight*/
  delay(2000);
  pause();
  analogWrite (9, 170);
  analogWrite (6, 0);/*right*/
  delay(500);
  pause();
  analogWrite (9, 100);
  analogWrite (6, 125);/*straight*/
  delay(2000);
  pause();
  analogWrite (9, 175);
  analogWrite (6, 0);/*right*/
  delay(500);/*800*/
  pause();
  analogWrite (9, 100);
  analogWrite (6, 125);/*straight*/
  delay(2000);
  analogWrite (9, 0);
  analogWrite (6, 0);
}

void square(){
  analogWrite (9, 100);
  analogWrite (6, 125);/*straight*/
  delay(1500);
  pause();
  analogWrite (9, 120);
  analogWrite (6, 0);/*right*/
  delay(500);
   pause();
  analogWrite (9, 100);
  analogWrite (6, 125);/*straight*/
  delay(1500);
  pause();
  analogWrite (9, 120);
  analogWrite (6, 0);/*right*/
  delay(500);
  pause();
  analogWrite (9, 100);
  analogWrite (6, 125);/*straight*/
  delay(1500);
  pause();
  analogWrite (9, 120);
  analogWrite (6, 0);/*right*/
  delay(500);
  pause();
  analogWrite (9, 100);
  analogWrite (6, 125);/*straight*/
  delay(1500);
  pause();
}
void face_default(){
 lcd.setCursor(0,0);
 lcd.print("     ^   ^     ");
 lcd.setCursor(0,1);
 lcd.print("       _       ");
 lcd.setCursor(0,0);
  }
void reset(){
  lcd.setCursor(0,0);
  lcd.print("                   ");
  lcd.setCursor(0,1);
  lcd.print("                   ");
  lcd.setCursor(0,0);
  }

void loop() {
  while (BT.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable 
  char c = BT.read(); //Conduct a serial read
  readvoice += c; //build the string- "forward", "reverse", "left" and "right"
  }  
  if (readvoice.length() > 0) {
    Serial.println(readvoice); 

  // Directions & Shapes
  
  if(readvoice == "forward" || readvoice == "Forward") 
  {
    straight();
  } 

  else if (readvoice == "right" || readvoice == "Right")
  {
    right();
    
  }
  
 else if ( readvoice == "left" || readvoice == "Left")
 {
   left();
 }
 
 else if (readvoice == "stop" || readvoice == "Stop")
 {
  
   pause();
 }

 else if (readvoice == "round" || readvoice=="Round")
{
   small_circle(); 
}

else if(readvoice == "reverse" || readvoice=="Reverse")
   {
    reverse_circle();
   }

else if (readvoice == "triangle" || readvoice=="Triangle")
{
   triangle();
}


else if (readvoice == "square" || readvoice=="Square")
{
  square();
}

// Communication

else if (readvoice == "hello"){
    // reset screen
    lcd.print("                ");
    lcd.setCursor(0,1);
    lcd.print("                ");
    lcd.setCursor(0,0);
    // conversation
    lcd.print("Hi, I'm K-9! :)");
    r2D2_1();
    delay(2000);
    lcd.setCursor(0,0);
    lcd.print("Nice to meet    ");
    lcd.setCursor(0,1);
    lcd.print("you! xD");
    delay(5000);
    face_default();
}
else if ((readvoice.indexOf("amazing")>0) || (readvoice.indexOf("beautiful")>0)){
    // reset screen
    reset();
    // conversation
    lcd.print("    Hmmmm...    ");
    delay(2000);
    reset();
    lcd.print("     X   X      ");
    lcd.setCursor(0,1);
    lcd.print("       v        ");
    laugh();
    delay(5000);
    face_default();
}
else if (readvoice.indexOf("old")>0){
    // reset screen
    reset();
    // conversation
    lcd.print("I'm 46 hours old");
    
    delay(3000);
    reset();
    lcd.print("Please ask");
    lcd.setCursor(0,1);
    lcd.print("something clever..");
    ohhh();
    delay(5000);
    reset();
    face_default();
}
else if (readvoice.indexOf("creator")>0){
    // reset screen
    reset();
    // conversation
    lcd.print("Are you my");
    lcd.setCursor(0,1);
    lcd.print("creator?");
    uhoh();
    delay(5000);
    reset();
    face_default();
}
else if (readvoice.indexOf("yes")>0){
    // reset screen
    reset();
    // conversation
    lcd.print("You forgot");
    lcd.setCursor(0,1);
    lcd.print("my nose...");
    squeak();
    delay(3000);
    reset();
    lcd.print("     T   T      ");
    lcd.setCursor(0,1);
    lcd.print("       _        ");
    ohhh();
    delay(5000);
    reset();
    face_default();
}
else if (readvoice.indexOf("music")>0){
    reset();
    lcd.print("Playing...");
    closeEncounters();
    reset();
    face_default();
  }
else if (readvoice.indexOf("pirates")>0){
    reset();
    lcd.print("Playing...");
    pirates();
    reset();
    face_default();
  }
else if (readvoice.indexOf("we wish")>0){
    reset();
    lcd.print("Playing...");
    wish();
    reset();
    face_default();
  }
else if (readvoice.indexOf("gravity")>0){
    reset();
    lcd.print("Playing...");
    gravity();
    reset();
    face_default();
  }
else if (readvoice.indexOf("robocop")>0){
    reset();
    lcd.print("Playing...");
    robocop();
    reset();
    face_default();
  }



else if (readvoice.indexOf("goodbye")>0){
    reset();
    lcd.print("     T   T      ");
    lcd.setCursor(0,1);
    lcd.print("       _        ");
    ohhh();
    delay(5000);
    reset();
    face_default();
  }
else {
  pause();
}
readvoice="";//Reset the variable

}} 
