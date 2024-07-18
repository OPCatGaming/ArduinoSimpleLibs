#include "RemoteController.h"

IRrecv irrecv(RECV_PIN);

// The most advanced approach i've made.
void RemoteController::update() {
  // Make sure a signal from the remote is detected.
  if (!irrecv.decode()) {
    irrecv.resume();
    return;
  }

  // Get the result of that signal in raw data. (the button pressed)
  long result = irrecv.decodedIRData.decodedRawData;

  // Allow the code to keep recieving signals.
  irrecv.resume();

  // Loop through all the buttons..
  for (int i = 0; i < 15; i++) {
    // If the button is being pressed;
    if (result == aButtons[i] || result == bButtons[i]) {
      // If the button isn't currently pressed or has just stopped being pressed
      if (pressed[i] == 0 || pressed[i] == 3) {
        pressed[i] = 2; // button down
        continue;
      }
      // Otherwise, if it is already being pressed or it was pressed down last frame
      pressed[i] = 1; // button pressed
      continue;
    }
    // If the button hasn't been pressed this frame, and it had another press event last frame (pressed / down)
    if (pressed[i] == 1 || pressed[i] == 2) {
      pressed[i] = 3; // 3 = button up
      continue;
    }
    // Otherwise, it will not register any event.
    pressed[i] = 0; // 0 = no event detected (button not pressed)
  }
}

/**
 * Returns whether the button has the value passed in. Values can be either 0, 1, 2, or 3.
 * 0 = not currently pressed & not just up.
 * 1 = currently pressed.
 * 2 = if the button was just pressed down.
 * 3 = if the button has just stopped being pressed.
 */
bool RemoteController::hasValue(int value, uint8_t button) {
  return pressed[button] == value;
}



// A bit more simple, using the lists for the buttons
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



// Simplest approach i've made, just a buncho if statements
bool RemoteController::getPressedSimple(uint8_t button) {
  // Make sure a signal from the remote is detected.
  if (!irrecv.decode()) {
    return false;
  }

  // Get the result of that signal in raw data. (the button pressed)
  long result = irrecv.decodedIRData.decodedRawData;

  // Allow the code to keep recieving signals.
  irrecv.resume();

  // Check which button is being pressed.
  if (button == 0) { // 0
    return false;
  }
  if (button == 1) { // 1
    return result == aRECV_1 || result == bRECV_1;
  }
  if (button == 2) { // 2
    return result == aRECV_2 || result == bRECV_2;
  }
  if (button == 3) { // 3
    return result == aRECV_3 || result == bRECV_3;
  }
  if (button == 4) { // 4
    return result == aRECV_4 || result == bRECV_4;
  }
  if (button == 5) { // 5
    return result == aRECV_5 || result == bRECV_5;
  }
  if (button == 6) { // 6
    return result == aRECV_6 || result == bRECV_6;
  }
  if (button == 7) { // 7
    return result == aRECV_7 || result == bRECV_7;
  }
  if (button == 8) { // 8
    return result == aRECV_8 || result == bRECV_8;
  }
  if (button == 9) { // 9
    return result == aRECV_9 || result == bRECV_9;
  }
  if (button == 10) { // left
    return result == aRECV_left || result == bRECV_left;
  }
  if (button == 11) { // right
    return result == aRECV_right || result == bRECV_right;
  }
  if (button == 12) { // up
    return result == aRECV_upper || result == bRECV_upper;
  }
  if (button == 13) { // down
    return result == aRECV_lower || result == bRECV_lower;
  }
  if (button == 14) { // ok
    return result == aRECV_ok || result == bRECV_ok;
  }

  return false;
}
