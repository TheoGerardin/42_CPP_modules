#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat bob("Bob", 50);
        Form form1("Tax Form", 75, 100);
        
        std::cout << "Initial state:" << std::endl;
        std::cout << bob << std::endl;
        std::cout << form1 << std::endl;

        bob.signForm(form1);
        std::cout << form1 << std::endl;

        Form form2("Top Secret", 20, 10);
        bob.signForm(form2);
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Form invalidForm("Invalid", 0, 100);
    } catch (const std::exception& e) {
        std::cout << "Exception caught while creating form: " << e.what() << std::endl;
    }

    try {
        Form invalidForm2("Invalid", 151, 100);
    } catch (const std::exception& e) {
        std::cout << "Exception caught while creating form: " << e.what() << std::endl;
    }

    return 0;
}