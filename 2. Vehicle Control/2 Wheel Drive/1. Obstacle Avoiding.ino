// Created by RoboticSchools.
// Robotics and Coding always fun when we're doing with our hands.
// " Welcome to the Roboteer's World "

// OBSTACLE AVAOIDING ROBOT - 2 WHEEL DRIVE

#include "AFMotor.h"

#define echopin A3 // echo pin  //change these two numbers to respective numbers those are connected in Arduino.
#define trigpin A4 // Trigger pin

 

AF_DCMotor motor1(2, MOTOR12_64KHZ); // Rightside Motor
AF_DCMotor motor2(3, MOTOR12_64KHZ); // Leftside Motor

int distance;
long duration;

int set = 15;        //This is the distance between object and ultrasonic sensor to respond
 
void setup() {
  Serial.begin(9600);           // Initialize serial port
  Serial.println("Start");

  pinMode (trigpin, OUTPUT);
  pinMode (echopin, INPUT );
  
  motor1.setSpeed(255);          // set the motor speed to 0-255
  motor2.setSpeed(255);

}

void loop() {
 distance = data();
 Serial.print("S=");
 Serial.println(distance);
  if (distance > set){
    Serial.println("Forward");
    motor1.run(FORWARD);         // turn it on going forward
    motor2.run(FORWARD); 
    }
  else{
     motor1.run(BACKWARD);   // turn it on going backward
     motor2.run(BACKWARD); 
     delay(600);
     motor1.run(BACKWARD);   // turn it on going right
     motor2.run(FORWARD);
     delay(1000); 
   }
}


long data(){
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  duration = pulseIn (echopin, HIGH);
  return duration / 29 / 2;
}
