#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robot("target");
        PresidentialPardonForm pardon("Alice");

        bob.signForm(shrubbery);
        bob.signForm(robot);
        bob.signForm(pardon);

        bob.executeForm(shrubbery);
        bob.executeForm(robot);
        bob.executeForm(pardon);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
