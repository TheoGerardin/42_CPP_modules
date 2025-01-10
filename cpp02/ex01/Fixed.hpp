#pragma once

#include <iostream>
#include <cmath>

class Fixed {
private:
    int _value;
    static const int _fractionalBits = 8;
public:
    Fixed();
    Fixed(const int intValue);
    Fixed(const float floatValue);

    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);

    ~Fixed();

    float toFloat(void) const;
    int toInt(void) const;

    std::ostream &print(std::ostream &out) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
