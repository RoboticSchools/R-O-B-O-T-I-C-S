## 1. Finding Button numbers 

<img src="https://lh4.googleusercontent.com/7d5r13tRFcywyPPj4qUhst6ZcPEpm3hF9fqhdC_fmHFJoV9BwmRdpv-dXBf1qGOzC0tkG2mhmREFmnxecbzEmkUMETOziDuXBZwHpjxlXXWqVE5jw6LneP-mLkiWE9_cc-xMeIDg" width=50% height=50%>

```C++
/* 
 *  Created by RoboticSchools
 *  Robotics and Coding always fun when we're doing with our hands.
 *  " Welcome to the Roboteer's World "
 *  
 *  FINDING BUTTON NUMBERS IN IR REMOTE USING ARDUINO CODE
 */

#include <SPI.h>
#include <IRremote.h>

int IR_Recv = 2;            //IR Receiver Pin 2
IRrecv irrecv(IR_Recv);
decode_results results;

void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);       //starts serial communication
  irrecv.enableIRIn();      // Starts the receiver
}

void loop()
{
  if (irrecv.decode(&results))
  {
    long int decCode = results.value;
    Serial.println(decCode);
    irrecv.resume();
  }
}
```

## 2. Turning ON & OFF LED Using IR Remote

<img src="https://i.ytimg.com/vi/KQiVLEhzzV0/maxresdefault.jpg" width=50% height=50%>

```C++
/* 
 *  Created by RoboticSchools
 *  Robotics and Coding always fun when we're doing with our hands.
 *  " Welcome to the Roboteer's World "
 *  
 *  TURNING LED ON & OFF USING IR REMOTE
 */

#include <IRremote.h>

int IR_Recv = 2; //IR Receiver Pin 2
IRrecv irrecv(IR_Recv);
decode_results results;

void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600); //starts serial communication
  irrecv.enableIRIn(); // Starts the receiver
}

void loop()
{
  if (irrecv.decode(&results))
  {
    long int decCode = results.value;
    Serial.println(decCode);
    
    if (results.value == 16753245) //Select button
    {
      digitalWrite(13, HIGH);
      Serial.println("LED turned ON");
    }
    if (results.value == 16736925) //Power button
    {
      digitalWrite(13, LOW);
      Serial.println("LED turned OFF");
    }
    irrecv.resume();
  }
}
```

