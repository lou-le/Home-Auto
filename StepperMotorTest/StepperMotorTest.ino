/* Example sketch to control a stepper motor with TB6600 stepper motor driver and Arduino without a library: continuous rotation. More info: https://www.makerguides.com */

// Define stepper motor connections:
//#define enablePin 6
//#define stepPin 8
//#define dirPin 10

//#define enablePin 1
//#define stepPin 2
//#define dirPin 4


#define enablePin 5
#define stepPin 7
#define dirPin 6

#define LEDPin 13

void setup() {
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(LEDPin, OUTPUT);

}

void loop() {
  // These four lines result in 1 step:
  digitalWrite(LEDPin, HIGH);

  digitalWrite(dirPin, HIGH);
  for (int i = 0; i < 2000; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(enablePin, HIGH);
  delay(4000);
  digitalWrite(enablePin, LOW);

  digitalWrite(LEDPin, LOW);
  digitalWrite(dirPin, LOW);
  for (int i = 0; i < 2000; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
  digitalWrite(enablePin, HIGH);
//  delay(4000);
//  digitalWrite(enablePin, LOW);
//
//
//
//  digitalWrite(dirPin, HIGH);
//  for (int i = 0; i < 2000; i++) {
//    digitalWrite(stepPin, HIGH);
//    delayMicroseconds(300);
//    digitalWrite(stepPin, LOW);
//    delayMicroseconds(300);
//  }
//  digitalWrite(enablePin, HIGH);
//  delay(4000);
//  digitalWrite(enablePin, LOW);
//
//
//  digitalWrite(dirPin, LOW);
//  for (int i = 0; i < 2000; i++) {
//    digitalWrite(stepPin, HIGH);
//    delayMicroseconds(300);
//    digitalWrite(stepPin, LOW);
//    delayMicroseconds(300);
//  }
//  digitalWrite(enablePin, HIGH);
//  delay(4000);
//  digitalWrite(enablePin, LOW);
}
