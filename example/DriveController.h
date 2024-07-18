#include <Arduino.h>
#include <pins_arduino.h>

#define RIGHT_WHEELS 7
#define LEFT_WHEELS 8


class DriveController {
  public:
    void setupPins();
    void setSpeed(uint8_t side, int speed); // Sets speed of a specific side.
    void setSpeed(int speed); // Sets speed of both sides.

  private:
    #define PWMA 5 // ANALOG: pulse width modulation A wheels (right side)
    #define PWMB 6 // ANALOG: pulse width modulation B wheels (left side) 
    #define B_IN 8 // DIGITAL: B input, LOW = bcwd, HIGH = fwd
    #define A_IN 7 // DIGITAL: A input, LOW = bcwd, HIGH = fwd 
    #define STBY 3 // DIGITAL: Standby, not sure why this is needed, always kept on HIGH
};