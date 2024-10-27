#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    // Check if the number of arguments is correct
    if (argc != 2) {
        std::cerr << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }

    // Call the convert method with the provided argument
    ScalarConverter::convert(argv[1]);

    return 0;
}
