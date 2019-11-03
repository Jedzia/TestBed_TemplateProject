//
// Created by Jedzia on 29.10.2019.
//

#ifndef STD17_NETWORK_H
#define STD17_NETWORK_H


class Network {
public:
    Network();

    virtual ~Network();

    void getName();

private:
    static bool initialized;
};


#endif //STD17_NETWORK_H
