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


void setupIRQ()
{
    //DDRB |= B00100000;  // set pin13 to output without affecting other pins
    // above is identical to pinMode(LEDPIN, OUTPUT); using Direct Port Manipulation
//    cli();
    TCCR1A = 0;
    TCCR1B = 0;
    OCR1A = 15624/8;  // = (target time / timer resolution) - 1 or 1 / 6.4e-5 - 1 = 15624
    //OCR1A = 15624>>1;  // divide by two >>EDIT added this line<<
    TCCR1B |= (1 << WGM12);// CTC mode on
    TCCR1B |= (1 << CS10);// Set CS10 and CS12 bits for 1024 prescaler:
    TCCR1B |= (1 << CS12);
    TIMSK1 |= (1 << OCIE1A);// timer compare intrupt
//    sei();
}


//
//ISR(TIMER1_COMPA_vect) {
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
//}
//

#define butInput1     4
#define butInput2     7
#define butInput3     8
#define butInput4    12
#define butInput5     6
#define butInput6   SDA

#define LED1Pin      13
#define LED2Pin       5


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

    setupIRQ();


//    pinMode(LED1Pin, OUTPUT);  // enable LED1 output
//    pinMode(LED2Pin, OUTPUT);  // enable LED1 output



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


    for (int i = 0; i < 3; ++i) {
        std::cout << "Timed loop " << i << std::endl;
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


    Interrupt i1;
    Interrupt i2;


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
