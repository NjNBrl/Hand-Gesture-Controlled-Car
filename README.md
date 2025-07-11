

##  Hand Gesture Mapping
| Gesture           | Fingers Up     | Action        | Sent Char |
|-------------------|----------------|---------------|-----------|
| ✌️ Victory         | [0,1,0,0,1]     | Stop          | `S`       |
| ☝️ Index Only      | [0,1,0,0,0]     | Forward       | `F`       |
| ✌️ Index + Thumb   | [1,1,0,0,0]     | Backward      | `B`       |
| 👍 Thumb Only      | [1,0,0,0,0]     | Left          | `L`       |
| 👆 Pinky Only      | [0,0,0,0,1]     | Right         | `R`       |
| 🖐️ All Fingers     | [1,1,1,1,1]     | ANTONY Mode   | `A`       |

##  Setup Instructions

### Python Side (Hand Detection)
1. Install dependencies:
    ```bash
    pip install opencv-python cvzone pyserial
    ```
2. Plug in your webcam (or use laptop cam).
3. Edit the COM port in the Python script:
    ```python
    bt = serial.Serial('COM5', 9600)  # Replace with your port
    ```
4. Run the script:
    ```bash
    python hand_gesture_control.py
    ```

Arduino Side
1. Upload `car_control.ino` to your Arduino.
2. Connect:
    - HC-05 to Arduino via TX/RX.
    - L298N to motor pins.
3. Power it up and pair the HC-05 with your PC.


