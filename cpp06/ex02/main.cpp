#include "Base.hpp"
#include <iostream>

int main() {
    for (int i = 0; i < 5; i++) {
        std::cout << "\nTest " << i + 1 << ":" << std::endl;
        
        Base* ptr = generate();
        
        std::cout << "Identify using pointer: ";
        identify(ptr);
        
        std::cout << "Identify using reference: ";
        identify(*ptr);
        
        delete ptr;
    }

    std::cout << "\nTest with NULL pointer:" << std::endl;
    Base* nullPtr = NULL;
    identify(nullPtr);

    return 0;
}
