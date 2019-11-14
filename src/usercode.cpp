//
// Created by Jedzia on 14.11.2019.
//


#include <iostream>
#include <CBreadBoard/cbreadboard.h>
#include <CBreadBoard/Arduino.h>

int DUMMY_TCCR1A_LOCATION;
auto DUMMY_TCCR1A_POINTER = &DUMMY_TCCR1A_LOCATION;

//#define DUMMY_TCCR1A _SFR_MEM8(0x80)
#define DUMMY_TCCR1A _SFR_MEM8(DUMMY_TCCR1A_POINTER)

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
}


void loop() {
    std::cout << "loop() called" << std::endl;

}