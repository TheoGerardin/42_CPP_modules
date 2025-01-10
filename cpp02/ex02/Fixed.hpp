#pragma once

#include <iostream>
#include <cmath>

class Fixed {
private:
    int _value;
    static const int _fractionalBits = 8;

public:
    Fixed();
    Fixed(const int i);
    Fixed(const float f);
    Fixed(const Fixed &src);
    ~Fixed();

    Fixed &operator=(const Fixed &rhs);

    int getRawBits() const;
    void setRawBits(int const raw);

    bool operator>(const Fixed &rhs) const;
    bool operator<(const Fixed &rhs) const;
    bool operator>=(const Fixed &rhs) const;
    bool operator<=(const Fixed &rhs) const;
    bool operator==(const Fixed &rhs) const;
    bool operator!=(const Fixed &rhs) const;

    Fixed operator+(const Fixed &rhs) const;
    Fixed operator-(const Fixed &rhs) const;
    Fixed operator*(const Fixed &rhs) const;
    Fixed operator/(const Fixed &rhs) const;

    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);

    static Fixed min(Fixed &a, Fixed &b);
    static Fixed min(const Fixed &a, const Fixed &b);
    static Fixed max(Fixed &a, Fixed &b);
    static Fixed max(const Fixed &a, const Fixed &b);

    float toFloat() const;
    int toInt() const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);
