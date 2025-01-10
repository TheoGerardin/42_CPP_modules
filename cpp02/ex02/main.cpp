#include "Fixed.hpp"

int main() {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
    return 0;
}

/*#include "Fixed.hpp"

int main() {
    Fixed a;
    Fixed b(5.05f);
    Fixed c(2);

    std::cout << "Initial a: " << a << std::endl;
    std::cout << "Initial b: " << b << std::endl;
    std::cout << "Initial c: " << c << std::endl;

    std::cout << "\nOpérateurs de comparaison:" << std::endl;
    std::cout << "a > b : " << (a > b) << std::endl;
    std::cout << "a < b : " << (a < b) << std::endl;
    std::cout << "b >= c : " << (b >= c) << std::endl;
    std::cout << "b <= c : " << (b <= c) << std::endl;
    std::cout << "b == b : " << (b == b) << std::endl;
    std::cout << "b != c : " << (b != c) << std::endl;

    std::cout << "\nOpérateurs arithmétiques:" << std::endl;
    Fixed add = b + c;
    std::cout << "b + c = " << add << std::endl;

    Fixed sub = b - c;
    std::cout << "b - c = " << sub << std::endl;

    Fixed mul = b * c;
    std::cout << "b * c = " << mul << std::endl;

    Fixed div = b / c;
    std::cout << "b / c = " << div << std::endl;

    std::cout << "\nOpérateurs d'incrémentation et de décrémentation:" << std::endl;
    std::cout << "a avant incrémentation : " << a << std::endl;

    std::cout << "++a : " << ++a << std::endl;
    std::cout << "a après incrémentation : " << a << std::endl;

    std::cout << "a++ : " << a++ << std::endl;
    std::cout << "a après post-incrémentation : " << a << std::endl;

    std::cout << "--a : " << --a << std::endl;
    std::cout << "a après décrémentation : " << a << std::endl;

    std::cout << "a-- : " << a-- << std::endl;
    std::cout << "a après post-décrémentation : " << a << std::endl;

    std::cout << "\nTest des méthodes statiques min et max:" << std::endl;
    Fixed min_val = Fixed::min(a, b);
    std::cout << "min(a, b) = " << min_val << std::endl;

    Fixed max_val = Fixed::max(a, b);
    std::cout << "max(a, b) = " << max_val << std::endl;

    Fixed const const_b(5.05f);
    Fixed const const_c(2);

    Fixed min_const_val = Fixed::min(const_b, const_c);
    std::cout << "min(const_b, const_c) = " << min_const_val << std::endl;

    Fixed max_const_val = Fixed::max(const_b, const_c);
    std::cout << "max(const_b, const_c) = " << max_const_val << std::endl;

    return 0;
}
*/