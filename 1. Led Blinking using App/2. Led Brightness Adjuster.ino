/* 
    Created by RoboticSchools
    ------------------------------------------------------------------
    Robotics and Coding are always fun when we are doing with our Hands
                  
                  WELCOME TO THE ROBOTEER'S WORLD
    ------------------------------------------------------------------
    Project Name : LED Brightness Control using Android App
    This program helps you to control LED Brightness using bluetooth module and Android App
 */
int led = 7;            // Initilizing the Led pin
int data = 0;           // Storing data coming from Android App

void setup() {
                        // put your setup code here, to run once:

Serial.begin(9600);
pinMode(led,OUTPUT);    // Set the Led as a output

}

void loop() {
                                  // put your main code here, to run repeatedly:
if (Serial.available()>0){        // Checking Incoming data from App
  data = Serial.read();           // Storing data coming from App
  Serial.println(data);           // Prints the Incoming values coming from App 
  analogWrite(led,data);          // It Changes the Brightness of Led using analogRead function
}
}
