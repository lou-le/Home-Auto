#include <AccelStepper.h>

#define slateAngle_EN 6
#define slateAngle_step 8
#define slateAngle_dir 10

#define slatePos_EN 1
#define slatePos_step 2
#define slatePos_dir 4

#define r_blind_button 40
#define l_blind_button 38
#define r_tilt_button 36
#define l_tilt_button 34

#define LEDPin 15


AccelStepper AngleStepper(AccelStepper::DRIVER, slateAngle_step, slateAngle_dir, slateAngle_EN);
AccelStepper PositionStepper(AccelStepper::DRIVER, slatePos_step, slatePos_dir, slatePos_EN);

int blindPosition = 0;
int blindAngle = 0;

const int blindMoveInterval = 10;

void IRAM_ATTR moveBlindR() {
  Serial.println("MoveBlindR Button Pressed");
  PositionStepper.move(blindMoveInterval);
  digitalWrite(LEDPin, 1);
  while (PositionStepper.distanceToGo() != 0) {
    PositionStepper.run();
  }
}
void IRAM_ATTR moveBlindL() {
  Serial.println("MoveBlindL Button Pressed");
  PositionStepper.move(-blindMoveInterval);
  digitalWrite(LEDPin, 1);
  while (PositionStepper.distanceToGo() != 0) {
    PositionStepper.run();
  }
}
void IRAM_ATTR moveTiltR() {
  Serial.println("moveTiltR() Button Pressed");
  AngleStepper.move(blindMoveInterval);
  digitalWrite(LEDPin, 1);
  while (AngleStepper.distanceToGo() != 0) {
    AngleStepper.run();
  }
}
void IRAM_ATTR moveTiltL() {
  Serial.println("moveTiltL Button Pressed");
  AngleStepper.move(-blindMoveInterval);
  digitalWrite(LEDPin, 1);
  while (AngleStepper.distanceToGo() != 0) {
    AngleStepper.run();
  }
}

void homeBlinds() {
  digitalWrite(LEDPin, 1);
  AngleStepper.move(1000);
  while (AngleStepper.distanceToGo() != 0) {
    AngleStepper.run();
  }
  AngleStepper.move(-1000);
  while (AngleStepper.distanceToGo() != 0) {
    AngleStepper.run();
  }
  digitalWrite(LEDPin, 0);
  delay(3000);
  digitalWrite(LEDPin, 1);

  PositionStepper.move(1000);
  while (PositionStepper.distanceToGo() != 0) {
    PositionStepper.run();
  }
  PositionStepper.move(-1000);
  while (PositionStepper.distanceToGo() != 0) {
    PositionStepper.run();
  }
  digitalWrite(LEDPin, 0);

  AngleStepper.setCurrentPosition(0);
  PositionStepper.setCurrentPosition(0);
}

void setup() {
  Serial.begin(115200);
  pinMode(LEDPin, OUTPUT);
  pinMode(r_blind_button, INPUT_PULLDOWN);
  pinMode(l_blind_button, INPUT_PULLDOWN);
  pinMode(r_tilt_button, INPUT_PULLDOWN);
  pinMode(l_tilt_button, INPUT_PULLDOWN);
  attachInterrupt(r_blind_button, moveBlindR, FALLING);
  attachInterrupt(l_blind_button, moveBlindL, FALLING);
  attachInterrupt(r_tilt_button, moveTiltR, FALLING);
  attachInterrupt(l_tilt_button, moveTiltL, FALLING);


  AngleStepper.setMaxSpeed(2500);
  AngleStepper.setAcceleration(1000);
  AngleStepper.setPinsInverted(0, 0, 1);

  PositionStepper.setMaxSpeed(2500);
  PositionStepper.setAcceleration(1000);
  PositionStepper.setPinsInverted(0, 0, 1);

  homeBlinds();
}


void loop() {
  digitalWrite(LEDPin, 0);
}
