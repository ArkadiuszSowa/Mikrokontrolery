#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN 11
int numPixels = 3;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numPixels  , PIN, NEO_GRB + NEO_KHZ800);

int leftBack=2;
int leftPwm=3; //analog
int leftFrw=4;
int rightBack=7;
int rightPwm=6; //analog
int rightFrw=5;
#define  sensorL A0
#define sensorR A1
int sensorM = 13;
// black 1
// white 0
//to jest enum jak cos 
  int rightDir=0;
  int leftDir=1;
  int ttime=0;
  int deltatime=0;
  int lastloop=0;
int ile=0; //to jest licznik zmian koloru
void turn(int direction, int del) //dir  z enuma, del w ms
{
  if(direction==rightDir)
  {
    digitalWrite(leftFrw, HIGH); 
    digitalWrite(rightFrw,LOW);
    digitalWrite(rightBack,HIGH);
  }
  else
  {
    digitalWrite(rightFrw, HIGH); 
    digitalWrite(leftFrw,LOW);
    digitalWrite(leftBack,HIGH);
  }
  delay(del);
  if(direction==rightDir)
  {
    digitalWrite(rightBack,LOW);
  }
  else
  {
    digitalWrite(leftBack,LOW);
  }
}
void engines_setup()      //ustawianie mocy silników
{
  analogWrite(leftPwm, 145);//145 
  analogWrite(rightPwm, 170);//170
}

void keep_on_track()
{
  if(digitalRead(sensorL)==1)
  {
    turn(leftDir,75);
  }
  else if(digitalRead(sensorR)==1)
  {
   
    turn(rightDir,75);
  }
}
void print_info()
{
   Serial.print("Left: ");
   Serial.print(digitalRead(sensorL));
   Serial.print("  Right: ");
   Serial.print(digitalRead(sensorR));
   Serial.print("  Middle: ");
   Serial.println(digitalRead(sensorM));
}
void change_color(int i)
{
  int x,y,z;
  int elo=i%3; // 0 1 lub 2
  switch(elo)
  {
   case 0:
   {
    x=255;y=0;z=0;
    break;
   }
   case 1:
   {
    x=0;y=255;z=0;
    break;
   }
   case 2:
   {
    x=0;y=0;z=225;
    break;
   }
  }
  for(int i=0;i<numPixels;i++)
  pixels.setPixelColor(i, pixels.Color(x,y,z));
  pixels.show(); 
}
void setup() {
  Serial.begin(9600);
  //granie muzyki
 // pinMode(10,OUTPUT);
//  digitalWrite(10,LOW);
  
  pinMode(A0,INPUT); //left sensor
  pinMode(A1,INPUT);  //right sensor
  pinMode(13,INPUT);  //mid sensor
  
  pinMode(2, OUTPUT); //Left Back
  pinMode(3, OUTPUT); //Left PWM
  pinMode(4, OUTPUT); //Left Forward
  
  pinMode(5, OUTPUT); //Right Back
  pinMode(6, OUTPUT); //Right PWM
  pinMode(7, OUTPUT); //Right Forward
  pixels.begin();             //powołanie do życia paska led
  pixels.setBrightness(255);   //bo rezi po oczach
  
  engines_setup();
}
bool foo(int deltaTime) //podajemy funkcji co pętle czas na białym tle (który się co chwila dodaje) i jeśli zostanie on przekroczony o ustaloną wartości to funkcja zwraca true
{
  ttime+=deltaTime;
  if(ttime>400) 
  {
     ttime=0;
    return true;
  }
  else return  false;
}
void engines_stop()
{
   analogWrite(leftPwm, 0);//145 
   analogWrite(rightPwm, 0);//170
}
void loop() {
  print_info();
  engines_setup();
  deltatime=millis()-lastloop; //deltatime - czas pojedyńczej iteracji pętli
  lastloop=millis(); //zapisanie aktualnego czasu, który minął od włączenia arduino                            
  Serial.println(ttime);
  if(digitalRead(sensorM)==1) //zerowanie czasu, który się nalicza podczas pobytu środkowego sensora na białym
  {
    ttime=0;
    deltatime=0;
  }
  keep_on_track();
  //wyłączanie kół jak podniesiemy
  if(digitalRead(sensorL)==1 && digitalRead(sensorR)==1)
  {
    engines_stop();
    while(digitalRead(sensorL)==1 && digitalRead(sensorR)==1)
    {
      ;;
    }
  }
  
  if(foo(deltatime)) //jeśli jesteśmy wystarczająco długo na białym tle to zmiana koloru
  {
   // tone(12, 139, 300);
   // // noTone(12);
    change_color(ile);
    ile++;            //zmienna pomocnnicza do cyklicznej zmiany kolorów
  }
  
  digitalWrite(leftFrw, HIGH); //lewy przod
  digitalWrite(rightFrw,HIGH); //wlaczyc prawy przod
  delay(20);
}

 
