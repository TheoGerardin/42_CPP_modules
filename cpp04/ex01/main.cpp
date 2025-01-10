#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    int j = 6;
    const Animal* animals[j];

    for (int i = 0; i < (j / 2); ++i) {
        animals[i] = new Dog();
    }
    for (int i = (j / 2); i < j; ++i) {
        animals[i] = new Cat();
    }

    for (int i = 0; i < j; ++i) {
        std::cout << animals[i]->getType() << std::endl;
        animals[i]->makeSound();
    }

    for (int i = 0; i < j; ++i) {
        delete animals[i];
    }

    return 0;
}
