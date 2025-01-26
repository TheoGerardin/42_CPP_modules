#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string& literal) {
    return (literal.length() == 1 && (literal[0]) && (literal[0]));
}

bool ScalarConverter::isInt(const std::string& literal) {
    if (literal.empty()) return false;
    size_t start = (literal[0] == '-' || literal[0] == '+') ? 1 : 0;
    return !literal.empty() && literal.find_first_not_of("0123456789", start) == std::string::npos;
}

bool ScalarConverter::isFloat(const std::string& literal) {
    if (literal == "nanf" || literal == "+inff" || literal == "-inff") return true;
    if (literal[literal.length() - 1] != 'f') return false;
    size_t start = (literal[0] == '-' || literal[0] == '+') ? 1 : 0;
    size_t dotCount = 0;
    for (size_t i = start; i < literal.length() - 1; i++) {
        if (literal[i] == '.') dotCount++;
        else if (!isdigit(literal[i])) return false;
    }
    return dotCount == 1;
}

bool ScalarConverter::isDouble(const std::string& literal) {
    if (literal == "nan" || literal == "+inf" || literal == "-inf") return true;
    size_t start = (literal[0] == '-' || literal[0] == '+') ? 1 : 0;
    size_t dotCount = 0;
    for (size_t i = start; i < literal.length(); i++) {
        if (literal[i] == '.') dotCount++;
        else if (!isdigit(literal[i])) return false;
    }
    return dotCount == 1;
}

void ScalarConverter::convertFromChar(char value) {
    std::cout << "char: '" << value << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(value) << std::endl;
    std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void ScalarConverter::convertFromInt(int value) {
    if (value >= 32 && value <= 126)
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << value << std::endl;
    std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void ScalarConverter::convertFromFloat(float value) {
    if (std::isnan(value) || std::isinf(value)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << value << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(value) << std::endl;
        return;
    }
    
    if (value >= 32 && value <= 126)
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
        
    if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    
    std::cout << "float: " << value << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convertFromDouble(double value) {
    if (std::isnan(value) || std::isinf(value)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
        std::cout << "double: " << value << std::endl;
        return;
    }
    
    if (value >= 32 && value <= 126)
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
        
    if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
        
    if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    
    std::cout << "double: " << value << std::endl;
}

void ScalarConverter::handlePseudoLiterals(const std::string& literal) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    
    if (literal == "nan" || literal == "nanf") {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (literal == "+inf" || literal == "+inff") {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (literal == "-inf" || literal == "-inff") {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

void ScalarConverter::convert(const std::string& literal) {
    if (literal.empty()) {
        std::cout << "Error: empty input" << std::endl;
        return;
    }

    if (literal == "nan" || literal == "nanf" || 
        literal == "+inf" || literal == "+inff" || 
        literal == "-inf" || literal == "-inff") {
        handlePseudoLiterals(literal);
        return;
    }

    if (isChar(literal)) {
        convertFromChar(literal[1]);
    }
    else if (isInt(literal)) {
        try {
            int value = std::atoi(literal.c_str());
            convertFromInt(value);
        }
        catch (...) {
            std::cout << "Error: conversion failed" << std::endl;
        }
    }
    else if (isFloat(literal)) {
        try {
            float value = std::atof(literal.c_str());
            convertFromFloat(value);
        }
        catch (...) {
            std::cout << "Error: conversion failed" << std::endl;
        }
    }
    else if (isDouble(literal)) {
        try {
            double value = std::atof(literal.c_str());
            convertFromDouble(value);
        }
        catch (...) {
            std::cout << "Error: conversion failed" << std::endl;
        }
    }
    else {
        std::cout << "Error: invalid input format" << std::endl;
    }
}
