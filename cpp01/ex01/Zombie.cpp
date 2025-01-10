#include "Zombie.hpp"

Zombie::Zombie() : name("") {
}

Zombie::Zombie(std::string zombieName) : name(zombieName) {
}

Zombie::~Zombie() {
    std::cout << name << " is destroyed." << std::endl;
}

void Zombie::setName(std::string zombieName) {
    name = zombieName;
}

void Zombie::announce() const {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
