//
// Created by Jedzia on 14.11.2019.
//

#include "CBreadBoard/mcu.h"
#include <iostream>
#include <CBreadBoard/io/input.h>
#include <CBreadBoard/Arduino.h>
#include "unistd.h"

void setup();

void simulate();

void loop();

extern ISR(TIMER1_COMPA_vect_dummy);

//InputDevice joystick(1);

void MCU::run() {
    std::cout << "MCU::run()" << std::endl;
    setup();
    simulate();

    //for (int i = 1; i < 6; ++i) {
    //delay(200);
    // }

    for (int i = 0; i < 10; ++i) {
        //joystick.DoSomething();
        TIMER1_COMPA_vect_dummy();
        loop();
        usleep(1000 * 200);
    }
}
