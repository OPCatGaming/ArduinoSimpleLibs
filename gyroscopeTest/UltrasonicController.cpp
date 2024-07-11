#include "UltrasonicController.h"

void UltrasonicController::setupPins() {
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
}

unsigned int UltrasonicController::ping() {
  unsigned int tempda = 0;
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  tempda = ((unsigned int)pulseIn(ECHO, HIGH) / 58);
  return tempda;
}