#include "DriveController.h"

void DriveController::setupPins() {
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(B_IN, OUTPUT);
  pinMode(A_IN, OUTPUT);
  pinMode(STBY, OUTPUT);

  digitalWrite(STBY, HIGH);
}

void DriveController::setSpeed(uint8_t side, int speed) {
  digitalWrite(side, speed > 0 ? HIGH : LOW);
  analogWrite(side - 2, abs(speed));
}

void DriveController::setSpeed(int speed) {
  setSpeed(LEFT_WHEELS, speed);
  setSpeed(RIGHT_WHEELS, speed);
}