/* 
 *  Created by RoboticSchools
 *  Robotics and Coding always fun when we're doing with our hands.
 *  " Welcome to the Roboteer's World "
 *  
 *  LIGHT FOLLOWING ROBOT
 */

#include<AFMotor.h> 
#define L1 A0 
#define M1 A1
#define R1 A2

AF_DCMotor motor1(2);
AF_DCMotor motor2(3);



void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(L1, INPUT);
pinMode(M1, INPUT);
pinMode(R1, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int LSensor = digitalRead(L1);
int MSensor = digitalRead(M1);
int RSensor = digitalRead(R1);

Serial.print("LSensor");
Serial.println(LSensor);
Serial.print("MSensor");
Serial.println(MSensor);
Serial.print("RSensor");
Serial.println(RSensor);

if((LSensor == 0)&&(MSensor == 0)&&(RSensor ==0)) { 
  //MOVE FORWARD
  motor1.setSpeed(120);
  motor1.run(FORWARD);
  motor2.setSpeed(120);
  motor2.run(FORWARD);
  
} else if((LSensor == 0)&&(MSensor == 0)&&(RSensor ==1)) {
  //TURN LEFT
  motor1.setSpeed(150);
  motor1.run(BACKWARD);
  motor2.setSpeed(150);
  motor2.run(BACKWARD);
  
}else if((LSensor == 1)&&(MSensor == 0)&&(RSensor ==0)) {
  //TURN RIGHT
  motor1.setSpeed(150);
  motor1.run(FORWARD);
  motor2.setSpeed(150);
  motor2.run(FORWARD);

}else if((LSensor == 1)&&(MSensor == 1)&&(RSensor ==1)) {
  //STOP
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);

}
}
