//Silnik krokowy + zasłonka
int Pin1 = 8; 
int Pin2 = 9; 
int Pin3 = 10; 
int Pin4 = 4; 
int count=0;
int _step = 0; 
boolean dir = true;// false=clockwise, true=counter clockwise
#define sensor 7
int ttime=0;
#include <SPI.h>//RFID 
#include <MFRC522.h>
 
#define SS_PIN 5 //SDA
#define RST_PIN 6
#define LED_G 3 //define green LED pin
#define LED_R 2 //define red LED
#define ACCESS_DELAY 2000
#define DENIED_DELAY 1000
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.


void silnik ()
{
  
switch(_step)
{ 
   case 0: 
     digitalWrite(Pin1, LOW);  
     digitalWrite(Pin2, LOW); 
     digitalWrite(Pin3, LOW); 
     digitalWrite(Pin4, HIGH); 
   break;  
   case 1: 
     digitalWrite(Pin1, LOW);  
     digitalWrite(Pin2, LOW); 
     digitalWrite(Pin3, HIGH); 
     digitalWrite(Pin4, HIGH); 
   break;  
   case 2: 
     digitalWrite(Pin1, LOW);  
     digitalWrite(Pin2, LOW); 
     digitalWrite(Pin3, HIGH); 
     digitalWrite(Pin4, LOW); 
   break;  
   case 3: 
     digitalWrite(Pin1, LOW);  
     digitalWrite(Pin2, HIGH); 
     digitalWrite(Pin3, HIGH); 
     digitalWrite(Pin4, LOW); 
   break;  
   case 4: 
     digitalWrite(Pin1, LOW);  
     digitalWrite(Pin2, HIGH); 
     digitalWrite(Pin3, LOW); 
     digitalWrite(Pin4, LOW); 
   break;  
   case 5: 
     digitalWrite(Pin1, HIGH);  
     digitalWrite(Pin2, HIGH); 
     digitalWrite(Pin3, LOW); 
     digitalWrite(Pin4, LOW); 
   break;  
     case 6: 
     digitalWrite(Pin1, HIGH);  
     digitalWrite(Pin2, LOW); 
     digitalWrite(Pin3, LOW); 
     digitalWrite(Pin4, LOW); 
   break;  
   case 7: 
     digitalWrite(Pin1, HIGH);  
     digitalWrite(Pin2, LOW); 
     digitalWrite(Pin3, LOW); 
     digitalWrite(Pin4, HIGH); 
   break;  
   default: 
     digitalWrite(Pin1, LOW);  
     digitalWrite(Pin2, LOW); 
     digitalWrite(Pin3, LOW); 
     digitalWrite(Pin4, LOW); 
   break;  
 } 
 if(dir){ 
   _step++; 
 }else{ 
   _step--; 
 } 
 if(_step>7){ 
   _step=0; 
 } 
 if(_step<0){ 
   _step=7; 
 } 
delay (2);
}
void silnikoff()
{
     digitalWrite(Pin1, LOW);  
     digitalWrite(Pin2, LOW); 
     digitalWrite(Pin3, LOW); 
     digitalWrite(Pin4, LOW); 
}


                   /////////////////////////////////////////////////////////SETUP///////////////////////////////////////////////////////////////////////////////////////////


void setup() 
{ 
 Serial.begin (9600);
 pinMode(Pin1, OUTPUT);  
 pinMode(Pin2, OUTPUT);  
 pinMode(Pin3, OUTPUT);  
 pinMode(Pin4, OUTPUT);  
 pinMode(sensor, INPUT);
  SPI.begin();          // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
  analogWrite(LED_R, 130);
  analogWrite(LED_G, 30);
} 
 void loop() 
{ 
 // Look for new cards
  if ( mfrc522.PICC_IsNewCardPresent()) 
  {
    mfrc522.PICC_ReadCardSerial();
    return;
  }
  /* // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }*/

  
 
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  if (content.substring(1) == "39 82 A5 59" || content.substring(1) == "E7 40 C0 69")
  {
    analogWrite(LED_G, 30);
    if(digitalRead(sensor)==1){
   // Serial.println(ttime);
      if(ttime>30)
     {
      silnikoff();
      analogWrite(LED_R, 0);
    
     // delay(1000);
     }else{
      for(int i=0; i<1000; i++){
        silnik();
      }
    
    }
    ttime++;
    }
  }
   else if (content.substring(1) != "39 82 A5 59" && content.substring(1) != "E7 40 C0 69" && content.substring(1) !="")
   {
    
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_R, HIGH);
  }
 
 //else{
 //   silnikoff();
 //   ttime=0;
// }
  
//spróbuj zamienić if z else, nadpisuj ten kod z karty starym kodem, jeżeli nie ma nowej karty

}
