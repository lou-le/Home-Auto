#include <AccelStepper.h>

#define slateAngle_EN 6
#define slateAngle_step 8
#define slateAngle_dir 10

#define slatePos_EN 1
#define slatePos_step 2
#define slatePos_dir 4

#define r_blind_button 39
#define l_blind_button 37
#define r_tilt_button 35
#define l_tilt_button 33

#define LEDPin 15


AccelStepper AngleStepper(AccelStepper::DRIVER, slateAngle_step, slateAngle_dir);
AccelStepper PositionStepper(AccelStepper::DRIVER, slatePos_step, slatePos_dir);

int blindPosition = 0;
int blindAngle = 0;

const int blindMoveInterval = 30;

void IRAM_ATTR moveBlindR() {
  Serial.println("MoveBlindR Button Pressed");
  PositionStepper.move(blindMoveInterval);
}
void IRAM_ATTR moveBlindL() {
  Serial.println("MoveBlindL Button Pressed");
  PositionStepper.move(-blindMoveInterval);

}
void IRAM_ATTR moveTiltR() {
  Serial.println("moveTiltR() Button Pressed");
  AngleStepper.move(blindMoveInterval);
}
void IRAM_ATTR moveTiltL() {
  Serial.println("moveTiltL Button Pressed");
  AngleStepper.move(-blindMoveInterval);
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
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);
  pinMode(r_blind_button, INPUT_PULLUP);
  pinMode(l_blind_button, INPUT_PULLUP);
  pinMode(r_tilt_button, INPUT_PULLUP);
  pinMode(l_tilt_button, INPUT_PULLUP);
  attachInterrupt(r_blind_button, moveBlindR, RISING);
  attachInterrupt(l_blind_button, moveBlindL, RISING);
  attachInterrupt(r_tilt_button, moveTiltR, RISING);
  attachInterrupt(l_tilt_button, moveTiltL, RISING);


  AngleStepper.setMaxSpeed(2500);
  AngleStepper.setAcceleration(1000);
  AngleStepper.setPinsInverted(0, 0, 1);
  AngleStepper.setEnablePin(slateAngle_EN);

  PositionStepper.setMaxSpeed(2500);
  PositionStepper.setAcceleration(1000);
  PositionStepper.setPinsInverted(0, 0, 1);
  PositionStepper.setEnablePin(slatePos_EN);

  Serial.println("Booted up");
  homeBlinds();
  Serial.println("Homing Completed");
}


void loop() {
  //  AngleStepper.disableOutputs();
  //  PositionStepper.disableOutputs();

  for (int i = 0; i <= 100; i++) {
    digitalWrite(LEDPin, 0);
    delay(700);
    digitalWrite(LEDPin, 1);
    delay(700);
  }

  while (PositionStepper.distanceToGo() != 0) {
    PositionStepper.run();    
  }
  while (AngleStepper.distanceToGo() != 0) {
    AngleStepper.run();
  }


}
