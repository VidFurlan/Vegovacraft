#pragma once

typedef void (*callbackFunction)();

class Timer {
  public:
    callbackFunction callback;
    bool running;

    Timer(unsigned long interval, int repeat = 1);
    void startTimer();
    void stopTimer();
    void check();

  private:
    unsigned long start;
    unsigned long interval;
    int repetitions;
    int counter;
};