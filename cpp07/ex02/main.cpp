#include <iostream>
#include <string>
#include "Array.hpp"

int main() {
    try {
        // Test default constructor
        Array<int> empty;
        std::cout << "Empty array size: " << empty.size() << std::endl;

        // Test parameterized constructor
        Array<int> numbers(5);
        std::cout << "Number array size: " << numbers.size() << std::endl;

        // Test assignment and access
        for (unsigned int i = 0; i < numbers.size(); i++) {
            numbers[i] = i * 2;
        }
        
        // Display elements
        std::cout << "Numbers array content: ";
        for (unsigned int i = 0; i < numbers.size(); i++) {
            std::cout << numbers[i] << " ";
        }
        std::cout << std::endl;

        // Test copy constructor
        Array<int> copy(numbers);
        std::cout << "Copy array content: ";
        for (unsigned int i = 0; i < copy.size(); i++) {
            std::cout << copy[i] << " ";
        }
        std::cout << std::endl;

        // Modify original to prove deep copy
        numbers[0] = 100;
        std::cout << "Original array after modification: " << numbers[0] << std::endl;
        std::cout << "Copy array unchanged: " << copy[0] << std::endl;

        // Test with strings
        Array<std::string> strings(3);
        strings[0] = "Hello";
        strings[1] = "World";
        strings[2] = "!";
        
        std::cout << "String array content: ";
        for (unsigned int i = 0; i < strings.size(); i++) {
            std::cout << strings[i] << " ";
        }
        std::cout << std::endl;

        // Test out of bounds exception
        try {
            numbers[10] = 0;
        }
        catch (const std::exception& e) {
            std::cout << "Exception caught: Out of bounds access" << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cout << "Unexpected exception caught" << std::endl;
    }

    return 0;
}
