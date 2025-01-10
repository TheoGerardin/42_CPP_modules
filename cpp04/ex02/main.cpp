#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const Animal* animals[6];

    for (int i = 0; i < 3; ++i) {
        animals[i] = new Dog();
    }
    for (int i = 3; i < 6; ++i) {
        animals[i] = new Cat();
    }

    for (int i = 0; i < 6; ++i) {
        std::cout << animals[i]->getType() << std::endl;
        animals[i]->makeSound();
    }

    for (int i = 0; i < 6; ++i) {
        delete animals[i];
    }

    Animal *a = new Dog();
    a->makeSound();
    delete a;

    return 0;
}
