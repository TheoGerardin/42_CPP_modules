#include <iostream>
#include "Serializer.hpp"

int main() {
    Data* data = new Data;
    data->s1 = "Hello";
    data->n = 42;
    data->s2 = "World";

    std::cout << "Original data address: " << data << std::endl;
    std::cout << "Original data content: " << data->s1 << ", " << data->n << ", " << data->s2 << std::endl;

    uintptr_t serialized = Serializer::serialize(data);
    std::cout << "Serialized value: " << serialized << std::endl;

    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized address: " << deserialized << std::endl;
    std::cout << "Deserialized content: " << deserialized->s1 << ", " << deserialized->n << ", " << deserialized->s2 << std::endl;

    std::cout << "\nPointer comparison: " << (data == deserialized ? "EQUAL" : "NOT EQUAL") << std::endl;

    delete data;
    return 0;
}
