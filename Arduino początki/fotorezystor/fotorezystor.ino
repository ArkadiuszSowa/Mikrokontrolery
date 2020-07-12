int dioda=2;
int fotorez;
int przerwa;

void setup() {
  // put your setup code here, to run once:
  pinMode(dioda, OUTPUT);
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.begin(9600);
  fotorez=analogRead(A0);


  przerwa=map(fotorez, 0,1023, 50, 1000);

  Serial.print("fotorez: ");
  Serial.println(fotorez);
  Serial.print("przrewa: ");
  Serial.println(przerwa);

  digitalWrite(dioda, HIGH);
  delay(przerwa);
  digitalWrite(dioda, LOW);
  delay(przerwa);
  
}
