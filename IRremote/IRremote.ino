/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  pinMode(13,OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);//1045770

    irrecv.resume(); // Receive the next value
  }
  delay(100);
        if(16732335==results.value){
    digitalWrite(13,HIGH);
     delay(500);
  }else{
    digitalWrite(13,LOW);
   
  }

}
