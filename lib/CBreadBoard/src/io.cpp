//
// Created by Jedzia on 10.11.2019.
//

#include <iostream>
#include <utility>
#include "CBreadBoard/io.h"

namespace cbb {

    Pin::Pin(std::string name, std::string port, std::string pin) noexcept
            : _name(std::move(name)),
              _port(std::move(port)),
              _pin(std::move(pin)),
              _state(false) {
        std::cout << "Pin[" << _name << "]:Created " << std::endl;
    }

    Pin::~Pin() {
        std::cout << "Pin[" << _name << "]:Destructed " << std::endl;
    }

    void Pin::setState(bool state) {
        if (_state != state)
            std::cout << "    [" << _name << "]:setting state " << state << std::endl;
        _state = state;
    }

    bool Pin::getState() const {
        return _state;
    }


    bool digitalRead(Pin &pin) {
        return pin.getState();
    }

    void digitalWrite(Pin &pin, bool state) {
        pin.setState(state);
    }
}