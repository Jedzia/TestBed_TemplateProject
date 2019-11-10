//
// Created by Jedzia on 10.11.2019.
//

#include <iostream>
#include "CBreadBoard/io.h"

namespace cbb {

    Pin::Pin(const std::string &name, const std::string &port, const std::string &pin)
            : name(name), port(port), pin(pin) {}

    void Pin::setState(bool state) {
        std::cout << "[" << name << "]:setting state " << state << std::endl;
    }


    void digitalWrite(Pin &pin, bool state) {
        pin.setState(state);
    }

}