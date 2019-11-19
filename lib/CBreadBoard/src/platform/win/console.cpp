//
// Created by Jedzia on 18.11.2019.
//
#include <CBreadBoard/console.h>
#include <windows.h>

namespace cbb {
    const WORD colors[] =
            {
                    0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
                    0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
            };

    void setTextAttributes(uint16_t attr){
        //HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
        HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
        //WORD index = 0;

        // Remember how things were when we started
        //CONSOLE_SCREEN_BUFFER_INFO csbi;
        //GetConsoleScreenBufferInfo(hstdout, &csbi);

        SetConsoleTextAttribute( hstdout, attr );
    }
}
