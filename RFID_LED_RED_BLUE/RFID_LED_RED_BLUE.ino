//Viral Science www.youtube.com/c/viralscience
//RFID Solenoid Lock

#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 5 //SDA
#define RST_PIN 6
#define LED_G 3 //define green LED pin
#define LED_R 2 //define red LED
#define ACCESS_DELAY 2000
#define DENIED_DELAY 1000
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
 
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();          // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
  Serial.println("Put your card to the reader...");
  Serial.println();
  digitalWrite(LED_R, HIGH);
  digitalWrite(LED_G, HIGH);
}
void loop()  
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
//  for (byte i = 0; i < mfrc522.uid.size; i++) 
 // {
     //Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     //Serial.print(mfrc522.uid.uidByte[i], HEX);
     //content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     //content.concat(String(mfrc522.uid.uidByte[i], HEX));
 // }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "39 82 A5 59")
  {
    Serial.println("Authorized access TOKEN");
    Serial.println();
    delay(200);
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_R, LOW);
    delay(500); 
    digitalWrite(LED_G, LOW);
    
  }
  else if (content.substring(1) == "E7 40 C0 69")
 {
  Serial.println("Authorized access CARD");
    Serial.println();
    delay(200);
    for(int i=0; i<3;i++)
    {
    digitalWrite(LED_G, HIGH);
    digitalWrite(LED_R, LOW);
    delay(150); 
    digitalWrite(LED_G, LOW);
    delay(50);
    }
 }
  
 else   {
    Serial.println(" Access denied");
    Serial.println();
    delay(200);
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, LOW);
    delay(500);
    digitalWrite(LED_R, LOW);
  }
}
