
String lvl;
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Woltage: ");
  Serial.println(analogRead(A0));
  // lvl== high, medium, low, 0;
  if(analogRead(A0)>670)
  {
    lvl="high";
  }
  if (analogRead(A0)<=670)
  {
    lvl="medium";
  }
  if (analogRead(A0)<620)
  {
    lvl="low";
  }
  if (analogRead(A0)==0)
  {
    lvl="0";
  }
  Serial.print("Water Level: ");
  Serial.println(lvl);
  delay(1000);
}
