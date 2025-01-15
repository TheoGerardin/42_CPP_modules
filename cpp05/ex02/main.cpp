#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        // Create bureaucrats with different grades
        Bureaucrat boss("Boss", 1);                // Highest grade
        Bureaucrat manager("Manager", 40);         // Mid-level grade
        Bureaucrat intern("Intern", 150);          // Lowest grade

        std::cout << "\n=== Testing Shrubbery Creation Form ===" << std::endl;
        ShrubberyCreationForm shrubbery("home");
        std::cout << shrubbery << std::endl;
        
        intern.signForm(shrubbery);      // Should fail (grade too low)
        boss.signForm(shrubbery);        // Should succeed
        intern.executeForm(shrubbery);   // Should fail (grade too low)
        boss.executeForm(shrubbery);     // Should succeed and create file

        std::cout << "\n=== Testing Robotomy Request Form ===" << std::endl;
        RobotomyRequestForm robotomy("Bender");
        std::cout << robotomy << std::endl;
        
        manager.signForm(robotomy);      // Should succeed
        intern.executeForm(robotomy);    // Should fail (grade too low)
        manager.executeForm(robotomy);   // Should succeed
        boss.executeForm(robotomy);      // Should succeed

        std::cout << "\n=== Testing Presidential Pardon Form ===" << std::endl;
        PresidentialPardonForm pardon("Criminal");
        std::cout << pardon << std::endl;
        
        manager.signForm(pardon);        // Should fail (grade too low)
        boss.signForm(pardon);           // Should succeed
        manager.executeForm(pardon);     // Should fail (grade too low)
        boss.executeForm(pardon);        // Should succeed

        std::cout << "\n=== Testing Exception Cases ===" << std::endl;
        // Try to execute unsigned form
        ShrubberyCreationForm unsignedForm("garden");
        boss.executeForm(unsignedForm);  // Should fail (not signed)

    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
