#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>

class RPN {
private:
    std::stack<int> _numbers;

    bool isOperator(char c);
    int performOperation(char op, int b, int a);

public:
    RPN();
    ~RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);

    int calculate(const std::string& expression);
};

#endif
