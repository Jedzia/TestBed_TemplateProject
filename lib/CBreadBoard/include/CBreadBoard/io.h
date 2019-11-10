//
// Created by Jedzia on 10.11.2019.
//

#ifndef STD17_IO_H
#define STD17_IO_H

#define _AVR_IO_H_

#include <CBreadBoard/avrgcc/sfr_defs.h>
#include <CBreadBoard/avrgcc/iom328p.h>
#include <string>

namespace cbb {

    class io {

    };

    class Pin {
        std::string name;
        std::string port;
        std::string pin;
    public:
        Pin(const std::string &name, const std::string &port, const std::string &pin);

        void setState(bool state);
    };

    void digitalWrite(Pin &pin, bool state);

}
#endif //STD17_IO_H
