// sketch to test the key pressed & display on LCD as well as Serial monitor

#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
// set up the LCD’s number of columns and rows:
lcd.begin(16, 2);
// Print a message to the LCD.
lcd.setCursor(0,0);
lcd.print("LCD Key Shield");
lcd.setCursor(0,1);
lcd.print("Press Key:");
Serial.begin(9600);
}

void loop() {
int x;
x = analogRead (0);
lcd.setCursor(10,1);
if (x < 100) {
lcd.print ("Right  ");
Serial.print("The value at pim A0 ‘Right key pressed’ is  :");
Serial.println(x,DEC);
}
else if (x < 200) {
lcd.print ("Up    ");
Serial.print("The value at pim A0 ‘UP key pressed’ is  :");
Serial.println(x,DEC);
}
else if (x < 400){
lcd.print ("Down  ");
Serial.print("The value at pim A0 ‘Down key pressed’ is  :");
Serial.println(x,DEC);
}
else if (x < 600){
lcd.print ("Left  ");
Serial.print("The value at pim A0 ‘Left key pressed’ is  :");
Serial.println(x,DEC);
}
else if (x < 800){
lcd.print ("Select");
Serial.print("The value at pim A0 ‘Select key pressed is  :");
Serial.println(x,DEC);
}
}
