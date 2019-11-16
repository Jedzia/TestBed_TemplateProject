//
// Created by Jedzia on 14.11.2019.
//

#include "CBreadBoard/mcu.h"
#include <iostream>
#include <CBreadBoard/Arduino.h>
#include <chrono>
#include "unistd.h"

InputDevice joystick(1);

extern void setup();

extern void simulate();

extern void loop();

extern ISR(TIMER1_COMPA_vect_dummy);


typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::milliseconds Milliseconds;

//InputDevice joystick(1);

void MCU::run() {
    std::cout << "MCU::run()" << std::endl;
    setup();
    simulate();

    //for (int i = 1; i < 6; ++i) {
    //delay(200);
    // }
    Clock::time_point t0 = Clock::now();

    for (int i = 0; i < 100000; ++i) {
        //joystick.DoSomething();
        if(joystick.ButtonBPressed())
            return;

        Clock::time_point t1 = Clock::now();
        auto elapsed_time = std::chrono::duration_cast<Milliseconds>(t1 - t0);
        auto duration = Milliseconds(1000);
        // Check if time left from initial 2 seconds wait the difference
        if (elapsed_time > duration) {
            TIMER1_COMPA_vect_dummy();
            t0 = Clock::now();
        }

        loop();
        usleep(1000 * 1);
    }
}
