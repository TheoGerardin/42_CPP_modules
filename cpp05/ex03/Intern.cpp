#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

AForm* Intern::createShrubberyForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    FormType forms[] = {
        {"shrubbery creation", &createShrubberyForm},
        {"robotomy request", &createRobotomyForm},
        {"presidential pardon", &createPresidentialForm}
    };
    
    const int numForms = sizeof(forms) / sizeof(forms[0]);
    
    for (int i = 0; i < numForms; i++) {
        if (formName == forms[i].name) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].create(target);
        }
    }
    
    std::cout << "Intern cannot create form: " << formName << " (unknown form type)" << std::endl;
    return NULL;
}
