#include <Arduino.h>
#include <pins_arduino.h>

#include <Servo.h>

class ServoController {
  public:
    void setupPins();
    void setAngle(int angle);
    
  private:
    Servo servo;
};