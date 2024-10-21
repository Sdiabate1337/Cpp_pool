#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Intern intern;

    // Test creating a RobotomyRequestForm
    AForm* rrf = intern.makeForm("robotomy request", "Bender");
    if (rrf) {
        Bureaucrat bureaucrat1("Alice", 50);
        bureaucrat1.signForm(*rrf);
        bureaucrat1.executeForm(*rrf);
        delete rrf; // Clean up the form
    }

    // Test creating a ShrubberyCreationForm
    AForm* scf = intern.makeForm("shrubbery creation", "Home");
    if (scf) {
        Bureaucrat bureaucrat2("Bob", 140);
        bureaucrat2.signForm(*scf);
        bureaucrat2.executeForm(*scf);
        delete scf; // Clean up the form
    }

    // Test creating a PresidentialPardonForm
    AForm* ppf = intern.makeForm("presidential pardon", "Zaphod");
    if (ppf) {
        Bureaucrat bureaucrat3("Charlie", 25);
        bureaucrat3.signForm(*ppf);
        bureaucrat3.executeForm(*ppf);
        delete ppf; // Clean up the form
    }

    // Test invalid form creation
    AForm* invalidForm = intern.makeForm("invalid form", "Target");
    if (invalidForm) {
        delete invalidForm; // Clean up if valid form was created
    }

    // Test grade exception for signing
    Bureaucrat bureaucrat4("Dave", 30);
    AForm* invalidSignForm = intern.makeForm("presidential pardon", "Martin");
    if (invalidSignForm) {
        try {
            bureaucrat4.signForm(*invalidSignForm);
            bureaucrat4.executeForm(*invalidSignForm);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        delete invalidSignForm; // Clean up the form
    }

    return 0;
}
