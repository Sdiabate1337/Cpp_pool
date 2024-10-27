// main.cpp
#include "identify.hpp"
#include <iostream>

int main() {
    Base* basePtr = generate();

    std::cout << "Identification via pointeur : ";
    identify(basePtr);

    std::cout << "Identification via référence : ";
    identify(*basePtr);

    // Libération de la mémoire
    delete basePtr;

    return 0;
}
