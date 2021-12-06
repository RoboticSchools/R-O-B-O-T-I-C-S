/* 
    Created by RoboticSchools
    ------------------------------------------------------------------
    Robotics and Coding are always fun when we are doing with our Hands
                  
                  WELCOME TO THE ROBOTEER'S WORLD
    ------------------------------------------------------------------
    Project Name : LED Brightness Control using Android App
    This program helps you to control LED Brightness using bluetooth module and Android App
 */
#include<SoftwareSerial.h>

SoftwareSerial mySerial(2,3);

int led = 9;            // Initilizing the Led pin
int data = 0;           // Storing data coming from Android App

void setup() {
                        // put your setup code here, to run once:
mySerial.begin(9600);
Serial.begin(9600);
pinMode(led,OUTPUT);    // Set the Led as a output

}

void loop() {
                                  // put your main code here, to run repeatedly:
if (mySerial.available()>0){        // Checking Incoming data from App
  data = mySerial.read();           // Storing data coming from App
  Serial.println(data);           // Prints the Incoming values coming from App 
  analogWrite(led,data);          // It Changes the Brightness of Led using analogRead function
}
}
