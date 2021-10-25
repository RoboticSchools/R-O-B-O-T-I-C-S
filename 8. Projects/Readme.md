## 1. 1. Authorization using RF ID and Display

<img src="https://cdn.shopify.com/s/files/1/0300/6424/6919/files/RFID-Attendance-System-Circuit-Diagram_grande.png?v=1590917520" width=40% height=40%>

```C++
/* 
 *  Created by RoboticSchools
 *  Robotics and Coding always fun when we're doing with our hands.
 *  " Welcome to the Roboteer's World "
 *  
 *  AUTHORIZATION USING RF ID AND DISPLAY
 */

#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

#define beep_pin 8

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
 
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  
  pinMode(beep_pin,OUTPUT);
  digitalWrite(beep_pin,LOW);
  
  lcd.begin(16, 2);
  lcd.setCursor(3, 1);
  lcd.print("Welcome!!");
  lcd.setCursor(0, 0);
  lcd.print("Circuit is Ready");
  delay(1500);
  lcd.clear();  
  
   
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Put your card to the reader...");
  Serial.println();

}
void loop() 
{
  digitalWrite(beep_pin, LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Put your card to");
  lcd.setCursor(0, 1);
  lcd.print("the reader......");
  delay(300);
  
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  

  
  if (content.substring(1) == "XX XX XX XX") //change here the UID of the card/cards that you want to give access
  {
    digitalWrite(beep_pin,HIGH);
    delay(200);
    digitalWrite(beep_pin,LOW);
    delay(100);
    lcd.setCursor(0, 0);
    lcd.print("ID : ");
    lcd.print(content.substring(1));
    lcd.setCursor(0, 1);
    lcd.print("Authorized access");
    Serial.println("Authorized access");
    delay(1200);      
  }
 
 else   {
    digitalWrite(beep_pin,HIGH);
    lcd.setCursor(0, 0);
    lcd.print("ID : ");
    lcd.print(content.substring(1));
    lcd.setCursor(0, 1);
    lcd.print("Access denied");
    Serial.println(" Access denied");
    delay(1500);
     }
} 

```

## 2. Social Distance Alarm

<img src="https://hackster.imgix.net/uploads/attachments/635638/blob_qSxfmzmc3s.blob?auto=compress%2Cformat&w=900&h=675&fit=min" width=40% height=40%>

```C++
/* 
 *  Created by RoboticSchools
 *  Robotics and Coding always fun when we're doing with our hands.
 *  " Welcome to the Roboteer's World "
 *  
 *  SOCIAL DISTANCE ALARM USING ULTRASONIC SENSOR
 */
 
int distance = 0;

int ultrasonic = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);

  pinMode(4, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop()
{
  ultrasonic = 0.01723 * readUltrasonicDistance(A1, A3);

  distance = 0.01723 * readUltrasonicDistance(A0, A1);
  Serial.println(distance);
  if (distance < 50) {
    digitalWrite(4, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(4, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(2, LOW);
  }
  delay(10); // Delay a little bit to improve simulation performance
}

## 2. Social Distance Alarm

<img src="https://hackster.imgix.net/uploads/attachments/635638/blob_qSxfmzmc3s.blob?auto=compress%2Cformat&w=900&h=675&fit=min" width=40% height=40%>

```C++
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#include <Adafruit_Sensor.h>
#include "DHT.h"
 
 
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
 
#define OLED_RESET -1
Adafruit_SH1106 display(OLED_RESET);
 
#define DHTPIN 2     // Digital pin connected to the DHT sensor
 
// Uncomment the type of sensor in use:
#define DHTTYPE    DHT11     // DHT 11
//#define DHTTYPE    DHT22     // DHT 22 (AM2302)
//#define DHTTYPE    DHT21     // DHT 21 (AM2301)
 
DHT dht(DHTPIN, DHTTYPE);
 
void setup() {
  Serial.begin(9600);
  dht.begin();
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  delay(2000);
  display.clearDisplay();
  display.setTextColor(WHITE);
}
 
void loop() {
  delay(1000);
 
  //read temperature and humidity
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  Serial.print(t); //send distance to MIT App
  Serial.print(";");
  Serial.print(h); //send distance to MIT App 
 
  //clear display
  display.clearDisplay();
 
  // display temperature
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Temperature: ");
  display.setTextSize(2);
  display.setCursor(0,10);
  display.print(t);
  display.print(" ");
  display.setTextSize(1);
  display.cp437(true);
  display.write(167);
  display.setTextSize(2);
  display.print("C");
  
  // display humidity
  display.setTextSize(1);
  display.setCursor(0, 35);
  display.print("Humidity: ");
  display.setTextSize(2);
  display.setCursor(0, 45);
  display.print(h);
  display.print(" %"); 
  
  display.display(); 
}  // display humidity
  display.setTextSize(1);
  display.setCursor(0, 35);
  display.print("Humidity: ");
  display.setTextSize(2);
  display.setCursor(0, 45);
  display.print(h);
  display.print(" %"); 
  
  display.display(); 
}

```

