//Alcohol Detector
const int MQ3=A0;
int value;

void setup() {
  Serial.begin(9600);
  pinMode(MQ3, INPUT);
}

void loop()
{
  value= analogRead(MQ3);
  Serial.println(value);
  delay (500);
}
