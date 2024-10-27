#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cctype>
#include <cmath>

// Vérifie si le littéral est un char
bool ScalarConverter::isChar(const std::string& literal) {
    return literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'';
}

// Vérifie si le littéral est un int
bool ScalarConverter::isInt(const std::string& literal) {
    char* end;
    long intValue = std::strtol(literal.c_str(), &end, 10);

    return *end == '\0' && intValue >= std::numeric_limits<int>::min() && intValue <= std::numeric_limits<int>::max();
}


// Vérifie si le littéral est un float
bool ScalarConverter::isFloat(const std::string& literal) {
    if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
        return true;
    }
    char* end;
    std::strtof(literal.c_str(), &end);
    return *end == 'f' && *(end + 1) == '\0';
}

// Vérifie si le littéral est un double
bool ScalarConverter::isDouble(const std::string& literal) {
    if (literal == "-inf" || literal == "+inf" || literal == "nan") {
        return true;
    }
    char* end;
    std::strtod(literal.c_str(), &end);
    return *end == '\0';
}

void ScalarConverter::convert(const std::string& literal) {
    if (isChar(literal)) {
        char c = literal[1]; // extrait le caractère entre les guillemets
        printChar(c);
        printInt(static_cast<int>(c));
        printFloat(static_cast<float>(c));
        printDouble(static_cast<double>(c));
    } else if (isInt(literal)) {
        long intValue = std::strtol(literal.c_str(), nullptr, 10);
        int i = static_cast<int>(intValue);
        printChar(static_cast<char>(i));
        printInt(i);
        printFloat(static_cast<float>(i));
        printDouble(static_cast<double>(i));
    } else if (isFloat(literal)) {
        float f = std::strtof(literal.c_str(), nullptr);
        printChar(static_cast<char>(f));
        printInt(static_cast<int>(f));
        printFloat(f);
        printDouble(static_cast<double>(f));
    } else if (isDouble(literal)) {
        double d = std::strtod(literal.c_str(), nullptr);
        printChar(static_cast<char>(d));
        printInt(static_cast<int>(d));
        printFloat(static_cast<float>(d));
        printDouble(d);
    } else {
        std::cerr << "Erreur : Littéral non reconnu" << std::endl;
    }
}

void ScalarConverter::printChar(char c) {
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non affichable" << std::endl;
}

void ScalarConverter::printInt(int i) {
    if (i > std::numeric_limits<int>::min() && i < std::numeric_limits<int>::max()) {
        std::cout << "int: " << i << std::endl;
    } else {
        std::cout << "int: impossible" << std::endl;
    }
}

void ScalarConverter::printFloat(float f) {
    if (std::isnan(f))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(f))
        std::cout << "float: " << (f > 0 ? "+inff" : "-inff") << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double d) {
    if (std::isnan(d))
        std::cout << "double: nan" << std::endl;
    else if (std::isinf(d))
        std::cout << "double: " << (d > 0 ? "+inf" : "-inf") << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}
