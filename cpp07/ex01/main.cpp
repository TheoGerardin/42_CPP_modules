#include <iostream>
#include "Iter.hpp"

template<typename T>
void print(T const & x) {
    std::cout << x << " ";
}

void multiply_by_two(int const & n) {
    const_cast<int&>(n) *= 2;
}

int main(void) {
    int intArray[] = {1, 2, 3, 4, 5};
    std::cout << "Original int array: ";
    iter(intArray, 5, print);
    std::cout << std::endl;

    iter(intArray, 5, multiply_by_two);
    std::cout << "After multiply_by_two: ";
    iter(intArray, 5, print);
    std::cout << std::endl;

    std::string strArray[] = {"Hello", "World", "!"};
    std::cout << "String array: ";
    iter(strArray, 3, print);
    std::cout << std::endl;

    double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
    std::cout << "Double array: ";
    iter(doubleArray, 4, print);
    std::cout << std::endl;

    return 0;
}
