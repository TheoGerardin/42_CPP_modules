#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << " constructed!" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << name << " destructed!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (energyPoints > 0 && hitPoints > 0) {
        std::cout << name << " trying to do something to " << target
                  << ", and with chances causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    } else {
        std::cout << name << " is useless now." << std::endl;
    }
}

void ScavTrap::guardGate() {
    std::cout << name << " is now in Gatekeeper mode." << std::endl;
}