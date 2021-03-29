/*
     Servo Motor Control using the Arduino Servo Library
*/

#include <Servo.h>

Servo pan;  // create servo object to control a servo
Servo tilt;
int dir='\0';
char pos = 0;
int ls_pan;
int ls_tilt;
int p,t,i,j;

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
    ls_pan=80;
    ls_tilt=80;
    
    Serial.println("Enter required direction: (T, B, L, R, TR, TL, BR, BL, O, C)");
}

void loop() 
{
  check:
 if(Serial.available()>0)   
 {
  String cmd= Serial.readString(); //Reading the Input string from Serial port. 

  if(cmd=="T\n")
  {
    Serial.println("Top");
    check1:
    int p=80;
    check2:
    goto slow;
    int t=125;
  }
  else if(cmd=="B\n")
  {
    Serial.println("Bottom");
    int p=80;
    int t=35;
    goto slow; 
  }
  else if(cmd=="L\n")
  {
    Serial.println("Left");
    int p=0;
    int t=125;
    goto slow;  
  }
  else if(cmd=="R\n")
  {
    Serial.println("Right");
    int p=180;
    int t=125;
    goto slow;  
  }
  else if(cmd=="TR\n")
  {
    Serial.println("Top Right");
    int p=125;
    int t=125;
    goto slow;  
  }
  else if(cmd=="TL\n")
  {
    Serial.println("Top Left");
    int p=35;
    int t=125;
    goto slow;  
  }
  else if(cmd=="BR\n")
  {
    Serial.println("Bottom Right");
    int p=35;
    int t=35;
    goto slow;  
  }
  else if(cmd=="BL\n")
  {
    Serial.println("Bottom Left");
    int p=125;
    int t=35;
    goto slow;  
  }
  else if(cmd=="O\n")
  {
    Serial.println("Origin");
    int p=0;
    int t=0;
    goto slow;  
  }
    else if(cmd=="C\n")
  {
    Serial.println("Center");
    int p=80;
    int t=80;
    goto slow;  
  }
  else
  {
    Serial.println("Enter current direction: (T, B, L, R, TR, TL, BR, BL, O, C)");
  } 
 }

 slow:
 for(i=ls_pan; i<=p; i++)
  {
    pan.write(i);
    delay(10);
  }
  ls_pan=i;

  goto check1; 
  
 for(i=ls_pan; i>=p; i--)
  {
    pan.write(i);
    delay(10);
  }
  ls_pan=i; 
 
 for(j=ls_tilt; j<=t; j++)
  {
    pan.write(j);
    delay(10);
  }
  ls_tilt=j;
    goto check2; 
 for(j=ls_tilt; j>=t; j--)
  {
    pan.write(j);
    delay(10);
  } 
  ls_tilt=j;
 
                   
}
