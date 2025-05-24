class GiaAnTraffic {
private:
  int state;

  int greenPin;
  int yellowPin;
  int redPin;

  int counter_greenPin;
  int counter_yellowPin;
  int counter_redPin;

  int greenTime;
  int yellowTime;
  int redTime;

  void MainLight(int green, int yellow, int red) {
    digitalWrite(greenPin, green);
    digitalWrite(yellowPin, yellow);
    digitalWrite(redPin, red);
  }

  void CounterLight(int green, int yellow, int red) {
    digitalWrite(counter_greenPin, green);
    digitalWrite(counter_yellowPin, yellow);
    digitalWrite(counter_redPin, red);
  }

  void runGreenState() {
    MainLight(1, 0, 0);
    for (int i = greenTime; i >= 0; i--) {
      CounterLight(0, 0, 1);
      delay(1000);
    }
  }

  void runYellowState() {
    MainLight(0, 1, 0);
    for (int i = yellowTime; i >= 0; i--) {
      CounterLight(0, 0, 1);
      delay(1000);
    }
  }

  void runRedState() {
    MainLight(0, 0, 1);
    for (int i = redTime; i >= 0; i--) {
      if (i >= yellowTime) {
        CounterLight(1, 0, 0);
      } else {
        CounterLight(0, 1, 0);
      }
      delay(1000);
    }
  }

public:
  GiaAnTraffic(int RedTime, int YellowTime, int GreenTime)
      : state(-1), redTime(RedTime), yellowTime(YellowTime), greenTime(GreenTime) {}
  
  void setPin(int greenPin, int yellowPin, int redPin) {
    this -> greenPin = greenPin;
    this -> yellowPin = yellowPin;
    this -> redPin = redPin;
  }

  void setCounterPin(int greenPin, int yellowPin, int redPin) {
    counter_greenPin = greenPin;
    counter_yellowPin = yellowPin;
    counter_redPin = redPin;
  }

  void setup() {
    for (int i = 8; i <= 13; i++) {
      pinMode(i, OUTPUT);
    }
  }
  void NormalState() {
    state++;
    switch (state % 3) {
      case 0:
        runRedState();
        break;
      case 1:
        runGreenState();
        break;
      case 2:
        runYellowState();
        break;
    }
  }

  void WalkingState() {
    for (int i = 2; i >= 0; i--) {
      MainLight(0, 1, 0);
      CounterLight(0, 0, 1);
      delay(1000);
      MainLight(0, 0, 0);
      delay(1000);
    }
  }
};