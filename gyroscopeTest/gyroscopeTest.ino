#include "DriveController.h"
#include "GyroscopeController.h"
#include "LineSensorController.h"
#include "ServoController.h"
#include "UltrasonicController.h"
#include "MPU6050.h"

DriveController driver;
GyroscopeController gyroscope;
LineSensorController lineSensor;
ServoController servo;
UltrasonicController ultrasonic;

MPU6050 accelgyro;

void setup() {
  lineSensor.setupPins();
  servo.setupPins();
  driver.setupPins();
  ultrasonic.setupPins();
  gyroscope.initializeGyroscope();
  Serial.begin(9600);
}

void moveAndPing(int angle) {
    servo.setAngle(angle);
    Serial.print("cm: ");
    Serial.println(ultrasonic.ping());
    delay(10);
  }

void loop() {
  for (int i = 0; i < 180; i++) {
    moveAndPing(i);
  }

  for (int i = 180; i > 0; i--) {
    moveAndPing(i);
  }

  // if (x_rot < -5) {
  //   // Moves fwd at speed 35 units
  //   digitalWrite(A_IN, HIGH); // Right side fwd
  //   digitalWrite(B_IN, HIGH); // Left side fwd
  //   analogWrite(PWMA, 35);
  //   analogWrite(PWMB, 35);
  // } else if (x_rot > 5) {
  //   // Moves bcwd at speed 40 units
  //   analogWrite(PWMA, 40);
  //   analogWrite(PWMB, 40);
  //   digitalWrite(A_IN, LOW); // Right side bcwd
  //   digitalWrite(B_IN, LOW); // Left side bcwd
  // } else {
  //   // STOPS the movement
  //   analogWrite(PWMA, 0);
  //   analogWrite(PWMB, 0);
  // }
}
