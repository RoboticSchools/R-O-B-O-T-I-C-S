#include <IRremote.h>

int IR_Recv = 2; //IR Receiver Pin 2
IRrecv irrecv(IR_Recv);
decode_results results;

void setup(){
  pinMode(13, OUTPUT);
  Serial.begin(9600); //starts serial communication
  irrecv.enableIRIn(); // Starts the receiver
}

void loop(){
  if (irrecv.decode(&results))
  {
    long int decCode = results.value;
    Serial.println(decCode);
    irrecv.resume();
  }
