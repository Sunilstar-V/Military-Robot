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

### 1. Hardware Connections

#### NodeMCU 1 (Primary Controller)

- **Servo 1:** Connect the control wire of Servo 1 to the D4 pin on NodeMCU 1.
- **Servo 2:** Connect the control wire of Servo 2 to the D5 pin on NodeMCU 1.
- **Power Connections:** Connect the servo's power (VCC) and ground (GND) wires to the appropriate pins on NodeMCU 1. Ensure the power supply is sufficient for both servos.

#### NodeMCU 2 (Optional/Additional Controller)

If using a second NodeMCU for additional tasks (e.g., more sensors or actuators), connect it according to your specific needs.

### 2. Software Setup

#### 2.1 Install Required Software

1. **Arduino IDE:**
   - Download and install the [Arduino IDE](https://www.arduino.cc/en/software).
2. **Firebase Library for Arduino:**
   - Install the `Firebase ESP Client` library by following the [installation instructions](https://github.com/mobizt/Firebase-ESP-Client).

#### 2.2 Configure Firebase

1. **Create a Firebase Project:**
   - Go to the [Firebase Console](https://console.firebase.google.com/) and create a new project.
2. **Obtain Firebase Credentials:**
   - Obtain the API Key and Database URL from your Firebase project settings.

#### 2.3 Update Arduino Code

1. **Open the Code:**
   - Open the `robot_movement.ino` file in the Arduino IDE.
2. **Replace Placeholder Values:**
   - Replace the placeholder values with your Wi-Fi credentials and Firebase details:

    ```cpp
    #define WIFI_SSID "your_wifi_ssid"
    #define WIFI_PASSWORD "your_wifi_password"
    #define API_KEY "your_firebase_api_key"
    #define DATABASE_URL "your_firebase_database_url"
    ```

#### 2.4 Upload Code to NodeMCU

1. **Select the Board and Port:**
   - Ensure you have selected the appropriate board (NodeMCU) and port in the Arduino IDE.
2. **Upload the Code:**
   - Connect NodeMCU 1 to your computer via USB.
   - Upload the `robot_movement.ino` code to NodeMCU 1.

## Code Explanation

### Wi-Fi Connection

The code initiates a connection to your Wi-Fi network:

```cpp
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
while (WiFi.status() != WL_CONNECTED) {
  delay(300);
  Serial.print(".");
}
Serial.println("Connected to Wi-Fi");
```

### Firebase Initialization
- The code initializes Firebase using your credentials:

```cpp
config.api_key = API_KEY;
config.database_url = DATABASE_URL;
Firebase.begin(&config, &auth);
Firebase.reconnectWiFi(true);
```

### Command Handling
- The code listens for commands from Firebase and controls the servos accordingly:
```cpp
if (Firebase.ready() && Firebase.RTDB.getString(&fbdo, "/commands")) {
  String command = fbdo.stringData();
  Serial.println("NodeMCU 1 received command: " + command);
  // Execute movement functions based on the command
}
```
## Usage Instructions
### Power the NodeMCU Boards:
Ensure the NodeMCU boards are powered and connected to the Wi-Fi network.
### Control the Robot:
- Use Firebase Realtime Database to send commands such as:
- FORWARD – Moves the robot forward.
- BACKWARD – Moves the robot backward.
- LEFT – Turns the robot left.
- RIGHT – Turns the robot right.
- STOP – Stops all movement.
### Monitor and Adjust:
- Use the Serial Monitor in the Arduino IDE for debugging and to see received commands.
### Expand and Customize:
- Add sensors or additional components as needed.
- Modify the movement functions to suit specific requirements.
## Troubleshooting
**No Wi-Fi Connection**: 
- Ensure the NodeMCU is within range of the Wi-Fi network and that the credentials are correct.
- Firebase Errors: Double-check the API key and database URL.
## Applications
- This project can be adapted for various applications including:

**Object Detection and Tracking**: 
- Integrate sensors to detect and track objects.
**Automated Systems**: 
- Automate tasks like movement and routine operations.
**Environmental Monitoring**: 
- Monitor environmental parameters with additional sensors.
**Remote Operation**:
- Suitable for industrial, research, and educational purposes.
## Credits
- **Firebase Library for Arduino**: [Firebase ESP Client](https://github.com/mobizt/Firebase-ESP-Client)
- **Arduino IDE**: Developed and maintained by Arduino and its community.
## License
This project is licensed under the MIT License - see the [LICENSE](https://opensource.org/license/MIT). file for details.
