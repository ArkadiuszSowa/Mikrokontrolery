void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i=0;
  for(i=0; i<50; i++)  //i++ -> i=i+1
  {
    analogWrite(2,i*5);
    delay(100);
  }
}
