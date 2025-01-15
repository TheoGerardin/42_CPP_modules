#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : 
    AForm("Shrubbery Creation Form", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
    AForm("Shrubbery Creation Form", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :
    AForm(other), target(other.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    checkExecutionRequirements(executor);
    
    std::string filename = target + "_shrubbery";
    std::ofstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Could not create file");

    file << "       ###       " << std::endl;
    file << "      #####      " << std::endl;
    file << "     #######     " << std::endl;
    file << "    #########    " << std::endl;
    file << "   ###########   " << std::endl;
    file << "      #####      " << std::endl;
    file << "      #####      " << std::endl;
    
    file.close();
}