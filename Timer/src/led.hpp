#pragma once

#include <Arduino.h>

class Led {
  public:
    Led(int pin);
    Led(int pin, bool on);

    bool getStatus();
    bool set(bool on);
    bool change();

  private:
    int pin;
};