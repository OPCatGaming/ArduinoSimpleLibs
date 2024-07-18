#include "GyroscopeController.h"

void GyroscopeController::calibrateGxo()
{
  unsigned short times = 100; //Sampling times
  for (int i = 0; i < times; i++)
  {
    gx = accelgyro.getRotationX();
    gxo += gx;  
  }
  gxo /= times; //Calculate gyroscope offset
}

void GyroscopeController::initializeGyroscope() {
  accelgyro.initialize();
  calibrateGxo();
}

float GyroscopeController::getXRot()
{
  unsigned long now = millis();   //Current time (ms)
  dt = (now - lastTime) / 1000.0; //Differential time(s)
  lastTime = now;                 //Last sampling time (ms)
  gx = accelgyro.getRotationX();
  float gyrox = -(gx - gxo) / 131.0 * dt; //x-axis angular velocity
  if (fabs(gyrox) < 0.05)
  {
    gyrox = 0.00;
  }
  agx += gyrox; //x-axis angular velocity integral
  xRot = agx;
  return xRot;
}