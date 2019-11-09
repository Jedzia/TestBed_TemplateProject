//
// Created by Jedzia on 09.11.2019.
//

#ifndef STD17_INTERRUPT_H
#define STD17_INTERRUPT_H

namespace cbb {

    class Interrupt {
        friend class constructor;

        struct constructor {
            constructor();
        };

        static constructor cons;
    public:
        Interrupt();
    };

}

#endif //STD17_INTERRUPT_H
