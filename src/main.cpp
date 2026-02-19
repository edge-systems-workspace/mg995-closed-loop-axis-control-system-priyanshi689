/**
* @file main.cpp
 * @brief MG995 Closed-Loop Axis Control System
 * @author Priyanshi
 * @date 19-02-2026
 */

#include <Arduino.h>
#include <Servo.h>

#define SERVO_PIN 9

Servo myServo;

/**
 * @brief Initializes serial communication and attaches the servo.
 */
void setup() {
    Serial.begin(9600);
    myServo.attach(SERVO_PIN);
    Serial.println("MG995 Ready. Enter angle (0-180):");
}

/**
 * @brief Reads target angle from serial, validates input, and moves the servo.
 */
void loop() {
    if (Serial.available() > 0) {
        int angle = Serial.parseInt();

        if (angle >= 0 && angle <= 180) {
            myServo.write(angle);
            Serial.print("Moved to angle: ");
            Serial.println(angle);
        } else {
            Serial.println("Invalid angle! Enter value between 0 and 180.");
        }

        while (Serial.available() > 0) {
            Serial.read();
        }
    }
}

