#include <Arduino.h>
#include "button.hpp"
#include "led.hpp"
#include "timer.hpp"

Button button(4, true);

Led led(3, true);

Timer timer(1000, 50);

void button4Press() {
  Serial.println("Timer cancled");
  timer.stopTimer();
}

void button4Release() {
  Serial.println("Gumb 4 releasan");
}

void timerOnComplete() {
  Serial.println("Done");
  led.change();
}

void setup() {
  button.onPress = button4Press;
  button.onRelease = button4Release;
  timer.callback = timerOnComplete;
  Serial.begin(115200);
  timer.startTimer();
}

void loop() {
  button.update();
  timer.check();
}