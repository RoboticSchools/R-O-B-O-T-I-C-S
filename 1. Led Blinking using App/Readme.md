Click on this link to open the
[LED APP CONTROLLER](https://gallery.appinventor.mit.edu/?galleryid=ac75ed0f-f5fe-4a53-ae39-82255356344a)

 
```C++
/* 
 *  Project Name : LED Control using Android App
 *  Created by - RoboticSchools
 *  Website - www.roboticschools.com
 *  This program lets you to control a LED on pin 13 of arduino using a bluetooth module
 */
char Incoming_value = 0;                //Variable for storing Incoming_value
void setup() 
{
  Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
  pinMode(13, OUTPUT);        //Sets digital pin 13 as output pin
}
void loop()
{
  if(Serial.available() > 0)  
  {
    Incoming_value = Serial.read();      //Read the incoming data and store it into variable Incoming_value
    Serial.print(Incoming_value);        //Print Value of Incoming_value in Serial monitor
    Serial.print("\n");        //New line 
    if(Incoming_value == '1')            //Checks whether value of Incoming_value is equal to 1 
      digitalWrite(13, HIGH);  //If value is 1 then LED turns ON
    else if(Incoming_value == '0')       //Checks whether value of Incoming_value is equal to 0
      digitalWrite(13, LOW);   //If value is 0 then LED turns OFF
  }                            
 
}                 
           
```
Click on this link to open the
[LED BRIGHTNESS CONTROLLER USING ANDROID APP](https://gallery.appinventor.mit.edu/?galleryid=0fa635e3-07ae-469c-a28b-481a4944259d)

 
```C++
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
```
