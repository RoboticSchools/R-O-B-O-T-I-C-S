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
