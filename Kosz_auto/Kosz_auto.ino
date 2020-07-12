#include <Servo.h>
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int pos = 30;    // variable to store the servo position
#define sensor 11
#define del 2000

void otworz()
{
for (pos = 0;pos <= 120; pos += 1) ///   OTWIERANIE 
  { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(7);                       // waits 15ms for the servo to reach the position
  }
}

void zamknij()
{
for (pos = 120; pos >= 0; pos -= 1)//  ZAMYKANIE
  { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(7);                       // waits 15ms for the servo to reach the position
  }
  
}


void setup() {
   pinMode(sensor,INPUT); //left sensor
  myservo.attach(12);  // attaches the servo on pin 9 to the servo object
  otworz();
  delay(1000);
  zamknij();
//  for (pos = 0;pos <= 120; pos += 1) ///   OTWIERANIE 
//  { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(7);                       // waits 15ms for the servo to reach the position
//  }
//  delay(1000);
//  for (pos = 120; pos >= 0; pos -= 1)//  ZAMYKANIE
//  { // goes from 180 degrees to 0 degrees
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(7);                       // waits 15ms for the servo to reach the position
//  }
  
}

void loop() {
  
   if(digitalRead(sensor)==0)
  {
    otworz();
    delay(del);
    zamknij();
  }
  delay(200);
}



 
