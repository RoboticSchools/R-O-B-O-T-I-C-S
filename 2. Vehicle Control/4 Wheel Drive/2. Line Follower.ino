// Created by RoboticSchools.
// Robotics and Coding always fun when we're doing with our hands.
// " Welcome to the Roboteer's World "

// LINE FOLLOWER ROBOT - 4 WHEEL DRIVE

#include <AFMotor.h>

#define lefts A5    --- Change these two numbers to respective numbers those are connected in Arduino.
#define rights A1 


AF_DCMotor motor1(2, MOTOR12_8KHZ);  // RightHand Side - Front Motor
AF_DCMotor motor2(3, MOTOR12_8KHZ);  // LeftHand Side - Front Motor
AF_DCMotor motor3(1, MOTOR12_8KHZ);  // RightHand Side - Back Motor
AF_DCMotor motor4(4, MOTOR12_8KHZ);  // LeftHand Side - Back Motor



void setup() {


  pinMode(lefts,INPUT);
  pinMode(rights,INPUT);

  Serial.begin(9600);
  
  
}

void loop(){
  //printing values of the sensors to the serial monitor
  Serial.println(digitalRead(lefts));
  Serial.println(digitalRead(rights));
  // When both sensors are not detecting line
  if(digitalRead(lefts)==0 && digitalRead(rights)==0){
    
    motor1.run(FORWARD);
    motor1.setSpeed(170);
    motor2.run(FORWARD);
    motor2.setSpeed(170);       //FORWARD
    motor3.run(FORWARD);
    motor3.setSpeed(170);
    motor4.run(FORWARD);
    motor4.setSpeed(170);


  }
  //line detected by right sensor
  else if(digitalRead(lefts)==0 && digitalRead(rights)==1){

    motor1.run(BACKWARD);
    motor1.setSpeed(140);
    motor2.run(FORWARD);
    motor2.setSpeed(170);
    motor3.run(BACKWARD);     // Turn Right
    motor3.setSpeed(140);
    motor4.run(FORWARD);
    motor4.setSpeed(170);

  }
  //line detected by left sensor
  else if(digitalRead(lefts)==1 && digitalRead(rights)==0){;


    motor1.run(FORWARD);
    motor1.setSpeed(170);
    motor2.run(BACKWARD);
    motor2.setSpeed(140);
    motor3.run(FORWARD);      // Turn Left 
    motor3.setSpeed(170);
    motor4.run(BACKWARD);
    motor4.setSpeed(140);



  }
  //line detected by none
  else if(digitalRead(lefts)==1 && digitalRead(rights)==1){
    
    motor1.run(RELEASE);
    motor2.run(RELEASE);      // stop
    motor3.run(RELEASE);
    motor4.run(RELEASE);

  }
  
}
