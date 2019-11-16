//
// Created by Jedzia on 14.11.2019.
//

#ifndef TESTBED_MCU_MCU_H
#define TESTBED_MCU_MCU_H

#include <CBreadBoard/io/input.h>

//#define DUMMY_TCCR1A _SFR_MEM8(0x80)
#define DUMMY_TCCR1A _SFR_MEM8(DUMMY_TCCR1A_POINTER)
#define ISR(x) void x()


class MCU {
public:
    static void run();
};

extern InputDevice joystick;

#endif //TESTBED_MCU_MCU_H
