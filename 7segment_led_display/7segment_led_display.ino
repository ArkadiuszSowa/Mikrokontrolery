/*
  Showing number 0-9 on a Common Anode 7-segment LED display
  Displays the numbers 0-9 on the display, with one second inbetween.
    A
   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---
    D
  This example code is in the public domain.
 */
 
// Pin 2-8 is connected to the 7 segments of the display.

int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;
int D1=9,D2=11, D3=10, D4=12;

void each_digit_hour(int x)
{
  for(int i=0; i<2; i++)
  {
   if(i==0)
   {
    int digit1=(x/10) %10;  
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
    display_digit(digit1);
   }
   else if(i==1)
   {
    int digit2=x %10;
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
    display_digit(digit2);
    }
  }
}


void each_digit_minute(int x)
{
  for(int i=0; i<2; i++)
  {
   if(i==0)
   {
    int digit1=(x/10) %10;  
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, LOW);
    digitalWrite(D4, HIGH);
    display_digit(digit1);
   }
   else if(i==1)
   {
    int digit2=x %10;
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, LOW);
    display_digit(digit2);
    }
  }
}

void display_digit(int digit)
{
  switch(digit)
  {
    case 0:
        //0
        digitalWrite(pinA, HIGH);   
        digitalWrite(pinB, HIGH);   
        digitalWrite(pinC, HIGH);   
        digitalWrite(pinD, HIGH);   
        digitalWrite(pinE, HIGH);   
        digitalWrite(pinF, HIGH);   
        digitalWrite(pinG, LOW);   
        delay(1000);    
        break;
    case 1:
        //1
        digitalWrite(pinA, LOW);   
        digitalWrite(pinB, HIGH);   
        digitalWrite(pinC, HIGH);   
        digitalWrite(pinD, LOW);   
        digitalWrite(pinE, LOW);   
        digitalWrite(pinF, LOW);   
        digitalWrite(pinG, LOW);   
        delay(1000);   
        break;
    case 2:
        //2
        digitalWrite(pinA, HIGH);   
        digitalWrite(pinB, HIGH);   
        digitalWrite(pinC, LOW);   
        digitalWrite(pinD, HIGH);   
        digitalWrite(pinE, HIGH);   
        digitalWrite(pinF, LOW);   
        digitalWrite(pinG, HIGH);     
        delay(1000);
        break;
    case 3:
        //3
        digitalWrite(pinA, HIGH);   
        digitalWrite(pinB, HIGH);   
        digitalWrite(pinC, HIGH);   
        digitalWrite(pinD, HIGH);   
        digitalWrite(pinE, LOW);   
        digitalWrite(pinF, LOW);   
        digitalWrite(pinG, HIGH);     
       // delay(1000);   
        break;
    case 4:
        //4
        digitalWrite(pinA, LOW);   
        digitalWrite(pinB, HIGH);   
        digitalWrite(pinC, HIGH);   
        digitalWrite(pinD, LOW);   
        digitalWrite(pinE, LOW);   
        digitalWrite(pinF, HIGH);   
        digitalWrite(pinG, HIGH);     
        delay(1000);               
        break;
    case 5:
        //5
        digitalWrite(pinA, HIGH);   
        digitalWrite(pinB, LOW);   
        digitalWrite(pinC, HIGH);   
        digitalWrite(pinD, HIGH);   
        digitalWrite(pinE, LOW);   
        digitalWrite(pinF, HIGH);   
        digitalWrite(pinG, HIGH);     
        delay(1000);               
        break;
    case 6:
        //6
        digitalWrite(pinA, HIGH);   
        digitalWrite(pinB, LOW);   
        digitalWrite(pinC, HIGH);   
        digitalWrite(pinD, HIGH);   
        digitalWrite(pinE, HIGH);   
        digitalWrite(pinF, HIGH);   
        digitalWrite(pinG, HIGH);     
        delay(1000);               
        break;
    case 7:
        //7
        digitalWrite(pinA, HIGH);   
        digitalWrite(pinB, HIGH);   
        digitalWrite(pinC, HIGH);   
        digitalWrite(pinD, LOW);   
        digitalWrite(pinE, LOW);   
        digitalWrite(pinF, LOW);   
        digitalWrite(pinG, LOW);     
        delay(1000);               // wait for a second       
        break; 
    case 8:
        //8
        digitalWrite(pinA, HIGH);   
        digitalWrite(pinB, HIGH);   
        digitalWrite(pinC, HIGH);   
        digitalWrite(pinD, HIGH);   
        digitalWrite(pinE, HIGH);   
        digitalWrite(pinF, HIGH);   
        digitalWrite(pinG, HIGH);     
        delay(1000);    
        break;
    case 9:
        //9
        digitalWrite(pinA, HIGH);   
        digitalWrite(pinB, HIGH);   
        digitalWrite(pinC, HIGH);   
        digitalWrite(pinD, HIGH);   
        digitalWrite(pinE, LOW);   
        digitalWrite(pinF, HIGH);   
        digitalWrite(pinG, HIGH);     
        delay(1000);
        break;                              
  }
  
}

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pins as outputs.
  Serial.begin(9600);
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);   
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() 
{
  for(int i=0; i<=24; i++)
  {
  each_digit_hour(i);
  each_digit_minute(i+12);
  delay(1000);
  }
  
}
