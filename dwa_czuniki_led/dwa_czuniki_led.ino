int sensor1=7;
int sensor2=6;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(sensor1, INPUT);
pinMode(sensor2, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
   Serial.print(" sensor1: ");
   Serial.print(digitalRead(sensor1));
   Serial.print("  sensor2: ");
   Serial.println(digitalRead(sensor2));
   
   delay(500);

}
