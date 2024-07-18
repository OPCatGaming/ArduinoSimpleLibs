#include <Arduino.h>
#include <pins_arduino.h>

class UltrasonicController {
  public:
    void setupPins();
    unsigned int ping();

  private:
    #define TRIG 13
    #define ECHO 12
    #define MAX_DISTANCE 200
};