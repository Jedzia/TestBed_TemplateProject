//
// Created by Jedzia on 12.11.2019.
//

#include <iostream>
#include "CBreadBoard/io/input.h"

InputDevice::InputDevice(int playerNumber) {
    // Set the Controller Number
    _controllerNum = playerNumber - 1;
    //std::cout << "InputDevice::Constructed" << std::endl;
}

void InputDevice::DoSomething() {
    //std::cout << "InputDevice::DoSomething()" << std::endl;
    if (IsConnected()) {
        std::cout << "InputDevice " << _controllerNum << " is Connected" << std::endl;
    }
}

XINPUT_STATE InputDevice::GetState() {
    // Zeroise the state
    ZeroMemory(&_controllerState, sizeof(XINPUT_STATE));

    // Get the state
    XInputGetState(_controllerNum, &_controllerState);

    return _controllerState;
}

bool InputDevice::IsConnected() {
    // Zeroise the state
    ZeroMemory(&_controllerState, sizeof(XINPUT_STATE));

    // Get the state
    DWORD Result = XInputGetState(_controllerNum, &_controllerState);

    if (Result == ERROR_SUCCESS) {
        return true;
    } else {
        return false;
    }
}

void InputDevice::Vibrate(int leftVal, int rightVal) {
    // Create a Vibraton State
    XINPUT_VIBRATION Vibration;

    // Zeroise the Vibration
    ZeroMemory(&Vibration, sizeof(XINPUT_VIBRATION));

    // Set the Vibration Values
    Vibration.wLeftMotorSpeed = leftVal;
    Vibration.wRightMotorSpeed = rightVal;

    // Vibrate the controller
    XInputSetState(_controllerNum, &Vibration);
}
