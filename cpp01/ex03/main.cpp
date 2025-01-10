#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
    {
        Weapon weapon("rusty sword");

        HumanA bob("Bob", weapon);
        bob.attack();
        weapon.setType("great sword");
        bob.attack();
    }

    {
        Weapon weapon("stick");

        HumanB jim("Jim");
        jim.setWeapon(weapon);
        jim.attack();
        weapon.setType("Thunderfury, Blessed Blade of the Windseeker");
        jim.attack();
    }

    return 0;
}
