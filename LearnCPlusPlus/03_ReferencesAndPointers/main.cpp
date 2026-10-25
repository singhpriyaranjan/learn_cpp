#include "Pointers.h"
#include "References.h"

#include <iostream>

int main()
{
    std::cout << "=== References and Pointers ===\n";
    std::cout << "\n--- 1. References as aliases ---\n";
    ReferencesExample references;
    references.run();
    std::cout << "\n--- 2. Addresses and nullable pointers ---\n";
    PointersExample pointers;
    pointers.run();
}