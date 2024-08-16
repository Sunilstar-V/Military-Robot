# Robot Movement

## Overview
This project controls a robot with two servos using two NodeMCU boards and Firebase. The robot's movements can be remotely controlled via Firebase commands.

## Hardware Requirements
- **NodeMCU (ESP8266) Board x 2**
- **Servo Motor (SP90) x 2**
- **Connecting Wires**
- **Power Supply**

## Software Requirements
- **Arduino IDE**: [Download and Install Arduino IDE](https://www.arduino.cc/en/software)
- **Firebase Library for Arduino**: [Firebase ESP Client](https://github.com/mobizt/Firebase-ESP-Client)

## Setup Instructions

1. **Hardware Connections:**
   - **NodeMCU 1:**
     - Connect Servo 1 to D4 pin.
     - Connect Servo 2 to D5 pin.
   - **NodeMCU 2:**
     - Connect the same way if additional NodeMCU is used for other tasks.

2. **Firebase Setup:**
   - Create a Firebase project and obtain your API key and database URL.
   - Update the `robot_movement.ino` file with your Firebase configuration details:
     ```cpp
     #define WIFI_SSID "your_wifi_ssid"
     #define WIFI_PASSWORD "your_wifi_password"
     #define API_KEY "your_firebase_api_key"
     #define DATABASE_URL "your_firebase_database_url"
     ```

3. **Upload Code to NodeMCU:**
   - Open the `robot_movement.ino` file in the Arduino IDE.
   - Select the appropriate board and port in the Arduino IDE.
   - Upload the code to your NodeMCU board.

4. **Firebase Commands:**
   - The NodeMCU will listen for commands from the Firebase Realtime Database at the `/commands` path.
   - Commands to control the robot: `FORWARD`, `BACKWARD`, `LEFT`, `RIGHT`, `STOP`.

## Usage Instructions
1. **Power the NodeMCU boards** using a suitable power source.
2. **Upload the code** to the NodeMCU using the Arduino IDE.
3. **Send commands** from Firebase to control the robot.

## Troubleshooting
- **No Wi-Fi Connection:** Ensure that your Wi-Fi credentials are correct and that the NodeMCU is within range.
- **Firebase Errors:** Verify that the API key and database URL are correct in the code.

## Credits
- Firebase Library for Arduino by Mobizt
- Arduino IDE and community

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
