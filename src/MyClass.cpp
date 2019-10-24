//
// Created by Jedzia on 24.10.2019.
//

#include "MyClass.h"
#include <iostream>

std::string MyClass::DoSomething() {
    return "Jahahaha.";
}

MyClass::~MyClass() {
    std::cout << "Destructor MyClass" << std::endl;
}
