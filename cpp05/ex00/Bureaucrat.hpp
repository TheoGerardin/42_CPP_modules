#pragma once

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat {
private:
    const std::string name;
    int grade;

public:
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    Bureaucrat(const std::string &name, int grade);
    ~Bureaucrat();

    const std::string& getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    friend std::ostream& operator<<(std::ostream &out, const Bureaucrat &b);
};