/* Example sketch to control a stepper motor with TB6600 stepper motor driver and Arduino without a library: continuous rotation. More info: https://www.makerguides.com */

// Define stepper motor connections:
#define slateAngle_EN 6
#define slateAngle_step 8
#define slateAngle_dir 10

#define slatePos_EN 1
#define slatePos_step 2
#define slatePos_dir 4

#define LEDPin 15

 int stepDelay = 500;

void setup() {
  // Declare pins as output:
  pinMode(slateAngle_step, OUTPUT);
  pinMode(slateAngle_dir, OUTPUT);
  pinMode(slateAngle_EN, OUTPUT);
  pinMode(slatePos_step, OUTPUT);
  pinMode(slatePos_dir, OUTPUT);
  pinMode(slatePos_EN, OUTPUT);
  pinMode(LEDPin, OUTPUT);


  digitalWrite(slateAngle_EN, LOW);

}

void loop() {
  stepDelay = 500;

  digitalWrite(slateAngle_EN, LOW);
  digitalWrite(LEDPin, HIGH);
  digitalWrite(slateAngle_dir, HIGH);

  for (int i = 0; i < 2000; i++) {
    digitalWrite(slateAngle_step, HIGH);
    delayMicroseconds(stepDelay);
    digitalWrite(slateAngle_step, LOW);
    delayMicroseconds(stepDelay);
  }
  digitalWrite(slateAngle_EN, HIGH);
  digitalWrite(LEDPin, LOW);


  delay(3000);

  stepDelay = 500;
  digitalWrite(slateAngle_EN, LOW);
  digitalWrite(LEDPin, HIGH);
  digitalWrite(slateAngle_dir, LOW);

  for (int i = 0; i < 2000; i++){
    digitalWrite(slateAngle_step, HIGH);
    delayMicroseconds(stepDelay);
    digitalWrite(slateAngle_step, LOW);
    delayMicroseconds(stepDelay);
  }
  digitalWrite(slateAngle_EN, HIGH);
  digitalWrite(LEDPin, LOW);

  delay(3000);


  ////////////////////////////////////////////  Next Motor Testing
//
//  digitalWrite(slatePos_EN, LOW);
//  digitalWrite(LEDPin, HIGH);
//  digitalWrite(slatePos_dir, HIGH);
//  stepDelay = 500;
//
//  for (int i = 0; i < 2000; i++) {
//    digitalWrite(slatePos_step, HIGH);
//    delayMicroseconds(stepDelay);
//    digitalWrite(slatePos_step, LOW);
//    delayMicroseconds(stepDelay);
//  }
//  digitalWrite(slatePos_EN, HIGH);
//  digitalWrite(LEDPin, LOW);
//
//
//  delay(3000);
//
//  stepDelay = 500;
//  digitalWrite(slatePos_EN, LOW);
//  digitalWrite(LEDPin, HIGH);
//  digitalWrite(slatePos_dir, LOW);
//
//  for (int i = 0; i < 2000; i++) {
//    digitalWrite(slatePos_step, HIGH);
//    delayMicroseconds(stepDelay);
//    digitalWrite(slatePos_step, LOW);
//    delayMicroseconds(stepDelay);
//  }
//  digitalWrite(slatePos_EN, HIGH);
//  digitalWrite(LEDPin, LOW);
//
//  delay(3000);
}
