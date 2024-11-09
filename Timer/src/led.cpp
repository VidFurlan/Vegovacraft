#include "led.hpp"

Led::Led(int pin) {
    this->pin = pin;
    pinMode(pin, OUTPUT);
}

Led::Led(int pin, bool on) {
    this->pin = pin;
    pinMode(pin, OUTPUT);
    set(on);
}

bool Led::set(bool on) {
    digitalWrite(pin, on ? HIGH : LOW);
    return on;
}

bool Led::getStatus() {
    return digitalRead(pin);
}

bool Led::change() {
    return set(!getStatus());
}