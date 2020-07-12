//////////////////////////////////////           WORKS ON NodeMCU 1.0(ESP.12E Module) 80Hz           /////////////////////////////////////

#define BLYNK_PRINT Serial
#include <LiquidCrystal_I2C.h>

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
 
#define RightMotorSpeed D1
#define RightMotorDir   D3 
#define LeftMotorSpeed  D2 
#define LeftMotorDir    D4

#define LED             D5

#define trig            D7
#define echo            D8


 
char auth[] = "BZ4KAcQ8crajY5GZdfDfye3tqr8AwYUq";
char ssid[] = "UPC2028476";//"KSDZ";
char pass[] = "Sp2yxzzaxm7m";//"1972ptak!";

int minRange = 312;
int maxRange = 712;

int minSpeed = 450;
int maxSpeed = 1023;
int noSpeed = 0;

int dist=0;
 
LiquidCrystal_I2C lcd(0x27,20,2);

void measure()
{
  int czas;
  digitalWrite(trig, HIGH);
  delay(1);
  digitalWrite(trig, LOW);
  czas=pulseIn(echo, HIGH);
  dist=czas/58;
}

void moveForward(int del)
{
  digitalWrite(RightMotorDir,HIGH);  
  digitalWrite(LeftMotorDir,HIGH);
  analogWrite(RightMotorSpeed,maxSpeed); 
  analogWrite(LeftMotorSpeed,maxSpeed);
  delay(del);
  digitalWrite(RightMotorDir,LOW);  
  digitalWrite(LeftMotorDir,LOW);
  analogWrite(RightMotorSpeed,noSpeed); 
  analogWrite(LeftMotorSpeed,noSpeed);
}
void moveBack(int del)
{
  digitalWrite(RightMotorDir,LOW);
  digitalWrite(LeftMotorDir,LOW);
  analogWrite(RightMotorSpeed,maxSpeed); 
  analogWrite(LeftMotorSpeed,maxSpeed);
  delay(del);
  digitalWrite(RightMotorDir,LOW);  
  digitalWrite(LeftMotorDir,LOW);
  analogWrite(RightMotorSpeed,noSpeed); 
  analogWrite(LeftMotorSpeed,noSpeed);

}

void moveControl(int x, int y)
{

  if(y >= maxRange && x >= minRange && x <= maxRange) //zataci R
  {
    digitalWrite(RightMotorDir,HIGH);  
    digitalWrite(LeftMotorDir,HIGH);
    analogWrite(RightMotorSpeed,maxSpeed); 
    analogWrite(LeftMotorSpeed,maxSpeed);
  }
  
  // move forward right
  else if(x >= maxRange && y >= maxRange)   //zataci R
  {
    digitalWrite(RightMotorDir,HIGH);
    digitalWrite(LeftMotorDir,HIGH);
    analogWrite(RightMotorSpeed,maxSpeed); 
    analogWrite(LeftMotorSpeed,minSpeed);
  }
 
  // move forward left
  else if(x <= minRange && y >= maxRange)
  {
      digitalWrite(RightMotorDir,HIGH);
    digitalWrite(LeftMotorDir,HIGH);
   analogWrite(RightMotorSpeed,minSpeed); 
    analogWrite(LeftMotorSpeed,maxSpeed);
  }
 
  // neutral zone
  else if(y < maxRange && y > minRange && x < maxRange && x > minRange)
  {
    analogWrite(RightMotorSpeed,noSpeed); 
    analogWrite(LeftMotorSpeed,noSpeed);
  }
 
 // move back
  else if(y <= minRange && x >= minRange && x <= maxRange)
  {
    digitalWrite(RightMotorDir,LOW);
    digitalWrite(LeftMotorDir,LOW);
   analogWrite(RightMotorSpeed,maxSpeed); 
    analogWrite(LeftMotorSpeed,maxSpeed);
  }
 
  // move back and right
 else if(y <= minRange && x <= minRange)
  {
   digitalWrite(RightMotorDir,LOW);
    digitalWrite(LeftMotorDir,LOW);
    analogWrite(RightMotorSpeed,minSpeed); 
    analogWrite(LeftMotorSpeed,maxSpeed);  
  }
 
  // move back and left
  else if(y <= minRange && x >= maxRange)
  {
    digitalWrite(RightMotorDir,LOW);
    digitalWrite(LeftMotorDir,LOW);
    analogWrite(RightMotorSpeed,maxSpeed); 
    analogWrite(LeftMotorSpeed,minSpeed);
  }
}



void lamp(int switch1)
{
  if(switch1==1) digitalWrite(LED, HIGH);
  else if(switch1==0) digitalWrite(LED, LOW);  
}


 
void setup()
{
  // initial settings for motors off and direction forward
  pinMode(RightMotorSpeed, OUTPUT);
  pinMode(LeftMotorSpeed, OUTPUT);
  pinMode(RightMotorDir, OUTPUT);
  pinMode(LeftMotorDir, OUTPUT);
  pinMode(LED,OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  digitalWrite(RightMotorSpeed, LOW);
  digitalWrite(LeftMotorSpeed, LOW);
  digitalWrite(RightMotorDir, HIGH);
  digitalWrite(LeftMotorDir,HIGH);
  digitalWrite(LED, LOW);
  Blynk.begin(auth, ssid, pass);


  //Wire.begin(3,1);
  lcd.init();
    //Print a message to the LCD.
  lcd.backlight();
   lcd.setCursor(0,0);
  lcd.print("Odleglosc");
 }
 
 
void loop()
{
  Blynk.run();
}
 

BLYNK_WRITE(V5)
 {
  digitalWrite(RightMotorDir,LOW);  
  digitalWrite(LeftMotorDir,LOW);
  analogWrite(RightMotorSpeed,noSpeed); 
  analogWrite(LeftMotorSpeed,noSpeed);
 }


BLYNK_WRITE(V1)
{
  int x = param[0].asInt();
  int y = param[1].asInt();
  moveControl(x,y); 
 
  
}
BLYNK_WRITE(V2)
{
  int switch1 = param.asInt();
  lamp(switch1);
  measure();
  lcd.setCursor(8,0);
  lcd.print(param.asInt());
  if (dist>18 && switch1==1)
  {
    moveForward(300);
    measure();
    switch1=param.asInt();
  }
  if (dist<9 && switch1==1)
  {
    moveBack(200);
    measure(); 
    switch1=param.asInt();
  }

}
BLYNK_WRITE(V3)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Odleglosc");
  measure();
  lcd.setCursor(0,1);
  lcd.print(dist);
  lcd.setCursor(5,1);
  lcd.print("cm");
}
