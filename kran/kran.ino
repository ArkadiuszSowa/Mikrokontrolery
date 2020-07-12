#define sensor 9
#define motor 2
void setup() {
   pinMode(sensor,INPUT); //sensor  
   pinMode(motor, OUTPUT);
   digitalWrite(motor, LOW);
}

void loop() {
  
   if(digitalRead(sensor)==0)
  {
    digitalWrite(motor, HIGH);
  }
  else
  {
    digitalWrite(motor, LOW);
  }
  delay(300);
}



 
