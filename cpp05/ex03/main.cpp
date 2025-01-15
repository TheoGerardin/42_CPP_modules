#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    try {
        Intern intern;
        Bureaucrat highLevel("Boss", 1);
        Bureaucrat lowLevel("Rookie", 150);

        AForm* shrubbery = intern.makeForm("shrubbery creation", "garden");
        AForm* robotomy = intern.makeForm("robotomy request", "Bender");
        AForm* pardon = intern.makeForm("presidential pardon", "Criminal");

        if (shrubbery) {
            std::cout << "\nTesting Shrubbery Creation Form:" << std::endl;
            std::cout << *shrubbery << std::endl;
            lowLevel.signForm(*shrubbery);
            highLevel.signForm(*shrubbery);
            lowLevel.executeForm(*shrubbery);
            highLevel.executeForm(*shrubbery);
            delete shrubbery;
        }

        if (robotomy) {
            std::cout << "\nTesting Robotomy Request Form:" << std::endl;
            std::cout << *robotomy << std::endl;
            highLevel.signForm(*robotomy);
            highLevel.executeForm(*robotomy);
            delete robotomy;
        }

        if (pardon) {
            std::cout << "\nTesting Presidential Pardon Form:" << std::endl;
            std::cout << *pardon << std::endl;
            highLevel.signForm(*pardon);
            highLevel.executeForm(*pardon);
            delete pardon;
        }

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
