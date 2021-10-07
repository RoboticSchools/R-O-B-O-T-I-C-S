### 1. DHT - 11 SENSOR TO CHECK TEMPERATURE AND HUMIDITY

<img src="https://8051microcontrollers.com/wp-content/uploads/2018/08/arduino-dht11-temperature-humidity-1.png" width=50% height=50%>

```C++
/* 
 *  Project Name : LED Control using Android App
 *  Created by - RoboticSchools
 *  Website - www.roboticschools.com
 *  This program lets you to control a LED on pin 13 of arduino using a bluetooth module
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
