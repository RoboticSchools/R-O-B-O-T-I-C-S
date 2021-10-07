/* 
    Created by RoboticSchools
    ------------------------------------------------------------------
    Robotics and Coding are always fun when we are doing with our Hands
                  
                  WELCOME TO THE ROBOTEER'S WORLD
    ------------------------------------------------------------------
    Project Name : LED Control using Android App
    This program helps you to control a LED on pin 13 of arduino using a bluetooth module
 */
char data = 0;                //Variable for storing Incoming_value from Android App
void setup() 
{
  Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
  pinMode(13, OUTPUT);        //Sets digital pin 13 as output pin
}
void loop()
{
  if(Serial.available() > 0)  
  {
    data= Serial.read();                 //Read the incoming data and store it into variable Incoming_value
    Serial.print(data);                  //Print Value of Incoming_value in Serial monitor
    Serial.print("\n");                  //New line 
    if(data == '1')                      //Checks whether value of Incoming_value is equal to 1 
      digitalWrite(13, HIGH);            //If value is 1 then LED turns ON
    else if(data == '0')                 //Checks whether value of Incoming_value is equal to 0
      digitalWrite(13, LOW);             //If value is 0 then LED turns OFF
  }                            
 
}                 
