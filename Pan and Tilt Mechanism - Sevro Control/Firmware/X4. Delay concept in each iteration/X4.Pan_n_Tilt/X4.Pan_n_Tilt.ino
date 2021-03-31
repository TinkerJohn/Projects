/*
     Servo Motor Control using the Arduino Servo Library
*/

#include <Servo.h>

Servo pan;  // create servo object to control a servo
Servo tilt;
int ls_tilt=0;
int ls_pan=0;
int i,j;

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

    pan.attach(2);  // (pin, min, max)
    tilt.attach(3); 
    Serial.println("3. Centering");
    pan.write(80);
    tilt.write(80);
    delay(1000);
    Serial.println("Positioned");
    delay(1000);
    Serial.println("\n");

    Serial.println("Enter correct direction: (t, b, l, r, tr, tl, br, bl, o, c)");
}

void loop() 
{
 if(Serial.available()>0)   
 {
  String cmd= Serial.readString(); //Reading the Input string from Serial port. 

  if(cmd=="t\n") //Pan=80 and Tilt=125
  {
    Serial.println("Top");
    if(ls_pan<80)
    {
    for(i=ls_pan; i<=80; i++)
    {
      pan.write(i);
      delay(10);
    }
    }
    else
    {
    for(i=ls_pan; i>=80; i--)
    {
      pan.write(i);
      delay(10);
    }
    }
    ls_pan=80;
    if(ls_tilt<125)
    {
    for(j=ls_tilt; j<=125; j++)
    {
      tilt.write(j);
      delay(10);
    }
    }
    else
    {
    for(j=ls_pan; j>=125; j--)
    {
      tilt.write(j);
      delay(10);
    }
    }
    ls_tilt=125;
  }


  
  else if(cmd=="b\n") //Pan=80 and Tilt=35
  {
    Serial.println("Bottom");
    if(ls_pan<80)
    {
    for(i=ls_pan; i<=80; i++)
    {
      pan.write(i);
      delay(10);
    }
    }
    else
    {
    for(i=ls_pan; i>=80; i--)
    {
      pan.write(i);
      delay(10);
    }
    }
    ls_pan=80;
    if(ls_tilt<35)
    {
    for(j=ls_tilt; j<=35; j++)
    {
      tilt.write(j);
      delay(10);
    }
    }
    else
    {
    for(j=ls_tilt; j>=35; j--)
    {
      tilt.write(j);
      delay(10);
    }
    }
    ls_tilt=35;
  }


  
  else if(cmd=="l\n") //Pan=0 and Tilt=125
  {
    Serial.println("Left");
    if(ls_pan<0)
    {
    for(i=ls_pan; i<=0; i++)
    {
      pan.write(i);
      delay(10);
    }
    }
    else
    {
    for(i=ls_pan; i>=0; i--)
    {
      pan.write(i);
      delay(10);
    }
    }
    ls_pan=0;
    if(ls_tilt<125)
    {
    for(j=ls_tilt; j<=125; j++)
    {
      tilt.write(j);
      delay(10);
    }
    }
    else
    {
    for(j=ls_tilt; j>=125; j--)
    {
      tilt.write(j);
      delay(10);
    }
    }
    ls_tilt=125;
  }


  
  else if(cmd=="r\n") //Pan=0 and Tilt=35
  {
    Serial.println("Right");
    if(ls_pan<0)
    {
    for(i=ls_pan; i<=0; i++)
    {
      pan.write(i);
      delay(10);
    }
    }
    else
    {
    for(i=ls_pan; i>=0; i--)
    {
      pan.write(i);
      delay(10);
    }
    }
    ls_pan=0;
    if(ls_tilt<35)
    {
    for(j=ls_tilt; j<=35; j++)
    {
      tilt.write(j);
      delay(10);
    }
    }
    else
    {
    for(j=ls_tilt; j>=35; j--)
    {
      tilt.write(j);
      delay(10);
    }
    }
    ls_tilt=35;     
  }


  
  else if(cmd=="tr\n") //Pan=125 and Tilt=125
  {
    Serial.println("Top Right");
    if(ls_pan<125)
    {
    for(i=ls_pan; i<=125; i++)
    {
      pan.write(i);
      delay(10);
    }
    }
    else
    {
    for(i=ls_pan; i>=125; i--)
    {
      pan.write(i);
      delay(10);
    } 
    }
    ls_pan=125;
    if(ls_tilt<125)
    {
    for(j=ls_tilt; j<=125; j++)
    {
      tilt.write(j);
      delay(10);
    }
    }
    else
    {
    for(j=ls_tilt; j>=125; j--)
    {
      tilt.write(j);
      delay(10);
    }
    }
    ls_tilt=125;
  }


  
  else if(cmd=="tl\n") //Pan=35 and Tilt=125
  {
    Serial.println("Top Left");
    if(ls_pan<35)
    {
    for(i=ls_pan; i<=35; i++)
    {
      pan.write(i);
      delay(10);
    }
    }
    else
    {
    for(i=ls_pan; i>=35; i--)
    {
      pan.write(i);
      delay(10);
    }
    }
    ls_pan=35;
    if(ls_tilt)
    {
    for(j=ls_tilt; j<=125; j++)
    {
      tilt.write(j);
      delay(10);
    }
    }
    else
    {
    for(j=ls_tilt; j>=125; j--)
    {
      tilt.write(j);
      delay(10);
    }
    }
    ls_tilt=125;
  }


  
  else if(cmd=="br\n") //Pan=35 and Tilt=35
  {
    Serial.println("Bottom Right");
    if(ls_pan<35)
    {
    for(i=ls_pan; i<=35; i++)
    {
      pan.write(i);
      delay(10);
    }
    }
    else
    {
      for(i=ls_pan; i>=35; i--)
    {
      pan.write(i);
      delay(10);
    }
    }
    ls_pan=35;
    if(ls_tilt<35)
    {
    for(j=ls_tilt; j<=35; j++)
    {
      tilt.write(j);
      delay(10);
    }
    }
    else
    {
    for(j=ls_tilt; j>=35; j--)
    {
      tilt.write(j);
      delay(10);
    }
    }
    ls_tilt=35; 
  }


  
  else if(cmd=="bl\n") //Pan=125 and Tilt=35
  {
    Serial.println("Bottom Left");
    if(ls_pan<125)
    {
    for(i=ls_pan; i<=125; i++)
    {
      pan.write(i);
      delay(10);
    }
    }
    else
    {
    for(i=ls_pan; i>=125; i--)
    {
      pan.write(i);
      delay(10);
    }
    }
    ls_pan=125;
    if(ls_tilt<35)
    {
    for(j=ls_tilt; j<=35; j++)
    {
      tilt.write(j);
      delay(10);
    }
    }
    else
    {
    for(j=ls_tilt; j>=35; j--)
    {
      tilt.write(j);
      delay(10);
    }
    }
    ls_tilt=35;
  }


  
  else if(cmd=="o\n") //Pan=0 and Tilt=0
  {
    Serial.println("Origin");
    if(ls_pan<0)
    {
    for(i=ls_pan; i<=0; i++)
    {
      pan.write(i);
      delay(10);
    }
    }
    else
    {
    for(i=ls_pan; i>=0; i--)
    {
      pan.write(0);
      delay(10);
    }
    }
    ls_pan=0;
    for(j=ls_tilt; j>=0; j--)
    {
      tilt.write(j);
      delay(10);
    }
    ls_tilt=0;
  }


  else if(cmd=="c\n") //Pan=80 and Tilt=80
  {
    Serial.println("Center");
    if(ls_pan<80)
    {
    for(i=ls_pan; i<=80; i++)
    {
      pan.write(i);
      delay(10);
    }
    }
    else
    {
    for(i=ls_pan; i>=80; i--)
    {
      pan.write(i);
      delay(10);
    }
    }
    ls_pan=80;
    if(ls_tilt<80)
    {
    for(j=ls_tilt; j<=80; j++)
    {
      tilt.write(j);
      delay(10);
    }
    }
    else
    {
    for(j=ls_pan; j>=80; j--)
    {
      tilt.write(j);
      delay(10);
    }
    }
    ls_tilt=80; 
  }


  else if(cmd=="x\n") //Pan=0 and Tilt=0
  {
    Serial.println("pan");
    Serial.println(pan.read());
    Serial.println("tilt");
    Serial.println(tilt.read());
  }
  
  else
  {
    Serial.println("Enter correct direction: (t, b, l, r, tr, tl, br, bl, o, c)"); 
  }


  
 }                     
}
