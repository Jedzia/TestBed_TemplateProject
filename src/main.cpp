#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    auto f = 3.14159f;
    std::cout << "Float=" << f << std::endl;
    std::cout << "Float=" << f*6 << std::endl;

    auto lambda = [](auto a) { std::cout << "lambada='" << a << "'." << std::endl; };
    lambda("I'm da lambda");
    return 0;
}