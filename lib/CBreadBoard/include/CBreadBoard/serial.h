//
// Created by Jedzia on 08.11.2019.
//

#ifndef STD17_SERIAL_H
#define STD17_SERIAL_H

namespace cbb {

    class SerialCom {
    public:
        static void println(const char *c);
    };

    extern SerialCom Serial;
}

#endif //STD17_SERIAL_H
