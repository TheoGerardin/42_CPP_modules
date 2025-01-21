#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::cout << "=== Basic test from subject ===" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "\n=== Test with 10,000 numbers ===" << std::endl;
    Span bigSpan(10000);
    srand(time(NULL));
    
    std::vector<int> numbers;
    for (int i = 0; i < 10000; ++i) {
        numbers.push_back(rand());
    }
    bigSpan.addRange(numbers.begin(), numbers.end());
    
    std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;

    std::cout << "\n=== Testing exceptions ===" << std::endl;
    try {
        Span sp2(1);
        sp2.addNumber(5);
        sp2.addNumber(3);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Span sp3(5);
        sp3.addNumber(5);
        std::cout << sp3.shortestSpan();
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
