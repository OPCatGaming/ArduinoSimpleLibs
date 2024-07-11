#include "ServoController.h"

void ServoController::setupPins() {
  servo.attach(10);
}

void ServoController::setAngle(int angle) {
  servo.write(angle);
}