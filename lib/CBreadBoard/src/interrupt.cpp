//
// Created by Jedzia on 09.11.2019.
//

#include <iostream>
#include "CBreadBoard/interrupt.h"

namespace cbb {

    Interrupt::Interrupt() {
        std::cout << "Constructor CBreadBoard::MyLibrary()" << std::endl;
    }

    Interrupt::constructor::constructor() {
        /* do some constructing here … */
        std::cout << "STATIC Interrupt::constructor::constructor()" << std::endl;
    }

    Interrupt::constructor Interrupt::cons;

}