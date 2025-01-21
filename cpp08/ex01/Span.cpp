#include "Span.hpp"
#include <algorithm>
#include <limits>

Span::Span(unsigned int N) : N(N) {
    numbers.reserve(N);
}

Span::Span(const Span& other) : N(other.N), numbers(other.numbers) {
}

Span::~Span() {
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        N = other.N;
        numbers = other.numbers;
    }
    return *this;
}

void Span::addNumber(int number) {
    if (numbers.size() >= N) {
        throw FullSpanException();
    }
    numbers.push_back(number);
}

unsigned int Span::shortestSpan() const {
    if (numbers.size() <= 1) {
        throw NoSpanToFindException();
    }

    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());
    
    unsigned int minSpan = std::numeric_limits<unsigned int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        unsigned int span = static_cast<unsigned int>(sorted[i] - sorted[i-1]);
        minSpan = std::min(minSpan, span);
    }
    
    return minSpan;
}

unsigned int Span::longestSpan() const {
    if (numbers.size() <= 1) {
        throw NoSpanToFindException();
    }
    
    std::pair<std::vector<int>::const_iterator, std::vector<int>::const_iterator> result = 
        std::minmax_element(numbers.begin(), numbers.end());
        
    return static_cast<unsigned int>(*result.second - *result.first);
}

const char* Span::FullSpanException::what() const throw() {
    return "Span is already full";
}

const char* Span::NoSpanToFindException::what() const throw() {
    return "No span can be found (empty or only one element)";
}
