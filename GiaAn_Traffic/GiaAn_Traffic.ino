#include "GiaAnLed.h"
#include "GiaAnTraffic.h"

GiaAnTraffic traffic(3, 2, 2);
const int WalkingButton = 2;
const int HandButton = 3;
const int SwitchButton = 4;
const int testLed = 5;
int buttonState = 0;

void setup() {
  
  //ButtonPin
  pinMode(WalkingButton, INPUT);
  pinMode(HandButton, INPUT);
  pinMode(SwitchButton, INPUT);
  pinMode(testLed, OUTPUT);
  
  //Traffic Light
     
  traffic.setPin(8, 9, 10);
  traffic.setCounterPin(11, 12, 13);

  traffic.setup();
}

int walking_cnt = 0;
int hand_cnt = 0;
int switch_cnt = 0;

void loop() {
  int WalkingState = digitalRead(WalkingButton);
  int HandState = digitalRead(HandButton);
  int SwitchState = digitalRead(SwitchButton);

  walking_cnt += WalkingState;
  hand_cnt += HandState;
  switch_cnt += SwitchState;

  switch (switch_cnt & 1) {
    case 0:
      if (walking_cnt & 1) {
        traffic.WalkingState();
      } else {
        traffic.NormalState();
      } 
      break;
    case 1:
      digitalWrite(testLed, HIGH);
      traffic.HandState(hand_cnt);
      break;
  }
}
