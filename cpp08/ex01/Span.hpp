#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>

class Span {
private:
    unsigned int N;
    std::vector<int> numbers;

public:
    Span(unsigned int N);
    Span(const Span& other);
    ~Span();
    Span& operator=(const Span& other);

    void addNumber(int number);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
    
    template<typename Iterator>
    void addRange(Iterator begin, Iterator end) {
        if (numbers.size() + std::distance(begin, end) > N) {
            throw std::runtime_error("Cannot add range: would exceed maximum capacity");
        }
        numbers.insert(numbers.end(), begin, end);
    }

    class FullSpanException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    class NoSpanToFindException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
};

#endif
