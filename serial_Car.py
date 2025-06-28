import cv2
import cvzone
from cvzone.HandTrackingModule import HandDetector
import serial
import time

# Set up Bluetooth serial
bt = serial.Serial('COM5', 9600)  # Replace COM6 with your HC-05 COM port
time.sleep(2.0)

detector = HandDetector(detectionCon=0.8, maxHands=1)
video = cv2.VideoCapture(1)

while True:
    ret, frame = video.read()
    hands, img = detector.findHands(frame)
    cv2.rectangle(img, (0, 480), (300, 425), (50, 50, 255), -2)

    if hands:
        lmList = hands[0]
        fingerUp = detector.fingersUp(lmList)
        print(fingerUp)

        if fingerUp == [0, 1, 0, 0, 1]:  # Stop
            bt.write(b'S')
            cv2.putText(frame, '   Stop Motors', (20, 460), cv2.FONT_HERSHEY_COMPLEX, 1, (255, 255, 255), 1, cv2.LINE_AA)
        elif fingerUp == [0, 1, 0, 0, 0]:  # Forward
            bt.write(b'F')
            cv2.putText(frame, '   Forward', (20, 460), cv2.FONT_HERSHEY_COMPLEX, 1, (255, 255, 255), 1, cv2.LINE_AA)
        elif fingerUp == [1, 1, 0, 0, 0]:  # Backward
            bt.write(b'B')
            cv2.putText(frame, '   Backward', (20, 460), cv2.FONT_HERSHEY_COMPLEX, 1, (255, 255, 255), 1, cv2.LINE_AA)
        elif fingerUp == [1, 0, 0, 0, 0]:  # Left
            bt.write(b'L')
            cv2.putText(frame, '   Left', (20, 460), cv2.FONT_HERSHEY_COMPLEX, 1, (255, 255, 255), 1, cv2.LINE_AA)
        elif fingerUp == [0, 0, 0, 0, 1]:  # Right
            bt.write(b'R')
            cv2.putText(frame, '   Right', (20, 460), cv2.FONT_HERSHEY_COMPLEX, 1, (255, 255, 255), 1, cv2.LINE_AA)
        elif fingerUp == [1, 1, 1, 1, 1]:  # Special
            bt.write(b'A')
            cv2.putText(frame, '   ANTONY', (20, 460), cv2.FONT_HERSHEY_COMPLEX, 1, (255, 255, 255), 1, cv2.LINE_AA)

    cv2.imshow("Frame", frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

video.release()
cv2.destroyAllWindows()
bt.close()
