// sketch to test the key pressed & display on LCD as well as Serial monitor

#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int sekundy, minuty, godziny;
boolean x=true;

void setup() {
  pinMode(A1,OUTPUT);
// set up the LCD’s number of columns and rows:
lcd.begin(16, 2);
// Print a message to the LCD.
lcd.setCursor(0,0);
lcd.print("Pij wode");

lcd.setCursor(0,1);
lcd.print("bedziesz WIELKI");
delay(1500);
Serial.begin(9600);
sekundy=0;
minuty=0;
godziny=0;
lcd.setCursor(9,0);
lcd.print("nalewam");
digitalWrite(A1,HIGH);
delay(6000);
digitalWrite(A1,LOW);
lcd.setCursor(9,0);
//    lcd.print("0");
lcd.print("0000000");
}

void loop() {

sekundy+=1;
if(sekundy>59){
  lcd.setCursor(9,0);
  lcd.print("0");
  sekundy=0;
  minuty+=1;
  if(minuty>59){
    lcd.setCursor(9,0);
    lcd.print("0");
    lcd.setCursor(13,0);
    lcd.print("0");
    minuty=0;
    godziny+=1;    
  }
}

if(sekundy<10){
  lcd.setCursor(10,0);
 
}else{
  lcd.setCursor(9,0);
}
lcd.print(sekundy);

lcd.setCursor(11,0);
lcd.print(":");


if(minuty<10){
  lcd.setCursor(13,0);
 
}else{
  lcd.setCursor(12,0);
}
lcd.print(minuty);

lcd.setCursor(14,0);
lcd.print(":");
lcd.setCursor(15,0);
lcd.print(godziny);

if(sekundy<13 && minuty<1){
  delay(990);
}else if(minuty>=30){
  if(x){
    x=false;
    lcd.setCursor(9,0);mfldsnfsdkds,d sdnklas
    lcd.print("nalewam");
    digitalWrite(A1,HIGH);
    delay(6000);
    digitalWrite(A1,LOW);
    lcd.setCursor(9,0);
    lcd.print("0000000");
  }
  delay(990);
}else if(sekundy>55 && minuty>28){
  delay(990);
}else{
  delay(2);
}
}
