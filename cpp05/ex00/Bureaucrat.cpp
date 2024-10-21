#include "Bureaucrat.hpp"

// Default constructor (not typically used, but part of canonical form)
Bureaucrat::Bureaucrat() : _name("Unnamed"), _grade(150) {
    std::cout << "Default constructor called." << std::endl;
}

// Parameterized constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    std::cout << "Parameterized constructor called." << std::endl;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
    std::cout << "Copy constructor called." << std::endl;
}

// Copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        _grade = other._grade; // Name is constant and cannot be reassigned.
    }
    std::cout << "Copy assignment operator called." << std::endl;
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor called." << std::endl;
}

// Getters
const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

// Increment and Decrement methods
void Bureaucrat::incrementGrade() {
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}

// Exception messages
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

// Overloading << operator
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade();
    return out;
}
