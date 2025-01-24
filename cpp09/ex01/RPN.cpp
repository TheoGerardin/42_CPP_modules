#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) : _numbers(other._numbers) {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _numbers = other._numbers;
    }
    return *this;
}

bool RPN::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::performOperation(char op, int b, int a) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) throw std::runtime_error("Division by zero");
            return a / b;
        default: throw std::runtime_error("Invalid operator");
    }
}

int RPN::calculate(const std::string& expression) {
    std::istringstream iss(expression);
    char token;
    
    while (iss >> token) {
        if (std::isdigit(token)) {
            _numbers.push(token - '0');
        } else if (isOperator(token)) {
            if (_numbers.size() < 2) 
                throw std::runtime_error("Insufficient operands");
            
            int b = _numbers.top(); _numbers.pop();
            int a = _numbers.top(); _numbers.pop();
            
            _numbers.push(performOperation(token, b, a));
        } else if (!std::isspace(token)) {
            throw std::runtime_error("Invalid token");
        }
    }
    
    if (_numbers.size() != 1) 
        throw std::runtime_error("Invalid expression");
    
    return _numbers.top();
}
