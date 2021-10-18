### 1. DHT - 11 Sensor to Check Temperature and Humidity

<img src="https://8051microcontrollers.com/wp-content/uploads/2018/08/arduino-dht11-temperature-humidity-1.png" width=50% height=50%>

```C++
/* 
 *  Created by RoboticSchools
 *  Robotics and Coding always fun when we're doing with our hands.
 *  " Welcome to the Roboteer's World "
 *  
 *  CHECKING TEMPERATURE AND HUMIDITY USING DHT-11 SENSOR
 */

#include <dht.h>        // Adding DHT 11 Library.

#define dht_apin A0     // Connect AnalogPin ( IR Sensor ) to Arduino 
 
dht DHT;
 
void setup(){
 
  Serial.begin(9600);
  delay(500);          // Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);         // Wait before accessing Sensor
 
}
 
void loop(){
 
    DHT.read11(dht_apin);
    
    Serial.print("Current humidity = ");       
    Serial.print(DHT.humidity);                // Print the Humidity values coming from Sensor
    Serial.print("%  ");
    Serial.print("temperature = ");            
    Serial.print(DHT.temperature);             // Print the Temperature Values coming from Seensor
    Serial.println("C  ");
    
    delay(5000);                              // Wait 5 seconds before accessing sensor again.
 
}

```

### 2. LDR Sensor

<img src="https://hackster.imgix.net/uploads/attachments/1108360/photoresistor-circuit_yUfrhZPgFE.png?auto=compress%2Cformat&w=680&h=510&fit=max" width=90% height=90%>

```c++
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
```

### 3. Sound Sensor

<img src="https://content.instructables.com/ORIG/FEB/JD9I/IUSLRPGM/FEBJD9IIUSLRPGM.jpg?auto=webp&fit=bounds&frame=1&width=1024" width=50% height=50%>

```c++
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
```

### 4. IR Sensor

<img src="https://miro.medium.com/max/800/0*syht9Gf5pIdVLIQf" width=50% height=50%>

```c++
/* 
 *  Created by RoboticSchools
 *  Robotics and Coding always fun when we're doing with our hands.
 *  " Welcome to the Roboteer's World "
 *  
 *  LED ON & OFF BASED ON AMOUNT OF DARK & BRIGHT COLORS USING IR SENSOR
 */
 
int IRSensor = 2; // connect ir sensor to arduino pin 2
int LED = 13; // conect Led to arduino pin 13

void setup() 
{
  pinMode (IRSensor, INPUT); // sensor pin INPUT
  pinMode (LED, OUTPUT); // Led pin OUTPUT
}

void loop()
{
  int statusSensor = digitalRead (IRSensor);
  
  if (statusSensor == 1)
  {
    digitalWrite(LED, LOW); // LED LOW
  }
  
  else
  {
    digitalWrite(LED, HIGH); // LED High
  }
  
}
```

### 5. Ultrasonic Sensor

<img src="https://marcteyssier.com/uduino/content/3-projects/3-ultrasonic-sensor-hc-sr04-on-unity/schematics.png" width=50% height=50%>

```c++
/* 
 *  Created by RoboticSchools
 *  Robotics and Coding always fun when we're doing with our hands.
 *  " Welcome to the Roboteer's World "
 *  
 *  PRINTING DISTANCE VALUES IN SERIAL MONITOR USING ULTRASONIC SENSOR
 */

#define echoPin 2        // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3        //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables

long duration;           // variable for the duration of sound wave travel
int distance;            // variable for the distance measurement

void setup() 
{
  pinMode(trigPin, OUTPUT);        // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT);         // Sets the echoPin as an INPUT
  Serial.begin(9600);              // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test");     // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}

void loop() 
{
                                          // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
                                          // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
                                          // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
                                          // Calculating the distance
  distance = duration * 0.034 / 2;        // Speed of sound wave divided by 2 (go and back)
                                          // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
```

### 5. PIR Sensor

<img src="https://cdn-learn.adafruit.com/assets/assets/000/000/543/medium800/proximity_pirardbb.gif" width=50% height=50%>

```c++
/* 
 *  Created by RoboticSchools
 *  Robotics and Coding always fun when we're doing with our hands.
 *  " Welcome to the Roboteer's World "
 *  
 *  LED ON & OFF BASED ON MOTION DETECTED BY THE PIR SENSOR
 */

int led = 13;                // the pin that the LED is atteched to
int sensor = 2;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)

void setup() 
{
  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(9600);        // initialize serial
}

void loop()
{
  val = digitalRead(sensor);   // read sensor value
  if (val == HIGH) 
  {                            // check if the sensor is HIGH
    digitalWrite(led, HIGH);   // turn LED ON
    delay(500);                // delay 100 milliseconds 
    
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;                            // update variable state to HIGH
    }
  } 
  else {
      digitalWrite(led, LOW);                  // turn LED OFF
      delay(500);                              // delay 200 milliseconds 
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;                          // update variable state to LOW
    }
  }
}
```


