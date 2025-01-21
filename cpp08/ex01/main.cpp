#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        std::vector<int> range(10000, 42);
        Span bigSpan(20000);
        bigSpan.addNumber(range.begin(), range.end());
        std::cout << "Shortest span in bigSpan: " << bigSpan.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}