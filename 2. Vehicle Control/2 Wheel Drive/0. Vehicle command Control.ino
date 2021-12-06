// Created by RoboticSchools.
// Robotics and Coding always fun when we're doing with our hands.
// " Welcome to the Roboteer's World "

// COMMAND CONTROL - 2 WHEEL DRIVE

#include "AFMotor.h"

const int MOTOR_1 = 2; 
const int MOTOR_2 = 3;  
 
AF_DCMotor motor1(MOTOR_1, MOTOR12_64KHZ); // create motor object, 64KHz pwm
AF_DCMotor motor2(MOTOR_2, MOTOR12_64KHZ); // create motor object, 64KHz pwm
AF_DCMotor motor3(MOTOR_3, MOTOR12_64KHZ); // create motor object, 64KHz pwm
AF_DCMotor motor4(MOTOR_4, MOTOR12_64KHZ); // create motor object, 64KHz pwm

int Speed = 180; 

void setup() {
  
motor1.setSpeed(Speed);
motor2.setSpeed(Speed);
  
}

void loop(){   

motor1.run(FORWARD); 
motor2.run(FORWARD); 
 
delay(3000);  
  
motor1.run(BACKWARD);
motor2.run(BACKWARD); 
  
delay(3000);
 
motor1.run(BACKWARD); 
motor2.run(FORWARD); 
  
delay(1000);

}
