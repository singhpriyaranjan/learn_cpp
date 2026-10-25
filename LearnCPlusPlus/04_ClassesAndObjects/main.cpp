#include "Composition.h"
#include "Encapsulation.h"

#include <iostream>

int main()
{
    std::cout << "=== Classes and Objects ===\n";
    std::cout << "\n--- 1. Encapsulation and invariants ---\n";
    EncapsulationExample encapsulation;
    encapsulation.run();
    std::cout << "\n--- 2. Composition (has-a) ---\n";
    CompositionExample composition;
    composition.run();
}