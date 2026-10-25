#include "SharedAndWeakOwnership.h"
#include "UniqueOwnership.h"

#include <iostream>

int main()
{
    std::cout << "=== C++ Smart Pointers ===\n";
    std::cout << "\n--- 1. Exclusive ownership with unique_ptr ---\n";
    UniqueOwnershipExample unique;
    unique.run();
    std::cout << "\n--- 2. Shared ownership and weak observation ---\n";
    SharedAndWeakOwnershipExample shared;
    shared.run();
}