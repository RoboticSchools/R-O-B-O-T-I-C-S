## 1. Push Button Piano

<img src="https://csg-prd.tinkercad.com/things/5QE79dJddzD/t725.png?rev=1592794677609000000&s=&v=1&type=circuits" width=70% height=70%>

```C++
/* 
 *  Created by RoboticSchools
 *  Robotics and Coding always fun when we're doing with our hands.
 *  " Welcome to the Roboteer's World "
 *  
 *  PUSH BUTTON PIANO USING ARDUINO CODE
 */

#define CS 3
#define CLK 13
#define DIN  11
#define VCC 5V
#define GND GND

// Including the required Arduino libraries
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// Uncomment according to your hardware type
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
//#define HARDWARE_TYPE MD_MAX72XX::GENERIC_HW

// Defining size, and output pins
#define MAX_DEVICES 4
#define CS_PIN 3

// Create a new instance of the MD_Parola class with hardware SPI connection
MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

void setup() {
  // Intialize the object
  myDisplay.begin();

  // Set the intensity (brightness) of the display (0-15)
  myDisplay.setIntensity(15);

  // Clear the display
  myDisplay.displayClear();

  myDisplay.displayScroll("ROBOTICSCHOOLS", PA_CENTER, PA_SCROLL_LEFT, 100);
}

void loop() {
  if (myDisplay.displayAnimate()) {
    myDisplay.displayReset();
  }
}
```

