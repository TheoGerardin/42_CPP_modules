#include "ScavTrap.hpp"

int main() {
    ClapTrap clap("Jean-Michel");
    clap.attack("Target");
    clap.takeDamage(5);
    clap.beRepaired(3);
    std::cout << "\n" << std::endl;
    ScavTrap scav("Robert");
    scav.attack("Enemy");
    scav.takeDamage(20);
    scav.beRepaired(15);
    scav.guardGate();

    return 0;
}