#pragma ide diagnostic ignored "readability-static-accessed-through-instance"

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

// Transition callback functions
void on_light_on_enter() {
    Serial.println("Entering LIGHT_ON");
}

void on_light_on_exit() {
    Serial.println("Exiting LIGHT_ON");
}

void on_light_off_enter() {
    Serial.println("Entering LIGHT_OFF");
}

void on_light_off_exit() {
    Serial.println("Exiting LIGHT_OFF");
}

void on_trans_light_on_light_off() {
    Serial.println("Transitioning from LIGHT_ON to LIGHT_OFF");
}

void on_trans_light_off_light_on() {
    Serial.println("Transitioning from LIGHT_OFF to LIGHT_ON");
}


#define ISR(x) void x()

ISR(TIMER1_COMPA_vect) {
    std::cout << "Fn(TIMER1_COMPA_vect)" << std::endl;

//        //PORTB ^= B00100000;// toggles bit which affects pin13
//        if(shouldBlinkShort)
//        {
//            bool led1State = digitalRead(LED1Pin);
//            digitalWrite(LED1Pin, led1State ^ 1);
//            if(led1State)
//            {
//                shouldBlinkShort = false;
//            }
//        }
//
//        /*if(shouldBlinkLong)
//        {
//          bool led2State = digitalRead(LED2Pin);
//          digitalWrite(LED2Pin, led2State ^ 1);
//          if(led2State)
//          {
//            shouldBlinkLong = false;
//          }
//        }*/
//
//        if(shortBlink)
//        {
//            //bool led2State = digitalRead(LED2Pin);
//            //digitalWrite(LED2Pin, led2State ^ 1);
//            //digitalWrite(LED2Pin, !((shortBlink % 4) <= 2));
//            digitalWrite(LED2Pin, !((shortBlink % 2) ));
//            /*if(led2State)
//            {
//              shouldBlinkLong = false;
//            }*/
//            shortBlink--;
//        }
//
//
//        if(longBlink)
//        {
//            //bool led2State = digitalRead(LED2Pin);
//            //digitalWrite(LED2Pin, led2State ^ 1);
//            digitalWrite(LED2Pin, !((longBlink % 8) <= 4));
//            /*if(led2State)
//            {
//              shouldBlinkLong = false;
//            }*/
//            longBlink--;
//        }
//
//
}


#define butInput1     4
#define butInput2     7
#define butInput3     8
#define butInput4    12
#define butInput5     6
#define butInput6   SDA

#define LED1Pin      13
#define LED2Pin       5

void setupIRQ();
void setup();
void loop();

int main() {

    std::cout << "Fucking Hello, World!" << std::endl;
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


    /* MCU Code ToDo: introduce setup() and loop(), later */

    MCU mcu;
    mcu.run();



//    pinMode(LED1Pin, OUTPUT);  // enable LED1 output
//    pinMode(LED2Pin, OUTPUT);  // enable LED1 output


    std::cout << std::endl;
    std::cout << "Input devices:" << std::endl;

    for (int i = 1; i < 6; ++i) {
        InputDevice joystick(1);
        joystick.DoSomething();
        delay(200);
    }

    std::cout << std::endl;
    //return 0;

    // State-Machine Mambo Jumbo

    State state_light_on(on_light_on_enter, nullptr, &on_light_on_exit);
    State state_light_off(on_light_off_enter, nullptr, &on_light_off_exit);
    Fsm fsm(&state_light_off);


    fsm.add_transition(&state_light_on, &state_light_off,
                       FLIP_LIGHT_SWITCH,
                       &on_trans_light_on_light_off);
    fsm.add_transition(&state_light_off, &state_light_on,
                       FLIP_LIGHT_SWITCH,
                       &on_trans_light_off_light_on);



    // No "fsm.run_machine()" call needed as no "on_state" funcions or timmed transitions exists
    // that is wrong
    fsm.run_machine();
    delay(200);
    fsm.trigger(FLIP_LIGHT_SWITCH);
    delay(200);
    fsm.trigger(FLIP_LIGHT_SWITCH);

    std::cout << std::endl;
    std::cout << std::endl;

    Interrupt i1;
    Interrupt i2;


    for (int i = 0; i < 5; ++i) {
        std::cout << "Timed loop " << i << std::endl;
        loop();

        Pin led_red("Red LED", "PortA", "LED1Pin");
        digitalWrite(led_red, i % 2);

        /* ToDo: run this via an interrupt simulation */
        TIMER1_COMPA_vect();

        InputDevice joystick(1);
        joystick.DoSomething();

        delay(500);
    }


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



    std::cout << std::endl << std::endl;
    std::cout << "goodbye" << std::endl;
    return 1;
}
