#include "Intern.hpp"
#include <iostream>

// Constructors and Destructor
Intern::Intern() {}

Intern::Intern(const Intern &other) {
    (void)other; // No need for deep copy as Intern has no members
}

Intern &Intern::operator=(const Intern &other) {
    (void)other; // No need for assignment as Intern has no members
    return *this;
}

Intern::~Intern() {}

// Helper function to create forms
AForm* createShrubbery(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(const std::string &target) {
    return new RobotomyRequestForm(target);
}

AForm* createPresidential(const std::string &target) {
    return new PresidentialPardonForm(target);
}

// Make form method
AForm* Intern::makeForm(const std::string &formName, const std::string &target) const {
    // Array of form names and their corresponding creation functions
    std::string formTypes[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*formCreators[])(const std::string &) = {
        createShrubbery,
        createRobotomy,
        createPresidential
    };

    for (int i = 0; i < 3; ++i) {
        if (formTypes[i] == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);
        }
    }

    std::cout << "Intern can't create form of type " << formName << std::endl;
    return nullptr;
}
