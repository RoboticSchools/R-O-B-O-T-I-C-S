
### 1. Obstacle Avoiding Robot - 2 Wheel Drive 

<img src="https://www.the-diy-life.com/wp-content/uploads/2020/07/Obstacle-Avoiding-Robot-Car-Using-An-Arduino-Uno.jpg" width="700" height="400" />


```C++
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
```

### 2. Line Follower Robot Robot - 2 Wheel Drive 

<img src="https://hackster.imgix.net/uploads/attachments/1196198/_yI59w8pKDD.blob?auto=compress%2Cformat&w=900&h=675&fit=min" width="600" height="400" />


```c++
// Created by RoboticSchools.
// Robotics and Coding always fun when we're doing with our hands.
// " Welcome to the Roboteer's World "

// LINE FOLLOWER ROBOT - 2 WHEEL DRIVE


#include <AFMotor.h>

//change these two numbers to respective numbers those are connected in Arduino.

#define lefts A5 
#define rights A1 


AF_DCMotor motor1(2, MOTOR12_8KHZ);   // Righthand side Motor
AF_DCMotor motor2(3, MOTOR12_8KHZ);   // Left hand side Motor


void setup() {


  pinMode(lefts,INPUT);
  pinMode(rights,INPUT);

  Serial.begin(9600);
  
}

void loop(){
  //printing values of the sensors to the serial monitor
  Serial.println(digitalRead(lefts));
  Serial.println(digitalRead(rights));
  //when line is not detecting
  if(digitalRead(lefts)==0 && digitalRead(rights)==0){
    
    motor1.run(FORWARD);     //FORWARD
    motor1.setSpeed(125);
    motor2.run(FORWARD);
    motor2.setSpeed(125);

  }
  // when right hand side sensor detects the line
  else if(digitalRead(lefts)==0 && digitalRead(rights)==1){
    
    motor1.run(BACKWARD);     //turn Right
    motor1.setSpeed(125);
    motor2.run(FORWARD);
    motor2.setSpeed(100);


  }
  // when left hand side sensor detects the line
  else if(digitalRead(lefts)==1 && digitalRead(rights)==0){;
    
    motor1.run(FORWARD);      //turn Right
    motor1.setSpeed(100);
    motor2.run(BACKWARD);
    motor2.setSpeed(125);


  }
  // line detected by none
  else if(digitalRead(lefts)==1 && digitalRead(rights)==1){
    
    motor1.run(RELEASE);        //stop
    motor2.run(RELEASE);

  }
  
}
```
### 3. Mobile Controlled Robot - 2 Wheeel Drive

<img src="https://hackster.imgix.net/uploads/attachments/1198529/_YvWVFCiyG0.blob?auto=compress%2Cformat&w=900&h=675&fit=min" width="600" height="400" />

```c++
// Created by RoboticSchools.
// Robotics and Coding always fun when we're doing with our hands.
// " Welcome to the Roboteer's World "

// MOBILE CONTROL ROBOT - 2 WHEEL DRIVE

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
```
