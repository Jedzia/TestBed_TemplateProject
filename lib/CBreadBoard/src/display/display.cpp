//
// Created by Jedzia on 21.11.2019.
//

#include <CBreadBoard/internal/display.h>
#include <curses.h>
#include <iostream>
#include <sstream>
#include <utility>
#include <mbctype.h>

extern int printLocales();

namespace cbb {


    void checkLocales() {
        return;
        // does not work on windoze
        // see https://sourceforge.net/p/mingw/mailman/message/31768770/
        // The GCC's libstdc++ does not support locales other than the C locale on
        // MinGW. Somebody has to implement it first.
        printLocales();
        std::wcout << "User-preferred locale setting is " << std::locale("").name().c_str() << '\n';
        // on startup, the global locale is the "C" locale
        std::wcout << 1000.01 << '\n';
        // replace the C++ global locale as well as the C locale with the user-preferred locale
        //std::locale::global(std::locale("en_EN.UTF-8"));
        std::locale::global(std::locale(u8"en-US.UTF-8"));
        // use the new global locale for future wide character output
        std::wcout.imbue(std::locale());
        // output the same number again
        std::wcout << 1000.01 << '\n';
    }

    void initDisplay() {
        checkLocales();

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
