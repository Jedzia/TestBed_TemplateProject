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
    if (!IsConnected())
        return;

    std::cout << "InputDevice " << _controllerNum << " is Connected" << std::endl;
    std::cout << "wButtons: '" << GetState().Gamepad.wButtons << "'." << std::endl;

    if (GetState().Gamepad.wButtons & (uint32_t) XINPUT_GAMEPAD_A) {
        Vibrate(65535, 0);
        std::cout << "InputDevice " << _controllerNum << " XINPUT_GAMEPAD_A" << std::endl;
    }
    if (GetState().Gamepad.wButtons & (uint32_t) XINPUT_GAMEPAD_B) {
        //Vibrate(65535, 0);
        //Vibrate();
        Vibrate(6535, 6535);
        std::cout << "InputDevice " << _controllerNum << " XINPUT_GAMEPAD_B" << std::endl;
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

    return Result == ERROR_SUCCESS;
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

bool InputDevice::ButtonAPressed() {
    return GetState().Gamepad.wButtons & (uint32_t) XINPUT_GAMEPAD_A;
}

bool InputDevice::ButtonBPressed() {
    return GetState().Gamepad.wButtons & (uint32_t) XINPUT_GAMEPAD_B;
}

bool InputDevice::ButtonXPressed() {
    return GetState().Gamepad.wButtons & (uint32_t) XINPUT_GAMEPAD_X;
}

