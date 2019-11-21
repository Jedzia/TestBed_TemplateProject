//
// Created by Jedzia on 21.11.2019.
//

#ifndef TESTBED_MCU_DISPLAY_H
#define TESTBED_MCU_DISPLAY_H

#include <string>

namespace cbb {
    void initDisplay();

    // inline int UNDEF(mvwaddstr)(WINDOW *win, int y, int x, const char * str)
    void printc(int y, int x, const std::string &s);
}

#endif //TESTBED_MCU_DISPLAY_H
