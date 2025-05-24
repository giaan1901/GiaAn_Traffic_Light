class GiaAnLed {
private:
  int LedPin = 0;
  int on_time = 0;
  int off_time = 0;
  int prev_millis = 0;
  int state = LOW;
public:
  void setup(int LedPin = 0, int on_time = 0, int off_time = 0) {
    this -> LedPin = LedPin;
    this -> on_time = on_time;
    this -> off_time = off_time;
    
    pinMode(LedPin, OUTPUT);
  }  

  void blink() {
    int curr_millis = millis();
    if (state == LOW && curr_millis - prev_millis >= off_time) {
      prev_millis = curr_millis;
      state = HIGH;
      digitalWrite(LedPin, state);
    } 
    else if (state == HIGH && curr_millis - prev_millis >= on_time) {
      prev_millis = curr_millis;
      state = LOW;
      digitalWrite(LedPin, state);
    } 
  }
  
  int getPin() {
    return LedPin;
  }

  int getOnTime() {
    return on_time;
  }
};