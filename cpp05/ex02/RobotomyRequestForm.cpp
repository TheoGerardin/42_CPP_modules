#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : 
    AForm("Robotomy Request Form", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
    AForm("Robotomy Request Form", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
    AForm(other), target(other.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    checkExecutionRequirements(executor);
    
    std::cout << "* drilling noises *" << std::endl;
    
    std::srand(std::time(0));
    if (std::rand() % 2) {
        std::cout << target << " has been robotomized successfully" << std::endl;
    } else {
        std::cout << "Robotomy failed for " << target << std::endl;
    }
}