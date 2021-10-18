
### 1. Obstacle Avoiding Robot - 4 Wheel Drive 

<img src="https://www.the-diy-life.com/wp-content/uploads/2020/07/Obstacle-Avoiding-Robot-Car-Using-An-Arduino-Uno.jpg" width="700" height="400" />


```C++
// Created by RoboticSchools.
// Robotics and Coding always fun when we're doing with our hands.
// " Welcome to the Roboteer's World "

// OBSTACLE AVAOIDING ROBOT - 4 WHEEL DRIVE

#include "AFMotor.h"

#define echopin A3 // echo pin  --- Change these two numbers to respective numbers those are connected in Arduino.
#define trigpin A4 // Trigger pin

 

AF_DCMotor motor1(2, MOTOR12_64KHZ); // RightHand Side - Front Motor
AF_DCMotor motor2(3, MOTOR12_64KHZ); // LeftHand Side - Front Motor
AF_DCMotor motor3(1, MOTOR12_64KHZ); // RightHand Side - Back Motor
AF_DCMotor motor4(4, MOTOR12_64KHZ); // LeftHand Side - Back Motor


int distance;
long duration;

int set = 15;   // distance between Object and Ultrasonic sensor to Respond.
 
void setup() {
  Serial.begin(9600);           // Initialize serial port
  Serial.println("Start");

  pinMode (trigpin, OUTPUT);
  pinMode (echopin, INPUT );
  
  motor1.setSpeed(255);          // set the motor speed to 0-255
  motor2.setSpeed(255);
  motor3.setSpeed(255);          
  motor4.setSpeed(255);

}

void loop() {
 distance = data();
 Serial.print("S=");
 Serial.println(distance);
  if (distance > set){
    Serial.println("Forward");
    motor1.run(FORWARD);         // turn it on going forward
    motor2.run(FORWARD);
    motor3.run(FORWARD);         
    motor4.run(FORWARD); 
    }
  else{
     motor1.run(BACKWARD);   // turn it on going backward
     motor2.run(BACKWARD);
     motor3.run(BACKWARD);   
     motor4.run(BACKWARD); 
     delay(600);
     motor1.run(BACKWARD);   // turn it on going right
     motor2.run(FORWARD);
     motor3.run(BACKWARD);   
     motor4.run(FORWARD);
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
```

### 2. Line Follower Robot Robot - 4 Wheel Drive 

<img src="https://hackster.imgix.net/uploads/attachments/1196198/_yI59w8pKDD.blob?auto=compress%2Cformat&w=900&h=675&fit=min" width="600" height="400" />


```c++
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

```
### 3. Mobile Controlled Robot - 4 Wheeel Drive

<img src="https://hackster.imgix.net/uploads/attachments/1198529/_YvWVFCiyG0.blob?auto=compress%2Cformat&w=900&h=675&fit=min" width="600" height="400" />

```c++
// Created by RoboticSchools.
// Robotics and Coding always fun when we're doing with our hands.
// " Welcome to the Roboteer's World "

// MOBILE CONTROL ROBOT - 4 WHEEL DRIVE

#include "AFMotor.h"

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
motor2.run(BACKWARD); 
motor3.run(FORWARD); 
motor4.run(FORWARD); 

}

void turnLeft(){
 // turn it on going left
motor1.run(FORWARD);
motor2.run(FORWARD);
motor3.run(BACKWARD);
motor4.run(BACKWARD); 

}

void Stop(){
 // stopped
 motor1.run(RELEASE);
 motor2.run(RELEASE);
 motor3.run(RELEASE);
 motor4.run(RELEASE);

}

```
### 3. Light Following Robot - 4 Wheeel Drive

<img src="https://hackster.imgix.net/uploads/attachments/1198529/_YvWVFCiyG0.blob?auto=compress%2Cformat&w=900&h=675&fit=min" width="600" height="400" />

```c++
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

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);


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
  motor3.setSpeed(120);
  motor3.run(FORWARD);
  motor4.setSpeed(120);
  motor4.run(FORWARD);
  
} else if((LSensor == 0)&&(MSensor == 0)&&(RSensor ==1)) {
  //TURN LEFT
  motor1.setSpeed(150);
  motor1.run(BACKWARD);
  motor2.setSpeed(150);
  motor2.run(BACKWARD);
  motor3.setSpeed(150);
  motor3.run(FORWARD);
  motor4.setSpeed(150);
  motor4.run(FORWARD);
  
}else if((LSensor == 1)&&(MSensor == 0)&&(RSensor ==0)) {
  //TURN RIGHT
  motor1.setSpeed(150);
  motor1.run(FORWARD);
  motor2.setSpeed(150);
  motor2.run(FORWARD);
  motor3.setSpeed(150);
  motor3.run(BACKWARD);
  motor4.setSpeed(150);
  motor4.run(BACKWARD);
}else if((LSensor == 1)&&(MSensor == 1)&&(RSensor ==1)) {
  //STOP
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
}
}

```
