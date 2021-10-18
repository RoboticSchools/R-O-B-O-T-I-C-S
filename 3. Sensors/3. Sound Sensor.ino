/* 
 *  Created by RoboticSchools
 *  Robotics and Coding always fun when we're doing with our hands.
 *  " Welcome to the Roboteer's World "
 *  
 *  LED ON & OFF BASED ON FREQUENCY OF SOUND USING SOUND SENSOR
 */

const int ledpin=13;           // ledpin and soundpin are not changed throughout the process
const int soundpin=A2;
const int threshold=540;       // sets threshold value for sound sensor

void setup() {

 Serial.begin(9600);
 pinMode(ledpin,OUTPUT);
 pinMode(soundpin,INPUT);
 
}

void loop() {

 int soundsens=analogRead(soundpin); // reads analog data from sound sensor
 Serial.println(soundsens);
 
 if (soundsens>=threshold) {
 
 digitalWrite(ledpin,HIGH); //turns led on
 delay(1000);
 
 }

 else{
 
  digitalWrite(ledpin,LOW);
  
 }
}
