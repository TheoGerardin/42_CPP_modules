#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main() {
    int N = 5;
    std::string name = "HordeZombie";

    Zombie* horde = zombieHorde(N, name);

    if (!horde) {
        std::cout << "Failed to create horde." << std::endl;
        return 1;
    }

    for (int i = 0; i < N; ++i) {
        horde[i].announce();
    }

    delete[] horde;

    return 0;
}
