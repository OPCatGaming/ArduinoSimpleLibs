#include "LineSensorController.h"

void LineSensorController::setupPins() {
  pinMode(ITR_L, INPUT);
  pinMode(ITR_M, INPUT);
  pinMode(ITR_R, INPUT);
}

float LineSensorController::getAnalog(uint8_t side) {
  return analogRead(side);
}