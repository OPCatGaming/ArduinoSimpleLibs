#include <Arduino.h>
#include <pins_arduino.h>

#define LEFT A2
#define MIDDLE A1
#define RIGHT A0

class LineSensorController {
  public:
    void setupPins();
    float getAnalog(uint8_t side);

  private:
    // Line sensor pins (ITR20001xxx)
    #define ITR_L A2
    #define ITR_M A1
    #define ITR_R A0
};