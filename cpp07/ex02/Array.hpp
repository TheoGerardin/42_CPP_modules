#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstdlib>

template<typename T>
class Array {
private:
    T* _array;
    unsigned int _size;

public:
    // Default constructor
    Array() : _array(NULL), _size(0) {}

    // Constructor with size
    Array(unsigned int n) : _size(n) {
        _array = new T[n]();
    }

    // Copy constructor
    Array(const Array& other) : _array(NULL), _size(0) {
        *this = other;
    }

    // Destructor
    ~Array() {
        if (_array)
            delete[] _array;
    }

    // Assignment operator
    Array& operator=(const Array& other) {
        if (this != &other) {
            if (_array)
                delete[] _array;
            _size = other._size;
            _array = new T[_size];
            for (unsigned int i = 0; i < _size; i++)
                _array[i] = other._array[i];
        }
        return *this;
    }

    // Subscript operator
    T& operator[](unsigned int index) {
        if (index >= _size)
            throw std::exception();
        return _array[index];
    }

    // Const subscript operator
    const T& operator[](unsigned int index) const {
        if (index >= _size)
            throw std::exception();
        return _array[index];
    }

    // Size getter
    unsigned int size() const {
        return _size;
    }
};

#endif
