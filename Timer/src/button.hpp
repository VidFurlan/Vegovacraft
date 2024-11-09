#pragma once

#include <Arduino.h>

typedef void (*buttonCallback)();

class Button{
public:
    buttonCallback onPress;
    buttonCallback onRelease;
    buttonCallback onChange;

    Button(int pin, bool is_pullup = false);

    void update();
    bool is_pressed();

private:

    bool is_pullup;
    int pin;

    bool old_state;

    const int debounce_time = 10;
    int last_press;
};
