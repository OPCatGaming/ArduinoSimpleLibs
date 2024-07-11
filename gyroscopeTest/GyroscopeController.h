#include "MPU6050.h"

class GyroscopeController {
  public:
    void calibrateGxo();
    void initializeGyroscope();
    float getXRot();

  private:
    int16_t gx;
    unsigned long now, lastTime = 0;
    float dt;      //Differential time
    float agx = 0; //Angle variable
    long gxo = 0;  //Gyroscope offset

    float xRot = 0;

    MPU6050 accelgyro;
};