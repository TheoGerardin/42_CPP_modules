#include "Span.hpp"
#include <vector>
#include <iostream>
#include <ctime>

int main()
{

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span sp2(101);

    sp2.addingRange(100, 200);

    std::cout << "Test 1: Shortest Span after adding range (100 to 200) = " << sp2.shortestSpan() << std::endl;
    std::cout << "Test 1: Longest Span after adding range (100 to 200) = " << sp2.longestSpan() << std::endl;

    Span sp3(10000);

    std::vector<int> large_numbers(10000);
    for (int i = 0; i < 10000; ++i) {
        large_numbers[i] = i + 1;
    }

    sp3.addNumber(large_numbers.begin(), large_numbers.end());

    std::cout << "Test 2: Shortest Span with 10 000 numbers = " << sp3.shortestSpan() << std::endl;
    std::cout << "Test 2: Longest Span with 10 000 numbers = " << sp3.longestSpan() << std::endl;

    return 0;
}
