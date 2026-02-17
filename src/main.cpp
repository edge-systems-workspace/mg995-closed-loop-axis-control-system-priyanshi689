#include <Arduino.h>
#include <Servo.h>
Servo myServo;
#define servoPin 9
void setup() {
serial.begin(9600);
myServo.attach(servoPin);
}

void loop() {
for (int pos = 0; pos <= 180; pos += 1) {
myServo.write(pos);
delay(15);
}
for (int pos = 180; pos >= 0; pos -= 1) {
myServo.write(pos);
delay(15);
}
}
