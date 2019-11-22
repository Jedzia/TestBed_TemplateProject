//
// Created by Jedzia on 10.11.2019.
//

#include <iostream>
#include <sstream>
#include <utility>
#include <fmt/core.h>
#include "CBreadBoard/io.h"
#include <CBreadBoard/console.h>
#include <CBreadBoard/internal/display.h>
#include <windows.h>

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
        if (_state != state) {
            // Linux std::cout << "\033[1;31mbold red text\033[0m\n";


            if (state) {
                // Tell the user how to stop
                //setTextAttributes(0xEC);
                //setTextAttributes( colors[ 3 ] );
                //std::cout << "Press any key to quit.\n";
                //setTextAttributes(colors[ 3 ]);
                //setTextAttributes(BACKGROUND_GREEN);
                setTextAttributes(FOREGROUND_GREEN);
                //setTextAttributes(BACKGROUND_BLUE);

            } else {
                //setTextAttributes( colors[ 1 ] );
                //setTextAttributes( 0 );
                //setTextAttributes(0);
                setTextAttributes(BACKGROUND_RED);
            }

            printc(5, 2, fmt::format("    [{}]:setting state {}", _name, state));
            setTextAttributes(0);
        }
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