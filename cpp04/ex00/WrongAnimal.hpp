#pragma once

#include <iostream>
#include <string>

class WrongAnimal {
protected:
    std::string type;
    
public:
    WrongAnimal();
    ~WrongAnimal();
    void makeSound() const;
    std::string getType() const;
};