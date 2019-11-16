//
// Created by Jedzia on 14.11.2019.
//

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "readability-static-accessed-through-instance"

#include <iostream>
#include <STD17lib/fsm.h>
#include <CBreadBoard/cbreadboard.h>
#include <CBreadBoard/Arduino.h>

// State machine variables
#define FLIP_LIGHT_SWITCH 1

using namespace cbb;

int DUMMY_TCCR1A_LOCATION;
auto DUMMY_TCCR1A_POINTER = &DUMMY_TCCR1A_LOCATION;


// Constants
const uint32_t ButtonPressLongDuration = 1000;

const uint8_t ShortBlinkTime = 7;
const uint8_t LongBlinkTime = 32;

// Variables
volatile uint8_t shortBlink = 0;
volatile uint8_t longBlink = 0;

volatile bool shouldBlinkShort;
volatile bool shouldBlinkLong;

// IO definitions
InputDevice joystick(1);
Pin LED1Pin("Red LED", "PortA", "LED1Pin");


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

State state_light_on(on_light_on_enter, nullptr, &on_light_on_exit);
State state_light_off(on_light_off_enter, nullptr, &on_light_off_exit);
Fsm fsm(&state_light_off);


//void TIMER1_COMPA_vect2() {
ISR(TIMER1_COMPA_vect_dummy) {
    //std::cout << "    Fn(TIMER1_COMPA_vect)" << std::endl;

//        //PORTB ^= B00100000;// toggles bit which affects pin13
    if (shouldBlinkShort) {
        bool led1State = digitalRead(LED1Pin);
        digitalWrite(LED1Pin, led1State ^ 1);
        if (led1State) {
            shouldBlinkShort = false;
        }
    }
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


void simulate() {
    std::cout << "simulate() called" << std::endl;
    // setup simulation parameters, e.g. only transition messages are shown for pins
}

void setupIRQ() {
    DUMMY_TCCR1A = 42;
    std::cout << "DUMMY_TCCR1A[" << DUMMY_TCCR1A_POINTER << "] = '" << *DUMMY_TCCR1A_POINTER << "'." << std::endl;

    return;
    //DDRB |= B00100000;  // set pin13 to output without affecting other pins
    // above is identical to pinMode(LEDPIN, OUTPUT); using Direct Port Manipulation
    cli();
    TCCR1A = 0;
    TCCR1B = 0;
    OCR1A = 15624 / 8;  // = (target time / timer resolution) - 1 or 1 / 6.4e-5 - 1 = 15624
    //OCR1A = 15624>>1;  // divide by two >>EDIT added this line<<
    TCCR1B |= (1 << WGM12);// CTC mode on
    TCCR1B |= (1 << CS10);// Set CS10 and CS12 bits for 1024 prescaler:
    TCCR1B |= (1 << CS12);
    TIMSK1 |= (1 << OCIE1A);// timer compare intrupt
    sei();
}

void setup() {
    std::cout << "setup() called" << std::endl;

    /*pinMode(LED1Pin, OUTPUT);  // enable LED1 output
    pinMode(LED2Pin, OUTPUT);  // enable LED1 output


    debInput4.onPressed(onShortPressed);
    debInput4.onPressedFor(ButtonPressLongDuration, onLongPressed);

    //debInput1.begin();
    //debInput2.begin();
    //debInput3.begin();
    debInput4.begin();
    //debInput5.begin();
    //debInput6.begin();

    */
    setupIRQ();



    // State-Machine Mambo Jumbo
    fsm.add_transition(&state_light_on, &state_light_off,
                       FLIP_LIGHT_SWITCH,
                       &on_trans_light_on_light_off);
    fsm.add_transition(&state_light_off, &state_light_on,
                       FLIP_LIGHT_SWITCH,
                       &on_trans_light_off_light_on);

}

int i = 0;

void loop() {
    //std::cout << "loop() called" << std::endl;
    //TIMER1_COMPA_vect();
    //for (int i = 0; i < 5; ++i) {
//    if (i % 200 == 0)
//        std::cout << "loop() iteration " << i << std::endl;


    if(!shouldBlinkShort)
        shouldBlinkShort = joystick.ButtonAPressed();
    i++;
    return;
    digitalWrite(LED1Pin, i % 2);

    /* ToDo: run this via an interrupt simulation */
    //TIMER1_COMPA_vect();

    joystick.DoSomething();


    // No "fsm.run_machine()" call needed as no "on_state" funcions or timmed transitions exists
    // that is wrong
    fsm.run_machine();
    delay(200);
    fsm.trigger(FLIP_LIGHT_SWITCH);
    delay(200);
    fsm.trigger(FLIP_LIGHT_SWITCH);

    std::cout << std::endl;
    std::cout << std::endl;


    i++;
    delay(500);
    //}

}

#pragma clang diagnostic pop