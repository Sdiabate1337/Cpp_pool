#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 50);
        Form taxForm("TaxForm", 45, 30);

        std::cout << taxForm << std::endl;
        bob.signForm(taxForm);  // Should fail because Bob's grade is too low

        Bureaucrat alice("Alice", 40);
        alice.signForm(taxForm);  // Should succeed
        std::cout << taxForm << std::endl;  // Check if the form is signed

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
