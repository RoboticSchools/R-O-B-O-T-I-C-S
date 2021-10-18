## 1. DOT DISPLAY 

<img src="https://www.makerguides.com/wp-content/uploads/2020/05/MAX7219-LED-dot-matrix-display-with-Arduino-Uno-wiring-diagram-schematic-pinout.jpg" width=80% height=80%>

```C++
/* 
 *  Created by RoboticSchools
 *  Robotics and Coding always fun when we're doing with our hands.
 *  " Welcome to the Roboteer's World "
 *  
 *  SCROLLING TEXT ON DOT DISPLAY
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

## 2. NEO PIXEL RING

<img src="https://1.bp.blogspot.com/-1HWUxFvhUnE/X7PqlhTIfFI/AAAAAAAAZ4I/EK6ZeCV2_XgntYJwGn75phhtt2OHxF0EgCLcBGAsYHQ/s741/neopixel-ring-arduino.PNG" width=80% height=80%>

```C++
/* 
 *  Created by RoboticSchools
 *  Robotics and Coding always fun when we're doing with our hands.
 *  " Welcome to the Roboteer's World "
 *  
 *  NEO PIXEL RING ARDUINO CODE
 */

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN        6
#define NUMPIXELS 16

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 500

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif

  pixels.begin();
}

void loop() {
  pixels.clear();

  for(int i=0; i<NUMPIXELS; i++) {

    pixels.setPixelColor(i, pixels.Color(0, 0, 255));
    pixels.show();
    delay(DELAYVAL);
  }
}

```

