//
// Created by Jedzia on 18.11.2019.
//

#ifndef TESTBED_MCU_CONSOLE_H
#define TESTBED_MCU_CONSOLE_H

#include <cstdint>

namespace cbb {

    extern const uint16_t colors[12];
    void setTextAttributes(uint16_t attr);

}

#endif //TESTBED_MCU_CONSOLE_H
