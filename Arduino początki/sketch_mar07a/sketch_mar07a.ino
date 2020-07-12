#define trig            7
#define echo            8

int dist=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int czas;
  digitalWrite(trig, HIGH);
  delay(1);
  digitalWrite(trig, LOW);
  czas=pulseIn(echo, HIGH);
  dist=czas/58;
  Serial.println(czas);
  Serial.println(dist);
  delay(1000);
}
