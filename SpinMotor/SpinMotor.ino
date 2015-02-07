#include <Servo.h>

Servo servo;
unsigned int sensorValue = 0;
unsigned int angle = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 9 as an output.
  pinMode(9, OUTPUT);
  
  // initialize digital pin 12 as an input.
  pinMode(12, INPUT);
  
  servo.attach(11);
}

// the loop function runs over and over again forever
void loop() {
  // if the button is pressed
  if (digitalRead(12)) {
    // turn on the motor
    digitalWrite(9, HIGH);
  } else { // otherwise
    // turn off the motor
    digitalWrite(9, LOW);
  }
  
  // result between 0 and 1023
  sensorValue = analogRead(0);
  // need to scale because write is only between 0 ans 255
  angle = (int) map(sensorValue, 0, 1023, 0, 179);
  servo.write(angle);

  delay(200);
}

