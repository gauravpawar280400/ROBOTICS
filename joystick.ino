#include <Servo.h>

// Pin assignments
const int servo1Pin = 9;
const int servo2Pin = 10;
const int joystickX = A0;
const int joystickY = A1;
const int button = 2;

// Joystick and servo configurations
const int joystickHomeY = 512;  // Default joystick center position
const int joystickDeadband = 50;

const int servo1Left = 0;
const int servo1Right = 180;
const int servo2Up = 0;
const int servo2Down = 180;
const int servo1Home = 90;
const int servo2Home = 90;

const int servo1Step = 1;
const int servo2Step = 1;

// Servo objects
Servo servo1;
Servo servo2;

// Current positions of the servos
int servo1Position = servo1Home;
int servo2Position = servo2Home;

void setup() {
  // Attach servos to their respective pins
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);

  // Initialize the button pin
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  // Read the joystick X and Y values
  int joystickValueX = analogRead(joystickX);
  int joystickValueY = analogRead(joystickY);

  // Move servo1 based on joystick X-axis
  if (joystickValueX < joystickHomeY - joystickDeadband) {  // Joystick moved left
    if (servo1Position > servo1Left) {
      servo1Position -= servo1Step;
    }
  } else if (joystickValueX > joystickHomeY + joystickDeadband) {  // Joystick moved right
    if (servo1Position < servo1Right) {
      servo1Position += servo1Step;
    }
  }

  // Move servo2 based on joystick Y-axis
  if (joystickValueY < joystickHomeY - joystickDeadband) {  // Joystick moved up
    if (servo2Position > servo2Up) {
      servo2Position -= servo2Step;
    }
  } else if (joystickValueY > joystickHomeY + joystickDeadband) {  // Joystick moved down
    if (servo2Position < servo2Down) {
      servo2Position += servo2Step;
    }
  }

  // Reset servos to home positions when button is pressed
  if (digitalRead(button) == LOW) {
    servo1Position = servo1Home;
    servo2Position = servo2Home;
  }

  // Write updated positions to servos
  servo1.write(servo1Position);
  servo2.write(servo2Position);

  delay(10);  // Short delay for smooth movement
}
