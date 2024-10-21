#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Form;

class Bureaucrat {
public:
    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    // Canonical form constructors and destructor
    Bureaucrat();                                      // Default constructor
    Bureaucrat(const Bureaucrat& other);               // Copy constructor
    Bureaucrat& operator=(const Bureaucrat& other);    // Copy assignment operator
    ~Bureaucrat();                                     // Destructor

    // Parameterized constructor
    Bureaucrat(const std::string& name, int grade);

    // Getters
    const std::string& getName() const;
    int getGrade() const;

    // Methods to increment and decrement grade
    void incrementGrade();
    void decrementGrade();

    void signForm(Form &form);

private:
    const std::string _name;
    int _grade;

    // Output operator overload
    friend std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);
};

#endif
