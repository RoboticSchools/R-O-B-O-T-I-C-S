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
