### Pycharm Python Code

``` Python
//# python 3.9
//# cvzone 1.5.2
//# mediapipe 0.8.5

import cv2
from cvzone.HandTrackingModule import HandDetector
from cvzone.SerialModule import SerialObject


cap = cv2.VideoCapture(0)
detector = HandDetector(detectionCon=0.8, maxHands=2)
mySerial = SerialObject("COM3", 9600,1)
while True:

    success,img = cap.read()
    hands, img = detector.findHands(img)
    cv2.imshow("Image", img)
    if hands:
        hand1 = hands[0]
        fingers1 = detector.fingersUp(hand1)
        #print(fingers1)
        mySerial.sendData(fingers1)
    cv2.waitKey(1)
```    
### Arduino code for Gesture Control

```python
#include <Servo.h>
#define numOfValRec 5
#define digitsPerValRec 1

Servo servoThumb;
Servo servoIndex;
Servo servoMiddle;
Servo servoRing;
Servo servoPinky;

int valsRec[numOfValRec];

int stringLength = numOfValRec * digitsPerValRec +1;

int counter = 0;
bool counterStart = false;

String receivedString;

void setup(){
  Serial.begin(9600);
  servoThumb.attach(7);
  servoIndex.attach(9);
  servoMiddle.attach(11);
  servoRing.attach(8);
  servoPinky.attach(10);
  
}

void receiveData(){
  while(Serial.available())
  {
    char c = Serial.read();
    if (c == '$'){
      counterStart = true;
    }
    if(counterStart){
      if (counter < stringLength){
        receivedString = String(receivedString+c);
        counter ++;
      }
      if (counter >=stringLength){

        for (int i=0; i<numOfValRec; i++){

          int num = (i*digitsPerValRec)+1;
         valsRec[i] = receivedString.substring(num,num+digitsPerValRec).toInt(); 
        }
        receivedString = "";
        counter = 0;
        counterStart = false;      

      }
    }
  }

  
}

void loop(){

  receiveData();
  if (valsRec[0]==1){servoThumb.write(180);}else{servoThumb.write(0);}
  if (valsRec[1]==1){servoIndex.write(180);}else{servoIndex.write(0);}
  if (valsRec[2]==1){servoMiddle.write(180);}else{servoMiddle.write(0);}
  if (valsRec[3]==1){servoRing.write(180);}else{servoRing.write(0);}
  if (valsRec[4]==1){servoPinky.write(180);}else{servoPinky.write(0);}
  
}
```
