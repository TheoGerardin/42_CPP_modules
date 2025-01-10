#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << name << " created!" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (energyPoints > 0 && hitPoints > 0) {
        energyPoints--;
        std::cout << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " can't attack due to lack of energy or health!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints <= amount) {
        hitPoints = 0;
        std::cout << name << " has taken " << amount << " damage and is destroyed!" << std::endl;
    } else {
        hitPoints -= amount;
        std::cout << name << " takes " << amount << " damage, remaining HP: " << hitPoints << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints > 0 && hitPoints > 0) {
        energyPoints--;
        hitPoints += amount;
        std::cout << name << " repairs itself for " << amount << " HP, total HP: " << hitPoints << std::endl;
    } else {
        std::cout << name << " can't repair due to lack of energy or health!" << std::endl;
    }
}
