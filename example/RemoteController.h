#include <Arduino.h>
#include <pins_arduino.h>
#include <IRremote.h>

#define BTN_0 0
#define BTN_1 1
#define BTN_2 2
#define BTN_3 3
#define BTN_4 4
#define BTN_5 5
#define BTN_6 6
#define BTN_7 7 
#define BTN_8 8 
#define BTN_9 9
#define BTN_LEFT 10
#define BTN_RIGHT 11
#define BTN_UP 12
#define BTN_DOWN 13
#define BTN_OK 14

class RemoteController {
  public:
    // Needed for all funcs to work
    void setup();

    // Advanced approach funcs
    void update();
    bool hasValue(int value, uint8_t button);

    // Moderate appoach func
    bool getPressed(uint8_t button);

    // Simple approach func
    bool getPressedSimple(uint8_t button);

  private:
    // Only used for the advanced approach
    int pressed[15] = { 0 };

    #define RECV_PIN 7

    // I DO NOT know whether these are the right raw data numbers, however, these were in the example code.

    /*A:4294967295*/
    #define aRECV_upper 16736925
    #define aRECV_lower 16754775
    #define aRECV_left 16720605
    #define aRECV_right 16761405
    #define aRECV_ok 16712445
    #define aRECV_1 16738455
    #define aRECV_2 16750695
    #define aRECV_3 16756815
    #define aRECV_4 16724175
    #define aRECV_5 16718055
    #define aRECV_6 16743045
    #define aRECV_7 16716015
    #define aRECV_8 16726215
    #define aRECV_9 16734885
    // #define aRECV_ *16728765
    // #define aRECV_0 16730805
    // #define aRECV_ # 16732845
    /*B:*/
    #define bRECV_upper 5316027
    #define bRECV_lower 2747854299
    #define bRECV_left 1386468383
    #define bRECV_right 553536955
    #define bRECV_ok 3622325019
    #define bRECV_1 3238126971
    #define bRECV_2 2538093563
    #define bRECV_3 4039382595
    #define bRECV_4 2534850111
    #define bRECV_5 1033561079
    #define bRECV_6 1635910171
    #define bRECV_7 2351064443
    #define bRECV_8 1217346747
    #define bRECV_9 71952287
    // #define bRECV_ *851901943
    // #define bRECV_0 465573243
    // #define bRECV_ # 1053031451

    long aButtons[15] = { 0, aRECV_1, aRECV_2, aRECV_3, aRECV_4, aRECV_5, aRECV_6, aRECV_7, aRECV_8, aRECV_9, aRECV_left, aRECV_right, aRECV_upper, aRECV_lower, aRECV_ok };
    long bButtons[15] = { 0, bRECV_1, bRECV_2, bRECV_3, bRECV_4, bRECV_5, bRECV_6, bRECV_7, bRECV_8, bRECV_9, bRECV_left, bRECV_right, bRECV_upper, bRECV_lower, bRECV_ok };
};