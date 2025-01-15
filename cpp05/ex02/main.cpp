#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat manager("Manager", 40);
        Bureaucrat intern("Intern", 150);

        std::cout << "\n=== Testing Shrubbery Creation Form ===" << std::endl;
        ShrubberyCreationForm shrubbery("home");
        std::cout << shrubbery << std::endl;
        
        intern.signForm(shrubbery);
        boss.signForm(shrubbery);
        intern.executeForm(shrubbery);
        boss.executeForm(shrubbery);

        std::cout << "\n=== Testing Robotomy Request Form ===" << std::endl;
        RobotomyRequestForm robotomy("Bender");
        std::cout << robotomy << std::endl;
        
        manager.signForm(robotomy);
        intern.executeForm(robotomy);
        manager.executeForm(robotomy);
        boss.executeForm(robotomy);

        std::cout << "\n=== Testing Presidential Pardon Form ===" << std::endl;
        PresidentialPardonForm pardon("Criminal");
        std::cout << pardon << std::endl;
        
        manager.signForm(pardon);
        boss.signForm(pardon);
        manager.executeForm(pardon);
        boss.executeForm(pardon);

        std::cout << "\n=== Testing Exception Cases ===" << std::endl;
        ShrubberyCreationForm unsignedForm("garden");
        boss.executeForm(unsignedForm);

    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
