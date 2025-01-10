#pragma once

#include <string>
#include <iostream>

class Zombie {
private:
    std::string name;

public:
    Zombie(std::string zombieName);
    ~Zombie();

    void announce() const;
};
