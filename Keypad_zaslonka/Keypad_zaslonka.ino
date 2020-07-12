///////////////////////////////////////////    KEYPAD   ///////////////////////////////////////

#include <Keypad.h> 
const byte numRows= 4; //number of rows on the keypad
const byte numCols= 3; //number of columns on the keypad

//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols]= 
{
{'1', '2', '3'}, 
{'4', '5', '6'}, 
{'7', '8', '9'},
{'*', '0', '#'}
};


byte rowPins[numRows] = {5,4,3,2}; //Rows 0 to 3 //if you modify your pins you should modify this too
byte colPins[numCols]= {9,10,11}; //Columns 0 to 3

int i1,i2,i3,i4;
char c1,c2,c3,c4;
char key_char, key1_char, keypressedx;
int key_int=0; 
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
///////////////////////////////////////////      LCD     ///////////////////////////////////////
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);

//////////////////////////////////////    REAL TIME MODULE    //////////////////////////////////
#include <DS1302.h>
// DS1302:  RST pin    -> Arduino Digital A0
//          DATA pin   -> Arduino Digital A1
//          CLK pin  -> Arduino Digital A2
int RST=6, DATA=7, CLK=12;
DS1302 rtc(RST, DATA, CLK);

Time t;
int A_hour=NULL;
int A_minute=NULL;
int AlarmIsActive=NULL;
int godzina, minuta;

void seTime()
{
 // Display time centered on the upper line
  lcd.setCursor(0, 0);
  lcd.print(rtc.getTimeStr());
  
  // Display abbreviated Day-of-Week in the lower left corner
  lcd.setCursor(9, 0);
  lcd.print(rtc.getDOWStr(FORMAT_SHORT));
  
  // Display date in the lower right corner
  lcd.setCursor(6, 1);
  lcd.print(rtc.getDateStr());
  
  // Wait one second before repeating :)
  delay(50);
}

void change_ascii(char key_char)
{
 switch(key_char)
 {
  case 49:key_int=1;break;
  case 50:key_int=2;break;
  case 51:key_int=3;break;
  case 52:key_int=4;break;
  case 53:key_int=5;break;
  case 54:key_int=6;break;
  case 55:key_int=7;break;
  case 56:key_int=8;break;
  case 57:key_int=9;break;
  case 48:key_int=0;break;
 }   
}

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
  digitalWrite(8 ,LOW);
  lcd.init();
  lcd.backlight();
  delay(300);
  
   // Set the clock to run-mode, and disable the write protection
  rtc.halt(false);
  rtc.writeProtect(false);
  // The following lines can be commented out to use the values already stored in the DS1302
  //rtc.setDOW(MONDAY);        // Set Day-of-Week to FRIDAY
  //rtc.setTime(00, 32, 0);     // Set the time to 12:00:00 (24hr format)
  //rtc.setDate(02, 01, 2020);   // Set the date to August 6th, 2010

  seTime();
  lcd.setCursor(0,0);
  lcd.print("chuj dupa i kamieni kupa");
  delay(2000);
//  customKeypad.begin();
}

void loop() {
while(key_char == NO_KEY){ //As long as no key is pressed we keep showing the date and time, I'm obliged to clear the screen everytime so the numbers don't get confused
                               //And I should add that little delay so the screen shows correctly otherwise it didn't work for me
  key_char = myKeypad.getKey();
   //Here after clearing the LCD we take the time from the module and print it on the screen with usual LCD functions
 
 
 
  seTime();
  t = rtc.getTime();
  
 
 if(t.hour==godzina && t.min==minuta && AlarmIsActive==1 && t.sec >= 0 && t.sec <= 2) 
  {
   while(keypressedx == NO_KEY)
   {
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
    delay(100);
    lcd.clear();
    lcd.print("Opening!!!"); //Message to show when the alarm is ringing
    
    keypressedx = myKeypad.getKey();
   }
  }
  
  if(key_int>100) lcd.noBacklight();
  key_int++;
 }

 lcd.backlight();
 key_int=0;
 if (key_char =='1')
  {
    Serial.println(t.min);
    digitalWrite(13, HIGH);
  }
 if(key_char =='2')
  {
   lcd.setCursor(0,1);
   lcd.print(key_char);
   digitalWrite(13,LOW);
  }
   if(key_char =='3')
  {
   lcd.setCursor(1,1);
   lcd.print(key_char);
   digitalWrite(8,HIGH);
  }
   if(key_char =='4')
  {
   lcd.setCursor(1,1);
   lcd.print(key_char);
   digitalWrite(8,LOW);
  }
  
       if (key_char == '#' && AlarmIsActive==0){
             
             lcd.backlight();
             key_int=0;
             
             lcd.clear();
             lcd.print("  Alarm setup  ");
             delay(500);
             lcd.clear();
             lcd.print("Set alarm hour");
               
              char keypressed14 = myKeypad.waitForKey();  // here all programs are stopped until you enter the four digits then it gets compared to the code above
                    if (keypressed14 != NO_KEY && keypressed14 !='*' && keypressed14 !='#' && keypressed14 !='A' && keypressed14 !='B' && keypressed14 !='C' && keypressed14 !='D' )
                      {
                       c1 = keypressed14;
                       lcd.setCursor(0, 1);
                       lcd.print(c1);
                       }
                    char   keypressed15 = myKeypad.waitForKey();
                    if (keypressed15 != NO_KEY && keypressed15 !='*' && keypressed15 !='#' && keypressed15 !='A' && keypressed15 !='B' && keypressed15 !='C' && keypressed15 !='D' )
                      {
                        c2 = keypressed15;
                       lcd.setCursor(1, 1);
                       lcd.print(c2);
                       }


                     i1=(c1-48)*10;
                     i2=c2-48;
                     godzina=i1+i2;
                    delay(500);
                     lcd.clear();
                     lcd.print("Set alarm minutes");
                      char keypressed16 = myKeypad.waitForKey();  // here all programs are stopped until you enter the four digits then it gets compared to the code above
                    if (keypressed16 != NO_KEY && keypressed16 !='*' && keypressed16 !='#' && keypressed16 !='A' && keypressed16 !='B' && keypressed16 !='C' && keypressed16 !='D' )
                      {
                       c1 = keypressed16;
                       lcd.setCursor(0, 1);
                       lcd.print(c1);
                       }
                    char   keypressed17 = myKeypad.waitForKey();
                    if (keypressed17 != NO_KEY && keypressed17 !='*' && keypressed17 !='#' && keypressed17 !='A' && keypressed17 !='B' && keypressed17 !='C' && keypressed17 !='D' )
                      {
                        c2 = keypressed17;
                       lcd.setCursor(1, 1);
                       lcd.print(c2);
                       }


                     i1=(c1-48)*10;
                     i2=c2-48;
                     minuta=i1+i2;
                    delay(500);
                     lcd.clear();
                     AlarmIsActive=1;
                     key_char=NO_KEY;
             }
             
             if (key_char == '#' && AlarmIsActive==1)
             {

               lcd.backlight();
               key_int=0;
              
              lcd.clear();
              lcd.print("Alarm deactivated");
              AlarmIsActive=0;
              key_char=NO_KEY;
              delay(500);
             }
             else {
              seTime();
              key_char=NO_KEY;
             }
             


}
