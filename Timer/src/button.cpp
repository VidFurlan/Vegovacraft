#include "button.hpp"


Button::Button(int pin, bool is_pullup = false){
    this->pin = pin;
    this->is_pullup = is_pullup;
    old_state = false;
    last_press = 0;
    
    if(is_pullup == true){
        pinMode(pin, INPUT_PULLUP);
    }else{
        pinMode(pin, INPUT);
    }
}

bool Button::is_pressed(){
    if(is_pullup == true){
        return !digitalRead(pin);
    }
    return digitalRead(pin);
}

void Button::update(){
    if(last_press + debounce_time > millis()){
        return;
    }

    bool new_state = is_pressed();

    if(old_state != new_state){
        if (onChange)
            onChange();

        if (new_state) {
            if (onPress)
                onPress();
        } 
        else {
            if (onRelease)
                onRelease();
        }

        old_state = new_state;
        last_press = millis();
    }
}