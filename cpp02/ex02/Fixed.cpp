#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int i) : _value(i << _fractionalBits) {}

Fixed::Fixed(const float f) : _value(roundf(f * (1 << _fractionalBits))) {}

Fixed::Fixed(const Fixed &src) {
    *this = src;
}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &rhs) {
    if (this != &rhs)
        _value = rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits() const {
    return _value;
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
}

bool Fixed::operator>(const Fixed &rhs) const {
    return _value > rhs._value;
}

bool Fixed::operator<(const Fixed &rhs) const {
    return _value < rhs._value;
}

bool Fixed::operator>=(const Fixed &rhs) const {
    return _value >= rhs._value;
}

bool Fixed::operator<=(const Fixed &rhs) const {
    return _value <= rhs._value;
}

bool Fixed::operator==(const Fixed &rhs) const {
    return _value == rhs._value;
}

bool Fixed::operator!=(const Fixed &rhs) const {
    return _value != rhs._value;
}

Fixed Fixed::operator+(const Fixed &rhs) const {
    Fixed result;
    result.setRawBits(_value + rhs.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const {
    Fixed result;
    result.setRawBits(_value - rhs.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const {
    Fixed result;
    result.setRawBits((_value * rhs.getRawBits()) >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &rhs) const {
    if (rhs.getRawBits() == 0) {
        std::cerr << "Error: Division by zero!" << std::endl;
        exit(1);
    }
    Fixed result;
    result.setRawBits((_value << _fractionalBits) / rhs.getRawBits());
    return result;
}

Fixed &Fixed::operator++() {
    ++_value;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++(*this);
    return temp;
}

Fixed &Fixed::operator--() {
    --_value;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --(*this);
    return temp;
}

Fixed Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

Fixed Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

Fixed Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

float Fixed::toFloat() const {
    return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt() const {
    return _value >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &f) {
    out << f.toFloat();
    return out;
}
