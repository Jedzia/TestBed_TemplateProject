//
// Created by Jedzia on 14.11.2019.
//

#include "CBreadBoard/mcu.h"
#include <iostream>
#include "unistd.h"

void setup();
void loop();

void MCU::run() {
    std::cout << "MCU::run()" << std::endl;
    setup();

    for (int i = 0; i < 10; ++i) {
        loop();
        usleep(1000 * 200);
    }
}
