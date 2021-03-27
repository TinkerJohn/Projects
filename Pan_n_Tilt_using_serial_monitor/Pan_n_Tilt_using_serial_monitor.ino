/*
     Servo Motor Control using the Arduino Servo Library
*/

#include <Servo.h>

Servo pan;  // create servo object to control a servo
Servo tilt;
int dir='\0';
char pos = 0;

void setup() 
{
 

  Serial.begin(9600);
  while(!Serial);
  Serial.println("---------------------------");
  Serial.println("  Pan & Tilt Mechanism");
  Serial.println("---------------------------");
  delay(1000);
  /*
    Serial.println("Intializing the mechanism");
    Serial.println("1. Panning check");
    pan.write(0);  // tell servo to go to a particular angle
    delay(1000);
    pan.write(180);  // tell servo to go to a particular angle
    delay(1000);
    Serial.println("Done");
    delay(1000);
    
    Serial.println("2. Tilting check");
    tilt.write(0);  // tell servo to go to a particular angle
    delay(1000);
    tilt.write(180);  // tell servo to go to a particular angle
    delay(1000);
    Serial.println("Done");
    delay(1000);
   */
    pan.attach(2,600,2300);  // (pin, min, max)
  tilt.attach(3,600,2300); 
    Serial.println("3. Centering");
    pan.write(80);
    tilt.write(80);
    delay(1000);
    Serial.println("Positioned");
    delay(1000);
    Serial.println("\n");
    
    Serial.println("Enter required direction: (T, B, L, R, TR, TL, BR, BL)");
}

void loop() 
{
 if(Serial.available()>0)   
 {
  String cmd= Serial.readString(); //Reading the Input string from Serial port. 

  if(cmd=="T\n")
  Serial.println("top");
  else if(cmd=="B\n")
  Serial.println("top");
   else if(cmd=="T\n")
  Serial.println("top");  

 
 }                     
}
