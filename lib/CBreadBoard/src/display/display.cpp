//
// Created by Jedzia on 21.11.2019.
//

#include <CBreadBoard/internal/display.h>
#include <curses.h>
#include <iostream>
#include <sstream>
#include <utility>

namespace cbb {
    void initDisplay() {
        initscr();
        cbreak();
        noecho();
        clear();
        mvaddstr(3, 0, "NCurses Interface");
        refresh();
    }

    void printc(int y, int x, const std::string &s) {
        std::cout << s << std::endl;
        mvaddstr(y, x, s.c_str());
        refresh();
    }
}
