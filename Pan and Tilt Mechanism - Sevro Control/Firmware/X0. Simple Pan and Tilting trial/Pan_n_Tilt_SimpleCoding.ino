 #include <Servo.h>
Servo pan;
Servo tilt;
int pos = 0;



void setup()

{

Serial.begin(9600);
while (!Serial);
Serial.println("-------------------------");
Serial.println("Pan & Tilt Mechanism is getting ready....");
delay(1000);
Serial.println("Pan & Tilt Mechanism is ready");
Serial.println("-------------------------");
pan.attach(2);
Serial.println("Pan is Calibrating...");
for(pos = 0; pos <= 180; pos += 1)
pan.write(0);
delay(1000);
pan.write(180);
delay(1000);
pan.write(90);
delay(1000);
tilt.attach(3);
Serial.println("Tilt is Calibrating...");
for(pos = 0; pos <= 180; pos += 1)
tilt.write(0);
delay(1000);
tilt.write(180);
delay(1000);
tilt.write(90);
delay(1000);
Serial.println("servo calibrated");
Serial.println("-------------------------");
Serial.println("Comand input online, write command to perform action");
Serial.println("-------------------------");

}

void loop() {
  
for(pos = 0; pos <= 180; pos += 1)
if (Serial.available())


{
  String cmd=Serial.readStringUntil(' ');
  String cmd1=Serial.readString();
  
//  int paning = Serial.parseInt();
   int paning=cmd.toInt();
   int tilting=cmd1.toInt();
   // Serial.print(paning);Serial.print("\t"); Serial.println(tilting);
if (paning < 10)

{
Serial.print(">");
Serial.println(paning);
Serial.println("cannost execute command, too low number");

}

if (paning >= 10 && paning < 170)
{
  Serial.print(">");
  Serial.println(paning);
  Serial.print("paning servo to ");
  Serial.print(paning);
  Serial.println(" degrees");
  pan.write(paning);
  
}


//  int tilting = Serial.parseInt();
if (tilting < 10)

{
Serial.print(">");
Serial.println(tilting);
Serial.println("cannost execute command, too low number");

}

if (tilting >= 10 && tilting < 170)
{
  Serial.print(">");
  Serial.println(tilting);
  Serial.print("tilting servo to ");
  Serial.print(tilting);
  Serial.println(" degrees");
  tilt.write(tilting);
  
}

}

}



  
