/*
     Servo Motor Control using the Arduino Servo Library
*/

#include <Servo.h>

Servo pan;  // create servo object to control a servo
Servo tilt;
int dir='\0';
char pos = 0;
int pr_tilt=0;
int pr_pan=0;
int ls_tilt=0;
int ls_pan=0;
void setup() 
{
 
ls_tilt=80;
ls_pan=80;
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

    Serial.println("Enter required direction: (T, B, L, R, TR, TL, BR, BL, O, C)");
}

void loop() 
{
 if(Serial.available()>0)   
 {
  String cmd= Serial.readString(); //Reading the Input string from Serial port. 

  if(cmd=="T\n")
  {
    Serial.println("Top");
    pan.write(80);
    for(int i=ls_tilt;i<=125;i++)
    {
     tilt.write(i);
     delay(10); 
    }
    ls_pan=80;
    ls_tilt=125;
  }


  
  else if(cmd=="B\n")
  {
    Serial.println("Bottom");
    pan.write(80); 
    for(int i=ls_tilt;i>=35;i--)
    {
     tilt.write(i);
     delay(10); 
    }
    ls_pan=80;
    ls_tilt=35;
  }


  
  else if(cmd=="L\n")
  {
    Serial.println("Left");
    for(int i=ls_pan;i>=0;i--)
    {
     pan.write(i);
     delay(10); 
    }
    for(int i=ls_tilt;i<=125;i++)
    {
     tilt.write(i);
     delay(10); 
    } 
    ls_pan=0;
    ls_tilt=125;
  }


  
  else if(cmd=="R\n")
  {
    Serial.println("Right");
    for(int i=ls_pan;i<=180;i++)
    {
     pan.write(i);
     delay(10); 
    }
       for(int i=ls_pan;i<=125;i++)
    {
    tilt.write(i);
     delay(10); 
    }
   // tilt.write(125);
    ls_pan=180;
    ls_tilt=125;      
  }


  
  else if(cmd=="TR\n")
  {
    Serial.println("Top Right");
    for(int i=ls_pan;i<=125;i++)
    {
     pan.write(i);
     delay(10); 
    }
    tilt.write(125);
    ls_pan=125;
    ls_tilt=125;
  }


  
  else if(cmd=="TL\n")
  {
    Serial.println("Top Left");
    for(int i=ls_pan;i>=35;i--)
    {
     pan.write(i);
     delay(10); 
    }
    tilt.write(125);
    ls_pan=35;
    ls_tilt=125;
  }


  
  else if(cmd=="BR\n")
  {
    Serial.println("Bottom Right");
    pan.write(35);
    for(int i=ls_tilt;i>=35;i--)
    {
     tilt.write(i);
     delay(10); 
    }
    ls_pan=35;
    ls_tilt=35; 
  }


  
  else if(cmd=="BL\n")
  {
    Serial.println("Bottom Left");
    for(int i=ls_pan;i<=125;i++)
    {
     pan.write(i);
     delay(10); 
    }
    tilt.write(35);
    ls_pan=125;
    ls_tilt=35; 
  }


  
  else if(cmd=="O\n")
  {
    Serial.println("Origin");
    for(int i=ls_pan;i>=0;i--)
    {
     pan.write(i);
     delay(10); 
    }
    for(int i=ls_tilt;i>=0;i--)
    {
     tilt.write(i);
     delay(10); 
    }
    ls_pan=0;
    ls_tilt=0;  
  }


  
  else if(cmd=="C\n")
  {
    Serial.println("Center");
    for(int i=ls_pan;i=80;i++)
    {
     pan.write(i);
     delay(10); 
    }
    for(int i=ls_tilt;i<=80;i++)
    {
     tilt.write(i);
     delay(10); 
    }
    ls_pan=80;
    ls_tilt=80;  
  }



  else
  {
    Serial.println("Enter correct direction: (T, B, L, R, TR, TL, BR, BL, O, C)"); 
  }


  
 }                     
}
