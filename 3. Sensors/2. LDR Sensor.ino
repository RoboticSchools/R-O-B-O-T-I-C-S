/* 
 *  Created by RoboticSchools
 *  Robotics and Coding always fun when we're doing with our hands.
 *  " Welcome to the Roboteer's World "
 *  
 *  LED ON & OFF BASED ON DARK AND BRIGHT SURROUNDINGS USING LDR SENSOR
 */

const int ledPin = 13;

const int ldrPin = A0;

void setup() {

 Serial.begin(9600);

 pinMode(ledPin, OUTPUT);

 pinMode(ldrPin, INPUT);

}

void loop() {

 int ldrStatus = analogRead(ldrPin);

 if (ldrStatus >= 200) {

  digitalWrite(ledPin, HIGH);

  Serial.print("Its DARK, Turn on the LED : ");

  Serial.println(ldrStatus);

 } 
 else {

  digitalWrite(ledPin, LOW);

  Serial.print("Its BRIGHT, Turn off the LED : ");

  Serial.println(ldrStatus);

 }

}
