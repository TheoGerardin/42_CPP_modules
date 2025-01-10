#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name)
    : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " has been summoned!" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << name << " has been annihilate!" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << name << " requests a high five! ✋" << std::endl;
}
