// Created by RoboticSchools.
// Robotics and Coding always fun when we're doing with our hands.
// " Welcome to the Roboteer's World "

// MOBILE CONTROL ROBOT - 4 WHEEL DRIVE

#include "AFMotor.h"
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

const int MOTOR_1 = 2; 
const int MOTOR_2 = 3;
const int MOTOR_3 = 1; 
const int MOTOR_4 = 4;  
 


AF_DCMotor motor1(MOTOR_1, MOTOR12_64KHZ); // create motor object, 64KHz pwm
AF_DCMotor motor2(MOTOR_2, MOTOR12_64KHZ); // create motor object, 64KHz pwm
AF_DCMotor motor3(MOTOR_3, MOTOR12_64KHZ); // create motor object, 64KHz pwm
AF_DCMotor motor4(MOTOR_4, MOTOR12_64KHZ); // create motor object, 64KHz pwm

int state;
int Speed = 130; 

void setup() {
  // set the motor speed to 0-255
motor1.setSpeed(Speed);
motor2.setSpeed(Speed);
motor3.setSpeed(Speed); 
motor4.setSpeed(Speed);
  
Serial.begin(9600);
mySerial.begin(9600);
delay(500); 
}

void loop(){   
if(mySerial.available() > 0){  //if some date is sent, reads it and saves in state     
state = mySerial.read();      
if(state > 10){Speed = state;}      
}
           
         // set the motor speed to 0-255
motor1.setSpeed(Speed);
motor2.setSpeed(Speed);
motor3.setSpeed(Speed);
motor4.setSpeed(Speed);

//===============================================================================
//                          Key Control Command
//===============================================================================   
     if(state == 1){forword(); }  // if the state is '1' the DC motor will go forward
else if(state == 2){backword();}  // if the state is '2' the motor will Reverse
else if(state == 3){turnLeft();}  // if the state is '3' the motor will turn left
else if(state == 4){turnRight();} // if the state is '4' the motor will turn right
else if(state == 5){Stop(); }     // if the state is '5' the motor will Stop
/////////////////////////////////////END\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//===============================================================================
//                          Voice Control Command
//===============================================================================
else if(state == 6){turnLeft();  delay(400);  state = 5;}
else if(state == 7){turnRight(); delay(400);  state = 5;}
/////////////////////////////////////END\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
delay(80);    
}

void forword(){
 // turn it on going forward
motor1.run(FORWARD); 
motor2.run(FORWARD);
motor3.run(FORWARD); 
motor4.run(FORWARD); 

}

void backword(){
 // the other way
motor1.run(BACKWARD);
motor2.run(BACKWARD);
motor3.run(BACKWARD);
motor4.run(BACKWARD); 
 
}

void turnRight(){
// the other right
motor1.run(BACKWARD); 
motor2.run(FORWARD); 
motor3.run(BACKWARD); 
motor4.run(FORWARD); 

}

void turnLeft(){
 // turn it on going left
motor1.run(FORWARD);
motor2.run(BACKWARD);
motor3.run(FORWARD);
motor4.run(BACKWARD); 

}

void Stop(){
 // stopped
 motor1.run(RELEASE);
 motor2.run(RELEASE);
 motor3.run(RELEASE);
 motor4.run(RELEASE);

}
