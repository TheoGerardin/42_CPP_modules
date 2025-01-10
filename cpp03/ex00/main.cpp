#include "ClapTrap.hpp"

int main() {
    ClapTrap robot("Jean-Michel");

    robot.attack("EnemyBot");
    robot.takeDamage(5);
    robot.beRepaired(3);
    robot.attack("EnemyBot");
    robot.takeDamage(10);
    robot.beRepaired(5);

    return 0;
}
