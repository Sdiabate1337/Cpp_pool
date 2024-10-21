#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructor
Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

// Copy constructor and assignment operator
Form::Form(const Form &other)
    : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form &Form::operator=(const Form &other) {
    if (this != &other) {
        _isSigned = other._isSigned;
        // const attributes can't be assigned
    }
    return *this;
}

// Destructor
Form::~Form() {}

// Getters
const std::string &Form::getName() const { return _name; }
bool Form::getIsSigned() const { return _isSigned; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }

// Member function to sign the form
void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        throw Form::GradeTooLowException();
    _isSigned = true;
}

// Exceptions
const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low!";
}

// Overload << operator
std::ostream &operator<<(std::ostream &out, const Form &form) {
    out << "Form " << form.getName()
        << ", signing grade: " << form.getGradeToSign()
        << ", execution grade: " << form.getGradeToExecute()
        << ", signed: " << (form.getIsSigned() ? "yes" : "no");
    return out;
}
