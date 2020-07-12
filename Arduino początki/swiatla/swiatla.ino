void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2, HIGH);
  delay(1000);
  digitalWrite(3, HIGH);
  delay(500);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  analogWrite(4, 60);//0-255
  delay(1600);
  digitalWrite(4, LOW);
  digitalWrite(3,HIGH);
  delay(800);
  digitalWrite(3,LOW);
  
}
