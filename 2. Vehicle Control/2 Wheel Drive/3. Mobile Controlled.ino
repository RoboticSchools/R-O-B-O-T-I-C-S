#include "AFMotor.h"

const int MOTOR_1 = 2; 
const int MOTOR_2 = 3; 
 


AF_DCMotor motor1(MOTOR_2, MOTOR12_64KHZ); // Right Hand side Motor
AF_DCMotor motor2(MOTOR_3, MOTOR12_64KHZ); // Left Hand side Motor

int state;
int Speed = 180;       // Initial speed of Vehicle

void setup() {
  // set the motor speed to 0-255
motor2.setSpeed(Speed);
motor3.setSpeed(Speed);
  
Serial.begin(9600);
delay(500); 
}

void loop(){   
if(Serial.available() > 0){  //if some date is sent, reads it and saves in state     
state = Serial.read();      
if(state > 10){Speed = state;}      
}
           
         // set the motor speed to 0-255
motor1.setSpeed(Speed);
motor2.setSpeed(Speed);

//===============================================================================
//                          Key Control Command
//===============================================================================   
     if(state == 1){forward(); }  // if the state is '1' the DC motor will go forward
else if(state == 2){backward();}  // if the state is '2' the motor will Reverse
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

void forward(){
 
motor1.run(FORWARD);    // move forward
motor2.run(FORWARD); 

}

void backward(){

motor1.run(BACKWARD);    // move backward
motor2.run(BACKWARD); 
 
}

void turnRight(){

motor1.run(BACKWARD);     // Turn Right
motor2.run(FORWARD); 

}

void turnLeft(){

motor1.run(FORWARD);       // Turn Left
motor2.run(BACKWARD); 

}

void Stop(){

 motor1.run(RELEASE);      // Stop
 motor2.run(RELEASE);

}
