#include <iostream>
#include <memory>
#include "MyClass.h"
#include <STD17lib/library.h>
#include <STD17lib/network.h>
#include <STD17lib/fsm.h>
#include <CBreadBoard/cbreadboard.h>
#include <chrono>

// State machine variables
#define FLIP_LIGHT_SWITCH 1

SerialCom Serial;

// Transition callback functions
void on_light_on_enter() {
    Serial.println("Entering LIGHT_ON");
}

void on_light_on_exit() {
    Serial.println("Exiting LIGHT_ON");
}

void on_light_off_enter() {
    Serial.println("Entering LIGHT_OFF");
}

void on_light_off_exit() {
    Serial.println("Exiting LIGHT_OFF");
}

void on_trans_light_on_light_off() {
    Serial.println("Transitioning from LIGHT_ON to LIGHT_OFF");
}

void on_trans_light_off_light_on() {
    Serial.println("Transitioning from LIGHT_OFF to LIGHT_ON");
}

int main() {
    std::cout << "Fucking Hello, World!" << std::endl;
    auto f = 3.14159f;
    std::cout << "Float=" << f << std::endl;
    std::cout << "Float=" << f * 6 << std::endl;

    auto lambda = [](auto a) { std::cout << "lambada='" << a << "'." << std::endl; };
    lambda("I'm da lambda");

    MyLibrary m;
    MyClass mc;
    std::cout << "MyClass=.DoSomething()='" << mc.DoSomething() << "'." << std::endl;

    {
        auto p = std::make_unique<MyClass>();
        std::cout << "*MyClass=.DoSomething()='" << p->DoSomething() << "'." << std::endl;
    }

    Network net;
    net.getName();

    std::cout << std::endl;
    std::cout << std::endl;


    State state_light_on(on_light_on_enter, NULL, &on_light_on_exit);
    State state_light_off(on_light_off_enter, NULL, &on_light_off_exit);
    Fsm fsm(&state_light_off);


    fsm.add_transition(&state_light_on, &state_light_off,
                       FLIP_LIGHT_SWITCH,
                       &on_trans_light_on_light_off);
    fsm.add_transition(&state_light_off, &state_light_on,
                       FLIP_LIGHT_SWITCH,
                       &on_trans_light_off_light_on);



    // No "fsm.run_machine()" call needed as no "on_state" funcions or timmed transitions exists
    fsm.run_machine();
    //delay(2000);
    fsm.trigger(FLIP_LIGHT_SWITCH);
    //delay(2000);
    fsm.trigger(FLIP_LIGHT_SWITCH);

    std::cout << std::endl << std::endl;
    std::cout << "goodbye" << std::endl;
    return 1;
}