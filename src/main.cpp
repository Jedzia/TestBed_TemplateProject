#include <iostream>
#include <memory>
#include "MyClass.h"
#include <STD17lib/library.h>
#include <STD17lib/network.h>


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

    std::cout << std::endl << std::endl;
    std::cout << "goodbye" << std::endl;
    return 0;
}