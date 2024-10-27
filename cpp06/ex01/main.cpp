// main.cpp
#include <iostream>
#include "Serializer.hpp"

int main() {
    // Création d'une instance de Data
    Data originalData;
    originalData.id = 42;
    originalData.name = "Example";

    // Sérialisation de l'instance de Data
    uintptr_t serializedData = Serializer::serialize(&originalData);

    // Désérialisation vers un pointeur de Data
    Data* deserializedData = Serializer::deserialize(serializedData);

    // Vérification que le pointeur d'origine et le pointeur désérialisé sont identiques
    std::cout << "Original pointer : " << &originalData << std::endl;
    std::cout << "Deserialized pointer : " << deserializedData << std::endl;

    // Vérification des valeurs des membres
    std::cout << "Data ID: " << deserializedData->id << std::endl;
    std::cout << "Data Name: " << deserializedData->name << std::endl;

    // Vérification si les adresses sont identiques
    if (&originalData == deserializedData) {
        std::cout << "Success: The deserialized pointer matches the original pointer." << std::endl;
    } else {
        std::cout << "Error: The deserialized pointer does not match the original pointer." << std::endl;
    }

    return 0;
}
