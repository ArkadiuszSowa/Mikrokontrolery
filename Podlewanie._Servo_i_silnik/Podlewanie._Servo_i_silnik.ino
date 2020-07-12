#include <Servo.h>
int engine=7;
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int pos = 45;    // variable to store the servo position


void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(engine, OUTPUT);
 
}

void loop() {
  for (pos = 45; pos <= 135; pos += 1) 
  { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }

  digitalWrite(engine, HIGH);
  delay(3000);
  digitalWrite(engine, LOW);
  delay(1000);
  for (pos = 135; pos >= 45; pos -= 1)
  { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  digitalWrite(engine, HIGH);
  delay(3000);
  digitalWrite(engine, LOW);
  delay(1000);  

}
