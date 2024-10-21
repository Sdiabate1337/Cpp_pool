#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 2);
        std::cout << b1 << std::endl;

        b1.incrementGrade();
        std::cout << b1 << std::endl;

        Bureaucrat b2(b1); // Test copy constructor
        std::cout << b2 << std::endl;

        Bureaucrat b3;
        b3 = b1; // Test copy assignment operator
        std::cout << b3 << std::endl;

        // This will throw an exception
        b1.incrementGrade();
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Bob", 151); // This will throw an exception
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
