#include "AForm.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute, const std::string &target)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), target(target) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute), target(other.target) {}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        this->isSigned = other.isSigned;
    }
    return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const {
    return name;
}

bool AForm::getIsSigned() const {
    return isSigned;
}

int AForm::getGradeToSign() const {
    return gradeToSign;
}

int AForm::getGradeToExecute() const {
    return gradeToExecute;
}

const std::string &AForm::getTarget() const {
    return target;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const {
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > gradeToExecute)
        throw GradeTooLowException();
    executeAction();
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Form grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Form grade too low!";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "Form not signed!";
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
    out << "Form: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No") 
        << ", Grade required to sign: " << form.getGradeToSign() 
        << ", Grade required to execute: " << form.getGradeToExecute();
    return out;
}
