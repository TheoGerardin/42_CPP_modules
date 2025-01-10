#include "ClapTrap.hpp"
#include "FragTrap.hpp"
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
    std::cout << "\n" << std::endl;
    FragTrap frag("Denis");
    frag.attack("Boss");
    frag.takeDamage(30);
    frag.beRepaired(25);
    frag.highFivesGuys();

    return 0;
}
