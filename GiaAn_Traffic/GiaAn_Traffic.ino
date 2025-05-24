#include "GiaAnLed.h"
#include "GiaAnTraffic.h"

GiaAnTraffic traffic(3, 2, 2);
const int buttonPin = 2;
int buttonState = 0;

void setup() {
  
  //ButtonPin
  pinMode(buttonPin, INPUT);
  pinMode(7, OUTPUT);
  //Traffic Light
     
  traffic.setPin(8, 9, 10);
  traffic.setCounterPin(11, 12, 13);

  traffic.setup();
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH) {
    traffic.NormalState();
    traffic.WalkingState();
  } else {
    traffic.NormalState();
  }
}