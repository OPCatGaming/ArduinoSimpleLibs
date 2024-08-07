#include "DriveController.h"
#include "GyroscopeController.h"
#include "LineSensorController.h"
#include "ServoController.h"
#include "UltrasonicController.h"
#include "RemoteController.h"
#include "MPU6050.h"

DriveController driver;
GyroscopeController gyroscope;
LineSensorController lineSensor;
ServoController servo;
UltrasonicController ultrasonic;
RemoteController remote;

MPU6050 accelgyro;

void setup() {
  lineSensor.setupPins();
  servo.setupPins();
  driver.setupPins();
  ultrasonic.setupPins();
  gyroscope.initializeGyroscope();
  remote.setup();
  Serial.begin(9600);
}

void moveAndPing(int angle) {
    servo.setAngle(angle);
    Serial.print("cm: ");
    Serial.println(ultrasonic.ping());
    delay(10);
  }

void loop() {
  // How to use my RemoteController class
  // Advanced:
  remote.update(); // You need this every time you want to refresh the inputs.
  // Values: 0 = not pressed, 1 = pressed, 2 = just down, 3 = just up
  remote.hasValue(1, BTN_UP); // This gets whether the up button is currently pressed.

  // Moderate:
  remote.getPressed(BTN_UP); // This gets whether the up button is currently pressed.

  // Simple
  remote.getPressedSimple(BTN_UP); // This gets whether the up button is currently pressed.






  // for (int i = 0; i < 180; i++) {
  //   moveAndPing(i);
  // }

  // for (int i = 180; i > 0; i--) {
  //   moveAndPing(i);
  // }

  // if (x_rot < -5) {
  //   // Moves fwd at speed 35 units
  //   digitalWrite(A_IN, HIGH); // Right side fwd
  //   digitalWrite(B_IN, HIGH); // Left side fwd
  //   analogWrite(PWMA, 35);
  //   analogWrite(PWMB, 35);
  // } else if (x_rot > 5) {
  //   // Moves bcwd at speed 40 units
  //   analogWrite(PWMA, 40);
  //   analogWrite(PWMB, 40);
  //   digitalWrite(A_IN, LOW); // Right side bcwd
  //   digitalWrite(B_IN, LOW); // Left side bcwd
  // } else {
  //   // STOPS the movement
  //   analogWrite(PWMA, 0);
  //   analogWrite(PWMB, 0);
  // }
}

// void getIRRemoteInput(uint8_t button) {
//   if (!irrecv.decode()) {
//     return false;
//   }

//   long result = irrecv.decodedIRData.decodedRawData;

//   switch(button) {
//     case 0: // 0
//       return result == 0;
//     case 1: // 1
//       return result == 0;
//     case 2: // 2
//       return result == 0;
//     case 3: // 3
//       return result == 0;
//     case 4: // 4
//       return result == 0;
//     case 5: // 5
//       return result == 0;
//     case 6: // 6
//       return result == 0;
//     case 7: // 7
//       return result == 0;
//     case 8: // 8
//       return result == 0;
//     case 9: // 9
//       return result == 0;
//     case 10: // left
//       return result == 0;
//     case 11: // right
//       return result == 0;
//     case 12: // up
//       return result == 0;
//     case 13: // down
//       return result == 0;
//   }

//   irrecv.resume();
// }
