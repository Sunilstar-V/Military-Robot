#include <ESP8266WiFi.h>
#include <Servo.h>
#include <Firebase_ESP_Client.h>
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

#define WIFI_SSID "**********"
#define WIFI_PASSWORD "*********"
#define API_KEY "************"
#define DATABASE_URL "***************"

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

Servo servo1;
Servo servo2;

// Define servo movement ranges
const int MIN_POSITION = 0;
const int MAX_POSITION = 180;
const int STEP_SIZE = 30;
const int DELAY_TIME = 15;

void setup() {
  Serial.begin(115200);

  servo1.attach(D4);  // Attach servo1 to D4 pin
  servo2.attach(D5);  // Attach servo2 to D5 pin

  // Connect to Wi-Fi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
    Serial.print(".");
  }
  Serial.println("Connected to Wi-Fi");

  // Initialize Firebase
  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}

void loop() {
  if (Firebase.ready() && Firebase.RTDB.getString(&fbdo, "/commands")) {
    String command = fbdo.stringData();
    Serial.println("NodeMCU 1 received command: " + command);

    if (command == "FORWARD") {
      moveForward();
    } else if (command == "BACKWARD") {
      moveBackward();
    } else if (command == "LEFT") {
      moveLeft();
    } else if (command == "RIGHT") {
      moveRight();
    } else if (command == "STOP") {
      stopMovement();
    }
  } else {
    Serial.println("Firebase Error... ");
  }
  delay(1000);
}

void moveForward() {
  for (int pos = MIN_POSITION; pos <= MAX_POSITION; pos += STEP_SIZE) {
    servo1.write(pos);
    servo2.write(pos);
    delay(DELAY_TIME);
  }
}

void moveBackward() {
  for (int pos = MAX_POSITION; pos >= MIN_POSITION; pos -= STEP_SIZE) {
    servo1.write(pos);
    servo2.write(pos);
    delay(DELAY_TIME);
  }
}

void moveLeft() {
  for (int pos1 = MIN_POSITION; pos1 <= MAX_POSITION; pos1 += STEP_SIZE) {
    servo1.write(pos1);
    servo2.write(MAX_POSITION - pos1);
    delay(DELAY_TIME);
  }
}

void moveRight() {
  for (int pos1 = MIN_POSITION; pos1 <= MAX_POSITION; pos1 += STEP_SIZE) {
    servo1.write(MAX_POSITION - pos1);
    servo2.write(pos1);
    delay(DELAY_TIME);
  }
}

void stopMovement() {
  servo1.write(90);
  servo2.write(90);
}
