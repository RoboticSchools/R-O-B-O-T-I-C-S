// Created by RoboticSchools.
// Robotics and Coding always fun when we're doing with our hands.
// " Welcome to the Roboteer's World "

// LINE FOLLOWER ROBOT - 2 WHEEL DRIVE


#include <AFMotor.h>

//change these two numbers to respective numbers those are connected in Arduino.

#define lefts A5 
#define rights A0


AF_DCMotor motor1(2, MOTOR12_8KHZ);   // Righthand side Motor
AF_DCMotor motor2(3, MOTOR12_8KHZ);   // Left hand side Motor


void setup() {


  pinMode(lefts,INPUT);
  pinMode(rights,INPUT);

  Serial.begin(9600);
  motor1.setSpeed(200);
  motor2.setSpeed(200);

  
}

void loop(){
  //printing values of the sensors to the serial monitor
  Serial.println(digitalRead(lefts));
  Serial.println(digitalRead(rights));
  //when line is not detecting
  if(digitalRead(lefts)==0 && digitalRead(rights)==0){
    
    motor1.run(FORWARD);     //FORWARD
    
    motor2.run(FORWARD);


  }
  // when right hand side sensor detects the line
  else if(digitalRead(lefts)==0 && digitalRead(rights)==1){
    
    motor1.run(BACKWARD);     //turn Right

    motor2.run(FORWARD);



  }
  // when left hand side sensor detects the line
  else if(digitalRead(lefts)==1 && digitalRead(rights)==0){;
    
    motor1.run(FORWARD);      //turn Right
 
    motor2.run(BACKWARD);
  


  }
  // line detected by none
  else if(digitalRead(lefts)==1 && digitalRead(rights)==1){
    
    motor1.run(RELEASE);        //stop
    motor2.run(RELEASE);

  }
  
}
