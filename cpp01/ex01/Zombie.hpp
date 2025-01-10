#pragma once

#include <string>
#include <iostream>

class Zombie {
private:
    std::string name;

public:
    Zombie();
    Zombie(std::string zombieName);
    ~Zombie();

    void setName(std::string zombieName);
    void announce() const;
};
