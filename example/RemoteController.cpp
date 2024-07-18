#include "RemoteController.h"

IRrecv irrecv(RECV_PIN);

void RemoteController::clearPressed() {
  for (int i = 0; i < 15; i++) {
    pressed[i] = false;
  }
}

bool RemoteController::getPressed(uint8_t button) {
  // Make sure a signal from the remote is detected.
  if (!irrecv.decode()) {
    return false;
  }

  // Get the result of that signal in raw data. (the button pressed)
  long result = irrecv.decodedIRData.decodedRawData;

  // Allow the code to keep recieving signals.
  irrecv.resume();

  // Check which button is being pressed.
  return result == aButtons[button] || result == bButtons[button];
}

bool RemoteController::getPressedSimple(uint8_t button) {
  // // Make sure a signal from the remote is detected.
  // if (!irrecv.decode()) {
  //   return false;
  // }

  // // Get the result of that signal in raw data. (the button pressed)
  // long result = irrecv.decodedIRData.decodedRawData;

  // // Allow the code to keep recieving signals.
  // irrecv.resume();

  // // Check which button is being pressed.
  // switch(button) {
  //   case 0: // 0
  //     return false;
  //   case 1: // 1
  //     return result == aRECV_1 || result == bRECV_1;
  //   case 2: // 2
  //     return result == aRECV_2 || result == bRECV_2;
  //   case 3: // 3
  //     return result == aRECV_3 || result == bRECV_3;
  //   case 4: // 4
  //     return result == aRECV_4 || result == bRECV_4;
  //   case 5: // 5
  //     return result == aRECV_5 || result == bRECV_5;
  //   case 6: // 6
  //     return result == aRECV_6 || result == bRECV_6;
  //   case 7: // 7
  //     return result == aRECV_7 || result == bRECV_7;
  //   case 8: // 8
  //     return result == aRECV_8 || result == bRECV_8;
  //   case 9: // 9
  //     return result == aRECV_9 || result == bRECV_9;
  //   case 10: // left
  //     return result == aRECV_left || result == bRECV_left;
  //   case 11: // right
  //     return result == aRECV_right || result == bRECV_right;
  //   case 12: // up
  //     return result == aRECV_upper || result == bRECV_upper;
  //   case 13: // down
  //     return result == aRECV_lower || result == bRECV_lower;
  //   case 14: // ok
  //     return result == aRECV_ok || result == bRECV_ok;
  //   default:
  //     re

  //   return false;
}

bool RemoteController::getDown(uint8_t button) {
  if (pressed[button]) {
    return false;
  }

  if (getPressed(button)) {
    pressed[button] = true;
    return true;
  }

  return false;
}
