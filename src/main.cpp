#include <iostream>
#include <memory>
#include <chrono>
#include <conio.h>

#include "MyClass.h"

#include <STD17lib/library.h>
#include <STD17lib/network.h>
#include <STD17lib/fsm.h>

#include <CBreadBoard/cbreadboard.h>
#include <CBreadBoard/Arduino.h>

// State machine variables
#define FLIP_LIGHT_SWITCH 1

using namespace cbb;
//SerialCom Serial;





#define butInput1     4
#define butInput2     7
#define butInput3     8
#define butInput4    12
#define butInput5     6
#define butInput6   SDA

#define LED1Pin      13
#define LED2Pin       5

int main() {

    std::cout << "Hello, World!" << std::endl;
    auto f = 3.14159f;
    std::cout << "Float=" << f << std::endl;
    std::cout << "Float=" << f * 6 << std::endl;

    auto lambda = [](auto a) { std::cout << "lambada='" << a << "'." << std::endl; };
    lambda("I'm da lambda");

    MyLibrary m;
    MyClass mc;
    std::cout << "MyClass=.DoSomething()='" << mc.DoSomething() << "'." << std::endl;

    {
        auto p = std::make_unique<MyClass>();
        std::cout << "*MyClass=.DoSomething()='" << p->DoSomething() << "'." << std::endl;
    }

    Network net;
    net.getName();

    std::cout << std::endl;
    std::cout << std::endl;


    //return 0;

//    pinMode(LED1Pin, OUTPUT);  // enable LED1 output
//    pinMode(LED2Pin, OUTPUT);  // enable LED1 output


    /*std::cout << std::endl;
    std::cout << "Input devices:" << std::endl;

    InputDevice joystick(1);
    for (int i = 1; i < 6; ++i) {
         joystick.DoSomething();
        delay(200);
    }*/

    std::cout << std::endl;
    //return 0;




    Interrupt i1;
    Interrupt i2;


    /*std::cout << "Press any key..." << std::endl;
    while(1)
    {
        if(kbhit())
        {
            break;
        }
    }*/




    /*// here is where you'd put code that needs to be running all the time.

    // check to see if it's time to blink the LED; that is, if the difference
    // between the current time and last time you blinked the LED is bigger than
    // the interval at which you want to blink the LED.
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
        // save the last time you blinked the LED
        previousMillis = currentMillis;

        // if the LED is off turn it on and vice-versa:
        if (ledState == LOW) {
            ledState = HIGH;
        } else {
            ledState = LOW;
        }

        // set the LED with the ledState of the variable:
        digitalWrite(ledPin, ledState);
    }
     */

    /* MCU Code ToDo: introduce setup() and loop(), later */

    MCU mcu;
    mcu.run();


    std::cout << std::endl << std::endl;
    std::cout << "goodbye" << std::endl;
    return 1;
}
