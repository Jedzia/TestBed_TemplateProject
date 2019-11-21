//
// Created by Jedzia on 12.11.2019.
//

#ifndef TESTBED_MCU_INPUT_H
#define TESTBED_MCU_INPUT_H

// No MFC
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <XInput.h>

class InputDevice {
public:
    InputDevice(int playerNumber);

    // [[deprecated("Use only for development testing")]]
    void DoSomething();

    XINPUT_STATE GetState();

    bool IsConnected();

    void Vibrate(int leftVal = 0, int rightVal = 0);

    bool ButtonAPressed();

    bool ButtonBPressed();

    bool ButtonXPressed();

private:
    XINPUT_STATE _controllerState = {};
    int _controllerNum;
};


#endif //TESTBED_MCU_INPUT_H
