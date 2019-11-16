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
        std::string _name;
        std::string _port;
        std::string _pin;
        bool _state;

    public:
        Pin(std::string name, std::string port, std::string pin) noexcept;
        virtual ~Pin();

        Pin & operator=(const Pin&) = delete;
        Pin(const Pin&) = delete;

        void setState(bool state);
        [[nodiscard]] bool getState() const;

    };

    bool digitalRead(Pin &pin);
    void digitalWrite(Pin &pin, bool state);

}
#endif //STD17_IO_H
