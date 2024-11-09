#include "timer.hpp"
#include <Arduino.h>

Timer::Timer(unsigned long interval, int repeat = 1) {
    this->interval = interval;
    repetitions = repeat;
}

void Timer::startTimer() {
    counter = 0;
    running = true;
    start = millis();
}

void Timer::stopTimer() {
    running = false;
}

void Timer::check() {
    if (!running) return;
    if (millis() >= start + interval) {
        if (callback)
            callback();
        start = millis();
        counter++;
        if (counter == repetitions) {
            counter = 0;
            running = false;
        }
    }
}